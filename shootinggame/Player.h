#pragma once

class Player
{
public:
	Player();
	void Update();
	void Render();

	float PlayerX;
	float PlayerY;
	float speed;
};