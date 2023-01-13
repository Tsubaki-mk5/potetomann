#include "Game02.h"
#include "Game03.h"
#include "Player.h"
#include "Boss02.h"
#include "Enemy02.h"
#include "../Title/Title.h"
#include "Field.h"
#include "UI.h"
#include "GameData.h"
#include "Gameclear.h"
#include "Gameover.h"
#include "Gimmick02.h"

Game02::Game02() :Base(eType_Scene) {
	Base::Add(new Field());
	Base::Add(new Player(CVector2D(200, 800)));
	Base::Add(new Boss02(CVector2D(400, 200)));
	Base::Add(new UI());


	srand(time(NULL));
	Base::Add(new Gimmick02(CVector2D(rand() % 1280, 0)));
	

}

Game02::~Game02() {
	switch (k) {
	case 0:
		//全てのオブジェクトを破棄
		Base::KillAll();
		Base::Add(new Game03());

		break;
	case 1:
		//全てのオブジェクトを破棄
		Base::KillAll();
		Base::Add(new Gameover());

		break;
	}
}



void Game02::Update() {
	//プレイヤー死亡　ボタン１でゲームシーン終了
	if (!Base::FindObject(eType_Player)) {
		SetKill();
		k = 1;
	}
	if (Base::FindObject(eType_Boss)) {
		//時間経過
		gimmik_cnt++;
		if (gimmik_cnt >= 30) {
			Base::Add(new Gimmick02(CVector2D(rand() % 1280, 0)));
			//タイマーリセット
			gimmik_cnt = 0;
		}
		if (Base::FindObject(eType_Boss)) {
			//時間経過
			enemy2_cnt++;
			//120f以上なら
			if (enemy2_cnt >= 60) {
				Base::Add(new Enemy02(CVector2D(rand() % 1280, 0)));
				//タイマーリセット
				enemy2_cnt = 0;
			}
		}
	}
	//敵全滅　ボタン１でゲームシーン終了
	if (!Base::FindObject(eType_Boss))
	{
		Base::KillAll();
		SetKill();


	}



}