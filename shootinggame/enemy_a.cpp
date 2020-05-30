#include "enemy_a.h"
#include "global.h"

EnemyA::EnemyA()
{
	isDead = false;

	state = kInit;

	const int centerX = WINDOW_WIDTH / 2;
	const int rangeX = 400;
	const int tempX = (rand() % rangeX) - (rangeX / 2);
	posX = centerX + tempX;
	posY = -50;

	velX = 0;
	velY = 0;
}

void EnemyA::Update()
{
	switch (state)
	{
	case kInit:
		state = kMoveToPoint;
		velY = 130;
		break;
	case kMoveToPoint:
		UpdateMoveToPoint();
		break;
	case kChooseDirection:
		UpdateChooseDirection();
		break;
	case kMoveToFinish:
		UpdateMoveToFinish();
		break;
	}

	posX += velX * deltaTime;
	posY += velY * deltaTime;
}

void EnemyA::Render()
{
	TextureElement* enemyA = textureManager.GetTexture(2003);

	// Rendering of scene objects can happen here
	enemyA->sprite->Begin(D3DXSPRITE_ALPHABLEND);

	RECT srcRect;
	srcRect.left = 0;
	srcRect.top = 0;
	srcRect.bottom = 70;
	srcRect.right = 40;

	D3DXVECTOR3 pos(posX - 20, posY- 35, 0);
	enemyA->sprite->Draw(enemyA->texture, &srcRect, nullptr, &pos, D3DCOLOR_XRGB(255, 255, 255));

	enemyA->sprite->End();
}

bool EnemyA::IsDead()
{
	return isDead;
}

void EnemyA::UpdateMoveToPoint()
{
	if (posY > WINDOW_HEIGHT * 0.3)
	{
		state = kChooseDirection;
	}
}

void EnemyA::UpdateChooseDirection()
{
	const int randValue = rand() % 100;
	if (randValue > 50)
	{
		velX = -(80 + rand() % 200);
		velY *= 3;
	}
	else {
		velX = 80 + rand() % 200;
		velY *= 3;
	}

	state = kMoveToFinish;
}

void EnemyA::UpdateMoveToFinish()
{
	if (posX<0 || posX>WINDOW_WIDTH ||
		posY > WINDOW_HEIGHT)
	{
		isDead = true;
	}
}