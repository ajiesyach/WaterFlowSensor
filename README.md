# WaterFlowSensor Library

Library ini dirancang untuk mengukur aliran air menggunakan berbagai jenis sensor aliran air yang kompatibel dengan Arduino, ESP32, dan ESP8266.

## Fitur

- Mendukung berbagai jenis sensor aliran air (YF-S21, YF-S401, YF-B1, YF-B1-S, OF10ZAT, OF10ZZT, OF05ZAT, OF05ZZT)
- Kompatibel dengan Arduino, ESP32, dan ESP8266
- Menghitung laju aliran dalam liter per menit
- Menghitung total volume air yang mengalir
- Menggunakan interrupt untuk akurasi pengukuran yang lebih baik

## Instalasi

1. Unduh repository ini sebagai file ZIP.
2. Di Arduino IDE, pergi ke Sketch > Include Library > Add .ZIP Library, lalu pilih file ZIP yang telah diunduh.
3. Atau, ekstrak file ZIP ke folder `libraries` di direktori Arduino Anda.

## Penggunaan

### Contoh Dasar

```cpp
#include "WaterFlowSensor.h"

#define FLOW_SENSOR_PIN 2  // Ganti dengan pin yang Anda gunakan

WaterFlowSensor flowSensor(FLOW_SENSOR_PIN, YF_S21);  // Ganti YF_S21 dengan tipe sensor yang Anda gunakan

void setup() {
  Serial.begin(115200);
  flowSensor.begin();
}

void loop() {
  float flowRate = flowSensor.getFlowRate();
  float totalVolume = flowSensor.getTotalVolume();

  Serial.print("Flow rate: ");
  Serial.print(flowRate);
  Serial.print(" L/min, Total volume: ");
  Serial.print(totalVolume);
  Serial.println(" L");

  delay(1000);
}
