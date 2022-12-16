#pragma once
#include "../Base/Base.h"


class Game : public Base {
public:
	int k = 0;
	int gimmik_cnt = 0;
	
	
	Game();
	~Game();
	void Update();
};