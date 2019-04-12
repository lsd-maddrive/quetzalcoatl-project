#ifndef INCLUDE_EXT_DAC_H_
#define INCLUDE_EXT_DAC_H_

#include <common.h>

#define EXTERNAL_DAC_SPI_DRIVER		&SPID1
#define EXTERNAL_DAC_CLK_LINE		PAL_LINE(GPIOA, 5)
#define EXTERNAL_DAC_CLK_MODE		PAL_MODE_ALTERNATE(5)
#define EXTERNAL_DAC_MISO_LINE		PAL_LINE(GPIOA, 6U)
#define EXTERNAL_DAC_MISO_MODE		PAL_MODE_ALTERNATE(5)
#define EXTERNAL_DAC_MOSI_LINE		PAL_LINE(GPIOA, 7U)
#define EXTERNAL_DAC_MOSI_MODE		PAL_MODE_ALTERNATE(5)
#define EXTERNAL_DAC_CS_PORT		GPIOD
#define EXTERNAL_DAC_CS_PIN			14
#define EXTERNAL_DAC_CS_MODE		PAL_MODE_OUTPUT_PUSHPULL

#define EXTERNAL_DAC_CS_LINE		PAL_LINE(EXTERNAL_DAC_CS_PORT,EXTERNAL_DAC_CS_PIN)

/*
 * @brief: Init external Dac
 */

void extDacInit( void );

/*@brief: Set 16 bit value
*
*/
void  extDacSetValue( uint8_t valueA, uint8_t valueB);

#endif