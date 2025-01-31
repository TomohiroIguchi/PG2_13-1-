#include"Player.h"
#include<Novice.h>
#include"Bullet.h"

bool call = false;

Player::Player() {
	bullet_ = new Bullet;
	playerPos_ = { 640.0f,360.0f };
	radius_ = 20.0f;
	speed_ = 8.0f;
	windowRight_ = 1280.0f;
	windowLeft_ = 0.0f;
	windowUp_ = 0.0f;
	windowDown_ = 720.0f;
};
/// <summary>
/// デストラクタ　（delete)
/// </summary>
Player::~Player() {
	delete bullet_;
};
/// <summary>
///発射処理
/// </summary>
void Player::Update(char*keys,char*preKeys) {
	if (playerPos_.x + radius_ < windowRight_ && keys[DIK_D]) {
		playerPos_.x += speed_;
	}
	if (playerPos_.x - radius_ > windowLeft_ && keys[DIK_A]) {
		playerPos_.x -= speed_;
	}

	if (playerPos_.y - radius_ > windowUp_ && keys[DIK_W]) {
		playerPos_.y -= speed_;
	}
	if (playerPos_.y + radius_ < windowDown_ && keys[DIK_S]) {
		playerPos_.y += speed_;
	}
	
	if (keys[DIK_SPACE] && !preKeys[DIK_SPACE] && !bullet_->isShot_) {
		bullet_->isShot_ = true;
		bullet_->pos_.x = playerPos_.x;
		bullet_->pos_.y = playerPos_.y;
	}
	bullet_->Update();

};
/// <summary>
/// 描画処理
/// </summary>
void Player::Draw() {
	Novice::DrawEllipse(static_cast<int>(playerPos_.x), static_cast<int>(playerPos_.y), static_cast<int>(radius_), static_cast<int>(radius_),
		0.0f, RED, kFillModeSolid);
	bullet_->Draw();
};
