#ifndef _SPRD_IOMMU_H
#define _SPRD_IOMMU_H

#include <linux/scatterlist.h>
#include <asm/cacheflush.h>

#define GSP_VSP_IOMMU_SIZE		(2 * 256 * 1024)
#define DCAM_ISP_IOMMU_SIZE	(26 * 100 * 1024)
#define CPP_JPEG_IOMMU_SIZE		(12 * 100 * 1024)
#define DISPC_IOMMU_SIZE		(5 * 100 * 1024)

struct sprd_iommu_init_data {
	int id;                        /* iommu id */
	char *name;                    /* iommu name */

	unsigned long iova_base;            /* io virtual address base */
	size_t iova_size;            /* io virtual address size */
	unsigned long pgt_base;             /* iommu page table base address */
	size_t pgt_size;             /* iommu page table array size */
	unsigned long ctrl_reg;             /* iommu control register */
	unsigned long fault_page;
	unsigned long re_route_page;
	unsigned int iommu_rev;

	/*add for whale2 iommupf*/
	unsigned int iommupf_rev;
	unsigned long pfch_iova_base;            /* io virtual address base */
	size_t pfch_iova_size;            /* io virtual address size */
	unsigned int fullmode_en;
	unsigned int  total_ch_num;

	unsigned int pf_ch_write_start;
	unsigned int pf_ch_write_end;

	unsigned int pf_ch_read_start;
	unsigned int pf_ch_read_end;
	unsigned int fullmode_ch_write;
	unsigned int fullmode_ch_read;

	/*add for 9860 interlace ddr*/
	/*iommu reserved memory of pf page table*/
	unsigned long pagt_base_ddr;
	unsigned long pagt_ddr_size;
	/*for shakrl2/isharl2*/
	unsigned int iommuex_rev;
};

#define SPRD_MAX_SG_CACHED_CNT 1024

enum sg_pool_status {
	SG_SLOT_FREE = 0,
	SG_SLOT_USED,
};

enum sprd_iommu_chtype {
	SPRD_IOMMU_PF_CH_READ = 0x100,/*prefetch channel only support read*/
	SPRD_IOMMU_PF_CH_WRITE,/* prefetch channel only support write*/
	SPRD_IOMMU_FM_CH_RW,/*fullmode channel support w/r in one channel*/
	SPRD_IOMMU_EX_CH_READ,/*channel only support read, only ISP use now*/
	SPRD_IOMMU_EX_CH_WRITE,/*channel only support read, only ISP use now*/
	SPRD_IOMMU_CH_TYPE_INVALID, /*unsupported channel type*/
};

enum sprd_iommu_id {
	SPRD_IOMMU_VSP,
	SPRD_IOMMU_DCAM,
	SPRD_IOMMU_CPP,
	SPRD_IOMMU_GSP,
	SPRD_IOMMU_JPG,
	SPRD_IOMMU_DISP,
	SPRD_IOMMU_ISP,
	SPRD_IOMMU_MAX,
};

struct sprd_iommu_sg_rec {
	unsigned long sg_table_addr;
	void *buf_addr;
	unsigned long iova_addr;
	unsigned long iova_size;
	enum sg_pool_status status;
	int map_usrs;
};

struct sprd_iommu_sg_pool {
	int pool_cnt;
	struct sprd_iommu_sg_rec slot[SPRD_MAX_SG_CACHED_CNT];
};

struct sprd_iommu_dev {
	struct sprd_iommu_init_data *init_data;
	struct gen_pool *pool;
	struct gen_pool *pf_ch_pool;
	struct sprd_iommu_ops *ops;
	struct clk* mmu_mclock;
	struct clk* mmu_pclock;
	struct clk* mmu_clock;
	struct clk* mmu_axiclock;
	atomic_t iommu_dev_cnt;

	void *private;
	unsigned int map_count;
	unsigned int div2_frq;
	bool light_sleep_en;
	spinlock_t pgt_lock;
	unsigned int status_count;
	struct mutex status_mutex;

	struct sprd_iommu_sg_pool sg_pool;
	struct device *drv_dev;
	unsigned long mmupf_iovaarray[SPRD_MAX_SG_CACHED_CNT];

	enum sprd_iommu_chtype ch_type;
	u32 channel_id;
	int id;
};

/*map arguments for kernel space*/
struct sprd_iommu_map_data {
	struct sg_table *table;
	void *buf;
	size_t iova_size;
	enum sprd_iommu_chtype ch_type;
	unsigned int sg_offset;
	unsigned long iova_addr;/*output*/
};

struct sprd_iommu_unmap_data {
	unsigned long iova_addr;
	size_t iova_size;
	enum sprd_iommu_chtype ch_type;
	struct sg_table *table;
	void *buf;
	u32 channel_id;
};

struct sprd_iommu_list_data {
	enum sprd_iommu_id iommu_id;
	bool enabled;
	struct sprd_iommu_dev *iommu_dev;
};

/*kernel API for Iommu map/unmap*/
#if IS_ENABLED(CONFIG_SPRD_IOMMU)
int sprd_iommu_attach_device(struct device *dev);
int sprd_iommu_dettach_device(struct device *dev);

int sprd_iommu_get_kaddr(struct device *dev, struct sprd_iommu_map_data *data);
int sprd_iommu_get_kaddr_with_sg(struct device *dev, struct sprd_iommu_map_data *data);
int sprd_iommu_map(struct device *dev, struct sprd_iommu_map_data *data);
int sprd_iommu_free_kaddr(struct device *dev, struct sprd_iommu_unmap_data *data);
int sprd_iommu_free_kaddr_with_id(struct device *dev,
			struct sprd_iommu_unmap_data *data, u32 channel_id);
int sprd_iommu_free_kaddr_with_sg(struct device *dev,
			struct sg_table *sg, size_t iova_size);
int sprd_iommu_unmap(struct device *dev, struct sprd_iommu_unmap_data *data);
int sprd_iommu_unmap_orphaned(struct sg_table *sg, int id);
int sprd_iommu_suspend(struct device *dev);
int sprd_iommu_resume(struct device *dev);
int sprd_iommu_restore(struct device *dev);
int sprd_iommu_open(struct device *dev);
int sprd_iommu_release(struct device *dev);
#else
static inline int sprd_iommu_attach_device(struct device *dev)
{
	return -ENODEV;
}

static inline int sprd_iommu_dettach_device(struct device *dev)
{
	return -ENODEV;
}

static inline int sprd_iommu_get_kaddr(struct device *dev,
					struct sprd_iommu_map_data *data)
{
	return -ENODEV;
}

static inline int sprd_iommu_get_kaddr_with_sg(struct device *dev,
					struct sprd_iommu_map_data *data)
{
	return -ENODEV;
}

static inline int sprd_iommu_map(struct device *dev,
					struct sprd_iommu_map_data *data)
{
	return -ENODEV;
}
static inline int sprd_iommu_free_kaddr(struct device *dev,
					struct sprd_iommu_unmap_data *data)
{
	return -ENODEV;
}

static inline int sprd_iommu_free_kaddr_with_id(struct device *dev,
			struct sprd_iommu_unmap_data *data, u32 channel_id)
{
	return -ENODEV;
}

static inline int sprd_iommu_free_kaddr_with_sg(struct device *dev,
			struct sg_table *sg, size_t iova_size)
{
	return -ENODEV;
}

static inline int sprd_iommu_unmap(struct device *dev,
			struct sprd_iommu_unmap_data *data)
{
	return -ENODEV;
}

static inline int sprd_iommu_unmap_orphaned(struct sg_table *sg, int id)
{
	return -ENODEV;
}

static inline int sprd_iommu_suspend(struct device *dev)
{
	return -ENODEV;
}

static inline int sprd_iommu_resume(struct device *dev)
{
	return -ENODEV;
}

static inline int sprd_iommu_restore(struct device *dev)
{
	return -ENODEV;
}

static inline int sprd_iommu_open(struct device *dev)
{
	return -ENODEV;
}

static inline int sprd_iommu_release(struct device *dev)
{
	return -ENODEV;
}

#endif

struct sprd_iommu_ops {
	int (*init)(struct sprd_iommu_dev *dev, struct sprd_iommu_init_data *data);
	int (*exit)(struct sprd_iommu_dev *dev);
	unsigned long (*iova_alloc)(struct sprd_iommu_dev *dev, size_t iova_length, struct sprd_iommu_map_data *);
	void (*iova_free)(struct sprd_iommu_dev *dev, unsigned long iova, size_t iova_length);
	int (*iova_map)(struct sprd_iommu_dev *dev, unsigned long iova, size_t iova_length, struct sg_table *table, struct sprd_iommu_map_data *);
	int (*iova_unmap)(struct sprd_iommu_dev *dev, unsigned long iova, size_t iova_length);
	int (*backup)(struct sprd_iommu_dev *dev);
	int (*restore)(struct sprd_iommu_dev *dev);
	void (*enable)(struct sprd_iommu_dev *dev);
	void (*disable)(struct sprd_iommu_dev *dev);
	int (*dump)(struct sprd_iommu_dev *dev, void *data);
	void (*open)(struct sprd_iommu_dev *dev);
	void (*release)(struct sprd_iommu_dev *dev);
	void (*pgt_show)(struct sprd_iommu_dev *dev);
	int (*suspend)(struct sprd_iommu_dev *dev);
	int (*resume)(struct sprd_iommu_dev *dev);
	int (*iova_unmap_orphaned)(struct sprd_iommu_dev *dev, unsigned long iova, size_t iova_length);
};

enum IOMMU_ID {
	IOMMU_GSP = 0,
	IOMMU_MM,
	/*for whale iommu*/
	IOMMU_VSP,
	IOMMU_DCAM,
	IOMMU_DISPC,
	IOMMU_GSP0,
	IOMMU_GSP1,
	IOMMU_VPP,
	IOMMUPF_R1_DCAM,
	IOMMUPF_R2_DISPC,
	IOMMU_CPP_JPG,
	/*for iwhal2 iommu r4p0*/
	IOMMU_R4_VSP,
	IOMMU_R4_GSP,
	IOMMUPF_R2_DCAM,
	IOMMUPF_R2_CPP_JPG,
	/*for sharkl2 iommu*/
	IOMMU_EX_VSP,
	IOMMU_EX_DCAM,
	IOMMU_EX_CPP,
	IOMMU_EX_GSP,
	IOMMU_EX_JPG,
	IOMMU_EX_DISP,
	IOMMU_EX_ISP,
	/*for isharkl2 iommu*/
	IOMMU_EXI_VSP,
	IOMMU_EXI_DCAM,
	IOMMU_EXI_DCAM1,
	IOMMU_EXI_CPP,
	IOMMU_EXI_GSP,
	IOMMU_EXI_JPG,
	IOMMU_EXI_DISP,
	IOMMU_EXI_ISP,
	IOMMU_EXI_ISP1,
	/*for sharklj1*/
	IOMMU_EXJ1_VSP,
	IOMMU_EXJ1_DCAM,
	IOMMU_EXJ1_CPP,
	IOMMU_EXJ1_GSP,
	IOMMU_EXJ1_JPG,
	IOMMU_EXJ1_DISP,
	IOMMU_EXJ1_ISP,
	/*for sharkle*/
	IOMMU_EXLE_VSP,
	IOMMU_EXLE_DCAM,
	IOMMU_EXLE_CPP,
	IOMMU_EXLE_GSP,
	IOMMU_EXLE_JPG,
	IOMMU_EXLE_DISP,
	IOMMU_EXLE_ISP,
	/*for pike2*/
	IOMMU_EXPK2_VSP,
	IOMMU_EXPK2_DCAM,
	IOMMU_EXPK2_CPP,
	IOMMU_EXPK2_GSP,
	IOMMU_EXPK2_JPG,
	IOMMU_EXPK2_DISP,
	IOMMU_EXPK2_ISP,
	/*for sharkl3*/
	IOMMU_EXL3_VSP,
	IOMMU_EXL3_DCAM,
	IOMMU_EXL3_CPP,
	IOMMU_EXL3_JPG,
	IOMMU_EXL3_DISP,
	IOMMU_EXL3_ISP,
	IOMMU_MAX,
};
extern struct sprd_iommu_ops sprd_iommu_hw_ops;
extern struct sprd_iommu_ops sprd_iommupf_hw_ops;
extern struct sprd_iommu_ops sprd_iommuex_hw_ops;

#define IOMMU_TAG "[iommu]"

#define IOMMU_DEBUG(fmt, ...) \
	pr_debug(IOMMU_TAG  " %s()-" pr_fmt(fmt), __func__, ##__VA_ARGS__)

#define IOMMU_ERR(fmt, ...) \
	pr_err(IOMMU_TAG  " %s()-" pr_fmt(fmt), __func__, ##__VA_ARGS__)

#define IOMMU_INFO(fmt, ...) \
	pr_info(IOMMU_TAG  "%s()-" pr_fmt(fmt), __func__, ##__VA_ARGS__)

#define IOMMU_WARN(fmt, ...) \
	pr_warn(IOMMU_TAG  "%s()-" pr_fmt(fmt), __func__, ##__VA_ARGS__)


#endif
