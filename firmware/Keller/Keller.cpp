// NOTE/NUANCE: When including WITHIN a library, no sub-dir prefix is needed.
#include "Keller.h"

//
//Public Functions
//

// Constructor
Keller::4_9LD::4_9LD()
{
  Wire.begin(); 
}

byte Keller::4_9LD::getMeasurement(){ 
  // Request Measurement from Pressure Transmitter 
  Wire.beginTransmission(WR_ADDR);
  Wire.write(REQUEST_MEASUREMENT);
  Wire.endTransmission();

  //Wait for Converions to Complete (minium of 8ms) 
  delay(10); //delay 10 ms

  //Read Results
  Wire.requestFrom(RD_ADDR, MEASUREMENT_BUFFER_SIZE);

  for(byte i=0; i<MEASUREMENT_BUFFER_SIZE; i++){
    MeasurementBuffer[i] = Wire.read();
  }

  Wire.endTransmission();

  return MeasurementBuffer[0];
}

float Keller::4_9LD::getPressure(){
  int value = (MeasurementBuffer[1] << 8) | (MeasurementBuffer[2] << 0)
  return map(value, P_OUTPUT_MIN, P_OUTPUT_MAX, P_RANGE_MIN, P_RANGE_MAX) / 1.0;
}

float Keller::4_9LD::getTemperature(){
  int value = (MeasurementBuffer[3] << 8) | (MeasurementBuffer[4] << 0)
  return map(value, T_OUTPUT_MIN, T_OUTPUT_MAX, T_RANGE_MIN, T_RANGE_MAX) / 1.0;
}

byte Keller::4_9LD::getStatus(){
  return MeasurementBuffer[0];
}

//
//Private Functions
//
