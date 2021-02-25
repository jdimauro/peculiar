// The Witch's Peculiar
// Being a Witch Lights sprite animation that plays on a shorter, denser pixel strip as part of a wearable garment.

#include <FastLED.h>
#include <config.h>


#ifndef PSTR
#define PSTR // Make Arduino Due happy
#endif

CRGB leds[NUM_LEDS];

// Function prototypes:
void resetStrip(void);



void setup()
{
	resetStrip();
}

void loop()
{
	
}

void resetStrip() 
{
		FastLED.addLeds<NEOPIXEL, NEOPIXEL_DATA_PIN>(leds, NUM_LEDS);

		for (int i = 0; i < NUM_LEDS; i++) {
			leds[i] = CRGB::Black;
		}

		FastLED.show();
}

