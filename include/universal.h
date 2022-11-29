namespace adc {
    void init(uint8_t pin, bool R0 = false, bool R1 = false, bool autoTrigger = false, uint16_t prescaler = 0);
    void setPin(uint8_t pin);
    void setReference(bool R0, bool R1);
    void setAutoTrigger(bool autoTrigger);
    void setPrescaler(uint16_t prescaler);
    uint16_t getResult(uint8_t precision);
}

namespace timer {
    void init(bool overflow = false, uint16_t prescaler = 0);
}