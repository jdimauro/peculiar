class Sprite {
	public:
		Sprite() {
			lastUpdateTime = 0;
			done = false;
		}

		virtual ~Sprite() {
		}

		virtual bool Update() = 0;

		bool allowCreation() {
				return true;		// Always true, no reason to veto this one.
		}

		boolean UpdateNow() {
			if (millis() - lastUpdateTime >= updateInterval) {
				lastUpdateTime = millis();
				return true;
			} else {
				return false;
			}
		}

		void MarkDone() {
				this->done = true;
		}

		bool IsDone() {
				return this->done;
		}

	protected:
		uint32_t lastUpdateTime;
		int updateInterval;
		boolean done;
};
