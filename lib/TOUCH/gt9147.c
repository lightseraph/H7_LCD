#include "gt9147.h"
#include "touch.h"
#include "ctiic.h"
//#include "usart.h"
#include "tim.h"
#include "string.h"
#include "ltdc.h"
//////////////////////////////////////////////////////////////////////////////////
//本程序只供学习使用，未经作者许可，不得用于其它任何用途
// ALIENTEK STM32F407开发板
// 4.3寸电容触摸屏-GT9147 驱动代码
//正点原子@ALIENTEK
//技术论坛:www.openedv.com
//创建日期:2014/5/7
//版本：V1.0
//版权所有，盗版必究。
// Copyright(C) 广州市星翼电子科技有限公司 2014-2024
// All rights reserved
//////////////////////////////////////////////////////////////////////////////////

// GT9147配置参数表
//第一个字节为版本号(0X60),必须保证新的版本号大于等于GT9147内部
// flash原有版本号,才会更新配置.
// 修改了参数表下面是GT911的，与GT9147不兼容，会导致触摸坐标不准
const u8 GT9147_CFG_TBL[] =
	{
		0X61,
		0xE0,
		0x01,
		0x20,
		0x03,
		0x05,
		0x04,
		0x10,
		0x01,
		0xC8,
		0x28,
		0x0F,
		0x50,
		0x32,
		0x03,
		0x05,
		0x00,
		0x00,
		0x00,
		0x00,
		0x11,
		0x11,
		0x05,
		0x18,
		0x1A,
		0x1E,
		0x14,
		0x88,
		0x29,
		0x0A,
		0x52,
		0x50,
		0x40,
		0x04,
		0x00,
		0x00,
		0x00,
		0x1A,
		0x32,
		0x1C,
		0x46,
		0x09,
		0x00,
		0x0F,
		0x00,
		0x2A,
		0xFF,
		0x7F,
		0x19,
		0x50,
		0x32,
		0x3C,
		0x64,
		0x94,
		0xD5,
		0x02,
		0x07,
		0x00,
		0x00,
		0x04,
		0x9F,
		0x3F,
		0x00,
		0x90,
		0x46,
		0x00,
		0x84,
		0x4D,
		0x00,
		0x79,
		0x55,
		0x00,
		0x6D,
		0x5F,
		0x00,
		0x6D,
		0x00,
		0x00,
		0x00,
		0x00,
		0xF0,
		0x4A,
		0x3A,
		0xFF,
		0xFF,
		0x27,
		0x00,
		0x00,
		0x00,
		0x00,
		0x00,
		0x00,
		0x00,
		0x00,
		0x00,
		0x00,
		0x00,
		0x00,
		0x00,
		0x00,
		0x00,
		0x00,
		0x00,
		0x00,
		0x00,
		0x00,
		0x00,
		0x00,
		0x00,
		0x00,
		0x00,
		0x00,
		0x14,
		0x12,
		0x10,
		0x0E,
		0x0C,
		0x0A,
		0x08,
		0x06,
		0x04,
		0x02,
		0xFF,
		0xFF,
		0xFF,
		0xFF,
		0xFF,
		0xFF,
		0xFF,
		0xFF,
		0xFF,
		0xFF,
		0xFF,
		0xFF,
		0xFF,
		0xFF,
		0xFF,
		0xFF,
		0xFF,
		0xFF,
		0xFF,
		0xFF,
		0x22,
		0x21,
		0x20,
		0x1F,
		0x1E,
		0x1D,
		0x1C,
		0x18,
		0x16,
		0x12,
		0x10,
		0x0F,
		0x08,
		0x06,
		0x04,
		0x02,
		0x00,
		0xFF,
		0xFF,
		0xFF,
		0xFF,
		0xFF,
		0xFF,
		0xFF,
		0xFF,
		0xFF,
		0xFF,
		0xFF,
		0xFF,
		0xFF,
		0xFF,
		0xFF,
		0xFF,
		0xFF,
		0xFF,
		0xFF,
		0xFF,
		0xFF,
		0xFF,
		0xFF,
		0xFF,
		0xFF,
};
//发送GT9147配置参数
// mode:0,参数不保存到flash
//     1,参数保存到flash
u8 GT9147_Send_Cfg(u8 mode)
{
	u8 buf[2];
	u8 i = 0;
	buf[0] = 0;
	buf[1] = mode; //是否写入到GT9147 FLASH?  即是否掉电保存
	for (i = 0; i < sizeof(GT9147_CFG_TBL); i++)
		buf[0] += GT9147_CFG_TBL[i]; //计算校验和
	buf[0] = (~buf[0]) + 1;
	GT9147_WR_Reg(GT_CFGS_REG, (u8 *)GT9147_CFG_TBL, sizeof(GT9147_CFG_TBL)); //发送寄存器配置
	GT9147_WR_Reg(GT_CHECK_REG, buf, 2);									  //写入校验和,和配置更新标记
	return 0;
}
//向GT9147写入一次数据
// reg:起始寄存器地址
// buf:数据缓缓存区
// len:写数据长度
//返回值:0,成功;1,失败.
u8 GT9147_WR_Reg(u16 reg, u8 *buf, u8 len)
{
	u8 i;
	u8 ret = 0;
	CT_IIC_Start();
	CT_IIC_Send_Byte(GT_CMD_WR); //发送写命令
	CT_IIC_Wait_Ack();
	CT_IIC_Send_Byte(reg >> 8); //发送高8位地址
	CT_IIC_Wait_Ack();
	CT_IIC_Send_Byte(reg & 0XFF); //发送低8位地址
	CT_IIC_Wait_Ack();
	for (i = 0; i < len; i++)
	{
		CT_IIC_Send_Byte(buf[i]); //发数据
		ret = CT_IIC_Wait_Ack();
		if (ret)
			break;
	}
	CT_IIC_Stop(); //产生一个停止条件
	return ret;
}
//从GT9147读出一次数据
// reg:起始寄存器地址
// buf:数据缓缓存区
// len:读数据长度
void GT9147_RD_Reg(u16 reg, u8 *buf, u8 len)
{
	u8 i;
	CT_IIC_Start();
	CT_IIC_Send_Byte(GT_CMD_WR); //发送写命令
	CT_IIC_Wait_Ack();
	CT_IIC_Send_Byte(reg >> 8); //发送高8位地址
	CT_IIC_Wait_Ack();
	CT_IIC_Send_Byte(reg & 0XFF); //发送低8位地址
	CT_IIC_Wait_Ack();
	CT_IIC_Start();
	CT_IIC_Send_Byte(GT_CMD_RD); //发送读命令
	CT_IIC_Wait_Ack();
	for (i = 0; i < len; i++)
	{
		buf[i] = CT_IIC_Read_Byte(i == (len - 1) ? 0 : 1); //发数据
	}
	CT_IIC_Stop(); //产生一个停止条件
}
//初始化GT9147触摸屏
//返回值:0,初始化成功;1,初始化失败
u8 GT9147_Init(void)
{
	u8 temp[5];
	GPIO_InitTypeDef GPIO_InitStruct;

	CT_IIC_Init(); //初始化电容屏的I2C总线
	GT_RST(0);	   //复位
	HAL_Delay(10);
	GT_RST(1); //释放复位
	HAL_Delay(10);

	GPIO_InitStruct.Pin = CT_INT_Pin;
	GPIO_InitStruct.Mode = GPIO_MODE_INPUT;
	GPIO_InitStruct.Pull = GPIO_NOPULL;
	GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_VERY_HIGH;
	HAL_GPIO_Init(CT_INT_GPIO_Port, &GPIO_InitStruct);

	HAL_Delay(100);
	GT9147_RD_Reg(GT_PID_REG, temp, 4); //读取产品ID
	temp[4] = 0;
	printf("CTP ID:%s\r\n", temp);		   //打印ID
	if (strcmp((char *)temp, "1158") == 0) // ID==9147; GT1151读出的ID是1158
	{
		temp[0] = 0X02;
		GT9147_WR_Reg(GT_CTRL_REG, temp, 1); //软复位GT9147
		/* GT9147_RD_Reg(GT_CFGS_REG, temp, 1); //读取GT_CFGS_REG寄存器
		if (temp[0] < 0X61)					 //默认版本比较低,需要更新flash配置
		{
			// printf("Default Ver:%d\r\n", temp[0]);
			GT9147_Send_Cfg(1); //更新并保存配置
		} */
		HAL_Delay(10);
		temp[0] = 0X00;
		GT9147_WR_Reg(GT_CTRL_REG, temp, 1); //结束复位
		return 0;
	}
	return 0;
}
const u16 GT9147_TPX_TBL[5] = {GT_TP1_REG, GT_TP2_REG, GT_TP3_REG, GT_TP4_REG, GT_TP5_REG};
//扫描触摸屏(采用查询方式)
// mode:0,正常扫描.
//返回值:当前触屏状态.
// 0,触屏无触摸;1,触屏有触摸
u8 GT9147_Scan(u8 mode)
{
	u8 buf[4];
	u8 i = 0;
	u8 res = 0;
	u8 temp;
	u8 tempsta;
	static u8 t = 0; //控制查询间隔,从而降低CPU占用率
	t++;
	if ((t % 10) == 0 || t < 10) //空闲时,每进入10次CTP_Scan函数才检测1次,从而节省CPU使用率
	{
		GT9147_RD_Reg(GT_GSTID_REG, &mode, 1); //读取触摸点的状态
		temp = 0;
		GT9147_WR_Reg(GT_GSTID_REG, &temp, 1); //清标志
		if ((mode & 0XF) && ((mode & 0XF) < 6))
		{
			temp = 0XFF << (mode & 0XF); //将点的个数转换为1的位数,匹配tp_dev.sta定义
			tempsta = tp_dev.sta;		 //保存当前的tp_dev.sta值
			tp_dev.sta = (~temp) | TP_PRES_DOWN | TP_CATH_PRES;
			tp_dev.x[4] = tp_dev.x[0]; //保存触点0的数据
			tp_dev.y[4] = tp_dev.y[0];
			for (i = 0; i < 5; i++)
			{
				if (tp_dev.sta & (1 << i)) //触摸有效?
				{
					GT9147_RD_Reg(GT9147_TPX_TBL[i], buf, 4); //读取XY坐标值
					if (tp_dev.touchtype & 0X01)			  //横屏
					{
						tp_dev.x[i] = (((u16)buf[1] << 8) + buf[0]);
						tp_dev.y[i] = (((u16)buf[3] << 8) + buf[2]);
					}
					else
					{
						tp_dev.y[i] = ((u16)buf[1] << 8) + buf[0];
						tp_dev.x[i] = 480 - (((u16)buf[3] << 8) + buf[2]);
					}
					// printf("x[%d]:%d,y[%d]:%d\r\n",i,tp_dev.x[i],i,tp_dev.y[i]);
				}
			}
			res = 1;
			if (tp_dev.x[0] > lcdltdc.width || tp_dev.y[0] > lcdltdc.height) //非法数据(坐标超出了)
			{
				if ((mode & 0XF) > 1) //有其他点有数据,则复第二个触点的数据到第一个触点.
				{
					tp_dev.x[0] = tp_dev.x[1];
					tp_dev.y[0] = tp_dev.y[1];
					t = 0; //触发一次,则会最少连续监测10次,从而提高命中率
				}
				else //非法数据,则忽略此次数据(还原原来的)
				{
					tp_dev.x[0] = tp_dev.x[4];
					tp_dev.y[0] = tp_dev.y[4];
					mode = 0X80;
					tp_dev.sta = tempsta; //恢复tp_dev.sta
				}
			}
			else
				t = 0; //触发一次,则会最少连续监测10次,从而提高命中率
		}
	}
	if ((mode & 0X8F) == 0X80) //无触摸点按下
	{
		if (tp_dev.sta & TP_PRES_DOWN) //之前是被按下的
		{
			tp_dev.sta &= ~(1 << 7); //标记按键松开
		}
		tp_dev.x[0] = 0xffff;
		tp_dev.y[0] = 0xffff;
		tp_dev.sta &= 0XE0; //清除点有效标记
	}
	if (t > 240)
		t = 10; //重新从10开始计数
	return res;
}
