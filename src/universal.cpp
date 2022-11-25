#include <Arduino.h>
#include <stdio.h>
#include <math.h>
#include "../include/universal.h"
// Lord forgive me for what I am about to code
namespace adc {
    void init(uint8_t pin, bool refs0, bool refs1, bool ate, uint16_t prescaler) {
        ADMUX = pin | refs1 << REFS1 | refs0 << REFS0;
        ADCSRA = 1 << ADEN | 1 << ADSC | ate << ADATE | (int) (log10(prescaler) / log10(2));
    }

    void setPin(uint8_t pin) {
        ADMUX &= B11100000;
        ADMUX |= pin;
    }

    void setReference(bool refs0, bool refs1) {
        ADMUX &= ~(1 << REFS0 | 1 << REFS1);
        ADMUX |= refs0 << REFS0 | refs1 << REFS1;
    }

    void setAutoTrigger(bool ate) {
        ADMUX &= ~(1 << ADATE);
        ADMUX |= ate << ADATE;
    }

    void setPrescaler(uint16_t prescaler) {
        ADMUX &= ~(1 << ADPS0 | 1 << ADPS1 | 1 << ADPS2);
        ADMUX |= (int) (log10(prescaler)/ log10(2));
    }

    uint16_t getResult() {
        return ADCL | ADCH << 8;
    }
}
// currently only supports overflow and prescaler
namespace timer {
    void init(bool ovf, uint16_t prescaler) {
        TCCR1A =
        TIMSK1 = ovf << TOIE1;
    }
}








