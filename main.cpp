#define _USE_MATH_DEFINES
#include <Novice.h>
#include<Player.h>
#include<Bullet.h>
#include"Enemy.h"
#include<math.h>
#include<assert.h>

const char kWindowTitle[] = "GC1B_02_イグチ‗トモヒロ＿タイトル";

bool Enemy::isALive_ = true;
Bullet* bullet = new Bullet;

// Windowsアプリでのエントリーポイント(main関数)
int WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR, int) {

	Player* player = new Player;
	Enemy* enemyA = new Enemy;
	Enemy* enemyB = new Enemy;

	// ライブラリの初期化
	Novice::Initialize(kWindowTitle, 1280, 720);
	
	// キー入力結果を受け取る箱
	char keys[256] = {0};
	char preKeys[256] = {0};

	enemyA->center_ = { 400.0f,200.00f };
	enemyB->center_ = { 800.0f,500.00f };

	// ウィンドウの×ボタンが押されるまでループ
	while (Novice::ProcessMessage() == 0) {
		// フレームの開始
		Novice::BeginFrame();

		// キー入力を受け取る
		memcpy(preKeys, keys, 256);
		Novice::GetHitKeyStateAll(keys);

		///
		/// ↓更新処理ここから
		///


		player->Update(keys,preKeys);
		
		if (enemyA != nullptr) {
			enemyA->UpDate();
		}
		if (enemyB != nullptr) {
			enemyB->UpDate();
		}
		
		//player->bullet_->radius_
		if (enemyA != nullptr && enemyB!=nullptr) {
			if (enemyA->radius_ + player->bullet_->radius_ >=
				sqrtf(powf(enemyA->center_.x - player->bullet_->pos_.x, 2.0f) + powf(enemyA->center_.y - player->bullet_->pos_.y, 2.0f)) ||
				enemyB->radius_ + player->bullet_->radius_ >=
				sqrtf(powf(enemyB->center_.x - player->bullet_->pos_.x, 2.0f) + powf(enemyB->center_.y - player->bullet_->pos_.y, 2.0f))) {
				Novice::DrawBox(0, 0, 1280, 720, 0.0f, BLACK, kFillModeSolid);
				Enemy::isALive_ = false;
				bullet->isShot_ = false;
			}
			if (!Enemy::isALive_) {
				delete enemyA;
				delete enemyB;
				enemyA = nullptr;
				enemyB = nullptr;
			}
		}

		///
		/// ↑更新処理ここまで
		///

		///
		/// ↓描画処理ここから
		///

		//Novice::DrawBox(0, 0, 1280, 720, 0.0f, BLACK, kFillModeSolid);
		player->Draw();

		
		if (enemyA != nullptr) {
			if (Enemy::isALive_) {
				enemyA->Draw();
			}
		}
		if (enemyB != nullptr) {
			if (Enemy::isALive_) {
				enemyB->Draw();
			}
		}

		///
		/// ↑描画処理ここまで
		///

		// フレームの終了
		Novice::EndFrame();

		// ESCキーが押されたらループを抜ける
		if (preKeys[DIK_ESCAPE] == 0 && keys[DIK_ESCAPE] != 0) {
			break;
		}
	}

	// ライブラリの終了
	Novice::Finalize();
	return 0;
}
