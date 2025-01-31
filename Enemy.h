#pragma once
#include<Vector2.h>

class Enemy
{
protected:
public:
	Enemy();
	~Enemy();
	Vector2 center_;
	float radius_;
	float speed_;
	static bool isALive_;
	void UpDate();
	void Draw();
};

