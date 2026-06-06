#pragma once


class DelayTime {
public:
	float time;
	float elapseTime;
	bool isTime = false;

	DelayTime(float time);
	~DelayTime();

	void update(float deltaTime);
};