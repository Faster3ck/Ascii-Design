/*
* This file is part of Ascii Design, an open-source cross-platform Ascii Art editor
* (C) Faster 2009 - 2013
*
* This program is free software; you can redistribute it and/or modify
* it under the terms of the GNU General Public License as published by
* the Free Software Foundation; either version 2 of the License, or
* (at your option) any later version.
*
* This program is distributed in the hope that it will be useful,
* but WITHOUT ANY WARRANTY; without even the implied warranty of
* MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
* GNU General Public License for more details.
* GNU General Public License for more details.
*
* You should have received a copy of the GNU General Public License
* along with this program; if not, write to the Free Software
* Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA 02110-1301
*
* Contact e-mail: Faster <faster3ck@gmail.com>
*
*/

#include <QDesktopServices>
#include <QUrl>
#include "dialoginfoimpl.h"

DialogInfoImpl::DialogInfoImpl( QWidget * parent, Qt::WFlags f) 
	: QDialog(parent, f)
{
	setupUi(this);

    QString titleVersion = QString("<html><head/><body><p><span style=\" font-size:14pt; font-weight:600;\">Ascii Design %1</span></p></body></html>")
            .arg(QCoreApplication::applicationVersion());
    this->labelTitleVersion->setText(titleVersion);

    connect(pushDonate, SIGNAL(clicked()), this, SLOT(openPaypalLink()));
	connect(buttonOk, SIGNAL(clicked()), this, SLOT(close()));
}

void DialogInfoImpl::openPaypalLink()
{
    QDesktopServices::openUrl(QUrl("https://www.paypal.com/cgi-bin/webscr?cmd=_s-xclick&hosted_button_id=HFD8FL89SU5LU", QUrl::TolerantMode));
}
