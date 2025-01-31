#pragma once
#include<Vector2.h>
#include"Bullet.h"

class Player
{
public:
	Bullet* bullet_;
	
	float radius_;
	float speed_;
	float windowRight_;
	float windowLeft_;
	float windowUp_;
	float windowDown_;
public:
	Vector2 playerPos_;
	Player();
	~Player();
	void Update(char*keys,char*preKeys);
	void Draw();
};

//class Player
//{
//};

