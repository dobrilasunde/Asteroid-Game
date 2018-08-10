#pragma once

#include"Component.hpp"
#include"Math.hpp"
class MoveComponent : public Component
{
public:
	MoveComponent(class Actor* owner, int updateOrder = 10);

	void Update(float deltaTime) override;

	float GetAngularSpeed() { return mAngularSpeed; }
	float GetForwardSpeed() { return mForwardSpeed; }
	void SetAngularSpeed(float speed) { mAngularSpeed = speed; }
	void SetForwardSpeed(float speed) { mForwardSpeed = speed; }

	void SetMass(float mass) { mMass = mass; }
	float GetMass() const { return mMass; }
	void SetVelocity(Vector2 velocity) { mVelocity = velocity; }
	void AddForce(const Vector2& force) { mSumOfForces += force; }
private:
	float mAngularSpeed;
	float mForwardSpeed;
	float mMass;
	Vector2 mSumOfForces;
	Vector2 mVelocity;
};