#include "Bullet.h"
class Monster {
private:
	Bullet bullet_queue[BULLET_MAX];
public:
	Monster();
	void ShootPatton(float x, float y, float r, int color);
	void ShootUpdate();
};