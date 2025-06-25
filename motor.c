#include "ti_msp_dl_config.h"
#include "motor.h"
void Motor_ON()
{
    DL_GPIO_setPins(GPIO_left_PIN_enable_PORT,GPIO_left_PIN_enable_PIN);
    DL_GPIO_setPins(GPIO_right_PORT,GPIO_right_PIN_right_enable_PIN);
}
void Motor_OFF()
{
    DL_GPIO_clearPins(GPIO_left_PIN_enable_PORT,GPIO_left_PIN_enable_PIN);
    DL_GPIO_clearPins(GPIO_right_PORT,GPIO_right_PIN_right_enable_PIN);

    DL_GPIO_clearPins(GPIO_left_PIN_left1_AN0_PORT ,GPIO_left_PIN_left1_AN0_PIN);
    DL_GPIO_clearPins(GPIO_left_PIN_left1_AN1_PORT,GPIO_left_PIN_left1_AN1_PIN);
    DL_GPIO_clearPins(GPIO_left_PIN_left2_AN0_PORT,GPIO_left_PIN_left2_AN0_PIN);
    DL_GPIO_clearPins(GPIO_left_PIN_left2_AN1_PORT,GPIO_left_PIN_left2_AN1_PIN);

    DL_GPIO_clearPins(GPIO_right_PORT ,GPIO_right_PIN_right1_AN0_PIN);
    DL_GPIO_clearPins(GPIO_right_PORT,GPIO_right_PIN_right1_AN1_PIN);
    DL_GPIO_clearPins(GPIO_right_PORT,GPIO_right_PIN_right2_AN0_PIN);
    DL_GPIO_clearPins(GPIO_right_PORT,GPIO_right_PIN_right2_AN1_PIN);
}
void Set_speed(uint8_t lun_num,int8_t duty)//0代表左前轮1代表左后轮2代表右前轮3代表右后轮
{
    uint32_t compareValue=0;
    Motor_ON();
    if(duty>0)
    {
        compareValue= 3199 - 3199*(duty/100.0);
        switch(lun_num){
        case 0:
        DL_TimerA_setCaptureCompareValue(PWM_MOTOR_INST, compareValue, DL_TIMER_CC_0_INDEX);
        DL_GPIO_setPins(GPIO_left_PIN_left1_AN0_PORT, GPIO_left_PIN_left1_AN0_PIN);
        DL_GPIO_clearPins(GPIO_left_PIN_left1_AN1_PORT ,GPIO_left_PIN_left1_AN1_PIN);
        break;
        case 1:
        DL_TimerA_setCaptureCompareValue(PWM_MOTOR_INST, compareValue, DL_TIMER_CC_1_INDEX);
        DL_GPIO_setPins(GPIO_left_PIN_left2_AN0_PORT, GPIO_left_PIN_left2_AN0_PIN);
        DL_GPIO_clearPins(GPIO_left_PIN_left2_AN1_PORT ,GPIO_left_PIN_left2_AN1_PIN);
        break;
        case 2:
        DL_TimerA_setCaptureCompareValue(PWM_MOTOR_INST, compareValue, DL_TIMER_CC_2_INDEX); 
        DL_GPIO_setPins(GPIO_right_PORT, GPIO_right_PIN_right1_AN0_PIN);
        DL_GPIO_clearPins(GPIO_right_PORT ,GPIO_right_PIN_right1_AN1_PIN);
        break;  
        case 3:
        DL_TimerA_setCaptureCompareValue(PWM_MOTOR_INST, compareValue, DL_TIMER_CC_3_INDEX); 
        DL_GPIO_setPins(GPIO_right_PORT, GPIO_right_PIN_right2_AN0_PIN);
        DL_GPIO_clearPins(GPIO_right_PORT ,GPIO_right_PIN_right2_AN1_PIN);
        break;   
        }
    }
    else if(duty<0)// AN1=0,AN2=1反转
    {
        compareValue= 3199 - 3199*(-duty/100.0);
        switch(lun_num){
        case 0:
        DL_TimerA_setCaptureCompareValue(PWM_MOTOR_INST, compareValue, DL_TIMER_CC_0_INDEX);
        DL_GPIO_clearPins(GPIO_left_PIN_left1_AN0_PORT, GPIO_left_PIN_left1_AN0_PIN);
        DL_GPIO_setPins(GPIO_left_PIN_left1_AN1_PORT ,GPIO_left_PIN_left1_AN1_PIN);
        break;
        case 1:
        DL_TimerA_setCaptureCompareValue(PWM_MOTOR_INST, compareValue, DL_TIMER_CC_1_INDEX);
        DL_GPIO_clearPins(GPIO_left_PIN_left2_AN0_PORT, GPIO_left_PIN_left2_AN0_PIN);
        DL_GPIO_setPins(GPIO_left_PIN_left2_AN1_PORT ,GPIO_left_PIN_left2_AN1_PIN);
        break;
        case 2:
        DL_TimerA_setCaptureCompareValue(PWM_MOTOR_INST, compareValue, DL_TIMER_CC_2_INDEX); 
        DL_GPIO_clearPins(GPIO_right_PORT,  GPIO_right_PIN_right1_AN0_PIN);
        DL_GPIO_setPins(GPIO_right_PORT ,GPIO_right_PIN_right1_AN1_PIN);
        break;  
        case 3:
        DL_TimerA_setCaptureCompareValue(PWM_MOTOR_INST, compareValue, DL_TIMER_CC_3_INDEX); 
        DL_GPIO_clearPins(GPIO_right_PORT, GPIO_right_PIN_right2_AN0_PIN);
        DL_GPIO_setPins(GPIO_right_PORT ,GPIO_right_PIN_right2_AN1_PIN);
        break;
        }
    }
    else if(duty==0)
    {
        Motor_OFF();
    }
}
