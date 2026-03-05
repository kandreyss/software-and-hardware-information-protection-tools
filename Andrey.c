#include "MDR32F9Qx_config.h"
#include "MDR32F9Qx_port.h"
#include "MDR32F9Qx_rst_clk.h"

#include <stdint.h>

void Delay(uint32_t nCount)
{
    while(nCount--)
    {
    }
}

int main(void)
{
    PORT_InitTypeDef PORT_InitStructure;

    RST_CLK_PCLKcmd(RST_CLK_PCLK_PORTC, ENABLE);
    RST_CLK_PCLKcmd(RST_CLK_PCLK_PORTD, ENABLE);

    PORT_InitStructure.PORT_Pin =
        PORT_Pin_10 | PORT_Pin_11 | PORT_Pin_12 |
        PORT_Pin_13 | PORT_Pin_14;

    PORT_InitStructure.PORT_OE = PORT_OE_IN;
    PORT_InitStructure.PORT_FUNC = PORT_FUNC_PORT;
    PORT_InitStructure.PORT_MODE = PORT_MODE_DIGITAL;
    PORT_InitStructure.PORT_SPEED = PORT_SPEED_SLOW;

    PORT_Init(MDR_PORTC, &PORT_InitStructure);

    PORT_InitStructure.PORT_Pin =
        PORT_Pin_10 | PORT_Pin_11 | PORT_Pin_12 |
        PORT_Pin_13 | PORT_Pin_14;

    PORT_InitStructure.PORT_OE = PORT_OE_OUT;
    PORT_InitStructure.PORT_FUNC = PORT_FUNC_PORT;
    PORT_InitStructure.PORT_MODE = PORT_MODE_DIGITAL;
    PORT_InitStructure.PORT_SPEED = PORT_SPEED_SLOW;

    PORT_Init(MDR_PORTD, &PORT_InitStructure);

    PORT_SetBits(MDR_PORTD,
        PORT_Pin_10 | PORT_Pin_11 | PORT_Pin_12 |
        PORT_Pin_13 | PORT_Pin_14);

    Delay(500000);

    PORT_ResetBits(MDR_PORTD,
        PORT_Pin_10 | PORT_Pin_11 | PORT_Pin_12 |
        PORT_Pin_13 | PORT_Pin_14);

    while (1)
    {
        if (PORT_ReadInputDataBit(MDR_PORTC, PORT_Pin_10) == 0)
        {
					int i = 10;
					for(; i < 15; i+=2) 
					{
						unsigned int pin1 = (1 << i);
						PORT_SetBits(MDR_PORTD, pin1);
						Delay(200000);
						PORT_ResetBits(MDR_PORTD, pin1);					
          }
				}					
				
				if (PORT_ReadInputDataBit(MDR_PORTC, PORT_Pin_11) == 0)
        {
					int i = 13;
					for(; i >= 10; i--) 
					{
						unsigned int pin = (1 << i);
						PORT_SetBits(MDR_PORTD, pin);
						Delay(200000);
						PORT_ResetBits(MDR_PORTD, pin);
					}
					
					PORT_SetBits(MDR_PORTD, (1 << 14));
					Delay(200000);
					PORT_ResetBits(MDR_PORTD, (1 << 14));
        }
				
				if (PORT_ReadInputDataBit(MDR_PORTC, PORT_Pin_12) == 0)
        {
            PORT_SetBits(MDR_PORTD, PORT_Pin_12);
						Delay(100000);
						PORT_ResetBits(MDR_PORTD, PORT_Pin_12);
						Delay(100000);
        }
				
				if (PORT_ReadInputDataBit(MDR_PORTC, PORT_Pin_13) == 0)
        {
            PORT_SetBits(MDR_PORTD, PORT_Pin_13);
						Delay(100000);
						PORT_ResetBits(MDR_PORTD, PORT_Pin_13);
						Delay(100000);
        }
				
				if (PORT_ReadInputDataBit(MDR_PORTC, PORT_Pin_14) == 0)
        {
            PORT_SetBits(MDR_PORTD, PORT_Pin_14);
						Delay(100000);
						PORT_ResetBits(MDR_PORTD, PORT_Pin_14);
						Delay(100000);
        }
				
        else
        {
            PORT_ResetBits(MDR_PORTD, PORT_Pin_10);
					  PORT_ResetBits(MDR_PORTD, PORT_Pin_11);
						PORT_ResetBits(MDR_PORTD, PORT_Pin_12);
						PORT_ResetBits(MDR_PORTD, PORT_Pin_13);
						PORT_ResetBits(MDR_PORTD, PORT_Pin_14);
        }
    }
}
