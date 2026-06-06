#include "EnemySpaceShip.cpp"

class Game {
private:
	SpaceShip *player;
	std::vector<EnemySpaceShip*> enemys;
	int n = 2;
	void addEnemy() {
		enemys.push_back(new EnemySpaceShip());
	}
public:
	Game() {
		player = new SpaceShip(20, 15);
	}
	~Game() {
		delete player;
		for (auto& enemy : enemys) {
			delete enemy;
		}
	}
	void update() {
		player->move();
		player->update();
		for (auto& enemy : enemys) {
			enemy->update();
		}

		for (auto& enemy : enemys) {
			player->checkCollision(enemy);
		}

		for (int i = 0; i < enemys.size(); i++) {
			if (enemys[i]->getHeath() <= 0) {
				enemys[i]->erase();
				delete enemys[i];
				enemys.erase(enemys.begin() + i);
			}
		}
		
		if (enemys.empty()) {
			for (int i = 0; i < n; i++) {
				addEnemy();
			}
			n++;
		}
	}
	void draw() { 
		Config::gotoxy(0, 0);
		std::cout << "                     ";
		Config::gotoxy(0, 0);
		std::cout << "So mang con lai: " << player->getHeath();
		player->draw();
		for (const auto& enemy : enemys) {
			enemy->draw();
		}
	}
};