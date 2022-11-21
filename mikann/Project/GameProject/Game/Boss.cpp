#include "Boss.h"
#include "Effect.h"
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
		m_pos.x += 4;
		if (m_pos.x > 550) {
			movedir = -1;
		}
	}
	else {
		m_pos.x -= 4;
		if (m_pos.x < 0) {
			movedir = 1;
		}
	}
	   
		
}

void Boss::Draw()
{
	m_img.SetPos(m_pos);
	m_img.Draw();
}

void Boss::Collision(Base* b)
{
	switch (b->m_type) {
	case eType_Bullet:
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
