#pragma once

#include "Bullet.h"
#include "Timer.h"
#include "Sound.h"

#define PLAY_TIME 20.0

bool isShooting = false;
float c_shoot_time = 0.0;
float c_cool_time = 0.0;
int c_bullet_n = 0;

float c_posx = 0;
float c_posy = 0;
int c_rad;

bool CirclePatton_Shoot(float posx, float posy, int bull = 3, float cooltime = 1.0, int r = 3)
{
	Sound_PlayShootEffect();
	if (isShooting)
		return false;
	isShooting = true;
	c_posx = posx;
	c_posy = posy;
	c_bullet_n = bull;
	c_cool_time = cooltime;
	c_rad = r;
	c_shoot_time = Timer_Now();
	return true;
}

bool CirclePatton_Update( )
{
	static int circle_color = RED;
	float nowtime = Timer_Now();

	if (!isShooting)
		return false;

	
	if ( nowtime - c_shoot_time > c_cool_time)
	{
		if (c_bullet_n<=0)
		{
			isShooting = false;
			return false;
		}

		if (circle_color != VIORET)
			circle_color = VIORET;
		else
			circle_color = RED;
		Bullet_CirclePatton(c_posx, c_posy, c_rad, circle_color);
		
		--c_bullet_n;
	}
	return true;
}