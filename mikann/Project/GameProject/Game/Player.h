#pragma once
#include"../Base/Base.h"
class Gauge;
class Player : public Base {
public:
	int m_hp;
	CImage m_img;
	bool kaiten;
	int m_count;
<<<<<<< HEAD
	int movedir;
=======
	int m_hp;
	int m_max_hp;
	Gauge* m_gauge;
>>>>>>> 2cc88dc0914264da1ff6637a7e9681414f167373
public:
	Player(const CVector2D& pos);
	~Player();
	void Update();
	void Draw();
	void Collision(Base*b);
};
