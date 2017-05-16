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
#include <project.h>
#include <stdio.h>
#include <math.h> 


int main()
{
    CyGlobalIntEnable; /* Enable global interrupts. */
    
    /* Start Components*/ 
    
    PGA_1_Start();
    ADC_Start(); 
    UART_1_Start();
    
    
    
    float voltage = 0; //voltage reading 
    uint16 counts = 0; // ADC Counts 
    char outputstring[50]; //String used to output value to UART 
   

    for(;;)
    {
        ADC_StartConvert(); 
        
        counts = ADC_GetResult16(); //read ADC 
        
        voltage = ADC_CountsTo_Volts(counts); 
        
        
        sprintf(outputstring, "%9.6f", voltage);  // convert voltage to string 
        
        UART_1_PutString(outputstring);  // print value to UART 
        UART_1_PutString("\r\n"); 
        
       
        CyDelay(300);        
        
    }
}



/* [] END OF FILE */
