#pragma once
#include"../Base/Base.h"
class Hittsatu : public Base {
public:
	CImage m_img;
public:
	Hittsatu(const CVector2D& pos);
	void Update();
	void Draw();
	void Collision(Base* b);
};