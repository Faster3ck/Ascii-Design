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

#include "dialogoptionsimpl.h"

dialogOptionsImpl::dialogOptionsImpl( QWidget * parent, Qt::WFlags f) 
	: QDialog(parent, f)
{
	setupUi(this);
	opt = new Options;
	
	lineFigletPath->setText(opt->figletPath());
	lineFigletFontsPath->setText(opt->fontsPath());
	
	connect(buttonOpenFiglet, SIGNAL(clicked()), this, SLOT(openFiglet()));
	connect(buttonOpenFigletFonts, SIGNAL(clicked()), this, SLOT(openFigletFonts()));
	connect(buttonOk, SIGNAL(clicked()), this, SLOT(saveOptions()));
	connect(buttonCancel, SIGNAL(clicked()), this, SLOT(reject()));

    // Check if figlet exists:
    QString figletFile = autoDetect();
    lineFigletPath->setText(figletFile);
}

void dialogOptionsImpl::openFiglet()
{	
	#ifdef Q_OS_WIN32
	QString figletFilter = "Figlet (figlet.exe)";
    #else
    QString figletFilter = "Figlet (figlet)";
    #endif
	
	QString fileName = QFileDialog::getOpenFileName(this,
		tr("Open Figlet"), QDir::homePath(), figletFilter);
	
	if (!fileName.isEmpty())
		lineFigletPath->setText(fileName);
}

void dialogOptionsImpl::openFigletFonts()
{
	QString dir = QFileDialog::getExistingDirectory(this, tr("Open Directory"),
                                                 QDir::homePath(),
                                                 QFileDialog::ShowDirsOnly
                                                 | QFileDialog::DontResolveSymlinks);

	if (!dir.isEmpty()) {
		QDir myDir(dir);
		QStringList fontList = myDir.entryList(QStringList() << "*.flf" , QDir::Files, QDir::Name);
		if (!fontList.isEmpty()) {
			lineFigletFontsPath->setText(dir);
		}
		else
			QMessageBox::information(0, tr("Warning"),
                                 tr("Invalid fonts directory! No fonts detected!"));
	}
	else
		QMessageBox::information(0, tr("Warning"),
                                 tr("Set figlet fonts directory!"));
}

void dialogOptionsImpl::saveOptions()
{
	if (lineFigletPath->text().isNull()) {
		QMessageBox::information(0, tr("Warning"),
                                 tr("Set figlet path!"));
		if (lineFigletFontsPath->text().isNull()) {
			QMessageBox::information(0, tr("Warning"),
                                 tr("Set figlet fonts path!"));
		}
	}
	else
	{
		opt->setFigletPath(lineFigletPath->text());
		opt->setFontsPath(lineFigletFontsPath->text());
		accept();
	}
}

QString dialogOptionsImpl::autoDetect()
{
    QFileInfo fi;
    QString loc = "/usr/bin/figlet";

    fi.setFile(loc);
    if (fi.exists())
        return loc;

    loc = "/usr/local/bin/figlet";

    fi.setFile(loc);
    if (fi.exists())
        return loc;

    return "";
}
