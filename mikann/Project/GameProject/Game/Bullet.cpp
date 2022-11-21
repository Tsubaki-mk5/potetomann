#include "Bullet.h"
#include "Effect.h"
#include "GameData.h"


Bullet::Bullet(int type,const CVector2D& pos,float ang, float speed):Base(eType_Bullet)
{
	if (type == eType_Player_Bullet)
		m_img = COPY_RESOURCE("Bullet", CImage);
	else
		m_img = COPY_RESOURCE("Bullet2", CImage);
	m_pos = pos;
	m_rad = 16;
	m_img.SetSize(32, 32);
	m_img.SetCenter(16, 16);
}

void Bullet::Update()
{
	m_vec = CVector2D(sin(m_ang), cos(m_ang)) * m_speed;
	m_pos += m_vec;
}

void Bullet::Draw()
{
	m_img.SetPos(m_pos);
	m_img.Draw();

}
void Bullet::Collision(Base* b) {
	switch (b->m_type) {
	case eType_Player:
		if (m_type == eType_Enemy_Bullet && Base::CollisionCircle(this, b)) {
			SetKill();
			b->SetKill();
		}
		break;
	case eType_Enemy:
		if (m_type == eType_Player_Bullet && Base::CollisionCircle(this, b)) {
			SetKill();
			b->SetKill();
		}
		break;
	}

}