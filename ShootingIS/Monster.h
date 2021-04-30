#pragma once

#include "Render.h"
#include "CirclePatton.h"


#define ORDERPOS_MAX 3

struct Pos
{
	float x;
	float y;
};

Pos monsPos = { SCREEN_WIDTH / 2 ,SCREEN_HEIGHT / 3 };
float mob_speed = 120 * delta_time;
int monsterSize = 7;

Pos orderPoses [ORDERPOS_MAX]= {{ 7 ,SCREEN_HEIGHT / 3 },{ SCREEN_WIDTH -7 ,SCREEN_HEIGHT / 3 } ,{ SCREEN_WIDTH / 2 ,SCREEN_HEIGHT / 4 } };
int orderInd = 0;

void Monster_InWindow()
{
	float haf = monsterSize / 2;
	if (monsPos.x >= SCREEN_WIDTH - haf)
		monsPos.x = SCREEN_WIDTH - 1 - haf;
	if (monsPos.y >= SCREEN_HEIGHT - haf)
		monsPos.y = SCREEN_HEIGHT - 1 - haf;
	if (monsPos.x <  haf)
		monsPos.x = haf - 1;
	if (monsPos.y <  haf)
		monsPos.y = haf - 1;
}
void Monster_SetPosition(int x, int y)
{
	monsPos.x = x;
	monsPos.y = y;

	Monster_InWindow();
	print(monsPos.x, monsPos.y, "( & & )", WHITE);
}
void Monster_Init()
{
	Monster_SetPosition(50, 10);
}

bool Monster_OrderToMove(Pos destPos)
{
	static Pos destinationPos = { 0,-9913 };
	static Pos startPos = { 0, -923};
	static float dt = 0.0;
	static float len;
	static float lenx;
	static float leny;

	if ((int)destinationPos.x != (int)destPos.x || (int)destinationPos.y != (int)destPos.y)
	{
		dt = 0.0;
		destinationPos = destPos;
		startPos = monsPos;
		len = sqrt((destPos.x - monsPos.x) * (destPos.x - monsPos.x) + (destPos.y - monsPos.y)*(destPos.y - monsPos.y));
		lenx = (destPos.x - monsPos.x);
		leny = (destPos.y - monsPos.y);
	}

	dt += mob_speed / len;
	if (dt > 1.0)
	{
		monsPos = destPos;
		dt = 0.0;
		return false;
	}
	monsPos.x = startPos.x + lenx * dt;
	monsPos.y = startPos.y +  leny * dt;
	
	return true;
}
void Monster_Update()
{
	if (!Monster_OrderToMove(orderPoses[orderInd]))
	{
		CirclePatton_Shoot(monsPos.x, monsPos.y, 1, 0.5, 8);
		++orderInd;
		if (orderInd >= ORDERPOS_MAX)
			orderInd = 0;
	}
	CirclePatton_Shoot(monsPos.x, monsPos.y, 3, 0.5, 2);
	Monster_SetPosition(monsPos.x, monsPos.y);	
}