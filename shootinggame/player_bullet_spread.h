#pragma once

#include "Bullet.h"

class PlayerBulletSpread : public Bullet
{
public:
	PlayerBulletSpread(int x, int y, float vx, float vy);

	void Update() override;
	void Render() override;

	float posX;
	float posY;

	float velX;
	float velY;
};