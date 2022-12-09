#include "Hittsatu.h"
#include "Effect.h"
#include "GameData.h"


Hittsatu::Hittsatu(const CVector2D& pos) :Base(eType_Hittsatu)
{
	m_img.Load("Image/tama.png");
	m_pos = pos;
	m_rad = 30;
	m_img.SetSize(150, 100);
	m_img.SetCenter(75, 50);
}

void Hittsatu::Update()
{
	const int move_speed = 4;
	m_pos.y -= move_speed;
}

void Hittsatu::Draw()
{
	m_img.SetPos(m_pos);
	m_img.Draw();

}
void Hittsatu::Collision(Base* b)
{
	switch (b->m_type) {
	case eType_Enemy :
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