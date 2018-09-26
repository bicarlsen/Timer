//Flash two LEDs at different rates using Simon Monk's Timer library
//http://www.doctormonk.com/2012/01/arduino-timer-library.html
//
//Jack Christensen 30Sep2013
//
//Beerware license: Free for any and all purposes, but if you find it
//useful AND we actually meet someday, you can buy me a beer!

#include "Timer.h"                     //http://github.com/JChristensen/Timer

const int LED1 = 8;                    //connect one LED to this pin (with appropriate current-limiting resistor of course)
const int LED2 = 9;                    //connect another LED to this pin (don't forget the resistor)
const unsigned long PERIOD1 = 1000;    //one second
const unsigned long PERIOD2 = 10000;   //ten seconds
const unsigned int  COUNT = 3;
Timer t;                               //instantiate the timer object

void setup(void)
{
    pinMode(LED1, OUTPUT);
    pinMode(LED2, OUTPUT);
    t.cycle(LED1, PERIOD1, PERIOD2, HIGH); // on for PERIOD1, off for PERIOD2
    t.cycle(LED2, PERIOD2, PERIOD1, HIGH, COUNT); // on for PERIOD2, off for PERIOD1, runs for COUNT cycles
}

void loop(void)
{
    t.update();
}
