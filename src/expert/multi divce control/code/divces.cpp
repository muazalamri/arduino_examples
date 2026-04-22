#ifndef divces
#define divces
#include "data.hpp"
void update_divces(uint8_t divces_index){
    if(divces_index>7){
        //throw error
    }
    divce_mlutipix[2]=int(divces_index+1>7);
    divce_mlutipix[1]=int((divces_index+1-8*divce_mlutipix[2])>4);
    divce_mlutipix[0]=int((divces_index+1-8*divce_mlutipix[2]-4*divce_mlutipix[1])>2);
}
void communicate(int divce_index,int protocol_index,uint8_t spi_enable){
    update_divces(divce_index);
    digitalWrite(ENABLE_SPI,spi_enable);
    digitalWrite(divce_multipix_1, divce_mlutipix[0]);
    digitalWrite(divce_multipix_2, divce_mlutipix[1]);
    digitalWrite(divce_multipix_3, divce_mlutipix[2]);
}
#endif