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

#ifndef MAINWINDOWIMPL_H
#define MAINWINDOWIMPL_H
//
#include <QtGui>
#include <QMainWindow>
#include <QMessageBox>
#include "ui_mainwindow.h"
#include "figletmanager.h"
#include "figletfonts.h"
#include "options.h"
#include "dialogoptionsimpl.h"
#include "dialoginfoimpl.h"

class MainWindowImpl : public QMainWindow, public Ui::MainWindow
{
Q_OBJECT
public:
	MainWindowImpl( QWidget * parent = 0, Qt::WFlags f = 0 );
private:
	bool saveFile(const QString &fileName);
	void setActions();
	void loadFonts();
	void loadOptions();

	FigletManager *fMan;
	Options *opt;
	QString fontsPath;
	QString figletPath;
	QComboBox *comboFonts;
	QString currentDocument;
    QString m_alignment;

private slots:
	void writeText();
	bool showOptionsDialog();
	
	void openText();
	bool save();
	bool saveAs();

    void changeAlignment();

	
	void showInfo();
    void openPaypalLink();
};
#endif
