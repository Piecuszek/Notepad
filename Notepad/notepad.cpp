#include "notepad.h"
#include "ui_notepad.h"

Notepad::Notepad(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Notepad)
{
    ui->setupUi(this);
    createActions();
    createMenus();
}

Notepad::~Notepad()
{
    delete ui;
}

void Notepad::createActions()
{
    // ------------- Plik
    newAct = new QAction(tr("&Nowy"), this);
    newAct->setShortcuts(QKeySequence::New);
    newAct->setStatusTip(tr("Nowy plik"));
    connect(newAct, &QAction::triggered, this, &Notepad::newFile);

    openAct = new QAction(tr("&Otwórz..."), this);
    openAct->setShortcuts(QKeySequence::Open);
    openAct->setStatusTip(tr("Otwórz istniejący plik"));
    connect(openAct, &QAction::triggered, this, &Notepad::open);

    saveAct = new QAction(tr("&Zapisz"), this);
    saveAct->setShortcuts(QKeySequence::Save);
    saveAct->setStatusTip(tr("Zapisz istnięjący plik"));
    connect(saveAct, &QAction::triggered, this, &Notepad::save);

    saveAsAct = new QAction(tr("&Zapisz jako..."), this);
    saveAsAct->setShortcuts(QKeySequence::SaveAs);
    saveAsAct->setStatusTip(tr("&Zapisz jako nowy plik"));
    connect(saveAsAct, &QAction::triggered, this, &Notepad::saveas);

    exitAct = new QAction(tr("&Zakończ"), this);
    exitAct->setShortcuts(QKeySequence::Quit);
    exitAct->setStatusTip(tr("Zakończ aplikację"));
    connect(exitAct, &QAction::triggered, this, &Notepad::exit);

    // ------------- Edycja
    undoAct = new QAction(tr("&Cofnij"), this);
    undoAct->setShortcuts(QKeySequence::Undo);
    undoAct->setStatusTip(tr("Cofnij ostatnią operację"));
    connect(undoAct, &QAction::triggered, this, &Notepad::mundo);

    redoAct = new QAction(tr("&Przywróć"), this);
    redoAct->setShortcuts(QKeySequence::Redo);
    redoAct->setStatusTip(tr("Przywróć cofniętą operację"));
    connect(redoAct, &QAction::triggered, this, &Notepad::mredo);

    cutAct = new QAction(tr("&Wytnij"), this);
    cutAct->setShortcuts(QKeySequence::Cut);
    cutAct->setStatusTip(tr("Wytnij zaznaczony tekst"));
    connect(cutAct, &QAction::triggered, this, &Notepad::cut);

    copyAct = new QAction(tr("&Kopiuj"), this);
    copyAct->setShortcuts(QKeySequence::Copy);
    copyAct->setStatusTip(tr("Skopiuj zaznaczony tekst"));
    connect(copyAct, &QAction::triggered, this, &Notepad::copy);

    pasteAct = new QAction(tr("&Wklej"), this);
    pasteAct->setShortcuts(QKeySequence::Paste);
    pasteAct->setStatusTip(tr("Wklej ze schowka"));
    connect(pasteAct, &QAction::triggered, this, &Notepad::paste);

}

void Notepad::createMenus()
{
    // ------------- Plik
    fileMenu = menuBar()->addMenu(tr("&Plik"));
    fileMenu->addAction(newAct);
    fileMenu->addAction(openAct);
    fileMenu->addAction(saveAct);
    fileMenu->addAction(saveAsAct);
    fileMenu->addSeparator();
    fileMenu->addAction(exitAct);

    // ------------- Edycja
    editMenu = menuBar()->addMenu(tr("&Edycja"));
    editMenu->addAction(undoAct);
    editMenu->addAction(redoAct);
    editMenu->addSeparator();
    editMenu->addAction(cutAct);
    editMenu->addAction(copyAct);
    editMenu->addAction(pasteAct);
    editMenu->addSeparator();

    // ------------- Kodowanie
    encodingMenu = menuBar()->addMenu(tr("&Edycja"));
    encodingMenu->addAction(utfAct);
    encodingMenu->addAction(ansiAct);
    encodingMenu->addSeparator();
    encodingMenu->addAction(cppAct);
    encodingMenu->addAction(javaAct);
    encodingMenu->addAction(cssAct);
}

void Notepad::newFile()
{
    currentFileName.clear();
    ui->tekst->setText(QString());
}

void Notepad::open()
{
    QString fileName = QFileDialog::getOpenFileName(this, "Otwórz plik");
    QFile file(fileName);
    currentFileName = fileName;
    if (!file.open(QIODevice::ReadOnly | QFile::Text))
    {
            QMessageBox::warning(this, "Błąd", "Nie można otworzyć pliku: " + file.errorString());
            return;
    }
    setWindowTitle(currentFileName);

    QTextStream in(&file);
    QString text = in.readAll();
    ui->tekst->setText(text);
    file.close();
}

void Notepad::save()
{
    QString fileName;
    // jeśli tworzymy nowy plik
    if (currentFileName.isEmpty())
    {
        fileName = QFileDialog::getSaveFileName(this, "Zapisz");
        currentFileName = fileName;
    } else {
        fileName = currentFileName;
    }

    QFile file(fileName);
    if (!file.open(QIODevice::WriteOnly | QFile::Text)) {
        QMessageBox::warning(this, "Błąd", "Nie można zapisać pliku: " + file.errorString());
        return;
    }
    setWindowTitle(fileName);

    QTextStream out(&file);
    QString text = ui->tekst->toPlainText();
    out << text;
    file.close();
}

void Notepad::saveas()
{
    QString fileName = QFileDialog::getSaveFileName(this, "Zapisz jako...");
    QFile file(fileName);

    if (!file.open(QFile::WriteOnly | QFile::Text)) {
        QMessageBox::warning(this, "Błąd", "Nie można zapisać pliku: " + file.errorString());
        return;
    }
    currentFileName = fileName;
    setWindowTitle(fileName);

    QTextStream out(&file);
    QString text = ui->tekst->toPlainText();
    out << text;
    file.close();
}

void Notepad::exit()
{
    QMessageBox::StandardButton button;
    button = QMessageBox::question(this, "Informacja", "Czy na pewno chcesz zakończyć? Niezapisane zmiany zostaną usunięte", QMessageBox::Yes | QMessageBox::No);

    if(button == QMessageBox::Yes)
    {
        QCoreApplication::quit();
    }
}

void Notepad::mundo()
{
    ui->tekst->undo();
}

void Notepad::mredo()
{
    ui->tekst->redo();
}

void Notepad::cut()
{
    ui->tekst->cut();
}

void Notepad::copy()
{
    ui->tekst->copy();
}

void Notepad::paste()
{
    ui->tekst->paste();
}

void Notepad::utf()
{

}

void Notepad::ansi()
{

}

void Notepad::cpp()
{
    repaintTekst(1);
}

void Notepad::java()
{
    repaintTekst(2);
}
void Notepad::css()
{
    repaintTekst(3);
}

void Notepad::repaintTekst(int newFormat)
{

}

