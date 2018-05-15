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
    saveAsAct->setShortcut(tr("Ctrl+Alt+S"));
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

    // ------------- Kodowanie
    utfAct = new QAction(tr("&UTF-8"), this);
    connect(utfAct, &QAction::triggered, this, &Notepad::utf);

    ansiAct = new QAction(tr("&ANSI"), this);
    connect(ansiAct, &QAction::triggered, this, &Notepad::ansi);

    cppAct = new QAction(tr("&C/C++"), this);
    connect(cppAct, &QAction::triggered, this, &Notepad::cpp);

    javaAct = new QAction(tr("&Java"), this);
    connect(javaAct, &QAction::triggered, this, &Notepad::java);

    cssAct = new QAction(tr("&CSS"), this);
    connect(cssAct, &QAction::triggered, this, &Notepad::css);

    // ------------- Czcionka
    sizeAct = new QAction(tr("&Rozmiar"), this);
    connect(sizeAct, &QAction::triggered, this, &Notepad::size);

    typeAct = new QAction(tr("&Typ czcionki"), this);
    connect(typeAct, &QAction::triggered, this, &Notepad::type);

    boldAct = new QAction(tr("&Pogrubienie"), this);
    boldAct->setCheckable(true);
    boldAct->setShortcut(QKeySequence::Bold);
    connect(boldAct, &QAction::triggered, this, &Notepad::bold);

    QFont boldFont = boldAct->font();
    boldFont.setBold(true);
    boldAct->setFont(boldFont);

    italicAct = new QAction(tr("&Kursywa"), this);
    italicAct->setCheckable(true);
    italicAct->setShortcut(QKeySequence::Italic);
    connect(italicAct, &QAction::triggered, this, &Notepad::italic);

    QFont italicFont = italicAct->font();
    italicFont.setItalic(true);
    italicAct->setFont(italicFont);

    underlineAct = new QAction(tr("&Podkreślenie"), this);
    underlineAct->setCheckable(true);
    underlineAct->setShortcut(QKeySequence::Underline);
    connect(underlineAct, &QAction::triggered, this, &Notepad::underline);

    QFont underlineFont = underlineAct->font();
    underlineFont.setUnderline(true);
    underlineAct->setFont(underlineFont);
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

    // ------------- Czcionka
    encodingMenu = menuBar()->addMenu(tr("&Czcionka"));
    encodingMenu->addAction(sizeAct);
    encodingMenu->addAction(typeAct);
    encodingMenu->addSeparator();
    encodingMenu->addAction(boldAct);
    encodingMenu->addAction(italicAct);
    encodingMenu->addAction(underlineAct);

    // ------------- Kodowanie
    encodingMenu = menuBar()->addMenu(tr("&Kodowanie"));
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

void Notepad::bold()
{
    ui->tekst->setText(tr("Invoked <b>Edit|Format|Bold</b>"));
}

void Notepad::italic()
{
    ui->tekst->setText(tr("Invoked <b>Edit|Format|Italic</b>"));
}

void Notepad::underline()
{
    ui->tekst->setText(tr("Invoked <b>Edit|Format|Underline</b>"));
}

void Notepad::size()
{

}

void Notepad::type()
{

}
