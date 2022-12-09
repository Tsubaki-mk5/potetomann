#pragma once
#include"../Base/Base.h"
class Player : public Base {
public:
	int m_hp;
	CImage m_img;
	bool kaiten;
	int m_count;
	int movedir;
public:
	Player(const CVector2D& pos);
	void Update();
	void Draw();
	void Collision(Base* b);
};
