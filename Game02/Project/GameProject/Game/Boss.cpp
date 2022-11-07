#include "Boss.h"

Boss::Boss(const CVector2D& pos) : Base(eType_Boss)
{
	m_img.Load("Image/Boss.png");
	m_pos = pos;
	m_rad = 12;
	m_img.SetSize(32, 32);
	m_img.SetCenter(16, 16);
}
void Boss::Update()
{
	

}

void Boss::Draw()
{
	m_img.SetPos(m_pos);
	m_img.Draw();
}
