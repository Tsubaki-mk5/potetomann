#include "Boss.h"

Boss::Boss(const CVector2D& pos) : Base(eType_Boss)
{
	m_img.Load("Image/sentouki.png");
	m_pos = pos;
	m_rad = 12;
	m_img.SetSize(220, 220);
	m_img.SetCenter(16, 16);
	movedir = -1;
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
