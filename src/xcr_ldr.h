#ifndef XCR_LDR_H
#define XCR_LDR_H

#include <Arduino.h>

#ifdef __cplusplus
extern "C" {
    #endif

    typedef struct {
        uint8_t pin;
        float vref;
        float A;
        float B;
    } XCR_LDR_t;

    void XCR_LDR_init(XCR_LDR_t *ldr, uint8_t pin, float vref, float A, float B);
    int XCR_LDR_readRaw(XCR_LDR_t *ldr);
    float XCR_LDR_readVoltage(XCR_LDR_t *ldr);
    float XCR_LDR_getLux(XCR_LDR_t *ldr);

    #ifdef __cplusplus
}
#endif

#endif
