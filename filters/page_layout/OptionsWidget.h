/*
    Scan Tailor - Interactive post-processing tool for scanned pages.
    Copyright (C) 2007-2008  Joseph Artsimovich <joseph_a@mail.ru>

    This program is free software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

#ifndef PAGE_LAYOUT_OPTIONSWIDGET_H_
#define PAGE_LAYOUT_OPTIONSWIDGET_H_

#include "ui_PageLayoutOptionsWidget.h"
#include "FilterOptionsWidget.h"
#include "IntrusivePtr.h"
#include "Margins.h"
//#include "AutoManualMode.h"
//#include "Dependencies.h"
#include "PageId.h"
#include <QIcon>
#include <memory>

namespace page_layout
{

class Settings;

class OptionsWidget :
	public FilterOptionsWidget,
	public Ui::PageLayoutOptionsWidget
{
	Q_OBJECT
public:
	OptionsWidget(IntrusivePtr<Settings> const& settings);
	
	virtual ~OptionsWidget();
	
	void preUpdateUI(PageId const& page_id);
	
	bool leftRightLinked() const { return m_leftRightLinked; }
	
	bool topBottomLinked() const { return m_topBottomLinked; }
	
	Margins const& marginsMM() const { return m_marginsMM; }
signals:
	void leftRightLinkToggled(bool linked);
	
	void topBottomLinkToggled(bool linked);
public slots:
	void marginsSetExternally(Margins const& margins_mm);
private slots:
	void unitsChanged(int idx);
	
	void topBottomLinkClicked();
	
	void leftRightLinkClicked();
private:
	void updateMarginsDisplay();
	
	void updateLinkDisplay(QToolButton* button, bool linked);
	
	IntrusivePtr<Settings> m_ptrSettings;
	//UiData m_uiData;
	QIcon m_chainIcon;
	QIcon m_brokenChainIcon;
	PageId m_pageId;
	double m_mmToUnit;
	double m_unitToMM;
	Margins m_marginsMM;
	bool m_leftRightLinked;
	bool m_topBottomLinked;
};

} // namespace page_layout

#endif