#include <Arduino.h>
#include <stdio.h>
#include <math.h>
#include "../include/universal.h"

namespace adc {
    enum reference {};
    void init(uint8_t pin, bool refs0 = false, bool refs1 = false, bool ate = false, uint16_t prescaler = 0) {
        ADMUX = pin | refs1 << REFS1 | refs0 << REFS0;
        ADCSRA = 1 << ADEN | 1 << ADSC | ate << ADATE | prescaler;
    }

    void setPin() {}
    void setReference() {}
    void setAutoTrigger() {}
    void setPrescaler() {}

    void getResult(uint8_t precision = 10) {}
}








