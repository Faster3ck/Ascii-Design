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

#include "options.h"
#include <QDesktopServices>

Options::Options()
{
#if QT_VERSION >= 0x050000
	QString myPath =  QStandardPaths::writableLocation(QStandardPaths::DataLocation);
#else
	QString myPath =  QDesktopServices::storageLocation(QDesktopServices::DataLocation);
#endif
	settings = new QSettings(QString("%1/.ascii-design_options.conf").arg(myPath),
			QSettings::IniFormat);

	
}
/* Saves */
void Options::setFigletPath(QString figletPath)
{
	settings->setValue("General/figletPath", figletPath);
}

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

QString Options::lastFont()
{
	return settings->value("General/Last font", "").toString();
}

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
