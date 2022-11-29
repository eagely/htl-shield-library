#include <Arduino.h>
#include <stdio.h>
#include <math.h>
#include "../include/universal.h"
// Lord forgive me for what I am about to code
namespace adc {
    void init(uint8_t pin, bool R0, bool R1, bool autoTrigger, uint16_t prescaler) {
        ADMUX = pin | R1 << REFS1 | R0 << REFS0;
        ADCSRA = 1 << ADEN | 1 << ADSC | autoTrigger << ADATE | (int) (log10(prescaler) / log10(2));
    }

    void setPin(uint8_t pin) {
        ADMUX &= B11100000;
        ADMUX |= pin;
    }

    void setReference(bool R0, bool R1) {
        ADMUX &= ~(1 << REFS0 | 1 << REFS1);
        ADMUX |= R0 << REFS0 | R1 << REFS1;
    }

    void setAutoTrigger(bool autoTrigger) {
        ADMUX &= ~(1 << ADATE);
        ADMUX |= 1 << ADATE;
    }

    void setPrescaler(uint16_t prescaler) {
        ADMUX &= ~(1 << ADPS0 | 1 << ADPS1 | 1 << ADPS2);
        ADMUX |= (int) (log10(prescaler)/ log10(2));
    }

    uint16_t getResult() {
        return ADCL | ADCH << 8;
    }
}

namespace timer {
    void init(bool overflow, uint16_t prescaler) {
        TCCR1A = (int) (log(prescaler) / log(4));
        TIMSK1 = overflow << TOIE1;
    }

    void setOverflow(bool overflow) {
        TIMSK1 &= ~(overflow << TOIE1);
        TIMSK1 |= overflow << TOIE1;
    }

    void setPrescaler(uint16_t prescaler) {
        TCCR1A &= ~(1 <<  CS10 | 1 << CS11 | 1 << CS12);
        TCCR1A |= (int) (log(prescaler) / log(4));
    }

    void setTime(uint16_t value) {
        TCNT1 = value;
    }
}








