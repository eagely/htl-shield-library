// Lord forgive me for what I am about to code
namespace adc {
    void init(uint8_t pin, bool R0 = false, bool R1 = false, bool autoTrigger = false, uint16_t prescaler = 0);
    void setPin(uint8_t pin);
    void setReference(bool R0, bool R1);
    void setAutoTrigger(bool autoTrigger);
    void setPrescaler(uint16_t prescaler);
    uint16_t getResult();
}

namespace timer {
    void init(bool overflow = false, uint16_t prescaler = 0);
    void setOverflow(bool overflow);
    void setPrescaler(uint16_t prescaler);
    void setTime(uint16_t value);
}