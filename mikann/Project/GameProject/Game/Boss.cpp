#include "Boss.h"
#include "Effect.h"
#include "Bossbullet.h"
#include "BossWaza.h"
Boss::Boss(const CVector2D& pos) : Base(eType_Boss)
{
	m_img.Load("Image/sentouki.png");
	m_pos = pos;
	m_rad = 50;
	m_img.SetSize(220, 220);
	m_img.SetCenter(110, 110);
	movedir = -1;
	m_hp = 500;
}
void Boss::Update()
{
	if (movedir == 1) {
		m_pos.x += 10;
		if (m_pos.x > 1000) {
			movedir = -1;
		}
	}
	else {
		m_pos.x -= 10;
		if (m_pos.x < 50) {
			movedir = 1;
		}
	}
	m_cnt++;
	const float move_speed = 0;
	Base* player = Base::FindObject(eType_Player);
	if (player) {
		CVector2D vec = player->m_pos - m_pos;
		m_ang = atan2(vec.x, vec.y);
		if (m_cnt >= 50) {
			Base::Add(new Bossbullet(eType_Boss_bullet, m_pos, m_ang, 4));
			m_cnt = 0;
		}
		m_ang = atan2(vec.x, vec.y);
		if (m_cnt >= 100) {
			Base::Add(new BossWaza(eType_BossWaza, m_pos, m_ang, 4));
			m_cnt = 0;
		}
	}
}

void Boss::Draw()
{
	m_img.SetPos(m_pos);
	m_img.SetAng(m_ang);
	m_img.Draw();
}

void Boss::Collision(Base* b)
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
	case   eType_Hittsatu:
		if (Base::CollisionCircle(this, b))
		{
			b->SetKill();
			m_hp -= 250;
			if (m_hp <= 0) {
				SetKill();
			}
			Base::Add(new Effect(b->m_pos));

		}
		break;
	}
}
