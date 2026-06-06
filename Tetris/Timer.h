#pragma once


class Timer {
private:
	float time;
	float elapseTime;
	bool flag;
public:
	Timer(float time);
	void setTime(float time);
	void update(float deltaTime);
	bool isTime();
	void reset();
	void turnOn();
};