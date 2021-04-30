#pragma once

#include "Render.h"
#include "Sound.h"
#include "Bullet.h"
int player_x = SCREEN_WIDTH / 2;
int player_y = SCREEN_HEIGHT - 2;
void Player_Init()
{
}
void Player_Move()
{
	if (GetAsyncKeyState(VK_LEFT) < 0)
	{
		if (!InWindow(--player_x, player_y))
			player_x++;
	}
	else if (GetAsyncKeyState(VK_RIGHT) < 0)
	{
		if(!InWindow(++player_x, player_y))
			player_x--;
	}
	if (GetAsyncKeyState(VK_UP) < 0)
	{
		if(!InWindow(player_x,--player_y))
			player_y++;
	}
	else if (GetAsyncKeyState(VK_DOWN) < 0)
	{
		if (!InWindow(player_x, ++player_y))
			player_y--;
	}
}

bool Player_Update()
{
	Player_Move();
	print(player_x, player_y, "¢¾", GREEN);
	
	if (Bullet_isColide(player_x, player_y))
	{
		return false;
	}
	return true;
}