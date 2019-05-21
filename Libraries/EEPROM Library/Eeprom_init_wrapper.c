
/*
 * Include Files
 *
 */
#if defined(MATLAB_MEX_FILE)
#include "tmwtypes.h"
#include "simstruc_types.h"
#else
#include "rtwtypes.h"
#endif



/* %%%-SFUNWIZ_wrapper_includes_Changes_BEGIN --- EDIT HERE TO _END */
#if !defined(MATLAB_MEX_FILE)  
#include "pin_defines.h"

#endif
/* %%%-SFUNWIZ_wrapper_includes_Changes_END --- EDIT HERE TO _BEGIN */
#define y_width 1

/*
 * Create external references here.  
 *
 */
/* %%%-SFUNWIZ_wrapper_externs_Changes_BEGIN --- EDIT HERE TO _END */
#if !defined(MATLAB_MEX_FILE)
extern I2C_HandleTypeDef hi2cEeprom;
#endif
/* %%%-SFUNWIZ_wrapper_externs_Changes_END --- EDIT HERE TO _BEGIN */

/*
 * Output function
 *
 */
void Eeprom_init_Outputs_wrapper(uint8_T *wpState,
			uint8_T *eepromState,
			uint8_T *resRead)
{
/* %%%-SFUNWIZ_wrapper_Outputs_Changes_BEGIN --- EDIT HERE TO _END */
#if !defined(MATLAB_MEX_FILE)  
    uint8_t eepromAddress = 0xA;
    uint8_t devAddress = 0;
    uint8_t memAddress = 0;
    uint8_t page = 0;
    uint8_t cell = 0;
    
    devAddress = eepromAddress << 3 | page >> 4;
	memAddress = page << 4 | cell;
    
    HAL_GPIO_WritePin(EEPROM_WP_GPIO_Port, EEPROM_WP_Pin, GPIO_PIN_RESET);
    *wpState = (uint8_T)0;
    HAL_I2C_Mem_Read(&hi2cEeprom, devAddress<<1, memAddress, I2C_MEMADD_SIZE_8BIT, eepromState, 1, 100);
    
#endif
/* %%%-SFUNWIZ_wrapper_Outputs_Changes_END --- EDIT HERE TO _BEGIN */
}


