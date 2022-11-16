#pragma once
#include"../Base/Base.h"

class Gimmick : public Base {
public:

	CImage m_img0;
	CImage m_img1;
	Gimmick();

public:
	Gimmick(const CVector2D& pos);
	void Update();
	void Draw();
	void Collision(Base* b);
};