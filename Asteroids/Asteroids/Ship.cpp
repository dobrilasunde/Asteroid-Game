#include"Ship.hpp"
#include"Game.hpp"
#include"SpriteComponent.hpp"
#include"InputComponent.hpp"
#include"Laser.hpp"
#include"CircleComponent.hpp"
#include"Asteroid.hpp"
#include<iostream>

Ship::Ship(Game* game) : Actor(game), mLaserCooldown(0.0f)
{
	SpriteComponent* sc = new SpriteComponent(this, 150);
	sc->SetTexture(game->GetTexture("Assets/Ship.png"));

	mInput = new InputComponent(this);
	mInput->SetForwardKey(SDL_SCANCODE_W);	
	mInput->SetBackKey(SDL_SCANCODE_S);
	mInput->SetClockwiseKey(SDL_SCANCODE_A);
	mInput->SetCounterClockwiseKey(SDL_SCANCODE_D);
	mInput->SetMaxForwardSpeed(300.0f);
	mInput->SetMaxAngularSpeed(Math::TwoPi);

	mCircle = new CircleComponent(this);
	mCircle->SetRadius(50.0f);
}

void Ship::UpdateActor(float deltaTime)
{
	mLaserCooldown -= deltaTime;

	for (auto ast : GetGame()->GetAsteroids())
	{
		if (Intersect(*mCircle, *ast->GetCircle()))
		{
			SetPosition(Vector2(512.0f, 384.0f));
			SetRotation(Math::PiOver2);
			mInput->SetVelocity(Vector2::Zero);
			break;
		}
	}
}

void Ship::ActorInput(const uint8_t* keyState)
{
	if (keyState[SDL_SCANCODE_SPACE] && mLaserCooldown <= 0.0f)
	{
		Laser* laser = new Laser(GetGame());
		laser->SetPosition(GetPosition());
		laser->SetRotation(GetRotation());

		mLaserCooldown = 0.5f;
	}
}