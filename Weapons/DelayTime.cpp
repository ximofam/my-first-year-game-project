#include "DelayTime.h"

DelayTime::DelayTime(float time) {
	this->time = time;
	elapseTime = 0;
}

DelayTime::~DelayTime() {

}

void DelayTime::update(float deltaTime) {
	elapseTime += deltaTime;

	if (elapseTime >= time) {
		isTime = true;
		elapseTime = 0;
	}
}