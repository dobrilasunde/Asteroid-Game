#pragma once

#include "Actor.hpp"

class Ship : public Actor
{
public:
	Ship(class Game* game);

	void UpdateActor(float deltaTime) override;
	void ActorInput(const uint8_t* keyState) override;

	class CircleComponent* GetCircle() { return mCircle; }

private:
	float mLaserCooldown;
	class CircleComponent* mCircle;
	float mSeconds;
	bool mDisappear;
};
