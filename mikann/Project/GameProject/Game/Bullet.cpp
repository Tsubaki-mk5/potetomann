#include "Bullet.h"
#include "Effect.h"
#include "GameData.h"


Bullet::Bullet(const CVector2D& pos):Base(eType_Bullet)
{
	m_img.Load("Image/Bullet.png");
	m_pos = pos;
	m_rad = 16;
	m_img.SetSize(32, 32);
	m_img.SetCenter(16, 16);
}

void Bullet::Update()
{
	const int move_speed = 4;
	m_pos.y -= move_speed;
}

void Bullet::Draw()
{
	m_img.SetPos(m_pos);
	m_img.Draw();

}
void Bullet::Collision(Base* b)
{
	switch (b->m_type) {
	case eType_Enemy:
		if (Base::CollisionCircle(this, b))
		{
			b->SetKill();
			SetKill();
			Base::Add(new Effect(b->m_pos));
			GameData::s_score += 100;
		}
		break;

	
	}
}
