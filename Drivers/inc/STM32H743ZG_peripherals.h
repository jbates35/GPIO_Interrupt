/*
 * STM32H743ZG_peripherals.h
 *
 *  Created on: Sep 29, 2023
 *      Author: jbates
 */

#ifndef STM32H743ZG_PERIPHERALS_H_
#define STM32H743ZG_PERIPHERALS_H_

#define __vo (volatile) //For easy casting as volatile memory

//Base addresses of peripherals
#define RAMECC3_BASEADD/R 		    0x58027000
#define HSEM_BASEADDR			    0x58026400
#define ADC3_BASEADDR               0x58026000
#define DMAMUX2_BASEADDR            0x58025800
#define BDMA_BASEADDR               0x58025400
#define CRC_BASEADDR                0x58024C00
#define PWR_BASEADDR                0x58024800
#define BASEADDR                0x58024400

#define GPIOK_BASEADDR              0x58022800
#define GPIOJ_BASEADDR              0x58022400
#define GPIOI_BASEADDR              0x58022000
#define GPIOH_BASEADDR              0x58021C00
#define GPIOG_BASEADDR              0x58021800
#define GPIOF_BASEADDR              0x58021400
#define GPIOE_BASEADDR              0x58021000
#define GPIOD_BASEADDR              0x58020C00
#define GPIOC_BASEADDR              0x58020800
#define GPIOB_BASEADDR              0x58020400
#define GPIOA_BASEADDR              0x58020000

#define SAI4_BASEADDR               0x58005400
#define IWDG1_BASEADDR              0x58004800     
#define RTC_BASEADDR                0x58004000     
#define VREF_BASEADDR               0x58003C00     
#define COMP1_BASEADDR              0x58003800     
#define LPTIM5_BASEADDR             0x58003000     
#define LPTIM4_BASEADDR             0x58002C00     
#define LPTIM3_BASEADDR             0x58002800     
#define LPTIM2_BASEADDR             0x58002400     
#define I2C4_BASEADDR               0x58001C00     
#define SPI6_BASEADDR               0x58001400     
#define LPUART1_BASEADDR            0x58000C00         
#define SYSCFG_BASEADDR             0x58000400     
#define EXTI_BASEADDR               0x58000000     
#define RAMECC1_BASEADDR            0x52009000         
#define SDMMC1_DELAY_BASEADDR       0x52008000             
#define SDMMC1_BASEADDR             0x52007000     
#define QUADSPI_DELAY_BASEADDR      0x52006000             
#define QUADSPI_CTRL_BASEADDR       0x52005000             
#define FMC_CTRL_BASEADDR           0x52004000         
#define JPEG_BASEADDR               0x52003000     
#define FLASH_INTERFACE_BASEADDR    0x52002000                  
#define DMA2D_CHROM_ART_BASEADDR    0x52001000                 
#define MDMA_BASEADDR               0x52000000     
#define GPV_BASEADDR                0x51000000     
#define WWDG1_BASEADDR              0x50003000     
#define LTDC_BASEADDR               0x50001000     
#define RAMECC2_BASEADDR            0x48023000         

#define SDMMC2_DELAY_BASEADDR       0x48022800 
#define SDMMC2_BASEADDR             0x48022400  
#define RNG_BASEADDR                0x48021800  
#define HASH_BASEADDR               0x48021400  
#define CRYPTO_BASEADDR             0x48021000  
#define DCMI_BASEADDR               0x48020000  
#define USB2_OTG_FS_BASEADDR        0x40080000 
#define USB1_OTG_HS_BASEADDR        0x40040000  
#define ETHERNET_MAC_BASEADDR       0x40028000  
#define ADC1_ADC2_BASEADDR          0x40022000  
#define DMAMUX1_BASEADDR            0x40020800  
#define DMA2_BASEADDR               0x40020400  
#define DMA1_BASEADDR               0x40020000  
#define HRTIM_BASEADDR              0x40017400 
#define DFSDM1_BASEADDR             0x40017000 
#define SAI3_BASEADDR               0x40016000  
#define SAI2_BASEADDR               0x40015C00  
#define SAI1_BASEADDR               0x40015800  
#define SPI5_BASEADDR               0x40015000  
#define TIM17_BASEADDR              0x40014800  
#define TIM16_BASEADDR              0x40014400  
#define TIM15_BASEADDR              0x40014000  
#define SPI4_BASEADDR               0x40013400  
#define SPI1_I2S1_BASEADDR          0x40013000  
#define USART6_BASEADDR             0x40011400  
#define USART1_BASEADDR             0x40011000  
#define TIM8_BASEADDR               0x40010400  
#define TIM1_BASEADDR               0x40010000  

#define CAN_BASEADDR                0x4000AC00 
#define CAN_CCU_BASEADDR            0x4000A800 
#define FDCAN2_BASEADDR             0x4000A400 
#define FDCAN1_BASEADDR             0x4000A000 
#define MDIOS_BASEADDR              0x40009400 
#define OPAMP_BASEADDR              0x40009000 
#define SWPMI_BASEADDR              0x40008800 
#define CRS_BASEADDR                0x40008400 
#define UART8_BASEADDR              0x40007C00 
#define UART7_BASEADDR              0x40007800 
#define DAC1_BASEADDR               0x40007400 
#define HDMI_CEC_BASEADDR           0x40006C00 
#define I2C3_BASEADDR               0x40005C00 
#define I2C2_BASEADDR               0x40005800 
#define I2C1_BASEADDR               0x40005400 
#define UART5_BASEADDR              0x40005000 
#define UART4_BASEADDR              0x40004C00 
#define USART3_BASEADDR             0x40004800 
#define USART2_BASEADDR             0x40004400 
#define SPDIFRX1_BASEADDR           0x40004000 
#define SPI3_I2S3_BASEADDR          0x40003C00 
#define SPI2_I2S2_BASEADDR          0x40003800 
#define LPTIM1_BASEADDR             0x40002400 
#define TIM14_BASEADDR              0x40002000 
#define TIM13_BASEADDR              0x40001C00 
#define TIM12_BASEADDR              0x40001800 
#define TIM7_BASEADDR               0x40001400 
#define TIM6_BASEADDR               0x40001000 
#define TIM5_BASEADDR               0x40000C00 
#define TIM4_BASEADDR               0x40000800 
#define TIM3_BASEADDR               0x40000400 
#define TIM2_BASEADDR               0x40000000 

/*
-------------peripheral structs-------------
Use these with and declare them as pointer structs to 
be able to access the memory easily
*/

typedef struct RegDef {

CR
HSICFGR
CRRCR
reserved
CSICFGR
CFGR
reserved
D1CFGR //good
D2CFGR
D3CFGR
reserved
PLLCKSELR
PLLCFGR
PLL1DIVR
PLL1FRACR
PLL2DIVR
PLL2FRACR
PLL3DIVR
PLL3FRACR
reserved
D1CCIPR //good
D2CCIP1R
D2CCIP2R
D3CCIPR
reserved 
CIER
CIFR
CICR
reserved 
BDCR //good
CSR
reserved 
AHB3RSTR
AHB1RSTR
AHB2RSTR
AHB4RSTR
APB3RSTR
APB1LRSTR
APB1HRSTR //good
APB2RSTR
APB4RSTR
GCR
reserved 
D3AMR
reserved 
RSR
AHB3ENR
AHB1ENR //good
AHB2ENR
AHB4ENR
APB3ENR
APB1LENR
APB1HENR
APB2ENR
APB4ENR
reserved 
AHB3LPENR // good
AHB1LPENR
AHB2LPENR
AHB4LPENR
APB3LPENR
APB1LLPENR
APB1HLPENR
APB2LPENR // good
APB4LPENR 
reserved 
C1_RSR
C1_AHB3ENR
C1_AHB1ENR
C1_AHB2ENR
C1_AHB4ENR
C1_APB3ENR // good
C1_APB1LENR
C1_APB1HENR
C1_APB2ENR
C1_APB4ENR
reserved 
C1_AHB3LPENR
C1_AHB1LPENR
C1_AHB2LPENR
C1_AHB4LPENR
C1_APB3LPENR
C1_APB1LLPENR
C1_APB1HLPENR
C1_APB2LPENR
C1_APB4LPENR

    
} RegDef_t;

/*
// Actual Pointer Notation with base addresses:

#define RAMECC3                 (*) RAMECC3_BASEADDR
#define HSEM                    (*) HSEM_BASEADDR
#define ADC3                    (*) ADC3_BASEADDR
#define DMAMUX2                 (*) DMAMUX2_BASEADDR
#define BDMA                    (*) BDMA_BASEADDR
#define CRC                     (*) CRC_BASEADDR
#define PWR                     (*) PWR_BASEADDR
#define RCC                     (*) BASEADDR
#define GPIOK                   (*) GPIOK_BASEADDR
#define GPIOJ                   (*) GPIOJ_BASEADDR
#define GPIOI                   (*) GPIOI_BASEADDR
#define GPIOH                   (*) GPIOH_BASEADDR
#define GPIOG                   (*) GPIOG_BASEADDR
#define GPIOF                   (*) GPIOF_BASEADDR
#define GPIOE                   (*) GPIOE_BASEADDR
#define GPIOD                   (*) GPIOD_BASEADDR
#define GPIOC                   (*) GPIOC_BASEADDR
#define GPIOB                   (*) GPIOB_BASEADDR
#define GPIOA                   (*) GPIOA_BASEADDR
#define SAI4                    (*) SAI4_BASEADDR
#define IWDG1                   (*) IWDG1_BASEADDR    
#define RTC                     (*) RTC_BASEADDR    
#define VREF                    (*) VREF_BASEADDR    
#define COMP1                   (*) COMP1_BASEADDR    
#define LPTIM5                  (*) LPTIM5_BASEADDR    
#define LPTIM4                  (*) LPTIM4_BASEADDR    
#define LPTIM3                  (*) LPTIM3_BASEADDR    
#define LPTIM2                  (*) LPTIM2_BASEADDR    
#define I2C4                    (*) I2C4_BASEADDR    
#define SPI6                    (*) SPI6_BASEADDR    
#define LPUART1                 (*) LPUART1_BASEADDR        
#define SYSCFG                  (*) SYSCFG_BASEADDR    
#define EXTI                    (*) EXTI_BASEADDR    
#define RAMECC1                 (*) RAMECC1_BASEADDR        
#define SDMMC1_DELAY            (*) SDMMC1_DELAY_BASEADDR            
#define SDMMC1                  (*) SDMMC1_BASEADDR    
#define QUADSPI_DELAY           (*) QUADSPI_DELAY_BASEADDR            
#define QUADSPI_CTRL            (*) QUADSPI_CTRL_BASEADDR            
#define FMC_CTRL                (*) FMC_CTRL_BASEADDR        
#define JPEG                    (*) JPEG_BASEADDR    
#define FLASH_INTERFACE         (*) FLASH_INTERFACE_BASEADDR                 
#define DMA2D_CHROM_ART         (*) DMA2D_CHROM_ART_BASEADDR                
#define MDMA                    (*) MDMA_BASEADDR    
#define GPV                     (*) GPV_BASEADDR    
#define WWDG1                   (*) WWDG1_BASEADDR    
#define LTDC                    (*) LTDC_BASEADDR    
#define RAMECC2                 (*) RAMECC2_BASEADDR        
#define SDMMC2_DELAY            (*) SDMMC2_DELAY_BASEADDR
#define SDMMC2                  (*) SDMMC2_BASEADDR 
#define RNG                     (*) RNG_BASEADDR 
#define HASH                    (*) HASH_BASEADDR 
#define CRYPTO                  (*) CRYPTO_BASEADDR 
#define DCMI                    (*) DCMI_BASEADDR 
#define USB2_OTG_FS             (*) USB2_OTG_FS_BASEADDR
#define USB1_OTG_HS             (*) USB1_OTG_HS_BASEADDR 
#define ETHERNET_MAC            (*) ETHERNET_MAC_BASEADDR 
#define ADC1_ADC2               (*) ADC1_ADC2_BASEADDR 
#define DMAMUX1                 (*) DMAMUX1_BASEADDR 
#define DMA2                    (*) DMA2_BASEADDR 
#define DMA1                    (*) DMA1_BASEADDR 
#define HRTIM                   (*) HRTIM_BASEADDR
#define DFSDM1                  (*) DFSDM1_BASEADDR
#define SAI3                    (*) SAI3_BASEADDR 
#define SAI2                    (*) SAI2_BASEADDR 
#define SAI1                    (*) SAI1_BASEADDR 
#define SPI5                    (*) SPI5_BASEADDR 
#define TIM17                   (*) TIM17_BASEADDR 
#define TIM16                   (*) TIM16_BASEADDR 
#define TIM15                   (*) TIM15_BASEADDR 
#define SPI4                    (*) SPI4_BASEADDR 
#define SPI1_I2S1               (*) SPI1_I2S1_BASEADDR 
#define USART6                  (*) USART6_BASEADDR 
#define USART1                  (*) USART1_BASEADDR 
#define TIM8                    (*) TIM8_BASEADDR 
#define TIM1                    (*) TIM1_BASEADDR 
#define CAN                     (*) CAN_BASEADDR
#define CAN_CCU                 (*) CAN_CCU_BASEADDR
#define FDCAN2                  (*) FDCAN2_BASEADDR
#define FDCAN1                  (*) FDCAN1_BASEADDR
#define MDIOS                   (*) MDIOS_BASEADDR
#define OPAMP                   (*) OPAMP_BASEADDR
#define SWPMI                   (*) SWPMI_BASEADDR
#define CRS                     (*) CRS_BASEADDR
#define UART8                   (*) UART8_BASEADDR
#define UART7                   (*) UART7_BASEADDR
#define DAC1                    (*) DAC1_BASEADDR
#define HDMI_CEC                (*) HDMI_CEC_BASEADDR
#define I2C3                    (*) I2C3_BASEADDR
#define I2C2                    (*) I2C2_BASEADDR
#define I2C1                    (*) I2C1_BASEADDR
#define UART5                   (*) UART5_BASEADDR
#define UART4                   (*) UART4_BASEADDR
#define USART3                  (*) USART3_BASEADDR
#define USART2                  (*) USART2_BASEADDR
#define SPDIFRX1                (*) SPDIFRX1_BASEADDR
#define SPI3_I2S3               (*) SPI3_I2S3_BASEADDR
#define SPI2_I2S2               (*) SPI2_I2S2_BASEADDR
#define LPTIM1                  (*) LPTIM1_BASEADDR
#define TIM14                   (*) TIM14_BASEADDR
#define TIM13                   (*) TIM13_BASEADDR
#define TIM12                   (*) TIM12_BASEADDR
#define TIM7                    (*) TIM7_BASEADDR
#define TIM6                    (*) TIM6_BASEADDR
#define TIM5                    (*) TIM5_BASEADDR
#define TIM4                    (*) TIM4_BASEADDR
#define TIM3                    (*) TIM3_BASEADDR
#define TIM2                    (*) TIM2_BASEADDR
*/
#endif /* STM32H743ZG_PERIPHERALS_H_ */
