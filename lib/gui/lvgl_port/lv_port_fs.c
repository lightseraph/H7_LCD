/**
 * @file lv_port_fs.c
 *
 */

/*Copy this file as "lv_port_fs.c" and set this value to "1" to enable content*/
#if 0

/*********************
 *      INCLUDES
 *********************/
#include "lv_port_fs.h"
#include "lvgl/lvgl.h"
#include "ff.h"
//#include "fatfs.h"

/*********************
 *      DEFINES
 *********************/

/**********************
 *      TYPEDEFS
 **********************/

/**********************
 *  STATIC PROTOTYPES
 **********************/
static FRESULT fs_init(void);

static void *fs_open(lv_fs_drv_t *drv, const char *path, lv_fs_mode_t mode);
static lv_fs_res_t fs_close(lv_fs_drv_t *drv, void *file_p);
static lv_fs_res_t fs_read(lv_fs_drv_t *drv, void *file_p, void *buf, uint32_t btr, uint32_t *br);
static lv_fs_res_t fs_write(lv_fs_drv_t *drv, void *file_p, const void *buf, uint32_t btw, uint32_t *bw);
static lv_fs_res_t fs_seek(lv_fs_drv_t *drv, void *file_p, uint32_t pos, lv_fs_whence_t whence);
// static lv_fs_res_t fs_size(lv_fs_drv_t *drv, void *file_p, uint32_t *size_p);
static lv_fs_res_t fs_tell(lv_fs_drv_t *drv, void *file_p, uint32_t *pos_p);

// static void *fs_dir_open(lv_fs_drv_t *drv, const char *path);
// static lv_fs_res_t fs_dir_read(lv_fs_drv_t *drv, void *rddir_p, char *fn);
// static lv_fs_res_t fs_dir_close(lv_fs_drv_t *drv, void *rddir_p);

// typedef FIL file_t;
// typedef DIR dir_t;

/**********************
 *  STATIC VARIABLES
 **********************/
/* char *path_buf = NULL;
    uint16_t path_len = strlen(path);

    path_buf = (char *)lv_mem_alloc(sizeof(char) * (path_len + 4));
    sprintf(path_buf, "S:/%s", path);
    */

/**********************
 * GLOBAL PROTOTYPES
 **********************/

/**********************
 *      MACROS
 **********************/

/**********************
 *   GLOBAL FUNCTIONS
 **********************/

void lv_port_fs_init(void)
{
    /*----------------------------------------------------
     * Initialize your storage device and File System
     * -------------------------------------------------*/
    fs_init();

    /*---------------------------------------------------
     * Register the file system interface in LVGL
     *--------------------------------------------------*/

    /*Add a simple drive to open images*/
    static lv_fs_drv_t fs_drv;
    lv_fs_drv_init(&fs_drv);

    /*Set up fields...*/
    fs_drv.letter = 'S';
    // fs_drv.cache_size = 40960;
    fs_drv.open_cb = fs_open;
    fs_drv.close_cb = fs_close;
    fs_drv.read_cb = fs_read;
    fs_drv.write_cb = fs_write;
    fs_drv.seek_cb = fs_seek;
    fs_drv.tell_cb = fs_tell;

    // fs_drv.dir_close_cb = fs_dir_close;
    // fs_drv.dir_open_cb = fs_dir_open;
    // fs_drv.dir_read_cb = fs_dir_read;

    lv_fs_drv_register(&fs_drv);
}

/**********************
 *   STATIC FUNCTIONS
 **********************/

/*Initialize your Storage device and File system.*/
static FRESULT fs_init(void)
{
    /*E.g. for FatFS initialize the SD card and FatFS itself*/

    /*You code here*/
    FATFS *flash_fs;
    FRESULT res = FR_OK;
    flash_fs = (FATFS *)lv_mem_alloc(sizeof(FATFS));
    res = f_mount(flash_fs, "0:", 1);
    printf("lvgl init status:%d\n", res);
    // lv_mem_free(flash_fs);
    return res;
}

/**
 * Open a file
 * @param drv       pointer to a driver where this function belongs
 * @param path      path to the file beginning with the driver letter (e.g. S:/folder/file.txt)
 * @param mode      read: FS_MODE_RD, write: FS_MODE_WR, both: FS_MODE_RD | FS_MODE_WR
 * @return          a file descriptor or NULL on error
 */
static void *fs_open(lv_fs_drv_t *drv, const char *path, lv_fs_mode_t mode)
{
    // lv_fs_res_t res = LV_FS_RES_NOT_IMP;
    LV_UNUSED(drv);
    FIL *f = lv_mem_alloc(sizeof(FIL));
    if (f == NULL)
        return NULL;
    FRESULT res = FR_OK;

    if (mode == LV_FS_MODE_WR)
    {
        res = f_open(f, path, FA_WRITE);
    }
    else if (mode == LV_FS_MODE_RD)
    {
        res = f_open(f, path, FA_READ);
    }
    else if (mode == (LV_FS_MODE_WR | LV_FS_MODE_RD))
    {
        res = f_open(f, path, FA_WRITE | FA_READ);
    }
    if (res == FR_OK)
    {
        printf("file open success\n");
        return f;
    }
    else
    {
        printf("file open failure\n");
        lv_mem_free(f);
        return NULL;
    }
}

/**
 * Close an opened file
 * @param drv       pointer to a driver where this function belongs
 * @param file_p    pointer to a file_t variable. (opened with fs_open)
 * @return          LV_FS_RES_OK: no error or  any error from @lv_fs_res_t enum
 */
static lv_fs_res_t fs_close(lv_fs_drv_t *drv, void *file_p)
{
    lv_fs_res_t res = LV_FS_RES_NOT_IMP;
    LV_UNUSED(drv);
    if (f_close((FIL *)file_p) == FR_OK)
    {
        res = LV_FS_RES_OK;
    }
    else
    {
        res = LV_FS_RES_FS_ERR;
    }

    return res;
}

/**
 * Read data from an opened file
 * @param drv       pointer to a driver where this function belongs
 * @param file_p    pointer to a file_t variable.
 * @param buf       pointer to a memory block where to store the read data
 * @param btr       number of Bytes To Read
 * @param br        the real number of read bytes (Byte Read)
 * @return          LV_FS_RES_OK: no error or  any error from @lv_fs_res_t enum
 */
static lv_fs_res_t fs_read(lv_fs_drv_t *drv, void *file_p, void *buf, uint32_t btr, uint32_t *br)
{
    lv_fs_res_t res = LV_FS_RES_NOT_IMP;
    LV_UNUSED(drv);

    FRESULT fres = f_read((FIL *)file_p, buf, (UINT)btr, (UINT *)br);
    if (fres != FR_OK)
    {
        printf("f_read error (%d)\n", fres);
        return res;
    }
    else
    {
        printf("f_read success. read(%ld bytes).\n", *br);
        return LV_FS_RES_OK;
    }
}

/**
 * Write into a file
 * @param drv       pointer to a driver where this function belongs
 * @param file_p    pointer to a file_t variable
 * @param buf       pointer to a buffer with the bytes to write
 * @param btr       Bytes To Write
 * @param br        the number of real written bytes (Bytes Written). NULL if unused.
 * @return          LV_FS_RES_OK: no error or  any error from @lv_fs_res_t enum
 */
static lv_fs_res_t fs_write(lv_fs_drv_t *drv, void *file_p, const void *buf, uint32_t btw, uint32_t *bw)
{
    LV_UNUSED(drv);
    lv_fs_res_t res = LV_FS_RES_NOT_IMP;

    /*Add your code here*/
    FRESULT fres = f_write((FIL *)file_p, buf, (UINT)btw, (UINT *)bw);
    if (fres == FR_OK)
        return LV_FS_RES_OK;
    else
        return res;
}

/**
 * Set the read write pointer. Also expand the file size if necessary.
 * @param drv       pointer to a driver where this function belongs
 * @param file_p    pointer to a file_t variable. (opened with fs_open )
 * @param pos       the new position of read write pointer
 * @param whence    tells from where to interpret the `pos`. See @lv_fs_whence_t
 * @return          LV_FS_RES_OK: no error or  any error from @lv_fs_res_t enum
 */
static lv_fs_res_t fs_seek(lv_fs_drv_t *drv, void *file_p, uint32_t pos, lv_fs_whence_t whence)
{
    /* LV_UNUSED(drv);
    lv_fs_res_t res = LV_FS_RES_NOT_IMP;


    FRESULT fres = f_lseek((FIL *)file_p, (FSIZE_t)pos);
    if (fres == FR_OK)
        return LV_FS_RES_OK;
    else
        return res;
    */

    LV_UNUSED(drv);
    printf("Seek Mode: %d. Seek pos: %ld\n\n", whence, pos);

    switch (whence)
    {
    case LV_FS_SEEK_SET:
        f_lseek(file_p, pos);
        break;
    case LV_FS_SEEK_CUR:
        f_lseek(file_p, f_tell((FIL *)file_p) + pos);
        break;
    case LV_FS_SEEK_END:
        f_lseek(file_p, f_size((FIL *)file_p) + pos);
        break;
    default:
        break;
    }
    return LV_FS_RES_OK;
}
/**
 * Give the position of the read write pointer
 * @param drv       pointer to a driver where this function belongs
 * @param file_p    pointer to a file_t variable.
 * @param pos_p     pointer to to store the result
 * @return          LV_FS_RES_OK: no error or  any error from @lv_fs_res_t enum
 */
static lv_fs_res_t fs_tell(lv_fs_drv_t *drv, void *file_p, uint32_t *pos_p)
{
    LV_UNUSED(drv);
    *pos_p = f_tell((FIL *)file_p);
    printf("tell pos: %ld\n", *pos_p);
    return LV_FS_RES_OK;
}

/**
 * Initialize a 'lv_fs_dir_t' variable for directory reading
 * @param drv       pointer to a driver where this function belongs
 * @param path      path to a directory
 * @return          pointer to the directory read descriptor or NULL on error
 */
/* static void *fs_dir_open(lv_fs_drv_t *drv, const char *path)
{
    void *dir = NULL;

    dir = ... return dir;
}
 */
/**
 * Read the next filename form a directory.
 * The name of the directories will begin with '/'
 * @param drv       pointer to a driver where this function belongs
 * @param rddir_p   pointer to an initialized 'lv_fs_dir_t' variable
 * @param fn        pointer to a buffer to store the filename
 * @return          LV_FS_RES_OK: no error or  any error from @lv_fs_res_t enum
 */
/* static lv_fs_res_t fs_dir_read(lv_fs_drv_t *drv, void *rddir_p, char *fn)
{
    lv_fs_res_t res = LV_FS_RES_NOT_IMP;

    return res;
} */

/**
 * Close the directory reading
 * @param drv       pointer to a driver where this function belongs
 * @param rddir_p   pointer to an initialized 'lv_fs_dir_t' variable
 * @return          LV_FS_RES_OK: no error or  any error from @lv_fs_res_t enum
 */
/* static lv_fs_res_t fs_dir_close(lv_fs_drv_t *drv, void *rddir_p)
{
    lv_fs_res_t res = LV_FS_RES_NOT_IMP;

    return res;
} */

#else /*Enable this file at the top*/

/*This dummy typedef exists purely to silence -Wpedantic.*/
typedef int keep_pedantic_happy;
#endif
