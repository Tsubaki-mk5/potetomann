#pragma once
#include"../Base/Base.h"
class Bullet : public Base {
public:
	CImage m_img;
	int m_attack_no;
public:
	Bullet(const CVector2D& pos);
	void Update();
	void Draw();
	void Collision(Base* b);
	
};