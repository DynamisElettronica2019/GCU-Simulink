
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
#define u_width 1
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
void Eeprom_read_Outputs_wrapper(const uint8_T *page,
			const uint8_T *cell,
			const uint8_T *dataSize,
			uint8_T *resRead,
			uint8_T *data)
{
/* %%%-SFUNWIZ_wrapper_Outputs_Changes_BEGIN --- EDIT HERE TO _END */
#if !defined(MATLAB_MEX_FILE)  
    uint8_t eepromAddress = 0xA;
    uint8_t devAddress = 0;
    uint8_t memAddress = 0;
    
    
    devAddress = eepromAddress << 3 | *page >> 4;
		memAddress = *page << 4 | *cell;
    
    //aggiungere header nel file costanti
    *resRead = HAL_I2C_Mem_Read(&hi2cEeprom, devAddress<<1, memAddress, I2C_MEMADD_SIZE_8BIT, data, *dataSize, 100);
  
#else
    *resRead = 1;
#endif
/* %%%-SFUNWIZ_wrapper_Outputs_Changes_END --- EDIT HERE TO _BEGIN */
}


