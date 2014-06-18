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

#include "figletmanager.h"

FigletManager::FigletManager(QString figletPath)
{
	figlet = figletPath;
}

QByteArray FigletManager::makeText(QString text, QString align, QString font)
{
	QString prog = figlet;
	QProcess figletProcess;
    figletProcess.start(prog, QStringList() << align << "-f" << font << text);
     if (!figletProcess.waitForStarted())
         return "";

     if (!figletProcess.waitForFinished())
         return "";

     QByteArray result = figletProcess.readAll();
     return result;
}
