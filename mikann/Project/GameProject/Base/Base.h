#pragma once
#include<GLLibrary.h>
enum {
	eType_Field,
	eType_UI,
	eType_HP,
	eType_Boss,
	eType_Enemy,
	eType_Player,
	eType_Enemy_Attack,
	eType_Boss_bullet,
	eType_Boss_bullet03,
	eType_Bullet,
	eType_Hittsatu,
	eType_Sword,
	eType_Enemy_Bullet,
	eType_BossWaza,
	eType_Effect,
	eType_Gimmick,
	eType_Gimmick02,
	eType_Gimmick03,
	eType_Bossbullet,
	eType_Bossbullet03,
	eType_Scene,
	eType_Gauge
};
//重力加速度
#define GRAVITY	(9.8f/20)
class Base {
public:
	int m_type;
	CVector2D m_pos;
	CVector2D m_pos_old;
	CVector2D m_vec;
	float m_rad;
	float m_ang;
	int m_hit_id;
	static std::list<Base*> m_list;
	bool m_kill;
	static CVector2D m_scroll;
	//矩形
	CRect	m_rect;
public:
	Base(int type);
	virtual ~Base();
	virtual void Update();
	virtual void Draw();
	virtual void Collision(Base* b);
	void SetKill() { m_kill = true; }
	static void KillAll();
	static void UpdateAll();
	static void DrawAll();
	static void Add(Base* b);
	static void CollisionAll();
	static bool CollisionCircle(Base* b1, Base* b2);
	static bool CollisionRect(Base* b1, Base* b2);
	static void CheckKillAll();
	static CVector2D GetScreenPos(const CVector2D& pos);
	Base* Base::FindObject(int Type);
	static std::list<Base*>FindObjects(int type);
	/// 矩形の表示
	void DrawRect();
};