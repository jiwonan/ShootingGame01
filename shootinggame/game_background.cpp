#include "game_background.h"
#include "global.h"

GameBackground::GameBackground()
{
    BackgroundY = 0;
}

void GameBackground::Update()
{
    BackgroundY += 0.05f;
}

void GameBackground::Render()
{
    TextureElement* background = textureManager.GetTexture(GAME_BACKGROUND);

    // Rendering of scene objects can happen here
    background->sprite->Begin(D3DXSPRITE_ALPHABLEND);

    RECT srcRect;
    srcRect.left = 0;
    srcRect.top = 0;
    srcRect.bottom = 680;
    srcRect.right = 640;

    D3DXVECTOR3 pos(0, BackgroundY, 0);
    background->sprite->Draw(background->texture, &srcRect, nullptr, &pos, D3DCOLOR_XRGB(255, 255, 255));

    pos = D3DXVECTOR3(0, BackgroundY - srcRect.bottom, 0);
    background->sprite->Draw(background->texture, &srcRect, nullptr, &pos, D3DCOLOR_XRGB(255, 255, 255));

    background->sprite->End();
}