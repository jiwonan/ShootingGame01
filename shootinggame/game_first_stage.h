#pragma once

#include "stage.h"
#include "game_background.h"
#include "Player.h"

class GameFirstStage : public Stage
{
public:
	GameFirstStage();
	void Update() override;
	void Render() override;

	GameBackground background;
	Player player;
};