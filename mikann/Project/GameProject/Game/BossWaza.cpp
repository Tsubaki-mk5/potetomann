#include "BossWaza.h"
BossWaza::BossWaza(int type, const CVector2D& pos, float ang, float speed) : Base(type)
{
	if (type == eType_BossWaza)
		m_img = COPY_RESOURCE("BossWaza", CImage);
	m_pos = pos;
	m_ang = ang;
	m_img.SetSize(30, 30);
	m_speed = speed;
	m_img.SetCenter(16, 16);
}

void BossWaza::Update()
{
	m_vec = CVector2D(sin(m_ang), cos(m_ang)) * m_speed;
	m_pos += m_vec;
}

void BossWaza::Draw()
{
	m_img.SetPos(m_pos);
	m_img.SetAng(m_ang);
	m_img.Draw();

}
void BossWaza::Collision(Base* b)
{
	switch (b->m_type) {
	case eType_Player:
		if (m_type == eType_BossWaza && Base::CollisionCircle(this, b)) {
			SetKill();
			b->SetKill();
		}
	}
}