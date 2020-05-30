#pragma once

#include <vector>

using namespace std;

class Bullet;
class Enemy;

class GameSystem
{
public:
	vector<Bullet*> bullets;
	vector<Enemy*> enemies;

	void GeneratePlayerBulletSpread(int x, int y);
	void GenerateEnemyA();

	void Update();
	void Render();

	float enemyATime;
};