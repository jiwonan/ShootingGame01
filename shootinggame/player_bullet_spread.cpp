#include "player_bullet_spread.h"
#include "global.h"

PlayerBulletSpread::PlayerBulletSpread(int x, int y, float vx, float vy)
{
	posX = x;
	posY = y;
	velX = vx;
	velY = vy;

    isDead = false;
}

void PlayerBulletSpread::Update()
{
	posX += velX;
	posY += velY;

    if (posX<0 || posX>WINDOW_WIDTH ||
        posY<0 || posY>WINDOW_HEIGHT)
    {
        isDead = true;
    }
}

void PlayerBulletSpread::Render()
{
    TextureElement* bullet = textureManager.GetTexture(GAME_PLAYER_BULLET_1);

    // Rendering of scene objects can happen here
    bullet->sprite->Begin(D3DXSPRITE_ALPHABLEND);

    RECT srcRect;
    srcRect.left = 0;
    srcRect.top = 0;
    srcRect.bottom = 11;
    srcRect.right = 11;

    D3DXVECTOR3 pos(posX - 5, posY - 5, 0);
    bullet->sprite->Draw(bullet->texture, &srcRect, nullptr, &pos, D3DCOLOR_XRGB(255, 255, 255));

    bullet->sprite->End();
}

bool PlayerBulletSpread::IsDead()
{
    return isDead;
}