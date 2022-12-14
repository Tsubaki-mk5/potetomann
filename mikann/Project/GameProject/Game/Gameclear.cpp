#include "Gameclear.h"
#include "../Title/Title.h"
#include "../Game/Game.h"


Gameclear::Gameclear() :Base(eType_Scene), m_title_text("C:\\Windows\\Fonts\\msgothic.ttc", 64) {
	m_img = COPY_RESOURCE("Clear", CImage);
	m_img.SetSize(1980, 1080);
}

Gameclear::~Gameclear() {
	Base::KillAll();
	if (HOLD(CInput::eButton10)) {//エンターキー
		//ゲームシーンへ
		Base::Add(new Title());
	}
}

void Gameclear::Update() {
	//エンターキーでゲームシーン終了
	if (PUSH(CInput::eButton10)) {
		SetKill();
	}
}

void Gameclear::Draw() {
	m_img.Draw();
	//m_title_text.Draw(156, 50, 255, 255, 0, "GameClear");

}