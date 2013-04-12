/*
* This file is part of Ascii Design, an open-source cross-platform Ascii Art editor
* (C) Faster 2004 - 2009
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

#include "options.h"

Options::Options()
{
	#ifdef Q_OS_LINUX
	QString myPath = QDir::homePath();
	#endif
	
	#ifdef Q_OS_WIN32
	QString myPath = QCoreApplication::applicationDirPath();
	#endif
	
	settings = new QSettings(QString("%1/.ascii-design_options.conf").arg(myPath),
			QSettings::IniFormat);
}
/* Saves */
void Options::setFigletPath(QString figletPath)
{
	settings->setValue("General/figletPath", figletPath);
}
//
void Options::setFontsPath(QString fontPath)
{
	settings->setValue("General/fontPath", fontPath);
}
void Options::setLastFont(QString font)
{
	settings->setValue("General/Last font", font);
}
/* Loads */
QString Options::figletPath()
{
	return settings->value("General/figletPath", "").toString();
}
//
QString Options::lastFont()
{
	return settings->value("General/Last font", "").toString();
}
//
QString Options::fontsPath()
{
	return settings->value("General/fontPath", "").toString();
}
/* Options Test */
bool Options::optionsTest()
{
	// finire qui
	if ((!settings->contains("General/figletPath")) && (!settings->contains("General/fontPath"))) {
		return false;
	}
	else
		return true;
}
/* On Windows */
#ifdef Q_OS_WIN32
void Options::windowsAutoOptions()
{
	QString thisAppPath = QCoreApplication::applicationDirPath();
	QString winFigletPath = QString("%1/figlet.exe").arg(thisAppPath);
	QString winFigletFontsPath = QString("%1/fonts").arg(thisAppPath);
	
	setFigletPath(winFigletPath);
	setFontsPath(winFigletFontsPath);
}
#endif
