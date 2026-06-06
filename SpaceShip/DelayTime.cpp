

class DelayTime {
public:
	int elapseTime = 0;
	int delayTime;
	DelayTime() {

	}
	DelayTime(int delayTime) {
		this->delayTime = delayTime;
	}
	bool checkTime(int detalTime) {
		if (elapseTime >= delayTime) {
			elapseTime = 0;
			return true;
		}
		elapseTime += detalTime;
		return false;
	}
	void setDelayTime(int time) {
		delayTime = time;
	}
};