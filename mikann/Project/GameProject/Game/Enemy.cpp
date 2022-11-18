#include "Enemy.h"
#include "Effect.h"
Enemy::Enemy(const CVector2D& pos):Base(eType_Enemy)
{
	m_img.Load("Image/tako.png");
	m_pos = pos;
	m_cnt = 0;
	m_rad = 25;
	m_img.SetSize(1000, 1000);
	m_img.SetCenter(500, 500);

}

void Enemy::Update()
{
	const int move_speed = 32;
	m_cnt++;
	if (m_cnt >= 60) {
		m_pos.y += move_speed;
		m_cnt = 0;
	}
	}
	

void Enemy::Draw()
{
	m_img.SetPos(m_pos);
	m_img.Draw();
}

void Enemy::Collision(Base*b)
{
	switch (b->m_type) {
	case eType_Player:
		if (Base::CollisionCircle(this, b))
		{
			b->SetKill();
			SetKill();
			Base::Add(new Effect(b->m_pos));
	
		}
		break;
	}
}
