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
		//�S�ẴI�u�W�F�N�g��j��
		Base::KillAll();
		Base::Add(new Game02());
		
		break;
	case 1:
		//�S�ẴI�u�W�F�N�g��j��
		Base::KillAll();
		Base::Add(new Gameover());
		
		break;
	}
}


void Game::Update() {
	//�v���C���[���S�@�{�^���P�ŃQ�[���V�[���I��
	if (!Base::FindObject(eType_Player)) {
		SetKill();
		k = 1;
	}
	//�{�X�����݂���Ȃ�
	if (Base::FindObject(eType_Boss)) {
		//���Ԍo��
		gimmik_cnt++;
		//120f�ȏ�Ȃ�
		if (gimmik_cnt >= 60) {
			//覐΂𐶐�
			Base::Add(new Gimmick(CVector2D(rand() % 1280, 0)));
			//�^�C�}�[���Z�b�g
			gimmik_cnt = 0;
		}
		if (Base::FindObject(eType_Boss)) {
			//���Ԍo��
			enemy_cnt++;
			//120f�ȏ�Ȃ�
			if (enemy_cnt >= 60) {
				Base::Add(new Enemy(CVector2D(rand() % 1280, 0)));
				//�^�C�}�[���Z�b�g
				enemy_cnt = 0;
			}
		}
	}
	//�G�S�Ł@�{�^���P�ŃQ�[���V�[���I��
	if (!Base::FindObject( eType_Boss ))
 {
		Base::KillAll();
		SetKill();
		
		
	}
	

	
}

