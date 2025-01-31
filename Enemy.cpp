#include "Enemy.h"
#include<Novice.h>

int windowRight = 1280;
int windowLeft = 0;
int windowUp = 0;
int windowDown = 720;

Enemy::Enemy() {
	center_ = { 400.0f,300.0f };
	radius_ = 30.0f;
	speed_ = 5.0f;
	isALive_ = true;
}

Enemy::~Enemy() {
	isALive_ = false;
}

void Enemy::UpDate() {
	center_.x += speed_;
	if (center_.x > windowRight - radius_) {
		speed_ = -speed_;
	}
	if (center_.x < windowLeft + radius_) {
		speed_ = -speed_;
	}
}

void Enemy::Draw() {
	Novice::DrawEllipse(static_cast<int>(center_.x), static_cast<int>(center_.y), static_cast<int>(radius_), static_cast<int>(radius_),
		0.0f, GREEN, kFillModeSolid);
}
