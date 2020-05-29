#include "Player.h"
#include "global.h"

Player::Player()
{

}

void Player::Update()
{

}

void Player::Render()
{
    TextureElement* player = textureManager.GetTexture(GAME_PLAYER_BODY);

    // Rendering of scene objects can happen here
    player->sprite->Begin(D3DXSPRITE_ALPHABLEND);

    RECT srcRect;
    srcRect.left = 0;
    srcRect.top = 0;
    srcRect.bottom = 680;
    srcRect.right = 640;

    D3DXVECTOR3 pos(0, 0, 0);
    player->sprite->Draw(player->texture, &srcRect, nullptr, &pos, D3DCOLOR_XRGB(255, 255, 255));

    player->sprite->End();
}