#include "WaterFlowSensor.h"

#define FLOW_SENSOR_PIN 34  // Ganti dengan pin yang Anda gunakan

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
