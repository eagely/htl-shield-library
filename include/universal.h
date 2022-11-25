namespace adc {
    void init(uint8_t pin, bool refs0 = false, bool refs1 = false, bool ate = false, uint16_t prescaler = 0);
    void setPin(uint8_t pin);
    void setReference(bool refs0, bool refs1);
    void setAutoTrigger(bool ate);
    void setPrescaler(uint16_t prescaler);
    uint16_t getResult(uint8_t precision);
}

namespace timer {
    void init(bool ovf = false, uint16_t prescaler = 0);
}