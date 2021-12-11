
#include "EEPROM.h"


void eeprom_write_char(u8 Data,u16 Address )
{
//    while(GET_BIT(EECR,EEWE));  // Wait until the previous EEPROM write operation 
//       
//    EEARL = Address;
//    EEARH = Address>>8;
//                            
//    EEDR = Data;
//                                /* Setting EEMWE to enable writing to EEPROM */
//    SET_BIT(EECR,EEMWE);
//                                /* Start eeprom write by setting EEWE */
//    SET_BIT(EECR,EEWE);



    
/* Wait for completion of previous write */
while(EECR & (1<<EEWE));

/* Set up address and data registers */
EEARL = Address;
EEARH = Address >>8;

EEDR = Data;
/* Write logical one to EEMWE */
EECR |= (1<<EEMWE);
/* Start eeprom write by setting EEWE */
EECR |= (1<<EEWE);

}


u8 eeprom_read_char(u16 Address){
                                                  /* Wait for completion of previous write */
    while(GET_BIT(EECR,EEWE));
                                                  /* Set up address register */
    EEARL = Address;
                                                  /* Start eeprom read by writing EERE */
    SET_BIT(EECR,EERE);
                                                  /* Return data from data register */
return EEDR;
}