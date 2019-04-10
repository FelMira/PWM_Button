#include "dimmer.hpp"

PwmOut Leds[]={(PD_13),(PD_15),(PA_9)};
Timeout contador,piscar;
InterruptIn botao(PA_0);
bool direcao=0;//0=DOWN; 1=UP

void ativar_timer(){
    contador.attach(&mudar_intensidade,1);
    botao.fall(&mudar_sentido);
}

void mudar_sentido(){
    contador.detach();
    Leds[direcao] = 0;
    direcao = !direcao;
    Leds[direcao] = 1; //1=mais brilho; 0=menos brilho
}

void mudar_intensidade(){
    botao.fall(&stop_blink);
    if(direcao==1){//Aumentar 5% do valor max. a cada segundo
        if(Leds[2]<1.0){
            Leds[2] = Leds[2]+0.05;
            rise_blue();
        }
        if(Leds[2]>=1.0){
            blinky_blue();
        }
    }
    if(direcao==0){//Diminuir na mesma passada que acima
        if(Leds[2]>0.0){
            Leds[2] = Leds[2]-0.05;
            fall_orange();
        }
        if(Leds[2]<=0.0){
            blinky_orange();
        }
    }
    contador.attach(&mudar_intensidade, 1);
}
void rise_blue(){
    if(Leds[1]==1){
        Leds[1]=0;
        piscar.attach(&rise_blue, 0.2);
    }
    else{
        Leds[1]=1;
    }
}

void fall_orange(){
    if(Leds[0]==1){
        Leds[0]=0;
        piscar.attach(&fall_orange, 0.2);
    }
    else{
        Leds[0]=1;
    }
}

void stop_blink(){
    piscar.detach();
    contador.detach();
    Leds[direcao]=1;
}

void blinky_blue(){
    Leds[1] = !Leds[1];
    contador.attach(&blinky_blue, 0.1);
    botao.fall(&mudar_sentido);
}

void blinky_orange(){
    Leds[0] = !Leds[0];
    contador.attach(&blinky_orange, 0.1);
    botao.fall(&mudar_sentido);
}