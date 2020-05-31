#pragma once

#include "enemy.h"

class EnemyA : public Enemy
{
public:

	enum State
	{
		kInit,
		kMoveToPoint,
		kChooseDirection,
		kMoveToFinish
	};

	EnemyA();

	void Update() override;
	void Render() override;
	bool IsDead() override;
	float GetRadius() override;
	D3DXVECTOR2 GetPosition() override;
	void Hit(float damage) override;

	void UpdateMoveToPoint();
	void UpdateChooseDirection();
	void UpdateMoveToFinish();

	float posX;
	float posY;
	float velX;
	float velY;
	bool isDead;

	float hp;

	float damage;

	float hitTimer;

	State state;
};