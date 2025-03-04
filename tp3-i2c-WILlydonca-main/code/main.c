/**

  @Nom du fichier
    main.c

  @Auteur
 wilken's Pinthière
   
  @Sommaire
 Programme pour démontrer le fonctionnement du module I2C du Pic18f25k80

*/

#include "mcc_generated_files/mcc.h"
#include  "mcc_generated_files/examples/i2c_master_example.h"
#include  "ecran_I2C.h"
#include  "eeprom.h"
/*
    Début de l'application principale
 */
void main(void)
{
    // Initialize the device
    SYSTEM_Initialize();
    curseurposition(0x40);
    while(1)
    {
        curseurposition(0x40);
        write_eeprom(0x02,0x03,'b');
        write_eeprom(0x02,0x43,'a');
        write_eeprom(0x02,0x43,'e');
        test();
        uint8_t message=read_eeprom(0x02,0x43);
        uint8_t  message1 = read_eeprom(0x02,0x03);
        curseurposition(0x44);
        ecriture(message); 
        curseurposition(0x45);
        ecriture(message1);
        
    }
    while(1){}

        
        
        

    
}
