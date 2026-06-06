

class DelayTime {
public:
	float time;
	float elapseTime = 0;
	DelayTime(float time) {
		this->time = time;
	}
	void reset() {
		elapseTime = 0;
	}
	bool update(float deltaTime) {
		elapseTime += deltaTime;
		if (elapseTime >= time) {
			elapseTime -= time;
			return true;
		}
		return false;
	}
};