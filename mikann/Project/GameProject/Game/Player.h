#pragma once
#include"../Base/Base.h"
class Player : public Base {
public:
	CImage m_img;
	bool kaiten;
	int m_count;
public:
	Player(const CVector2D& pos);
	void Update();
	void Draw();
	void Collision(Base* b);
};
