#include "iic.h"

#ifdef IIC_CONFIG


/*******************************************************************************
* 函数名         : Delay10us()
* 函数功能		   : 延时10us
* 输入           : 无
* 输出         	 : 无
*******************************************************************************/

static void Delay10us()
{
	unsigned char a,b;
	for(b=1;b>0;b--)
		for(a=2;a>0;a--);

}
/*******************************************************************************
* 函数名         : I2cStart()
* 函数功能		 : 起始信号：在IIC_SCL时钟信号在高电平期间IIC_SDA信号产生一个下降沿
* 输入           : 无
* 输出         	 : 无
* 备注           : 起始之后IIC_SDA和IIC_SCL都为0
*******************************************************************************/

void I2cStart()
{
	IIC_SDA=1;
	Delay10us();
	IIC_SCL=1;
	Delay10us();//建立时间是IIC_SDA保持时间>4.7us
	IIC_SDA=0;
	Delay10us();//保持时间是>4us
	IIC_SCL=0;			
	Delay10us();		
}
/*******************************************************************************
* 函数名         : I2cStop()
* 函数功能		 : 终止信号：在IIC_SCL时钟信号高电平期间IIC_SDA信号产生一个上升沿
* 输入           : 无
* 输出         	 : 无
* 备注           : 结束之后保持IIC_SDA和IIC_SCL都为1；表示总线空闲
*******************************************************************************/

void I2cStop()
{
	IIC_SDA=0;
	Delay10us();
	IIC_SCL=1;
	Delay10us();//建立时间大于4.7us
	IIC_SDA=1;
	Delay10us();
}
/*******************************************************************************
* 函数名         : I2cSendByte(unsigned char dat)
* 函数功能		 : 通过I2C发送一个字节。在IIC_SCL时钟信号高电平期间，保持发送信号IIC_SDA保持稳定
* 输入           : num
* 输出         	 : 0或1。发送成功返回1，发送失败返回0
* 备注           : 发送完一个字节IIC_SCL=0,IIC_SDA=1
*******************************************************************************/

unsigned char I2cSendByte(unsigned char dat)
{
	unsigned char a=0,b=0;//最大255，一个机器周期为1us，最大延时255us。		
	for(a=0;a<8;a++)//要发送8位，从最高位开始
	{
		IIC_SDA=dat>>7;	 //起始信号之后IIC_SCL=0，所以可以直接改变IIC_SDA信号
		dat=dat<<1;
		Delay10us();
		IIC_SCL=1;
		Delay10us();//建立时间>4.7us
		IIC_SCL=0;
		Delay10us();//时间大于4us		
	}
	IIC_SDA=1;
	Delay10us();
	IIC_SCL=1;
	while(IIC_SDA)//等待应答，也就是等待从设备把IIC_SDA拉低
	{
		b++;
		if(b>200)	 //如果超过2000us没有应答发送失败，或者为非应答，表示接收结束
		{
			IIC_SCL=0;
			Delay10us();
			return 0;
		}
	}
	IIC_SCL=0;
	Delay10us();
 	return 1;		
}
/*******************************************************************************
* 函数名         : I2cReadByte()
* 函数功能		   : 使用I2c读取一个字节
* 输入           : 无
* 输出         	 : dat
* 备注           : 接收完一个字节IIC_SCL=0,IIC_SDA=1.
*******************************************************************************/

unsigned char I2cReadByte()
{
	unsigned char a=0,dat=0;
	IIC_SDA=1;			//起始和发送一个字节之后IIC_SCL都是0
	Delay10us();
	for(a=0;a<8;a++)//接收8个字节
	{
		IIC_SCL=1;
		Delay10us();
		dat<<=1;
		dat|=IIC_SDA;
		Delay10us();
		IIC_SCL=0;
		Delay10us();
	}
	return dat;		
}



#endif /* IIC_CONFIG */