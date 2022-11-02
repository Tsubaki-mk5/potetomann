#pragma once
#include <GLLibrary.h>
#define GRAVITY	(9.8f/20)

enum {
	eType_Field,
	eType_Player,
	eType_Enemy,
	eType_Bullet,
	eType_Player_Attack,
	eType_Enemy_Attack,
	eType_Effect,
	eType_UI,
	eType_Gimmick,
	eType_Boss,
};
class Base {
public:
	//座標データ
	CVector2D m_pos;
	bool m_kill;
	static std::list<Base*> m_list;
	//オブジェクトの種類
	int m_type;
	//半径
	float m_rad;
	//移動ベクトル
	CVector2D m_vec;
	//スクロール値
	static CVector2D m_scroll;
	//短形
	CRect m_rect;
public:
	static CVector2D GetScreenPos(const CVector2D& pos);
	static std::list<Base*> FindObjects(int type);
	Base(int type);
	virtual ~Base();
	virtual void Update();
	virtual void Draw();
	virtual void Collision(Base* b);
	void SetKill() { m_kill = true; }
	static void CollisionAll();
	//短形同士の判定
	static bool CollisionRect(Base* b1, Base b2);
	//短形の表示
	void DrawRect();

	static void UpdateAll();
	static void DrawAll();
	bool CollisionRect(Base* b1, Base* b2);
	static void CheckKillAll();
	static void Add(Base* b);
	static bool CollisionCircle(Base* b1, Base* b2);
	Base* Base::FindObject(int type);
};


