class SpriteManager {
	private:
		boolean updatedSomething = false;
		SpriteVector* spriteVector;

	public:
		SpriteManager() {
				spriteVector = new SpriteVector(MAXSPRITES);
		}

		~SpriteManager() {
			 // Don't bother. Should never be called.
		}

		int SpriteCount() {
			return spriteVector->Count();
		}

		void Update() {
				updatedSomething = false;

				for (int i = 0; i < this->SpriteCount(); i++) {
						updatedSomething |= spriteVector->Get(i)->Update();
				}

				if (updatedSomething) {
						FastLED.show();
				}

				this->Clean();
		}

		bool Add(Sprite *newSprite) {
			bool x = spriteVector->Add(newSprite);
			return x;
		}

		// Garbage collection. Remove any sprites that have finished their animation
		// from the SpriteVector, in order to make room for others.
		void Clean() {
				for (int i = this->SpriteCount() - 1; i >= 0; i--) {
						if (spriteVector->Get(i)->IsDone()) {
								spriteVector->RemoveAt(i);
						}
				}
		}
};
