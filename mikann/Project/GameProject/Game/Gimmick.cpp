#include "Gimmick.h"
#include "../Base/Base.h"
#include "Effect.h"
#include <stdlib.h>
//d—Í‰Á‘¬“x
#define GRAVITY	(1.0f/70)

Gimmick::Gimmick(const CVector2D& pos) : Base(eType_Gimmick) {
	
		
	
	
	m_pos = pos;
	m_img0.Load("Image/Inseki.png");
	m_img0.SetSize(350, 500);
	m_img0.SetCenter(120, 120);
	m_rad = 56;
	m_img1.Load("Image/Akikann.png"); 
	m_img1.SetSize(200, 200);
	m_img1.SetCenter(60, 60);
		
	
}

void Gimmick::Update()
{
	m_vec.y += GRAVITY;
	m_pos += m_vec;
	
}

void Gimmick::Draw()
{
	m_img0.SetPos(m_pos);
	m_img0.Draw();
	m_img1.SetPos(m_pos);
	m_img1.Draw();
	
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
