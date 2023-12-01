#ifndef __DEVICE__
#define __DEVICE__

#include <Wire.h>
#include "trace.h"

class Device
{
public:
	inline void setup()
    {
        Wire.begin();
    }
	inline void loop()
    {
        findI2CDevice();
    }
    inline void findI2CDevice()
    {
        byte error, address;
        int nDevices;
        EspTrace.printf("Scanning...\n");
        nDevices = 0;
        for(address = 1; address < 127; address++ )
        {
            // The i2c_scanner uses the return value of
            // the Write.endTransmisstion to see if
            // a device did acknowledge to the address.
            Wire.beginTransmission(address);
            error = Wire.endTransmission();

            if (error == 0)
            {
                EspTrace.print("I2C device found at address 0x");
                if (address<16)
                    EspTrace.print("0");
                EspTrace.print(address,HEX);
                EspTrace.println(" !");

                nDevices++;
            }
            else if (error==4)
            {
                EspTrace.print("Unknow error at address 0x");
                if (address<16)
                    EspTrace.print("0");
                EspTrace.println(address,HEX);
            }
        }
        if (nDevices == 0)
            EspTrace.printf("No I2C devices found\n");
        else
            EspTrace.printf("done\n");
        delay(5000); // wait 5 seconds for next scan
    }
	Device(){}
private:
	
};

#endif //__DEVICE_