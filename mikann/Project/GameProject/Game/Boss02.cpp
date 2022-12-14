#include "Boss02.h"
#include "Effect.h"
#include "Bossbullet.h"
#include "BossWaza.h"
Boss02::Boss02(const CVector2D & pos) : Base(eType_Boss)
{
	m_img.Load("Image/su.png");
	m_pos = pos;
	m_rad = 50;
	m_img.SetSize(220, 220);
	m_img.SetCenter(110, 110);
	movedir = -1;
	m_hp = 500;
}
void Boss02::Update()
{
	m_cnt++;
	Base* b = Base::FindObject(eType_Player);
	if (b) {
		CVector2D vec = b->m_pos - m_pos;
		m_ang = atan2(vec.x, vec.y);
		if (m_cnt >= 50) {
			Base::Add(new Bossbullet(eType_Boss_bullet, m_pos, m_ang, 4));
			m_cnt = 0;
		}
	}
	if (b) {
		CVector2D vec = b->m_pos - m_pos;
		m_ang = atan2(vec.x, vec.y);
		if (m_cnt >= 100) {
			Base::Add(new BossWaza(eType_BossWaza, m_pos, m_ang, 4));
			m_cnt = 0;
		}
	}
	if (movedir == 1) {
		m_pos.x += 4;
		if (m_pos.x > 650) {
			movedir = -1;
		}
	}
	else {
		m_pos.x -= 4;
		if (m_pos.x < 50) {
			movedir = 1;
		}
	}


}

void Boss02::Draw()
{
	m_img.SetPos(m_pos);
	m_img.SetAng(m_ang);
	m_img.Draw();
}

void Boss02::Collision(Base* b)
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
