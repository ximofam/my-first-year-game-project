#include "Gun.h"

Gun::Gun() {
	resetState();
	range = 250;
	reloadTime = new DelayTime(1.5);
	shootTime = new DelayTime(0.1);
}

Gun::~Gun() {
	for (auto& bullet : bullets) {
		delete bullet;
	}

	delete shootTime;
	delete reloadTime;

	cout << "Da giai phong sung\n";
}

void Gun::resetState() {
	numberOfBullets = 50;
}


void Gun::shoot(Vector2 direction) {
	if (reloadTime->isTime && shootTime->isTime && numberOfBullets > 0) {
		bullets.push_back(new Bullet(position, direction, range));
		numberOfBullets--;
		shootTime->isTime = false;
	}
}

void Gun::reload() {
	if (reloadTime->isTime)
		reloadTime->isTime = false;
}

void Gun::update(float deltaTime) {
	for (auto& bullet : bullets) {
		bullet->update(deltaTime);
	}

	for (int i = bullets.size() - 1; i >= 0; i--) {
		if (bullets[i]->isActive() == false) {
			delete bullets[i];
			bullets.erase(bullets.begin() + i);
		}
	}

	if (reloadTime->isTime == false) {
		reloadTime->update(deltaTime);
		if (reloadTime->isTime) resetState();
	}

	if (shootTime->isTime == false) {
		shootTime->update(deltaTime);
	}
}

void Gun::draw() {
	DrawCircleLinesV(position, range, GREEN);

	DrawText(TextFormat("Ammo: %d", numberOfBullets), GetScreenWidth() * 0.75, GetScreenHeight() - 30, 30, GREEN);

	if (reloadTime->isTime == false) {
		DrawText(TextFormat("Reloading: %.1f s", reloadTime->time - reloadTime->elapseTime), GetScreenWidth() * 0.40, GetScreenHeight() - 30, 30, GREEN);
	}

	for (auto& bullet : bullets) {
		bullet->draw();
	}

}

void Gun::setPosition(Vector2 pos) {
	position = pos;
}

float Gun::getRange() {
	return range;
}

vector<Bullet*> Gun::getBullets() {
	return bullets;
}

Vector2 Gun::getPosition() {
	return position;
}

bool Gun::isOutOfAmmo() {
	return numberOfBullets == 0;
}