#include "Hittsatu.h"
#include "Effect.h"
#include "GameData.h"
static TexAnim _animation_[] = {
	{ 0,1 },
	{ 1,1 },
	{ 2,1 },
	{ 3,1 },
	{ 4,1 },
	{ 5,1 },
	{ 6,1 },
	{ 7,1 },
};
TexAnimData _anim_data[] = {
	ANIMDATA(_animation_),
};

Hittsatu::Hittsatu(const CVector2D& pos) :Base(eType_Hittsatu)
{
	m_img.Load("Image/tama.png",_anim_data,96,96);
	m_img.ChangeAnimation(0);
	m_pos = pos;
	m_rad = 30;
	m_img.SetSize(150, 100);
	m_img.SetCenter(75, 50);
}

void Hittsatu::Update()
{
	const int move_speed = 4;
	m_pos.y -= move_speed;
	m_img.UpdateAnimation();

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