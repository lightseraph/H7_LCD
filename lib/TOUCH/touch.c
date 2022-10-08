#include "touch.h"
#include "lcd.h"
#include "tim.h"
#include "stdlib.h"
#include "math.h"
//#include "24cxx.h"
//////////////////////////////////////////////////////////////////////////////////
//鏈▼搴忓彧渚涘涔犱娇鐢紝鏈粡浣滆€呰鍙紝涓嶅緱鐢ㄤ簬鍏跺畠浠讳綍鐢ㄩ€�
// ALIENTEK STM32F407寮€鍙戞澘
//瑙︽懜灞忛┍鍔紙鏀寔ADS7843/7846/UH7843/7846/XPT2046/TSC2046/OTT2001A绛夛級 浠ｇ爜
//姝ｇ偣鍘熷瓙@ALIENTEK
//鎶€鏈鍧�:www.openedv.com
//鍒涘缓鏃ユ湡:2014/5/7
//鐗堟湰锛歏1.2
//鐗堟潈鎵€鏈夛紝鐩楃増蹇呯┒銆�
// Copyright(C) 骞垮窞甯傛槦缈肩數瀛愮鎶€鏈夐檺鍏徃 2014-2024
// All rights reserved
//********************************************************************************
//淇敼璇存槑
// V1.1 20140721
//淇MDK鍦�-O2浼樺寲鏃�,瑙︽懜灞忔暟鎹棤娉曡鍙栫殑bug.鍦═P_Write_Byte鍑芥暟娣诲姞涓€涓欢鏃�,瑙ｅ喅闂.
// V1.2 20141130
//鐢靛瑙︽懜灞忓鍔燜T5206鐨勬敮鎸�
//////////////////////////////////////////////////////////////////////////////////

_m_tp_dev tp_dev =
	{
		TP_Init,
		TP_Scan,
		0,
		0,
		0,
		0,
		0,
		0,
		0,
		0,
		0,
};
//榛樿涓簍ouchtype=0鐨勬暟鎹�.
u8 CMD_RDX = 0XD0;
u8 CMD_RDY = 0X90;

//////////////////////////////////////////////////////////////////////////////////
//瑙︽懜鎸夐敭鎵弿
// tp:0,灞忓箷鍧愭爣;1,鐗╃悊鍧愭爣(鏍″噯绛夌壒娈婂満鍚堢敤)
//杩斿洖鍊�:褰撳墠瑙﹀睆鐘舵€�.
// 0,瑙﹀睆鏃犺Е鎽�;1,瑙﹀睆鏈夎Е鎽�
u8 TP_Scan(u8 tp)
{

	return tp_dev.sta & TP_PRES_DOWN; //杩斿洖褰撳墠鐨勮Е灞忕姸鎬�
}

//瑙︽懜灞忓垵濮嬪寲
//杩斿洖鍊�:0,娌℃湁杩涜鏍″噯
//       1,杩涜杩囨牎鍑�
u8 TP_Init(void)
{
	// GPIO_InitTypeDef GPIO_Initure;

	if (lcddev.id == 0X5510) //鐢靛瑙︽懜灞�
	{
		if (GT9147_Init() == 0) //鏄疓T9147
		{
			tp_dev.scan = GT9147_Scan; //鎵弿鍑芥暟鎸囧悜GT9147瑙︽懜灞忔壂鎻�
		}
		else
		{
			// OTT2001A_Init();
			// tp_dev.scan = OTT2001A_Scan; //鎵弿鍑芥暟鎸囧悜OTT2001A瑙︽懜灞忔壂鎻�
		}
		tp_dev.touchtype |= 0X80;			   //鐢靛灞�
		tp_dev.touchtype |= lcddev.dir & 0X01; //妯睆杩樻槸绔栧睆
		return 0;
	}
	else if (lcddev.id == 0X1963)
	{
		// FT5206_Init();
		// tp_dev.scan = FT5206_Scan;			   //鎵弿鍑芥暟鎸囧悜GT9147瑙︽懜灞忔壂鎻�
		tp_dev.touchtype |= 0X80;			   //鐢靛灞�
		tp_dev.touchtype |= lcddev.dir & 0X01; //妯睆杩樻槸绔栧睆
		return 0;
	}
	else
	{
		/* RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOB, ENABLE); //浣胯兘GPIOB鏃堕挓
		RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOC, ENABLE); //浣胯兘GPIOC鏃堕挓
		RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOF, ENABLE); //浣胯兘GPIOF鏃堕挓

		// GPIOB1,2鍒濆鍖栬缃�
		GPIO_Initure.GPIO_Pin = GPIO_Pin_1 | GPIO_Pin_2; // PB1/PB2 璁剧疆涓轰笂鎷夎緭鍏�
		GPIO_Initure.GPIO_Mode = GPIO_Mode_IN;			 //杈撳叆
		GPIO_Initure.GPIO_PuPd = GPIO_PuPd_UP;			 //涓婃媺
		GPIO_Initure.GPIO_Speed = GPIO_High_Speed;		 //楂橀€�
		GPIO_Init(GPIOB, &GPIO_Initure);				 //鍒濆鍖�

		// PB0
		GPIO_Initure.GPIO_Pin = GPIO_Pin_0;		 // PB0璁剧疆涓烘帹鎸借緭鍑�
		GPIO_Initure.GPIO_Mode = GPIO_Mode_OUT;	 //杈撳嚭
		GPIO_Initure.GPIO_OType = GPIO_OType_PP; //鎺ㄦ尳
		GPIO_Init(GPIOB, &GPIO_Initure);		 //鍒濆鍖�

		// PC13
		GPIO_Initure.GPIO_Pin = GPIO_Pin_13; // PC13璁剧疆涓烘帹鎸借緭鍑�
		GPIO_Init(GPIOC, &GPIO_Initure);	 //鍒濆鍖�

		// PF11
		GPIO_Initure.GPIO_Pin = GPIO_Pin_11; // PF11璁剧疆鎺ㄦ尳杈撳嚭
		GPIO_Init(GPIOF, &GPIO_Initure);	 //鍒濆鍖� */

		/* TP_Read_XY(&tp_dev.x[0], &tp_dev.y[0]); //绗竴娆¤鍙栧垵濮嬪寲
		AT24CXX_Init();							//鍒濆鍖�24CXX

		LCD_Clear(WHITE); //娓呭睆
		TP_Adjust();	  //灞忓箷鏍″噯
		TP_Save_Adjdata();
		TP_Get_Adjdata(); */
	}
	return 1;
}
