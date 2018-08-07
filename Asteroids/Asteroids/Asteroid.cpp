#include "Asteroid.hpp"
#include "Game.hpp"
#include"Math.hpp"
#include"Random.hpp"
#include"SpriteComponent.hpp"
#include"MoveComponent.hpp"

Asteroid::Asteroid(Game* game) : Actor(game)
{
	Vector2 randPos = Random::GetVector(Vector2::Zero, Vector2(1024.0f, 768.0f));
	SetPosition(randPos);
	SetRotation(Random::GetFloatRange(0.0f, Math::TwoPi));

	SpriteComponent* sc = new SpriteComponent(this);
	sc->SetTexture(game->GetTexture("Assets/Asteroid.png"));
	MoveComponent* mc = new MoveComponent(this);
	mc->SetForwardSpeed(150.0f);
}

Asteroid::~Asteroid()
{
	
}