//--------------------------------------------------------------
// File     : stm32_ub_adc2_single.h
//--------------------------------------------------------------

//--------------------------------------------------------------
#ifndef __STM32F7_UB_ADC2_SINGLE_H
#define __STM32F7_UB_ADC2_SINGLE_H

//--------------------------------------------------------------
// Includes
//--------------------------------------------------------------
#include "stm32_ub_system.h"

//--------------------------------------------------------------
// Liste aller ADC-Kan�le
// (keine Nummer doppelt und von 0 beginnend)
//--------------------------------------------------------------
typedef enum {
  ADC_PA0 = 0, // PA0
  ADC_PA4 = 1, // PA4
  ADC_PA6 = 2  // PA6
} ADC2s_NAME_t;

//--------------------------------------------------------------
// Anzahl der Mittelwerte
//--------------------------------------------------------------
typedef enum {
  MW_NONE = 0, // keine Mittelwerte
  MW_2,        // 2 Mittelwerte
  MW_4,        // 4 Mittelwerte
  MW_8,        // 8 Mittelwerte
  MW_16,       // 16 Mittelwerte
  MW_32,       // 32 Mittelwerte
  MW_64,       // 64 Mittelwerte
  MW_128       // 128 Mittelwerte
} ADC2s_MW_t;

//--------------------------------------------------------------
// ADC-Clock
// Max-ADC-Frq = 36MHz
// Grundfrequenz = PCLK2 (PCLK2=100MHz)
// Moegliche Vorteiler = 2,4,6,8
//--------------------------------------------------------------

//#define ADC2s_VORTEILER     ADC_CLOCKPRESCALER_PCLK_DIV2   // Frq = 50 MHz
#define ADC2s_VORTEILER ADC_CLOCKPRESCALER_PCLK_DIV4 // Frq = 25 MHz
//#define ADC2s_VORTEILER     ADC_CLOCKPRESCALER_PCLK_DIV6 // Frq = 16.66 MHz
//#define ADC2s_VORTEILER     ADC_CLOCKPRESCALER_PCLK_DIV8 // Frq = 12.5 MHz

//--------------------------------------------------------------
// Struktur eines ADC Kanals
//--------------------------------------------------------------
typedef struct {
  ADC2s_NAME_t ADC_NAME;  // Name
  GPIO_TypeDef *ADC_PORT; // Port
  const uint16_t ADC_PIN; // Pin
  const uint32_t ADC_CH;  // ADC-Kanal
  ADC2s_MW_t ADC_MW;      // Mittelwerte
} ADC2s_t;

//--------------------------------------------------------------
// Globale Funktionen
//--------------------------------------------------------------
void UB_ADC2_SINGLE_Init(void);
uint16_t UB_ADC2_SINGLE_Read(ADC2s_NAME_t adc_name);
uint16_t UB_ADC2_SINGLE_Read_MW(ADC2s_NAME_t adc_name);

//--------------------------------------------------------------
#endif // __STM32F7_UB_ADC2_SINGLE_H
