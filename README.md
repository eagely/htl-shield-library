# htl-shield-library 

## How to add library to your project:

### platformio.ini
```
lib_deps =
    "htl-shield"
```

### main.cpp
If you need ADC and Timer Interrupt functions:
```
#include "../lib/htl-shield-library/include/universal.h"
```
If you need I2C functions:
```
#include "../lib/htl-shield-library/include/I2C.h"
```