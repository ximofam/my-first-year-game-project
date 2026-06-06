#include "Timer.h"

Timer::Timer(float t) {
	time = t;
	reset();
}

void Timer::setTime(float t) {
	time = t;
}

void Timer::update(float dt) {
	elapseTime += dt;
	if (elapseTime >= time) {
		elapseTime -= time;
		flag = true;
	}
}

void Timer::reset() {
	elapseTime = 0;
	turnOn();
}

bool Timer::isTime() {
	return flag;
}

void Timer::turnOn() {
	flag = false;
}
