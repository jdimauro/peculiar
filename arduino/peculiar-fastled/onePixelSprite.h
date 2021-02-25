class onePixelSprite : public Sprite {
	private:
		int currentPixel;
		CRGB color;

	public:
		onePixelSprite() {
				this->currentPixel = -1;
				this->color = CRGB::White;
		}

		onePixelSprite(int startPixel, CRGB startColor) {
				// Minus one because we'll increment it as the first step in Update().
				this->currentPixel = startPixel - 1;
				this->color = startColor;
		}

		~onePixelSprite() {
		}

		boolean UpdateNow() {
			if (millis() - lastUpdateTime >= TEST_PATTERN_V_MS) {
				lastUpdateTime = millis();
				return true;
			} else {
				return false;
			}
		}

		bool Update() {
			if (this->UpdateNow()) {
				currentPixel++;

				if (currentPixel >= NUM_LEDS) {
						leds[currentPixel - 1] = CRGB::Black;
						this->MarkDone();
				}

				leds[currentPixel] = this->color;
				if (currentPixel > 0) {
						leds[currentPixel - 1] = CRGB::Black;
				}

				return true;
			}

			return false;
		}
};