#pragma once
#include <Sprite.h>

class Fade {
public:

	enum class Status {
		None,
		FadeIn,
		FadeOut,
	};

	~Fade();

	void Initialize();

	void Update();

	void Draw(ID3D12GraphicsCommandList* commandList);

	void Start(Status status, float duration);

	void Stop();

	bool IsFinished() const;

	Status GetStatus() const { return status_; }

private:
	Sprite* sprite_ = nullptr;
	Status status_ = Status::None;
	float duration_ = 0.0f;
	float counter_ = 0.0f;
};
