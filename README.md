# XCR-LDR

A lightweight, Arduino library for reading light intensity (lux) from LDR (photoresistor) sensors using calibration constants.

---
<img width="883" height="857" alt="image" src="https://github.com/user-attachments/assets/776e64f7-2e8e-427b-b654-4929feedfc5e" />

## 🌟 Features

* Object-like handling (multiple LDRs independently)
* Lux calculation using empirical calibration constants `A` and `B`
* Tiny, portable, and fast

---


## 🧪 Example

```cpp
#include "xcr_ldr.h"

XCR_LDR_t sensor;

void setup() {
    Serial.begin(9600);
    XCR_LDR_init(&sensor, A0, 5.0, 1.2e8, -1.45);
}

void loop() {
    float lux = XCR_LDR_getLux(&sensor);
    Serial.print("Lux: ");
    Serial.println(lux);
    delay(1000);
}
```

---

## ⚙️ Calibration

Use constants `A` and `B` derived from fitting the LDR's response curve to:

```
lux = A * (rawADC)^B
```
