#include "PushButton.h"

#include <stdio.h>
#include <string.h>
#include <inttypes.h>
#include "Arduino.h"

PushButton::PushButton(byte pinBotao, int tempoDebounce) {
  pinMode(pinBotao, INPUT_PULLUP);
  pino = pinBotao;
  tempo = tempoDebounce;
}

void PushButton::button_loop() {
  apertado = false;
  solto = false;
  
  if ( (millis() - debounceBotao) >= tempo ) {
    estadoBotao = digitalRead(pino);
    
	if (!estadoBotao && estadoBotaoAnt) {
      debounceBotao = millis();
	  tempoInicio = debounceBotao;
	  apertado = true;
    }

    if (estadoBotao && !estadoBotaoAnt) {
      debounceBotao = millis();
	  tempoInicio = 0;
	  solto = true;
    }
	
	estadoBotaoAnt = estadoBotao;
  }

}

bool PushButton::pressed() {
  return apertado;
}

bool PushButton::released() {
  return solto;
}

int PushButton::button() {
  if (estadoBotao == APERTADO){
	  return (millis() - tempoInicio);
  }
  return 0;
}
