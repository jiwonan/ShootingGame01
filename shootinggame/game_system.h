#pragma once

#include <vector>

using namespace std;

class Bullet;

class GameSystem
{
public:
	vector<Bullet*> bullets;

	void GeneratePlayerBulletSpread(int x, int y);

	void Update();
	void Render();
};