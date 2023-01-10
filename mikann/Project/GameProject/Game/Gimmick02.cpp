#include "Gimmick02.h"
#include "../Base/Base.h"
#include "Effect.h"
#include "Boss02.h"
//d—Í‰Á‘¬“x
#define GRAVITY	(5.0f/70)

Gimmick02::Gimmick02(const CVector2D& pos) : Base(eType_Gimmick02) {

	m_pos = pos;
	m_img.Load("Image/Inseki.png");
	m_img.SetSize(350, 500);
	m_img.SetCenter(100, 170);
	m_rad = 35;
	int cnt = 0;
	

}

void Gimmick02::Update()
{
	m_vec.y += GRAVITY;
	m_pos += m_vec;

}

void Gimmick02::Draw()
{
	m_img.SetPos(m_pos);
	m_img.Draw();

}

void Gimmick02::Collision(Base* b)
{
	switch (b->m_type) {
	case eType_Player:
		if (Base::CollisionCircle(this, b))
		{
			b->SetKill();
			SetKill();
			Base::Add(new Effect(b->m_pos));
			break;
		}
	}
}
