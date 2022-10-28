#include "Field.h"

Field::Field() :Base(eType_Field) {

	m_space = COPY_RESOURCE("Space", CImage);

	
}
void Field::Draw() {
	float sc;
	m_space.Draw();
	sc = m_scroll.y / 4;
	m_space.SetRect(sc, 0, sc + 1920, 1080);
}