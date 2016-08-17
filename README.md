# MCP41xxx Arduino driver

Created & maintained by Max Chan.

## Introduction

This driver interfaces the microcontroller with the Microchip MCP41xxx/42xxx
digital potentiometers and MCP43xxx/44xxx digital rheostats.

## Device addressing

This driver supports a daisy-chained string of digi-pots sharing a single chip
select line. Device 0 is the first pot on the chip closest to the MCU. Only
MCP42xxx and MCP44xxx can daisy chain, but MCP41xxx and MCP43xxx can be at the
end of a chain.

When using a lone MCP41xxx/43xxx digi-pot, you can call `analogWrite` without
the device address.

## Shutdown Mode

Those digi-pots can enter shut down mode. To enter this mode, write
`DAC_SHUTDOWN` into the pot. Writing any other value will take the gate out of
shutdown mode as long as it is not inhibited by the hardware shutdown line on
MCP42xxx/44xxx.

## Using the Driver

The driver uses a similar syntax as the default PWM outputs, albeit with an
object.

```Arduino
#include <MCP41xxx.h>

MCP41xxx dac(10);

void setup(void)
{
  dac.begin();
}

void loop(void)
{
  dac.analogWrite(0, millis());
}
```

## License

This library is licensed under the 3-clause BSD license.
