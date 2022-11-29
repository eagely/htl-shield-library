#include "Arduino.h"
#include "Wire.h"
// Lord forgive me for what I am about to code
class I2C {
public:
    uint8_t port;
    explicit I2C(uint8_t port);

    void begin() {
        Wire.begin();
    }
    void write(uint16_t value) {
        Wire.beginTransmission(port);
        Wire.write(value);
        Wire.endTransmission();
    }
};

