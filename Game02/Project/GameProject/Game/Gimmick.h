#pragma once
#include"../Base/Base.h"

class Gimmick : public Base {
public:

	CImage m_img;
	Gimmick();

public:
	void Update();
	void Draw();
};