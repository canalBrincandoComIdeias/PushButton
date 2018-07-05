#ifndef PushButton_h
#define PushButton_h

#include "Arduino.h"

class PushButton {
  public:
    PushButton(byte pinBotao, int tempoDebounce = 200);
    void button_loop(); 
    bool pressed();
  private:
    unsigned long debounceBotao;
    bool estadoBotaoAnt = HIGH;
    bool apertado = false;
    byte pino;
    int  tempo;
};

#endif