#include "Title.h"
#include "../Game/Game.h"


Title::Title() :Base(eType_Scene), m_title_text("C:\\Windows\\Fonts\\msgothic.ttc", 128), m_menu_text("C:\\Windows\\Fonts\\msgothic.ttc", 50), m_member_text("C:\\Windows\\Fonts\\msgothic.ttc", 40) {
	m_img = COPY_RESOURCE("Title", CImage);
	//SOUND("titleBGM")->Play(true);
}

Title::~Title() {
	//全てのオブジェクトを破棄
	Base::KillAll();
	if (HOLD(CInput::eButton1)) {//Zキー
		//SOUND("titleBGM")->Stop();
		//ゲームシーンへ
		Base::Add(new Game());
	}

}

void Title::Update() {

	//ボタン１でタイトル破棄
	if (PUSH(CInput::eButton1)) {
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

	m_title_text.Draw(156, 200, 255, 255, 0, "こぶし");
}