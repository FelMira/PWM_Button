#include "dimmer.hpp"

PwmOut Leds[]={(PD_13),(PD_15),(PD_9)};
Timeout contador;
InterruptIn botao(PA_0);
bool direcao=0;

void ativar_timer(){
    contador.attach(&mudar_intensidade,1);
    botao.fall(&mudar_sentido);
}

void mudar_sentido(){
    contador.detach();
    direcao = !direcao; //1=mais brilho; 0=menos brilho
}

void mudar_intensidade(){
    if(direcao==1){
        
        //Aumentar 20% do valor max. a cada segundo
        }
    else{
        //Diminuir na mesma passada que acima
        }
    contador.attach(&mudar_intensidade, 1);
}