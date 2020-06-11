#include "boss_bullet_a.h"
#include "global.h"

BossBulletA::BossBulletA(float x, float y, float vx, float vy)
{
	isDead = false;

	posX = x;
	posY = y;
	velX = vx;
	velY = vy;
}


void BossBulletA::Update()
{
	posX += velX;
	posY += velY;

	if (posX<0 || posX>WINDOW_WIDTH ||
		posY<0 || posY>WINDOW_HEIGHT)
	{
		isDead = true;
	}

}

void BossBulletA::Render()
{

	TextureElement* bossBulletA=  textureManager.GetTexture(GAME_ENEMY_BOSS_A_BULLET_1);

	bossBulletA->sprite->Begin(D3DXSPRITE_ALPHABLEND);

	RECT srcRect;
	srcRect.left = 0;
	srcRect.top = 0;
	srcRect.bottom = 18;
	srcRect.right = 18;

	D3DXVECTOR3 pos(posX - 9, posY - 9, 0);
	D3DCOLOR spriteColor = D3DCOLOR_XRGB(255, 255, 255);

	bossBulletA->sprite->Draw(bossBulletA->texture, &srcRect, nullptr, &pos, spriteColor);


	bossBulletA->sprite->End();

}

bool BossBulletA::IsDead()
{
	return isDead;
}

float BossBulletA::GetRadius()
{
	return 9.0f;
}

D3DXVECTOR2 BossBulletA::GetPosition()
{
	return D3DXVECTOR2(posX, posY);
}

void BossBulletA::Hit()
{
	isDead = true;
}