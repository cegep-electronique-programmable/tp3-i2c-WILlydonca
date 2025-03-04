/*
 * File:   eeprom.c
 * Author: A.D
 *
 * Created on February 25, 2025, 9:59 AM
 */


#include "eeprom.h"
#include "mcc_generated_files/examples/i2c_master_example.h"
#include "mcc_generated_files/mcc.h"
 
#define ADDRESSE_EEprom  0x57


void write_eeprom(uint8_t add_H,uint8_t add_L, uint8_t data ) 
{
    uint8_t  comm_write_eeprom[3]={add_H,add_L,data};
    while(I2C_Open(ADDRESSE_EEprom) == I2C_BUSY);       //Passage de l'adresse
    I2C_SetBuffer(comm_write_eeprom, 3);               //Passage des données
    I2C_MasterOperation(0);                             //Démarrer une opération d'écriture
    while (I2C_Close() == I2C_BUSY);                   	//Attendre que l'opération soit complète
    __delay_ms(1000);
    
}

uint8_t read_eeprom(uint8_t add_H,uint8_t add_L) 
{
    if ((add_H==0x00)&&(add_L ==0x00 )){add_H=0xFF;add_L=0xFF;}
    else if (add_L==0x00){add_H-=0x01;add_L=0xFF;}
    else{add_L-=0x01;}
    
    uint8_t  comm_read_eeprom[3]={add_H,add_L,0x00};
    while(I2C_Open(ADDRESSE_EEprom) == I2C_BUSY);       //Passage de l'adresse
    I2C_SetBuffer(comm_read_eeprom, 3);               //Passage des données
    I2C_MasterOperation(0);                             //Démarrer une opération d'écriture
    while (I2C_Close() == I2C_BUSY);                   	//Attendre que l'opération soit complète
    __delay_ms(1000);
    
    uint8_t  comm_lecture_eeprom[1]={};
    while(I2C_Open(ADDRESSE_EEprom) == I2C_BUSY);       //Passage de l'adresse
    I2C_SetBuffer(comm_lecture_eeprom, 1);               
    I2C_MasterOperation(1);                             //Démarrer une opération lecture
    while (I2C_Close() == I2C_BUSY);                   	//Attendre que l'opération soit complète
    return comm_lecture_eeprom[0] ;
    __delay_ms(1000);
}
