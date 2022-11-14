#include "Boss.h"

Boss::Boss(const CVector2D& pos) : Base(eType_Boss)
{
	m_img.Load("Image/sentouki.png");
	m_pos = pos;
	m_rad = 12;
	m_img.SetSize(120, 120);
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
