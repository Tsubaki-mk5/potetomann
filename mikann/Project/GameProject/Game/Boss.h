#pragma once
#include "../Base/Base.h"

class Boss : public Base {
public:
	CImage m_img;
	int movedir;
	int m_hp;
public:
	Boss(const CVector2D& pos);
	void Update();
	void Draw();
	void Collision(Base* b);
};
