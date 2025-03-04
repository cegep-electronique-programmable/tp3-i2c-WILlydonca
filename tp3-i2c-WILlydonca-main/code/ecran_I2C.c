#include "ecran_I2C.h"
#include "mcc_generated_files/examples/i2c_master_example.h"
#include "mcc_generated_files/mcc.h"
#define ADDRESSE_I2C_ECRAN 0x28
void ecranAllume(void) // allume l'�cran
{   
    uint8_t  comm_ecranAllume[2]={0xfe,0x41};
    while(I2C_Open(ADDRESSE_I2C_ECRAN) == I2C_BUSY);    //Passage de l'adresse
    I2C_SetBuffer(comm_ecranAllume, 2);                          //Passage des donn�es
    I2C_MasterOperation(0);                             //D�marrer une op�ration d'�criture
    while (I2C_Close() == I2C_BUSY);                   	//Attendre que l'op�ration soit compl�te    

    //EUSART1_Write(0xFE);
    //EUSART1_Write(0x41);
}

void ecranEteint(void) // �teint l'�cran 
{   
    uint8_t  comm_ecraneteint[2]={0xfe,0x42};
    while(I2C_Open(ADDRESSE_I2C_ECRAN) == I2C_BUSY);    //Passage de l'adresse
    I2C_SetBuffer(comm_ecraneteint, 2);                          //Passage des donn�es
    I2C_MasterOperation(0);                             //D�marrer une op�ration d'�criture
    while (I2C_Close() == I2C_BUSY);                   	//Attendre que l'op�ration soit compl�te    

    //EUSART1_Write(0xFE);
    //EUSART1_Write(0x42);
}
void curseurposition(int position) // donne au curseur une position sp�cifique
{
    uint8_t  comm_ecranposition[3]={0xfe,0x45,position};
    while(I2C_Open(ADDRESSE_I2C_ECRAN) == I2C_BUSY);    //Passage de l'adresse
    I2C_SetBuffer(comm_ecranposition, 3);               //Passage des donn�es
    I2C_MasterOperation(0);                             //D�marrer une op�ration d'�criture
    while (I2C_Close() == I2C_BUSY);                   	//Attendre que l'op�ration soit compl�te 
    
    //EUSART1_Write(0xFE);
    //EUSART1_Write(0x45);
    //EUSART1_Write(position);
}

void vide_ecran(void) // efface tout sur l'�cran
{
    uint8_t  comm_ecran_vide_ecran[2]={0xfe,0x51};
    while(I2C_Open(ADDRESSE_I2C_ECRAN) == I2C_BUSY);    //Passage de l'adresse
    I2C_SetBuffer(comm_ecran_vide_ecran, 2);            //Passage des donn�es
    I2C_MasterOperation(0);                             //D�marrer une op�ration d'�criture
    while (I2C_Close() == I2C_BUSY);                   	//Attendre que l'op�ration soit compl�te  
    //EUSART2_Write(0xFE);
    //EUSART2_Write(0x51);
}
void ecriture(int charactere) // permet d'�crire un caract�re
{
  //    juste �crire le caract�re directement.
  //  par exemple: 'b'
    
    uint8_t  comm_ecran_ecriture[1]={charactere};
    while(I2C_Open(ADDRESSE_I2C_ECRAN) == I2C_BUSY);    //Passage de l'adresse
    I2C_SetBuffer(comm_ecran_ecriture, 1);            //Passage des donn�es
    I2C_MasterOperation(0);                             //D�marrer une op�ration d'�criture
    while (I2C_Close() == I2C_BUSY);                   	//Attendre que l'op�ration soit compl�te  
    
  //EUSART1_Write(charactere);
}

void movegauche(void) // bouge le curseur vers la gauche
{   
    uint8_t  comm_ecran_movegauche[2]={0xfe,0x4A};
    while(I2C_Open(ADDRESSE_I2C_ECRAN) == I2C_BUSY);    //Passage de l'adresse
    I2C_SetBuffer(comm_ecran_movegauche, 2);            //Passage des donn�es
    I2C_MasterOperation(0);                             //D�marrer une op�ration d'�criture
    while (I2C_Close() == I2C_BUSY);                   	//Attendre que l'op�ration soit compl�te  
    //EUSART1_Write(0xFE);
    //EUSART1_Write(0x4A);
}
void movedroite(void) // bouge le curseur vers la droite
{
    uint8_t  comm_ecran_movedroite[2]={0xfe,0x49};
    while(I2C_Open(ADDRESSE_I2C_ECRAN) == I2C_BUSY);    //Passage de l'adresse
    I2C_SetBuffer(comm_ecran_movedroite, 2);            //Passage des donn�es
    I2C_MasterOperation(0);                             //D�marrer une op�ration d'�criture
    while (I2C_Close() == I2C_BUSY);                   	//Attendre que l'op�ration soit compl�te  
    //EUSART1_Write(0xFE);
    //EUSART1_Write(0x49);
}
void shiftdroite(void) // fait shifter tout les caract�res vers la droite
{   
    uint8_t  comm_ecran_shiftdroite[2]={0xfe,0x56};
    while(I2C_Open(ADDRESSE_I2C_ECRAN) == I2C_BUSY);    //Passage de l'adresse
    I2C_SetBuffer(comm_ecran_shiftdroite, 2);           //Passage des donn�es
    I2C_MasterOperation(0);                             //D�marrer une op�ration d'�criture
    while (I2C_Close() == I2C_BUSY);                   	//Attendre que l'op�ration soit compl�te  
    //EUSART1_Write(0xFE);
    //EUSART1_Write(0x56);
}
void shiftgauche(void) // fait shifter tout les caract�res vers la gauche
{
    uint8_t  comm_ecran_shiftgauche[2]={0xfe,0x55};
    while(I2C_Open(ADDRESSE_I2C_ECRAN) == I2C_BUSY);    //Passage de l'adresse
    I2C_SetBuffer(comm_ecran_shiftgauche, 2);           //Passage des donn�es
    I2C_MasterOperation(0);                             //D�marrer une op�ration d'�criture
    while (I2C_Close() == I2C_BUSY);                   	//Attendre que l'op�ration soit compl�te  
    //EUSART1_Write(0xFE);
    //EUSART1_Write(0x55);
}
void test(void) // test pour capture
{
    uint8_t  comm_ecran_test[1]={0x22};
    while(I2C_Open(ADDRESSE_I2C_ECRAN) == I2C_BUSY);    //Passage de l'adresse
    I2C_SetBuffer(comm_ecran_test, 1);           //Passage des donn�es
    I2C_MasterOperation(0);                             //D�marrer une op�ration d'�criture
    while (I2C_Close() == I2C_BUSY); 
    
    //Attendre que l'op�ration soit compl�te 
    while(I2C_Open(ADDRESSE_I2C_ECRAN) == I2C_BUSY);    //Passage de l'adresse
    I2C_SetBuffer(comm_ecran_test, 1);           //Passage des donn�es
    I2C_MasterOperation(0);                             //D�marrer une op�ration d'�criture
    while (I2C_Close() == I2C_BUSY);                   	//Attendre que l'op�ration soit compl�te 

}