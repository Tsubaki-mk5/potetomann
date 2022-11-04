#pragma once
#include "../Base/Base.h"


class Boss : public Base {
private:
	
	int m_hp;
	int m_state;
	int m_cnt;
	CImage m_img;
	bool m_flip;
	bool m_is_ground;
	int m_damage_no;
	int m_attack_no;



public:
	Boss(const CVector2D& p, bool flip);
	void Update();
	void Draw();
	void Collision(Base* b);

};