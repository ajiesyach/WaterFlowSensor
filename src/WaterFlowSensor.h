#ifndef WATER_FLOW_SENSOR_H
#define WATER_FLOW_SENSOR_H

#include <Arduino.h>

enum SensorType {
  YF_S21,
  YF_S401,
  YF_B1,
  YF_B1_S,
  OF10ZAT,
  OF10ZZT,
  OF05ZAT,
  OF05ZZT
};

class WaterFlowSensor {
  public:
    WaterFlowSensor(uint8_t pin, SensorType type);
    void begin();
    float getFlowRate();
    float getTotalVolume();
    void reset();
    static void IRAM_ATTR pulseCounter();

  private:
    uint8_t _pin;
    SensorType _type;
    volatile uint32_t _pulseCount;
    uint32_t _lastTime;
    float _flowRate;
    float _totalVolume;
    float _pulsePerLiter;

    static WaterFlowSensor* instance;

    void setPulsePerLiter();
};

#endif
