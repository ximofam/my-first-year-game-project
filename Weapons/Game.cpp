#include "Character.h"
#include "Enemy.h"



class Game {
private:
	Character* player;
	vector<Enemy*> enemys;
	bool isEnemyInGunRange(Enemy* enemy, Gun* gun) {
		return MagnitudeSqrt(Subtract(enemy->getPosition(), gun->getPosition())) <= gun->getRange() * gun->getRange();
	}
public:
	Game() {
		player = new Character({ 400, 400 }, 400);
	}
	~Game() {
		delete player;
		for (auto& enemy : enemys) {
			delete enemy;
		}
	}

	void input() {
		player->input();

		if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON)) {
			enemys.push_back(new Enemy(GetMousePosition(), 100));
		}
	}

	void update(float deltaTime) {
		input();

		player->update(deltaTime);

		Gun* gun = player->getGun();
		for (auto& enemy : enemys) {
			if (isEnemyInGunRange(enemy, gun)) {
				gun->shoot(NormalizeVector(Subtract(enemy->getPosition(), gun->getPosition())));
			}
		}

		if (gun->isOutOfAmmo()) {
			gun->reload();
		}


		for (auto& enemy : enemys) {
			enemy->setDirection(NormalizeVector(Subtract(player->getPosition(), enemy->getPosition())));
			enemy->update(deltaTime);
		}

	}

	void render() {

		player->draw();


		for (auto enemy : enemys) {
			enemy->draw();
		}
	}

};