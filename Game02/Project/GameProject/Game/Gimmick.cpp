#include "Gimmick.h"
Gimmick::Gimmick(const CVector2D& pos) : Base(eType_Gimmick) {
	m_pos = pos;
	m_img.Load("Image/Inseki.png");
	m_img.SetSize(350, 500);

}

void Gimmick::Update()
{
}

void Gimmick::Draw()
{
	m_img.SetPos(m_pos);
	m_img.Draw();
}
