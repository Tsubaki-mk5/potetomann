#include "Gauge.h"
Gauge::Gauge(int gauge_type):Base(eType_UI){
	m_img = COPY_RESOURCE("Gauge", CImage);
	m_par = 0;
	m_gauge_type = gauge_type;
}

void Gauge::Draw(){
	m_img.SetRect(0, 0, 256, 64);
	m_img.SetCenter(-1320, 0);
	m_img.SetSize(510, 64);
	m_img.SetPos(m_pos);
	m_img.Draw();
	int border = 4;
	int width = (510 - border - border) * m_par;
	int y = (m_gauge_type + 1);
	m_img.SetRect(border, (64 * y) + border, 4 + width, (64 * (y + 1)) - border);
	m_img.SetSize(width, 64 - border - border);
	m_img.SetPos(m_pos + CVector2D(border, border));
	m_img.Draw();
}

void Gauge::SetValue(float par){
	m_par = par;
}
