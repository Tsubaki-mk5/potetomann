#include "Boss.h"

Boss::Boss(const CVector2D& p, bool flip) : Base(eType_Boss) {
	m_img = COPY_RESOURCE("Boss", CImage);
	m_img.ChangeAnimation(0);
	m_pos = p;
	m_img.SetCenter(480, 480);
	m_img.SetSize(500, 500);
	m_rect = CRect(-350, -250, 0, 0);
	m_rad = 270;
	m_flip = flip;
	m_is_ground = false;
	m_hp = 500;
}

void Boss::Update()
{
	
}

void Boss::Draw()
{
	m_img.SetPos(GetScreenPos(m_pos));
	m_img.SetFlipH(m_flip);
	m_img.Draw();
	DrawRect();

	
}

void Boss::Collision(Base* b)
{
}
