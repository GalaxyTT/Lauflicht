#include "gpio.h"
#include <lgpio.h>

Gpio::Gpio(QObject *parent) : QObject(parent)
{
    m_handle = lgGpiochipOpen(CHIP);

    for(int pin : LEDS)
        lgGpioClaimOutput(m_handle, FLAGS, pin, 0); /* initial level 0 */
}

void Gpio::set(int pin, bool state)
{
    lgGpioWrite(m_handle, pin, state);
}

int Gpio::get(int pin)
{
    return lgGpioRead(m_handle, pin);
}

