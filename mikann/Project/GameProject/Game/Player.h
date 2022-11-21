#pragma once
#include"../Base/Base.h"
class Player : public Base {
public:
	CImage m_img;
	int m_count;
	int m_hp;
public:
	Player(const CVector2D& pos);
	void Update();
	void Draw();
	void Collision(Base* b);
};
