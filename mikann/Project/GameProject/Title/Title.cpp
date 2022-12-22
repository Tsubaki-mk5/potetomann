#include "Title.h"
#include "../Game/Game.h"
#include "../Game/Game02.h"
#include "../Game/Game03.h"


Title::Title() :Base(eType_Scene), m_title_text("C:\\Windows\\Fonts\\msgothic.ttc", 50), m_menu_text("C:\\Windows\\Fonts\\msgothic.ttc", 50), m_member_text("C:\\Windows\\Fonts\\msgothic.ttc", 40) {
	m_img = COPY_RESOURCE("Title", CImage);
	//SOUND("titleBGM")->Play(true);
}
Title::~Title() {
	//�S�ẴI�u�W�F�N�g��j��
	Base::KillAll();
	if (HOLD(CInput::eButton10)) {//W�L�[
		//SOUND("titleBGM")->Stop();
		//�Q�[���V�[����
	Base::Add(new Game());
	

	}
	
	
}

void Title::Update() {

	//�{�^���P�Ń^�C�g���j��
	if (PUSH(CInput::eButton10)) {
		SetKill();
	}
	if (PUSH(CInput::eButton2)) {
		SetKill();
	}
	if (PUSH(CInput::eButton3)) {
		SetKill();
	}
	if (PUSH(CInput::eButton4)) {
		SetKill();
	}
	/*if (PUSH(CInput::eButton5)) {
		SetKill();
	}*/
}

void Title::Draw() {

	m_img.Draw();

	m_title_text.Draw(100, 200, 255, 255, 0, "Universeinvestigation");
	
}