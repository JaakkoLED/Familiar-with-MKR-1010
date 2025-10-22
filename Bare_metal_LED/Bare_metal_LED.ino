PA20 = D6
PA10 = D2

#include "sam.h"
#define LED_PIN 20 // D6 → PA20 
#define INPUT_PIN 10 // D2 → PA10

void setup()
{

// Enable the APB clock for the PORT module (pakollinen)
PM->APBBMASK.reg |= PM_APBBMASK_PORT;

//Port Goup A- pins
// Configure LED_PIN as OUTPUT (set bit in DIRSET)
PORT->Group[0].DIRSET.reg = (1 << LED_PIN);

//Port Goup A- pins
// Configure INPUT_PIN as INPUT (clear bit in DIRCLR)
PORT->Group[0].DIRCLR.reg = (1 << INPUT_PIN);
}


void loop()
{
// Turn LED ON
//OUTSET = output set
PORT->Group[0].OUTSET.reg = (1 << LED_PIN);
delay(500);

//OUTCLR = output clear 
// Turn LED OFF
PORT->Group[0].OUTCLR.reg = (1 << LED_PIN);
delay(500);
}
