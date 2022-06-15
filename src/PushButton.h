#ifndef PushButton_h
#define PushButton_h

#include "Arduino.h"

#define APERTADO LOW

class PushButton {
  public:
    PushButton(byte pinBotao, int tempoDebounce = 100);
    void button_loop();
    bool pressed();
	bool released();
	int button();
	
  private:
    bool estadoBotao = HIGH;
    bool estadoBotaoAnt = HIGH;
	
	unsigned long debounceBotao = 0;
	unsigned long tempoInicio = 0;

    bool apertado = false;
	bool solto = false;
    byte pino;
    int  tempo;
	
};

#endif