#include <Arduino.h>

#include "emulator/emulator.h"

extern "C" int IsKBHit() {
    int ret = Serial.available() ? 1 : 0;
    return ret;
}

extern "C" int ReadKBByte() {
    if (Serial.available()) {
        int ret = Serial.read();
        return ret;
    }
    return 0xffffffff;
}

void setup() {
    Serial.begin(115200);

    psramInit();

    Serial.printf("Total heap: %d\n", ESP.getHeapSize());
    Serial.printf("Free heap: %d\n", ESP.getFreeHeap());
    Serial.printf("Total PSRAM: %d\n", ESP.getPsramSize());
    Serial.printf("Free PSRAM: %d\n", ESP.getFreePsram());
    Serial.flush();


    // put your setup code here, to run once:
    riscv_emu();
}

void loop() {
    // put your main code here, to run repeatedly:
}
