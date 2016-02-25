// 
// 4_9LD.h
// Library for Keller's 4LD...9LD pressure transducers
// Based on original library published by Luca Dentella (http://www.lucadentella.it)
// Writen by Tim Hall @ EO Labs Feb 2016
//

#include "application.h"

#ifndef _KELLER_H
#define _KELLER_H

#define MEASUREMENT_BUFFER_SIZE 5

#define P_OUTPUT_MIN 16384
#define P_OUTPUT_MAX 49152
#define P_RANGE_MIN 0
#define P_RANGE_MAX 10

#define T_OUTPUT_MIN 384
#define T_OUTPUT_MAX 64384
#define T_RANGE_MIN -50
#define T_RANGE_MAX 80

//Default LD I2C address
#define LD_ADDRESS  0x40

#define RD_ADDR (LD_ADDRESS << 1) + 1
#define WR_ADDR (LD_ADDRESS << 1) + 0

//COMMAND definitions
#define REQUEST_MEASUREMENT   0xAC

namespace Keller
{
  class 4_9LD
  {
    public:
      // variables

      // functions
      4_9LD();
      byte getMeasurement();
      float getPressure();
      float getTemperature();
      byte getStatus();
    private:
      // variables
      byte MeasurementBuffer[MEASUREMENT_BUFFER_SIZE];
      // functions
  };
}

#endif
