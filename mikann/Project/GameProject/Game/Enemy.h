#pragma once
#include "../Base/Base.h"

class Enemy: public Base {
public:
	int m_hp;
	int m_cnt;
	CImage m_img;
	int movedir;

public:
	Enemy(const CVector2D& pos);
	void Update();
	void Draw();
	void Collision(Base* b);
};