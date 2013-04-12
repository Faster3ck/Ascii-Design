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

#include "mainwindowimpl.h"
//
MainWindowImpl::MainWindowImpl( QWidget * parent, Qt::WFlags f)
	: QMainWindow(parent, f)
{
	setupUi(this);
	
	#ifdef Q_OS_WIN32
	qApp->setStyle("Plastique");
	#endif
	
	currentDocument = "";
	
	comboFonts = new QComboBox;
	toolBar->addWidget(comboFonts);
	opt = new Options;
	
	if (!opt->optionsTest())
		/*On windows set auto path */
		//
		#ifdef Q_OS_WIN32
		opt->windowsAutoOptions();
		#endif
		//
		#ifdef Q_OS_LINUX
		if (!showOptionsDialog()) {
			QMessageBox::information(0, tr("Warning"),
                                 tr("Please, set correctly \"figlet path\" and \"figlet fonts path\" to use \"Ascii Design\"!"));
            close();
		}
		#endif

	loadOptions();	// Loads inifile ".ascii-design_options.conf";
	
	fMan = new FigletManager(figletPath);
	
	connect(textEditNormal, SIGNAL(textChanged()), this, SLOT(writeText()));
	connect(comboFonts, SIGNAL(currentIndexChanged(int)), this, SLOT(writeText()));
	
	setActions();
}
//
void MainWindowImpl::writeText()
{
	QString myText = textEditNormal->toPlainText();
	QString myFont = comboFonts->currentText();
	QByteArray text = fMan->makeText(myText, QString("%1/%2.flf").arg(fontsPath).arg(myFont));
	
	/*#ifdef Q_OS_LINUX
	textEditFiglet->setFont(QFont("Monospace"));
	#endif
	
	#ifdef Q_OS_WIN32
	textEditFiglet->setFont(QFont("Courier"));
	#endif*/
	
	textEditFiglet->setFont(QFont("DeJaVu Sans Mono"));
	
	textEditFiglet->setText(text);
	opt->setLastFont(myFont);
}
//
void MainWindowImpl::loadFonts()
{
	comboFonts->clear();
	FigletFonts *fonts = new FigletFonts;
	QStringList fontsL = fonts->getFonts(fontsPath);
	
	for (int i = 0; i < fontsL.count(); i++)
		comboFonts->addItem(fontsL.at(i).left(fontsL.at(i).size()-4));
}
//
void MainWindowImpl::loadOptions()
{
	/* Load figlet path*/
	figletPath = opt->figletPath();
	
	/* Load last used font */
	fontsPath = opt->fontsPath();
	loadFonts();	// Search fonts

	QString lastFont = opt->lastFont();
	int idx = 0;
	
	if (lastFont != "")
		idx = comboFonts->findText(lastFont, Qt::MatchExactly);
	comboFonts->setCurrentIndex(idx);
}
//
bool MainWindowImpl::showOptionsDialog()
{
	dialogOptionsImpl *dialogOpt = new dialogOptionsImpl;
	bool dlgState = dialogOpt->exec();

	loadOptions();

	return dlgState;
}
//
void MainWindowImpl::setActions()
{
	connect(actionOpenFile, SIGNAL(triggered()), this, SLOT(openText()));
	connect(actionSave, SIGNAL(triggered()), this, SLOT(save()));
	connect(actionSaveAs, SIGNAL(triggered()), this, SLOT(saveAs()));
	connect(actionClose, SIGNAL(triggered()), this, SLOT(close()));
	connect(actionConfigure, SIGNAL(triggered()), this, SLOT(showOptionsDialog()));
	connect(actionHelp, SIGNAL(triggered()), this, SLOT(showInfo()));
	connect(actionInfo, SIGNAL(triggered()), this, SLOT(showInfo()));
}
//
void MainWindowImpl::openText()
{
	QString fileName = QFileDialog::getOpenFileName(this,
		tr("Open Text File"), QDir::homePath(), tr("Text files (*.txt *)"));
	if (!fileName.isEmpty()) {
		
			QFile file(fileName);
			if (!file.open(QFile::ReadOnly | QFile::Text)) {
			QMessageBox::warning(this, tr("Application"),
		                             tr("Cannot read file %1:\n%2.")
		                             .arg(fileName)
		                             .arg(file.errorString()));
				return;
			}
		
			QTextStream in(&file);
			QApplication::setOverrideCursor(Qt::WaitCursor);
			textEditNormal->setPlainText(in.readAll());
			QApplication::restoreOverrideCursor();

		statusBar()->showMessage(tr("File loaded"), 2000);
	}
}
//
bool MainWindowImpl::save()
{
    if (currentDocument.isEmpty()) {
        return saveAs();
    } else {
        return saveFile(currentDocument);
    }
}
//
bool MainWindowImpl::saveAs()
{
    QString fileName = QFileDialog::getSaveFileName(this,
		tr("Save Text File"), QDir::homePath(), tr("Text files (*.txt *)"));
    if (fileName.isEmpty())
        return false;
    currentDocument = fileName;
    return saveFile(fileName);
}
//
bool MainWindowImpl::saveFile(const QString &fileName)
{
    QFile file(fileName);
    if (!file.open(QFile::WriteOnly | QFile::Text)) {
        QMessageBox::warning(this, tr("Application"),
                             tr("Cannot write file %1:\n%2.")
                             .arg(fileName)
                             .arg(file.errorString()));
        return false;
    }

    QTextStream out(&file);
    QApplication::setOverrideCursor(Qt::WaitCursor);
    out << textEditFiglet->toPlainText();
    QApplication::restoreOverrideCursor();

    statusBar()->showMessage(tr("File saved"), 2000);
    return true;
}
//
void MainWindowImpl::showInfo()
{
	DialogInfoImpl dlg;
	dlg.exec();
}
