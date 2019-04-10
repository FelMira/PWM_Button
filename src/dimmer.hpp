#ifndef DIMMER_HPP
#define DIMMER_HPP
#include "mbed.h"

extern PwmOut Leds[];
extern InterruptIn botao;
void ativar_timer();
void mudar_sentido();
void mudar_intensidade();
void blinky_blue();
void blinky_orange();
void stop_blink();
void rise_blue();
void fall_orange();

#endif