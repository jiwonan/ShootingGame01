#include "game_first_stage.h"
#include "global.h"
#include "game_background.h"

GameFirstStage::GameFirstStage()
{
    gameSystem.player = &player;

    gameSystem.ClearAll();
    gameSystem.GameStartLevelOne();
}
void GameFirstStage::Update()
{
    background.Update();
    player.Update();
    gameSystem.Update();
}
void GameFirstStage::Render()
{
    background.Render();
    player.Render();
    gameSystem.Render();
}