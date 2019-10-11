/* ========================================
 *
 * Copyright YOUR COMPANY, THE YEAR
 * All Rights Reserved
 * UNPUBLISHED, LICENSED SOFTWARE.
 *
 * CONFIDENTIAL AND PROPRIETARY INFORMATION
 * WHICH IS THE PROPERTY OF your company.
 *
 * ========================================
*/
#include "project.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>



const int PWMSERVO_MIN = 544;
const int PWMSERVO_MAX = 2400;
const int PWMSERVO_X_CORRECTION = 90-9;
const int PWMSERVO_Y_CORRECTION = 90+3;
const float X_Volt_EMPMAX = 4.5;
const float Y_Volt_EMPMAX = 4.3;
const int X_MAX = 3540;
const int Y_MAX = 3690;
const int X_MIN = 380;
const int Y_MIN = 180;
float Xrel = 0;
float Yrel = 0;
float Vddval = 5;
float Vssval = 0;

int x_int = 0;
int y_int = 0;
float x_float = 0;
float y_float = 0;
int x_req = 2000;
int y_req = 2000;
float X_Ak=0;
float Y_Ak=0;
float X_Akmenos1=0;
float Y_Akmenos1=0;
float X_Ek=0;
float Y_Ek=0;
float X_Ekmenos1=0;
float Y_Ekmenos1=0;
float X_prep=0;
float Y_prep=0;


CY_ISR_PROTO(Y_interrupcion_Handler);
CY_ISR_PROTO(X_interrupcion_Handler);

//Definiendo funciones que utilizaremos en nuestro sistema de control
int mapANGtoTIME(float Angulo){ //Esta función mapea apartir de un rango dado a otro rango dado.
    if (0<Angulo && Angulo<180){
        float angrelativo = (Angulo)/180;
        float timerelative= angrelativo*(PWMSERVO_MAX-PWMSERVO_MIN);
        return timerelative+PWMSERVO_MIN-1;
    }
    else{
        if (Angulo>180){
            float angrelativo = (180)/180;
            float timerelative= angrelativo*(PWMSERVO_MAX-PWMSERVO_MIN);
            return timerelative+PWMSERVO_MIN-1;
        }
        else{
            float angrelativo = (0)/180;
            float timerelative= angrelativo*(PWMSERVO_MAX-PWMSERVO_MIN);
            return timerelative+PWMSERVO_MIN-1;
        }
    }
}
void SetServoX(float Angulo){
    Angulo=(Angulo*-1)+PWMSERVO_X_CORRECTION;
    PWM_X_WriteCompare1(mapANGtoTIME(Angulo)); 
    return;
}
void SetServoY(float Angulo){
    Angulo=(Angulo*-1)+PWMSERVO_Y_CORRECTION;
    PWM_Y_WriteCompare1(mapANGtoTIME(Angulo));
    return;
}
/*void Volt_update(void){ //Actualiza el valor del voltaje minimo y maximo que puede leer para ajustarse a las dimenciones.
    AxisSelector_Write(0xFF);   //Seleccionamos el eje X poniendo unos.
    CyDelay(1);
    Vddval = ADC_YAxis_CountsTo_Volts(ADC_YAxis_GetResult16());
    AxisSelector_Write(0x00);   //Seleccionamos el eje Y poniendo ceros.
    CyDelay(1);
    Vssval = ADC_XAxis_CountsTo_Volts(ADC_XAxis_GetResult16());
    return;
}*/
int ReadXAxis(void){
    int value_int = Touch_Measure();
    Touch_ActivateY();
    return value_int;
}

int ReadYAxis(void){
    int value_int = Touch_Measure();
    Touch_ActivateX();
    return value_int;
}

float PosRealX(int PosXint){
    float PosVolt=((PosXint-X_MIN)*Xrel);
    return PosVolt;
}

float PosRealY(int PosYint){
    float PosVolt=((PosYint-Y_MIN)*Yrel);
    return PosVolt;
}

float Saturador(float val, float min, float max){
    if (val>max){
        return max;
    }
    else{
        if (val<min){
            return min;
        }
        else{
            return val;
        }
    }
    
}

void printScreen(int Xpos, int Ypos, int Xreq, int Yreq){
        char x_to_print[10];
        char y_to_print[10];
        char x_pos_print[10];
        char y_pos_print[10];       
        sprintf(x_to_print, "Xrq=%d", Xreq);
        sprintf(y_to_print, "Yrq=%d", Yreq);
        sprintf(x_pos_print, "Xps=%d", Xpos);
        sprintf(y_pos_print, "Yps=%d", Ypos);
        LCD_ClearDisplay();
        LCD_Position(0u, 0u); // first row, first column
        LCD_PrintString(x_to_print);   
        LCD_Position(1u, 0u); // first row, first column
        LCD_PrintString(y_to_print);
        LCD_Position(0u, 8u); // first row, first column
        LCD_PrintString(x_pos_print);   
        LCD_Position(1u, 8u); // first row, first column
        LCD_PrintString(y_pos_print);
        return;
}

CY_ISR(Y_interrupcion_Handler)
{
        y_int = ReadYAxis();
        Y_Ek = PosRealY(y_req-y_int);
        y_int = y_req-y_int;
        Y_Ak=Y_prep+Y_Ek*(251.59);
        Y_Ak=Saturador(Y_Ak,-30,30);
        SetServoY(-Y_Ak);
        Y_Akmenos1=Y_Ak;
        Y_Ekmenos1=Y_Ek;
        Y_prep = Y_Akmenos1*0.2632+Y_Ekmenos1*(-242.38);

}

CY_ISR(X_interrupcion_Handler)
{
        x_int = ReadXAxis();
        X_Ek = PosRealX(x_req-x_int);
        x_int = x_req-x_int;
        X_Ak=X_prep+X_Ek*(251.59);
        X_Ak=Saturador(X_Ak,-30,30);
        SetServoX(X_Ak);
        X_Akmenos1=X_Ak;
        X_Ekmenos1=X_Ek;
        X_prep = X_Akmenos1*0.519211+X_Ekmenos1*(-94.13);

}

int main(void)
{   
    //Inicializamos variables globales
    Xrel =(X_Volt_EMPMAX/(X_MAX-X_MIN));
    Yrel =(Y_Volt_EMPMAX/(Y_MAX-Y_MIN));
        
    //Inicializamos los contadores que generaran las señales para los servos
    PWM_X_Start();
    PWM_Y_Start();
    CyDelay(100);
    
    //Separamos los PWM 10 milisegundos entre sí
    PWM_reset_Write(0xF);
    CyDelay(20);
    PWM_reset_Write(0x6);
    CyDelay(10);
    PWM_reset_Write(0x0);
    Touch_Start();

    /* Place your initialization/startup code here (e.g. MyInst_Start()) */
    LCD_Start();
    Y_interrupcion_StartEx(Y_interrupcion_Handler);
    X_interrupcion_StartEx(X_interrupcion_Handler);
    CyGlobalIntEnable; /* Enable global interrupts. */
    for(;;)
    {
        printScreen(x_int, y_int, x_req, y_req);        
        CyDelay(100);       

    }
}


/* [] END OF FILE */
