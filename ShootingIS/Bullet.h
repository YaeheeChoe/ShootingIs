#pragma once
#include <math.h>
#include "Render.h"
struct Bullet
{
	float x;
	float y;
	float dx;
	float dy;
	bool life;
	int color;
};

#define BULLET_MAX 500
Bullet bullet_queue[BULLET_MAX];
int bullet_top = 0;
float bullet_speed = 0.3;
#define PI 3.1415926535
//여기부터 bullet 객체
void Bullet_create(float x, float y, float dx, float dy, int color = RED)
{
	bullet_queue[bullet_top].life = true;
	bullet_queue[bullet_top].x = x;
	bullet_queue[bullet_top].y = y;
	bullet_queue[bullet_top].dx = dx;
	bullet_queue[bullet_top].dy = dy;
	bullet_queue[bullet_top].color = color;
	++bullet_top;
	if (bullet_top > BULLET_MAX - 1)
		bullet_top = 0;
}


void Bullet_Init()
{
	int i;
	for (i = 0; i < BULLET_MAX; i++)
	{
		bullet_queue[i].x = -1;
		bullet_queue[i].y = -1;
		bullet_queue[i].dx = 0;
		bullet_queue[i].dy = 0;
		bullet_queue[i].life = false;
	}
}
bool Bullet_isColide(int x, int y)
{
	int i;
	for (i = 0; i < BULLET_MAX; i++)
	{
		if (!bullet_queue[i].life)
			continue;
		if ((int)bullet_queue[i].x == x && (int)bullet_queue[i].y == y)
			return true;
	}
	return false;
}
//
void Bullet_CirclePatton(float x, float y,  float r = 1.0, int color = RED)
{
	float alpha;
	float delta = PI / 18;

	for (alpha = 0.0; alpha <= 2 * PI; alpha += delta )
	{
		Bullet_create(x + r*cos(alpha), y + r* sin(alpha), cos(alpha) * bullet_speed, sin(alpha)*bullet_speed, color);
	}
}

void Bullet_Update()
{
	int i;
	for (i = 0; i < BULLET_MAX; i++)
	{
		if (bullet_queue[i].life == true)
		{
			bullet_queue[i].x = bullet_queue[i].x + bullet_queue[i].dx;
			bullet_queue[i].y = bullet_queue[i].y + bullet_queue[i].dy;

 			if (!InWindow(bullet_queue[i].x, bullet_queue[i].y))
			{
				bullet_queue[i].life = false;
			}
			else
			{
				print(bullet_queue[i].x, bullet_queue[i].y, "@", bullet_queue[i].color);
			}
		}
	}
}