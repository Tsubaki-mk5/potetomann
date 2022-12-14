#pragma once
#include"../Base/Base.h"
class Bossbullet03 : public Base {
public:
	CImage m_img;
	int type;
	float m_speed;
	float ang;
public:
	Bossbullet03(int type, const CVector2D& pos, float ang, float speed);
	void Update();
	void Draw();
	void Collision(Base* b);
};
