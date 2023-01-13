#include "Gameover.h"
#include "../Title/Title.h"
#include "../Game/Game.h"


Gameover::Gameover() :Base(eType_Scene), m_title_text("C:\\Windows\\Fonts\\msgothic.ttc", 64) {
	m_img = COPY_RESOURCE("Gameover", CImage);
	m_img.SetSize(1980, 1080);
	SOUND("si")->Play(true);
	SOUND("BGM_Sentou1")->Stop();
	SOUND("af")->Stop();
}

Gameover::~Gameover() {
	Base::KillAll();
	if (HOLD(CInput::eButton10)) {//エンターキー
		//ゲームシーンへ
		Base::Add(new Title());
	}
}

void Gameover::Update() {
	//エンターキーでゲームシーン終了
	if (PUSH(CInput::eButton10)) {
		SetKill();
	}
}

void Gameover::Draw() {
	m_img.Draw();
	//m_title_text.Draw(156, 870, 255, 255, 0, "Enterでタイトルに戻る");
	

}