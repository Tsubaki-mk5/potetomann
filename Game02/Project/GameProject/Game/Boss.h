#pragma once
#include "../Base/Base.h"

class Boss : public Base {
public:
	CImage m_img;
public:
	Boss(const CVector2D& pos);
	void Update();
	void Draw();
};
