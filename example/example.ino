#include "xcr_ldr.h"

XCR_LDR_t leftLDR;
XCR_LDR_t rightLDR;

void setup() {
    Serial.begin(9600);
    XCR_LDR_init(&leftLDR, A0, 5.0, 1.2e8, -1.45);
    XCR_LDR_init(&rightLDR, A1, 5.0, 1.1e8, -1.40);
}

void loop() {
    float luxL = XCR_LDR_getLux(&leftLDR);
    float luxR = XCR_LDR_getLux(&rightLDR);

    Serial.print("Left: ");
    Serial.print(luxL, 2);
    Serial.print(" lx\tRight: ");
    Serial.print(luxR, 2);
    Serial.println(" lx");

    delay(1000);
}
