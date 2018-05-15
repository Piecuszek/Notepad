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
    connect(undoAct, &QAction::triggered, this, &Notepad::undo);

    redoAct = new QAction(tr("&Przywróć"), this);
    redoAct->setShortcuts(QKeySequence::Redo);
    redoAct->setStatusTip(tr("Przywróć cofniętą operację"));
    connect(redoAct, &QAction::triggered, this, &Notepad::redo);

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


}

void Notepad::newFile()
{
    mgbox.setText("To");
    mgbox.exec();
}

void Notepad::open()
{
    mgbox.setText("To");
    mgbox.exec();
}

void Notepad::save()
{
    mgbox.setText("To");
    mgbox.exec();
}

void Notepad::saveas()
{
    mgbox.setText("To");
    mgbox.exec();
}

void Notepad::exit()
{
    mgbox.setText("To");
    mgbox.exec();
}

void Notepad::undo()
{
    mgbox.setText("To");
    mgbox.exec();
}

void Notepad::redo()
{
    mgbox.setText("To");
    mgbox.exec();
}

void Notepad::cut()
{
    mgbox.setText("To");
    mgbox.exec();
}

void Notepad::copy()
{
    mgbox.setText("To");
    mgbox.exec();
}

void Notepad::paste()
{
    mgbox.setText("To");
    mgbox.exec();
}
