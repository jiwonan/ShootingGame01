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

	void UpdateMoveToPoint();
	void UpdateChooseDirection();
	void UpdateMoveToFinish();

	float posX;
	float posY;
	float velX;
	float velY;
	bool isDead;

	State state;
};