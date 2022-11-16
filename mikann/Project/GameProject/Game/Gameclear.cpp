#include "Gameclear.h"
#include "../Title/Title.h"
#include "../Game/Game.h"


Gameclear::Gameclear() :Base(eType_Scene), m_title_text("C:\\Windows\\Fonts\\msgothic.ttc", 64) {
	m_img = COPY_RESOURCE("Clear", CImage);
}

Gameclear::~Gameclear() {
	Base::KillAll();
	if (HOLD(CInput::eButton10)) {//�G���^�[�L�[
		//�Q�[���V�[����
		Base::Add(new Title());
	}
}

void Gameclear::Update() {
	//�G���^�[�L�[�ŃQ�[���V�[���I��
	if (PUSH(CInput::eButton10)) {
		SetKill();
	}
}

void Gameclear::Draw() {
	m_img.Draw();
	m_title_text.Draw(156, 50, 255, 255, 0, "GameClear");

}