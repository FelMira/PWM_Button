#ifndef DIMMER_HPP
#define DIMMER_HPP
#include "mbed.h"

extern DigitalOut Leds[];
extern InterruptIn botao;
void ativar_timer();
void mudar_sentido();
void mudar_intensidade();

#endif