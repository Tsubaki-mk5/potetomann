#include "Gimmick.h"
#include "../Base/Base.h"
#include "Effect.h"
//d—Í‰Á‘¬“x
#define GRAVITY	(1.0f/70)

Gimmick::Gimmick(const CVector2D& pos) : Base(eType_Gimmick) {
	m_pos = pos;
	m_img.Load("Image/Inseki.png");
	m_img.SetSize(350, 500);
	m_img.SetCenter(40,40);
	m_rad =60;

}

void Gimmick::Update()
{
	m_vec.y += GRAVITY;
	m_pos += m_vec;
}

void Gimmick::Draw()
{
	m_img.SetPos(m_pos);
	m_img.Draw();
}

void Gimmick::Collision(Base* b)
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
