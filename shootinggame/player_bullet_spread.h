#pragma once

#include "Bullet.h"

class PlayerBulletSpread : public Bullet
{
public:
	PlayerBulletSpread(int x, int y, float vx, float vy);

	void Update() override;
	void Render() override;
	bool IsDead() override;
	float GetRadius() override;
	D3DXVECTOR2 GetPosition() override;
	bool Hit() override;

	float posX;
	float posY;

	float velX;
	float velY;
	bool isDead;
};