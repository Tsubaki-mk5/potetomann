#include "Bossbullet.h"
#include "Effect.h"
#include "GameData.h"

Bossbullet::Bossbullet(int type, const CVector2D& pos, float ang, float speed):Base(type)
{
	if (type == eType_Boss_bullet) 
		m_img = COPY_RESOURCE("Bossbullet", CImage);
	m_pos = pos;
	m_ang = ang;
	m_img.SetSize(30, 30);
	m_speed = speed;
	m_img.SetCenter(16, 16);
}

void Bossbullet::Update()
{
	m_vec = CVector2D(sin(m_ang), cos(m_ang)) * m_speed;
	m_pos += m_vec;
}

void Bossbullet::Draw()
{
	m_img.SetPos(m_pos);
	m_img.SetAng(m_ang);
	m_img.Draw();

}
void Bossbullet::Collision(Base* b)
{
	switch (b->m_type) {
	case eType_Player:
		if (m_type == eType_Boss_bullet && Base::CollisionCircle(this, b)) {
			SetKill();
			b->SetKill();
		}
	}
}