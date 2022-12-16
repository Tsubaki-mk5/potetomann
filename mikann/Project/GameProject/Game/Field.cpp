#include "Field.h"

Field::Field() :Base(eType_Field) {

	m_space = COPY_RESOURCE("Space", CImage);

	
}
void Field::Draw() {
	float sc;
	m_space.Draw();
	sc = m_scroll.y / 4;
	m_space.SetRect(0, 0, 0 + 1920, 1080);
}