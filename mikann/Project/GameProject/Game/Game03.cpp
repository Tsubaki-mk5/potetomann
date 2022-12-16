#include "Game03.h"
#include "Enemy03.h"
#include "Player.h"
#include "Enemy.h"
#include "Boss03.h"
#include "../Title/Title.h"
#include "Field.h"
#include "Gimmick.h"
#include "UI.h"
#include "GameData.h"
#include "Gameclear.h"
#include "Boss.h"
#include "Gameover.h"
Game03::Game03() :Base(eType_Scene) {
	Base::Add(new Field());
	Base::Add(new Player(CVector2D(200, 800)));
	Base::Add(new Enemy03(CVector2D(200, 200)));
	Base::Add(new Enemy03(CVector2D(300, 200)));
	Base::Add(new Enemy03(CVector2D(400, 200)));
	Base::Add(new Enemy03(CVector2D(500, 200)));
	Base::Add(new Boss03(CVector2D(400, 200)));
	Base::Add(new UI());


	srand(time(NULL));
	Base::Add(new Gimmick(CVector2D(rand() % 720, 300)));

}

Game03::~Game03() {
	switch (k) {
	case 0:
		//�S�ẴI�u�W�F�N�g��j��
		Base::KillAll();
		Base::Add(new Gameclear());

		break;
	case 1:
		//�S�ẴI�u�W�F�N�g��j��
		Base::KillAll();
		Base::Add(new Gameover());

		break;
	}
}


void Game03::Update() {
	//�v���C���[���S�@�{�^���P�ŃQ�[���V�[���I��
	if (!Base::FindObject(eType_Player) && PUSH(CInput::eButton1)) {
		SetKill();
		k = 1;
	}

	//�G�S�Ł@�{�^���P�ŃQ�[���V�[���I��
	if (!Base::FindObject(eType_Boss) && PUSH(CInput::eButton2))
	{
		Base::KillAll();
		SetKill();


	}



}