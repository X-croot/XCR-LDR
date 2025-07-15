#include "xcr_ldr.h"
#include <math.h>

void XCR_LDR_init(XCR_LDR_t *ldr, uint8_t pin, float vref, float A, float B) {
    ldr->pin = pin;
    ldr->vref = vref;
    ldr->A = A;
    ldr->B = B;
    pinMode(pin, INPUT);
}

int XCR_LDR_readRaw(XCR_LDR_t *ldr) {
    return analogRead(ldr->pin);
}

float XCR_LDR_readVoltage(XCR_LDR_t *ldr) {
    int raw = analogRead(ldr->pin);
    return ((float)raw * ldr->vref) / 1023.0f;
}

float XCR_LDR_getLux(XCR_LDR_t *ldr) {
    int raw = analogRead(ldr->pin);
    if (raw <= 0) return 0.0f;
    return ldr->A * powf((float)raw, ldr->B);
}
