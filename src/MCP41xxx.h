/*
 MCP41xxx.h
 MCP41xxx driver for Arduino
 
 Copyright 2015-2016 Max Chan <max@maxchan.info>
 */

#ifndef _MCP41XXX_H_
#define _MCP41XXX_H_

#include <Arduino.h>

#ifndef DAC_SHUTDOWN
#define DAC_SHUTDOWN UINT16_MAX
#endif

/// Driver for Microchip MCP41xxx digi-pot.
class MCP41xxx
{
private:
    uint8_t _ss;
    
public:
    /*!
     Initialize the TLC5615 driver.
     
     @param ss GPIO pin used for the chip select for the DAC.
     */
    MCP41xxx(uint8_t ss);
    
    /*!
     Initialize the SPI bus and the DAC chip.
     */
    void begin(void);
    
	/*!
	 Write a value to the DAC chip.

	 @param value The DAC value. It is capped to 10 bits and excessive bits are
	 ignored.
	 */
	void analogWrite(uint16_t value);

    /*!
     Write a value to the DAC chip.
     
	 @param gate  The ID of the DAC.
     @param value The DAC value. It is capped to 10 bits and excessive bits are
     ignored.
     */
    void analogWrite(uint8_t gate, uint16_t value);
};

#endif // !defined(_TLC5615_H_)
