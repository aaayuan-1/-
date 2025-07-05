/*
 * Copyright (c) 2021, Texas Instruments Incorporated
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions
 * are met:
 *
 * *  Redistributions of source code must retain the above copyright
 *    notice, this list of conditions and the following disclaimer.
 *
 * *  Redistributions in binary form must reproduce the above copyright
 *    notice, this list of conditions and the following disclaimer in the
 *    documentation and/or other materials provided with the distribution.
 *
 * *  Neither the name of Texas Instruments Incorporated nor the names of
 *    its contributors may be used to endorse or promote products derived
 *    from this software without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
 * AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO,
 * THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR
 * PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT OWNER OR
 * CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL,
 * EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO,
 * PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS;
 * OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY,
 * WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR
 * OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE,
 * EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 */
//在CCS图形化配置串口的时候需要把UART设置成PA10 PA11
#include "ti_msp_dl_config.h"
#include "stdio.h"
#include "string.h"
void SendString_BT(char*str);
void SendString_Openmv(char*str);
int a=100;
char tx_buff[100];
int main(void)
{
    SYSCFG_DL_init();

    while (1) {
        sprintf(tx_buff,"chenliangyuan %d\r\n",3507);
        printf("Hello %d\r\n",a);
        SendString_BT("tx_buff\r\n");
        SendString_Openmv("openmv");
        delay_cycles(CPUCLK_FREQ);
    }
}
void SendString_BT(char*str)
{
    while(*str!=0)
    {
        DL_UART_Main_transmitDataBlocking(UART_BT_INST,*str++);
    }
}
void SendString_Openmv(char*str)
{
    while(*str!=0)
    {
        DL_UART_Main_transmitDataBlocking(UART_Openmv_INST,*str++);
    }
}
// int fputc(int c, FILE * stream)
// {
//     DL_UART_Main_transmitDataBlocking(UART_0_INST,c);
//     return c;
// }
// int fputs(const char*restrict s,FILE* restrict stream)
// {
//     uint16_t i,len;
//     len=strlen(s);
//     for(i=0;i<len;i++)
//     {
//         DL_UART_Main_transmitDataBlocking(UART_0_INST,s[i]);
//     }
//     return len;
// }
// int puts(const char*_ptr)
// {
//     int count=fputs(_ptr,stdout);
//     count +=fputs("\n",stdout);
//     return count;
// }
