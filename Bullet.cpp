#include "Bullet.h"
#include"Player.h"
#include<Novice.h>

Bullet::Bullet() {
	pos_ = { 640.0f,360.0f };
	radius_ = 10.0f;
	speed_ = 10.0f;
	isShot_ = false;
};
/// <summary>
///発射処理
/// </summary>
void Bullet::Update() {
	if (isShot_) {
		pos_.y -= speed_;
	}
	if (pos_.y <= 0.0f) {
		isShot_ = false;
		pos_ = { 640.0f,360.0f };
	}
};
/// <summary>
/// 描画処理
/// </summary>
void Bullet::Draw() {
	if (isShot_) {
		Novice::DrawEllipse(static_cast<int>(pos_.x), static_cast<int>(pos_.y), static_cast<int>(radius_), static_cast<int>(radius_),
			0.0f, WHITE, kFillModeSolid);
	}
};
