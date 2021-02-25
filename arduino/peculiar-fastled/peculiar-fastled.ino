// The Witch's Peculiar
// Being a Witch Lights sprite animation that plays on a shorter, denser pixel strip as part of a wearable garment.


// Libraries
#include <FastLED.h>
#include <config.h>
CRGB leds[NUM_LEDS];					// leds is the virtual representation of the LED strip

// Internal Stuff
#include <Sprite.h>
#include <SpriteVector.h>
#include <SpriteManager.h>
#include <onePixelSprite.h>

#ifndef PSTR
#define PSTR // Make Arduino Due happy
#endif


// Function prototypes:
void resetStrip(void);


// Make room for objects:
SpriteManager *spriteManager;	// spriteManager is the little engine at the heart of the state machine loop

// Declare global variables:
bool isBooted = false;								// when true, we've done a system self-test; this and the next could probably be put someplace better than a global, huh?
bool testSpritesCreated = false;			
int starttime = millis();			// start the relative clock; probably something we could handle better?


void setup()
{
	// Initialize the SpriteManager object:
	spriteManager = new SpriteManager();
	// Set up the led strip and paint it black.
	resetStrip();
}

void loop()
{
	if (! isBooted) {
		if (! testSpritesCreated) {
			spriteManager->Add(new W1V1Sprite(10, 0x750787));
			spriteManager->Add(new W1V1Sprite( 8, 0x004dff));
			spriteManager->Add(new W1V1Sprite( 6, 0x008026));
			spriteManager->Add(new W1V1Sprite( 4, 0xffed00));
			spriteManager->Add(new W1V1Sprite( 2, 0xff8c00));
			spriteManager->Add(new W1V1Sprite( 0, 0xe40303));

			testSpritesCreated = true;
		}

		spriteManager->Update();

		if (spriteManager->SpriteCount() == 0) {
			isBooted = true;
		}

		return;
	}
}

void resetStrip() 
{
	FastLED.addLeds<NEOPIXEL, NEOPIXEL_DATA_PIN>(leds, NUM_LEDS);

	for (int i = 0; i < NUM_LEDS; i++) {
		leds[i] = CRGB::Black;
	}

	FastLED.show();
}

