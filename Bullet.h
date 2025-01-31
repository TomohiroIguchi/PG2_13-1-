#pragma once
#include"Vector2.h"

class Bullet
{
public:
	
	float radius_;
	float speed_;
	bool isShot_;
public:
	Vector2 pos_;
	Bullet();
	void Update();
	void Draw();
};

