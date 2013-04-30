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
* Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307  USA
*
* Contact e-mail: Faster <faster3ck@gmail.com>
*
*/

#ifndef __OPTIONS_H__
#define __OPTIONS_H__

#include <QCoreApplication>
#include <QSettings>
#include <QDir>

class Options: public QObject
{
Q_OBJECT
public:
	Options();
	//
	void setFigletPath(QString figletPath);
	void setFontsPath(QString font);
	void setLastFont(QString font);
	//
	QString figletPath();
	QString fontsPath();
	QString lastFont();
	//
	bool optionsTest();
	//
	#ifdef Q_OS_WIN32
	void windowsAutoOptions();
	#endif
private:
	QSettings *settings;
};

#endif // __OPTIONS_H__
