#include "Laser.hpp"
#include "SpriteComponent.hpp"
#include "MoveComponent.hpp"
#include "Game.hpp"
#include "CircleComponent.hpp"
#include "Asteroid.hpp"

Laser::Laser(Game* game) : Actor(game), mDeathTimer(1.0f)
{
	SpriteComponent* sc = new SpriteComponent(this);
	sc->SetTexture(game->GetTexture("Assets/Laser.png"));
	mMove = new MoveComponent(this);
	mMove->SetMass(0.5f);

	mCircle = new CircleComponent(this);
	mCircle->SetRadius(11.0f);
}

void Laser::UpdateActor(float deltaTime)
{
	mMove->AddForce(GetForward()*500.0f);

	mDeathTimer -= deltaTime;
	if (mDeathTimer <= 0.0f)
	{
		SetState(EDead);
	}
	else
	{
		for (auto ast : GetGame()->GetAsteroids())
		{
			if (Intersect(*mCircle, *ast->GetCircle()))
			{
				SetState(EDead);
				ast->SetState(EDead);
				break;
			}
		}
	}
}