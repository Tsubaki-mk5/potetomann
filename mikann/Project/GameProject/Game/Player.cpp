#include "Player.h"
#include "Bullet.h"
Player::Player(const CVector2D& pos) : Base(eType_Player)
{
	m_img.Load("Image/Player.png");
	m_pos = pos;
	//m_rad = 12;
	m_img.SetSize(32, 32);
	m_img.SetCenter(16, 16);
	m_count = 0;
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
	/*if (HOLD(CInput::eButton4))
		m_ang = 8;
		*/
	if (PUSH(CInput::eButton1)) {
		
		Base::Add(new Bullet(CVector2D(m_pos)));
	}
	

}

void Player::Draw()
{
	m_img.SetPos(m_pos);
	//m_img.SetAng(m_ang);
	m_img.Draw();
	DrawRect();
}
