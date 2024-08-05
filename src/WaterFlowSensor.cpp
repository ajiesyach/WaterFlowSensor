#include "WaterFlowSensor.h"

WaterFlowSensor* WaterFlowSensor::instance = nullptr;

WaterFlowSensor::WaterFlowSensor(uint8_t pin, SensorType type) : _pin(pin), _type(type) {
  _pulseCount = 0;
  _lastTime = 0;
  _flowRate = 0.0;
  _totalVolume = 0.0;
  setPulsePerLiter();
  instance = this;
}

void WaterFlowSensor::begin() {
  pinMode(_pin, INPUT_PULLUP);
  attachInterrupt(digitalPinToInterrupt(_pin), pulseCounter, RISING);
}

void IRAM_ATTR WaterFlowSensor::pulseCounter() {
  if (instance) {
    instance->_pulseCount++;
  }
}

float WaterFlowSensor::getFlowRate() {
  uint32_t currentTime = millis();
  uint32_t deltaTime = currentTime - _lastTime;

  if (deltaTime >= 1000) {
    noInterrupts();
    _flowRate = ((_pulseCount / _pulsePerLiter) / (deltaTime / 1000.0)) * 60.0;
    _totalVolume += _pulseCount / _pulsePerLiter;
    _pulseCount = 0;
    interrupts();
    
    _lastTime = currentTime;
  }

  return _flowRate;
}

float WaterFlowSensor::getTotalVolume() {
  return _totalVolume;
}

void WaterFlowSensor::reset() {
  _totalVolume = 0.0;
  _pulseCount = 0;
}

void WaterFlowSensor::setPulsePerLiter() {
  switch (_type) {
    case YF_S21:   _pulsePerLiter = 450.0;  break;
    case YF_S401:  _pulsePerLiter = 5880.0; break;
    case YF_B1:    _pulsePerLiter = 660.0;  break;
    case YF_B1_S:  _pulsePerLiter = 1077.0; break;
    case OF10ZAT:  _pulsePerLiter = 400.0;  break;
    case OF10ZZT:  _pulsePerLiter = 400.0;  break;
    case OF05ZAT:  _pulsePerLiter = 2174.0; break;
    case OF05ZZT:  _pulsePerLiter = 2174.0; break;
    default:       _pulsePerLiter = 450.0;  break;
  }
}
