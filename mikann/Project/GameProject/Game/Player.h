#pragma once
#include"../Base/Base.h"
class Gauge;
class Player : public Base {
public:
	int m_hp;
	CImage m_img;
	bool kaiten;
	int m_count;
	int movedir;
	int m_max_hp;
	Gauge* m_gauge;
	int hama;

public:
	Player(const CVector2D& pos);
	~Player();
	void Update();
	void Draw();
	void Collision(Base*b);
};
