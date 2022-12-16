#pragma once
#include "../Base/Base.h"


class Enemy03 : public Base {
public:
	int m_hp;
	int m_cnt;
	CImage m_img;
	int movedir;

public:
	Enemy03(const CVector2D& pos);
	void Update();
	void Draw();
	void Collision(Base* b);
};