#include "Game.h"
#include "Game02.h"
#include "Player.h"
#include "Enemy.h"
#include "../Title/Title.h"
#include "Field.h"
#include "Gimmick.h"
#include "UI.h"
#include "GameData.h"
#include "Gameclear.h"
#include "Boss.h"
#include "Gameover.h"
Game::Game() :Base(eType_Scene) {
	Base::Add(new Field());
	Base::Add(new Player(CVector2D(200, 800)));
	Base::Add(new Enemy(CVector2D(200, 200)));
	Base::Add(new Boss(CVector2D(400, 200)));
	Base::Add(new UI());
	
	
	srand(time(NULL));
	Base::Add(new Gimmick(CVector2D(rand() % 720, 0)));
	
}

Game::~Game() {
	switch (k) {
	case 0:
		//全てのオブジェクトを破棄
		Base::KillAll();
		Base::Add(new Game02());
		
		break;
	case 1:
		//全てのオブジェクトを破棄
		Base::KillAll();
		Base::Add(new Gameover());
		
		break;
	}
}


void Game::Update() {
	//プレイヤー死亡　ボタン１でゲームシーン終了
	if (!Base::FindObject(eType_Player)) {
		SetKill();
		k = 1;
	}
	//ボスが存在するなら
	if (Base::FindObject(eType_Boss)) {
		//時間経過
		gimmik_cnt++;
		//120f以上なら
		if (gimmik_cnt >= 60) {
			//隕石を生成
			Base::Add(new Gimmick(CVector2D(rand() % 1280, 0)));
			//タイマーリセット
			gimmik_cnt = 0;
		}
		if (Base::FindObject(eType_Boss)) {
			//時間経過
			enemy_cnt++;
			//120f以上なら
			if (enemy_cnt >= 60) {
				Base::Add(new Enemy(CVector2D(rand() % 1280, 0)));
				//タイマーリセット
				enemy_cnt = 0;
			}
		}
	}
	//敵全滅　ボタン１でゲームシーン終了
	if (!Base::FindObject( eType_Boss ))
 {
		Base::KillAll();
		SetKill();
		
		
	}
	

	
}

