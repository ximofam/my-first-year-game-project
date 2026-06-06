

class DelayTime {
public:
	int elapseTime = 0;
	int time;
	DelayTime(int time) {
		this->time = time;
	}

	void reset() {
		elapseTime = 0;
	}

	bool update(int deltaTime) {

		elapseTime += deltaTime;

		if (elapseTime >= time) {
			elapseTime -= time;
			return true;
		}
		
		return false;
	}
};