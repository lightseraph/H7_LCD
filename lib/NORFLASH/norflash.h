#ifndef __NORFLASH_H
#define __NORFLASH_H
#include "sys.h"
//////////////////////////////////////////////////////////////////////////////////
//本程序只供学习使用，未经作者许可，不得用于其它任何用途
// ALIENTEK STM32H7开发板
// NOR FLASH(W25QXX) QPI模式驱动代码
//正点原子@ALIENTEK
//技术论坛:www.openedv.com
//创建日期:2019/5/4
//版本：V1.0
//版权所有，盗版必究。
// Copyright(C) 广州市星翼电子科技有限公司 2014-2024
// All rights reserved
//////////////////////////////////////////////////////////////////////////////////

// W25X系列/Q系列芯片列表
// W25Q80  ID  0XEF13
// W25Q16  ID  0XEF14
// W25Q32  ID  0XEF15
// W25Q64  ID  0XEF16
// W25Q128 ID  0XEF17
// W25Q256 ID  0XEF18
#define W25Q80 0XEF13
#define W25Q16 0XEF14
#define W25Q32 0XEF15
#define W25Q64 0XEF16
#define W25Q128 0XEF17
#define W25Q256 0XEF18

extern u16 NORFLASH_TYPE; //定义W25QXX芯片型号

//////////////////////////////////////////////////////////////////////////////////
//指令表
#define W25X_WriteEnable 0x06
#define W25X_WriteDisable 0x04
#define W25X_ReadStatusReg1 0x05
#define W25X_ReadStatusReg2 0x35
#define W25X_ReadStatusReg3 0x15
#define W25X_WriteStatusReg1 0x01
#define W25X_WriteStatusReg2 0x31
#define W25X_WriteStatusReg3 0x11
#define W25X_ReadData 0x03
#define W25X_FastReadData 0x0B
#define W25X_FastReadDual 0x3B
#define W25X_PageProgram 0x02
#define W25X_BlockErase 0xD8
#define W25X_SectorErase 0x20
#define W25X_ChipErase 0xC7
#define W25X_PowerDown 0xB9
#define W25X_ReleasePowerDown 0xAB
#define W25X_DeviceID 0xAB
#define W25X_ManufactDeviceID 0x90
#define W25X_JedecDeviceID 0x9F
#define W25X_Enable4ByteAddr 0xB7
#define W25X_Exit4ByteAddr 0xE9
#define W25X_SetReadParam 0xC0
#define W25X_EnterQPIMode 0x38
#define W25X_ExitQPIMode 0xFF

//////////////////////////////////////////////////////////////////////////////////////////
#define QSPI_W25Qxx_OK 0             // W25Qxx通信正常
#define W25Qxx_ERROR_INIT -1         // 初始化错�?
#define W25Qxx_ERROR_WriteEnable -2  // 写使能错�?
#define W25Qxx_ERROR_AUTOPOLLING -3  // 轮询等待错误，无响应
#define W25Qxx_ERROR_Erase -4        // 擦除错误
#define W25Qxx_ERROR_TRANSMIT -5     // 传输错误
#define W25Qxx_ERROR_MemoryMapped -6 // 内存映射模式错误

#define W25Qxx_CMD_EnableReset 0x66 // 使能复位
#define W25Qxx_CMD_ResetDevice 0x99 // 复位器件
#define W25Qxx_CMD_JedecID 0x9F     // JEDEC ID
#define W25Qxx_CMD_WriteEnable 0X06 // 写使�?

#define W25Qxx_CMD_SectorErase 0x20    // 扇区擦除�?4K字节�? 参�?�擦除时�? 45ms
#define W25Qxx_CMD_BlockErase_32K 0x52 // 块擦除，  32K字节，参考擦除时�? 120ms
#define W25Qxx_CMD_BlockErase_64K 0xD8 // 块擦除，  64K字节，参考擦除时�? 150ms
#define W25Qxx_CMD_ChipErase 0xC7      // 整片擦除，参考擦除时�? 20S

#define W25Qxx_CMD_QuadInputPageProgram 0x32 // 1-1-4模式�?(1线指�?1线地�?4线数�?)，页编程指令，参考写入时�? 0.4ms
#define W25Qxx_CMD_FastReadQuad_IO 0xEB      // 1-4-4模式�?(1线指�?4线地�?4线数�?)，快速读取指�?

#define W25Qxx_CMD_ReadStatus_REG1 0X05 // 读状态寄存器1
#define W25Qxx_Status_REG1_BUSY 0x01    // 读状态寄存器1的第0位（只读），Busy标志位，当正在擦�?/写入数据/写命令时会被�?1
#define W25Qxx_Status_REG1_WEL 0x02     // 读状态寄存器1的第1位（只读），WEL写使能标志位，该标志位为1时，代表可以进行写操�?

#define W25Qxx_PageSize 256                  // 页大小，256字节
#define W25Qxx_FlashSize 0x800000            // W25Q64大小�?8M字节
#define W25Qxx_FLASH_ID 0Xef4017             // W25Q64 JEDEC ID
#define W25Qxx_ChipErase_TIMEOUT_MAX 100000U // 超时等待时间，W25Q64整片擦除�?�?�?大时间是100S
#define W25Qxx_Mem_Addr 0x90000000           // 内存映射模式的地�?

void NORFLASH_Init(void);                                                    //初始化W25QXX
void NORFLASH_Qspi_Enable(void);                                             //使能QSPI模式
void NORFLASH_Qspi_Disable(void);                                            //关闭QSPI模式
u16 NORFLASH_ReadID(void);                                                   //读取FLASH ID
u8 NORFLASH_ReadSR(u8 regno);                                                //读取状态寄存器
void NORFLASH_4ByteAddr_Enable(void);                                        //使能4字节地址模式
void NORFLASH_Write_SR(u8 regno, u8 sr);                                     //写状态寄存器
void NORFLASH_Write_Enable(void);                                            //写使能
void NORFLASH_Write_Disable(void);                                           //写保护
void NORFLASH_Write_NoCheck(u8 *pBuffer, u32 WriteAddr, u16 NumByteToWrite); //写flash,不校验
void NORFLASH_Read(u8 *pBuffer, u32 ReadAddr, u16 NumByteToRead);            //读取flash
void NORFLASH_Write(u8 *pBuffer, u32 WriteAddr, u16 NumByteToWrite);         //写入flash
void NORFLASH_Erase_Chip(void);                                              //整片擦除
void NORFLASH_Erase_Sector(u32 Dst_Addr);                                    //扇区擦除
void NORFLASH_Wait_Busy(void);                                               //等待空闲
void QSPI_Send_CMD(u8 cmd, u32 addr, u8 mode, u8 dmcycle);                   // QSPI发送命令
u8 QSPI_Receive(u8 *buf, u32 datalen);                                       // QSPI接收数据
u8 QSPI_Transmit(u8 *buf, u32 datalen);                                      // QSPI发送数据
int8_t NORFLASH_MemoryMappedMode(void);                                      // 将QSPI设置为内存映射模式
int8_t NORFLASH_AutoPollingMemReady(void);                                   // 使用自动轮询标志查询
int8_t NORFLASH_Reset(void);                                                 // 复位器件
#endif
