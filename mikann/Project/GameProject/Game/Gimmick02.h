
#pragma once
#include"../Base/Base.h"

class Gimmick02 : public Base {
public:

	CImage m_img;
	
	Gimmick02();

public:
	Gimmick02(const CVector2D& pos);
	void Update();
	void Draw();
	void Collision(Base* b);
};