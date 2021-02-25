// The Witch's Peculiar
// Being a Witch Lights sprite animation that plays on a shorter, denser pixel strip as part of a wearable garment.

#include <FastLED.h>
#include <config.h>
#include <SpriteManager.h>

#ifndef PSTR
#define PSTR // Make Arduino Due happy
#endif

CRGB leds[NUM_LEDS];

// Function prototypes:
void resetStrip(void);


// declare variables in scope

SpriteManager *spriteManager;

bool isBooted;
bool testSpritesCreated;
int starttime = millis();


void setup()
{
	// Initialize the SpriteManager object
	spriteManager = new SpriteManager();
	// Set up the led strip and paint it black.
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

