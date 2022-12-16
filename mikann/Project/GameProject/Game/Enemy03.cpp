#include "Enemy03.h"
#include "Effect.h"
#include "../Base/Base.h"
Enemy03::Enemy03(const CVector2D& pos) :Base(eType_Enemy)
{
	m_img.Load("Image/Enemy03.png");
	m_pos = pos;
	m_rad = 12;
	m_img.SetSize(32, 32);
	m_img.SetCenter(16, 16);
	movedir = -1;
	m_hp = 40;
	m_cnt = 0;
	m_rad = 25;
	m_img.SetSize(100, 100);
	m_img.SetCenter(50, 50);

}

void Enemy03::Update()
{
	const int move_speed = 32;
	m_cnt++;
	if (m_cnt >= 60) {
		m_pos.y += move_speed;
		m_cnt = 0;
	}
}


void Enemy03::Draw()
{
	m_img.SetPos(m_pos);
	m_img.SetAng(m_ang);
	m_img.Draw();
}

void Enemy03::Collision(Base* b)
{
	switch (b->m_type) {
	case   eType_Bullet:
		if (Base::CollisionCircle(this, b))
		{
			b->SetKill();
			m_hp -= 20;
			if (m_hp <= 0) {
				SetKill();
			}
			Base::Add(new Effect(b->m_pos));

		}
		break;
	}
}
