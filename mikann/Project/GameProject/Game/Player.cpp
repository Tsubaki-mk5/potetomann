#include "Player.h"
#include "Bullet.h"
#include"Gauge.h"
#include"Effect.h"
#include"Hittsatu.h"

Player::Player(const CVector2D& pos) : Base(eType_Player)
{
	m_img.Load("Image/Player.png");
	m_pos = pos;
	m_rad = 12;
	m_img.SetSize(32, 32);
	m_img.SetCenter(16, 16);
	m_count = 0;
	Base::Add(m_gauge = new Gauge(0));
	m_hp = m_max_hp = 1000;
	hama = 1;
}
Player::~Player(){
	if (m_gauge)
		m_gauge->SetKill();
	kaiten = false;
	movedir = -1;
	m_hp = 100;
}
void Player::Update()
{
	const int move_speed = 5;
	if (HOLD(CInput::eRight))
		m_pos.x += move_speed;
	if (HOLD(CInput::eUp))
		m_pos.y -= move_speed;
	if (HOLD(CInput::eDown))
		m_pos.y += move_speed;
	if (HOLD(CInput::eLeft))
		m_pos.x -= move_speed;
	if (PUSH(CInput::eButton4))
		kaiten = true;
	if (kaiten) {
		m_ang += DtoR(10);
		if (m_ang >= DtoR(360)) {
			m_ang = 0;
			kaiten = false;
		}
	}
		
	if (PUSH(CInput::eButton1)) {
		SOUND("SE_Tin")->Play();
		Base::Add(new Bullet(CVector2D(m_pos)));
		m_scroll.y = m_pos.y - 600;
	}

	if (PUSH(CInput::eButton5)&& hama ==1) {
		SOUND("SE_Tin2")->Play();
		hama = 0;
		Base::Add(new Hittsatu(CVector2D(m_pos)));

	}
	m_gauge->SetValue((float)m_hp / m_max_hp);
	m_gauge->m_pos = CVector2D(0, 0);

}
void Player::Collision(Base* b)
{
	switch (b->m_type) {
	case eType_Enemy:
	case eType_Boss_bullet:
	case eType_Boss_bullet03:
	{
			if (Base::CollisionCircle(this, b))
			{
				b->SetKill();
				m_hp -= 20;
				if (m_hp <= 0) {
					SetKill();
				}
				Base::Add(new Effect(b->m_pos));

			}
		}
		CVector2D v = b->m_pos - m_pos;
		float l = v.Length();
			if (kaiten && l < b->m_rad + 64)
		{
			b->SetKill();
			Base::Add(new Effect(b->m_pos));
		}
	
		break;
	}
}


void Player::Draw()
{
	m_img.SetPos(m_pos);
	m_img.SetAng(m_ang);
	m_img.Draw();
	DrawRect();
}