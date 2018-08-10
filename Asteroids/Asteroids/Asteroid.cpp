#include "Asteroid.hpp"
#include "Game.hpp"
#include"Math.hpp"
#include"Random.hpp"
#include"SpriteComponent.hpp"
#include"MoveComponent.hpp"
#include"CircleComponent.hpp"
#include<iostream>
Asteroid::Asteroid(Game* game) : Actor(game)
{
	Vector2 randPos = Random::GetVector(Vector2::Zero, Vector2(1024.0f, 768.0f));
	SetPosition(randPos);
	SetRotation(Random::GetFloatRange(0.0f, Math::TwoPi));

	SpriteComponent* sc = new SpriteComponent(this);
	sc->SetTexture(game->GetTexture("Assets/Asteroid.png"));
	mMove = new MoveComponent(this);
	//mc->SetForwardSpeed(150.0f);
	mMove->SetMass(10.0f);
	mMove->AddForce(GetForward()*150.0f);
	mCircle = new CircleComponent(this);
	mCircle->SetRadius(40.0f);

	game->AddAsteroid(this);
}

Asteroid::~Asteroid()
{
	GetGame()->RemoveAsteroid(this);
}

void Asteroid::UpdateActor(float deltaTime)
{
	mMove->AddForce(GetForward() * 150.0f);
}
