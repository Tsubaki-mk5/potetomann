#include "Bossbullet03.h"
#include "Effect.h"
#include "GameData.h"

Bossbullet03::Bossbullet03(int type, const CVector2D& pos, float ang, float speed) :Base(type)
{
	if (type == eType_Boss_bullet03)
		m_img = COPY_RESOURCE("Bossbullet03", CImage);
	m_pos = pos;
	m_ang = ang;
	m_img.SetSize(80, 80);
	m_speed = speed;
	m_img.SetCenter(16, 16);
}

void Bossbullet03::Update()
{
	m_vec = CVector2D(sin(m_ang), cos(m_ang)) * m_speed;
	m_pos += m_vec;
}

void Bossbullet03::Draw()
{
	m_img.SetPos(m_pos);
	m_img.SetAng(m_ang);
	m_img.Draw();

}
void Bossbullet03::Collision(Base* b)
{
	switch (b->m_type) {
		//case eType_Player:
		if (m_type == eType_Boss_bullet03 && Base::CollisionCircle(this, b)) {
			SetKill();

		}
	}
}
