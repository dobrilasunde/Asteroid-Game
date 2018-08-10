#include"InputComponent.hpp"
#include"Actor.hpp"

InputComponent::InputComponent(Actor* owner): MoveComponent(owner), mForwardKey(0), mBackKey(0), mClockwiseKey(0), mCounterClockwiseKey(0) 
{
	SetMass(5.0f);
}

void InputComponent::ProcessInput(const uint8_t* keyState)
{
	float forwardSpeed = 0.0f;
	if (keyState[mForwardKey])
	{
		forwardSpeed += mMaxForwardSpeed;
	}
	if (keyState[mBackKey])
	{
		forwardSpeed -= mMaxForwardSpeed;
	}
	AddForce(mOwner->GetForward()*forwardSpeed);
	//SetForwardSpeed(forwardSpeed);
	

	float angularSpeed = 0.0f;
	if (keyState[mClockwiseKey])
	{
		angularSpeed += mMaxAngularSpeed;
	}
	if (keyState[mCounterClockwiseKey])
	{
		angularSpeed -= mMaxAngularSpeed;
	}
	SetAngularSpeed(angularSpeed);

}