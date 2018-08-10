#include"MoveComponent.hpp"
#include"Actor.hpp"
#include<iostream>
MoveComponent::MoveComponent(Actor* owner, int updateOrder): Component(owner, updateOrder), mAngularSpeed(0.0f), mForwardSpeed(0.0f), mSumOfForces(Vector2::Zero), mMass(0.0f), mVelocity(Vector2::Zero) {}

void MoveComponent::Update(float deltaTime)
{
	if (!Math::NearZero(mAngularSpeed))
	{
		float rot = mOwner->GetRotation();
		rot += mAngularSpeed * deltaTime;
		mOwner->SetRotation(rot);
	}

		Vector2 acceleration = Vector2(mSumOfForces.x / mMass, mSumOfForces.y / mMass);
		mVelocity += acceleration * deltaTime;

		Vector2 pos = mOwner->GetPosition();
		pos += mVelocity * deltaTime;

		if (pos.x < 0.0f) { pos.x = 1022.0f; }
		else if (pos.x > 1024.0f) { pos.x = 2.0f; }

		if (pos.y < 0.0f) { pos.y = 766.0f; }
		else if (pos.y > 768.0f) { pos.y = 2.0f; }

		mOwner->SetPosition(pos);

		mSumOfForces = Vector2::Zero;
	
}