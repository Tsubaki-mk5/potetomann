#pragma once
#include"../Base/Base.h"

class Gimmick03 : public Base {
public:

	CImage m_img;

	Gimmick03();

public:
	Gimmick03(const CVector2D& pos);
	void Update();
	void Draw();
	void Collision(Base* b);
};