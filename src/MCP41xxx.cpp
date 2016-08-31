/*
 MCP41xxx.cpp
 MCP41xxx driver for Arduino
 
 Copyright 2015-2016 Max Chan <max@maxchan.info>
 */

#include "MCP41xxx.h"
#include <SPI.h>

MCP41xxx::MCP41xxx(uint8_t ss)
{
    _ss = ss;
}

void MCP41xxx::begin(void)
{
    // Prepare SPI hardware.
    SPI.begin();
    
    // Prepare SPI SS line
    digitalWrite(_ss, 1);
    pinMode(_ss, OUTPUT);
}

void MCP41xxx::analogWrite(uint16_t value)
{
	analogWrite(0, value);
}

void MCP41xxx::analogWrite(uint8_t gate, uint16_t value)
{

	// Prepare SPI data;
	if (value == DAC_SHUTDOWN)
	{
		value = 0x2000;
	}
	else
	{
		value &= 0xff;
		value |= 0x1000;
	}

	value |= (gate & 0x1) ? 0x200 : 0x100;
    
    // Assert SPI bus
    digitalWrite(_ss, 0);
    
    // Perform SPI Transfer
    SPI.beginTransaction(SPISettings(10000000, MSBFIRST, SPI_MODE0));

	uint8_t zeros = gate >> 1;
	for (uint8_t idx = 0; idx < zeros; idx++)
	{
		// Send zeros to bypass irelevant chips
		SPI.transfer16(0);
	}
	SPI.transfer16(value);

    SPI.endTransaction();
    
    // Deassert SPI bus
    digitalWrite(_ss, 1);
}

