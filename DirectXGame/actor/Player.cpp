#include "Player.h"
#include "ImGuiManager.h"
#include "MathUtilityForText.h"
#include "Vector3.h"
#include <cassert>
#include <numbers>

void Player::Initialize(Model* model, ViewProjection* viewProjection) {

	// NULLポインタチェック
	assert(model);

	model_ = model;

	// ワールド変換の初期化
	worldTransform_.Initialize();
	worldTransform_.translation_.x = 1.0f;
	worldTransform_.translation_.y = 1.0f;
	worldTransform_.rotation_.y = std::numbers::pi_v<float> / 2.0f;
	viewProjection_ = viewProjection;
}

void Player::Update() { worldTransform_.UpdateMatrix(); }

void Player::Draw() {
	// 3Dモデルを描画
	model_->Draw(worldTransform_, *viewProjection_);
}
