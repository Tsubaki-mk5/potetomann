#pragma once
#include "../Base/Base.h"

extern TexAnimData Boss_anim_data[];
class Boss02 : public Base {
public:
	int m_hp;
	int m_cnt;
	int m_flip;
	CImage m_img;
	int movedir;
public:
	Boss02(const CVector2D& pos);
	void Update();
	void Draw();
	void Collision(Base* b);
};

