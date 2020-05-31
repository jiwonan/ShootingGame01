#pragma once

#include <vector>

using namespace std;

class Bullet;
class Enemy;
class Player;

class GameSystem
{
public:
	Player* player;
	vector<Bullet*> bullets;
	vector<Enemy*> enemies;

	GameSystem();

	void ClearAll();

	void GeneratePlayerBulletSpread(int x, int y);
	void GenerateEnemyA();

	void Update();
	void Render();

	float enemyATime;
};