#pragma once
#include"../Base/Base.h"

class Gimmick : public Base {
public:

	CImage m_img;
	Gimmick();

public:
	Gimmick(const CVector2D& pos);
	void Update();
	void Draw();
};