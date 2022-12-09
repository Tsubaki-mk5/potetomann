#pragma once
#include"../Base/Base.h"
class Gauge;
class Player : public Base {
public:
	CImage m_img;
	bool kaiten;
	int m_count;
	int m_hp;
	int m_max_hp;
	Gauge* m_gauge;
public:
	Player(const CVector2D& pos);
	~Player();
	void Update();
	void Draw();
	void Collision(Base* b);
};
