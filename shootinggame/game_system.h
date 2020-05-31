#pragma once

#include <vector>

using namespace std;

class Bullet;
class Enemy;
class Player;
class SpriteEffect;

class GameSystem
{
public:
	Player* player;
	vector<Bullet*> bullets;
	vector<Enemy*> enemies;
	vector<SpriteEffect*> effects;

	GameSystem();

	void ClearAll();

	void GeneratePlayerBulletSpread(int x, int y);
	void GenerateEnemyA();
	void GenerateEnemyExplosionA(float x, float y);

	void Update();
	void Render();

	float enemyATime;
};