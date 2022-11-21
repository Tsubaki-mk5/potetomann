#include "Enemy.h"
#include "Effect.h"
#include"Bullet.h"
Enemy::Enemy(const CVector2D& pos):Base(eType_Enemy)
{
	m_img.Load("Image/Enemy.png");
	m_pos = pos;
	m_cnt = 0;
	m_rad = 12;
	m_img.SetSize(32, 32);
	m_img.SetCenter(16, 16);
	m_hp = 500;
}

void Enemy::Update()
{
	const int move_speed = 32;
	m_cnt++;
	if (m_cnt >= 60) {
		m_pos.y += move_speed;
		m_cnt = 0;
	}
	Base* b = Base::FindObject(eType_Player);
	if (b) {
		CVector2D vec = b->m_pos - m_pos;
		m_ang = atan2(vec.x, vec.y);
		if (m_cnt >= 120) {
			Base::Add(new Bullet(eType_Enemy_Bullet, m_pos, m_ang, 4));
			m_cnt = 0;
		}
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
	case eType_Player_Bullet:
		if (Base::CollisionCircle(this, b))
		{
			b->SetKill();
			m_hp -=20;
			if (m_hp >=0);
			SetKill();
			Base::Add(new Effect(b->m_pos));
	
		}
		break;
	}
}
