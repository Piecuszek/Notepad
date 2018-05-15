#ifndef NOTEPAD_H
#define NOTEPAD_H

#include <QMainWindow>
#include <QFile>
#include <QFileDialog>
#include <QMessageBox>
#include <QTextStream>
#include <QFont>
#include <QFontDialog>

class QAction;
class QActionGroup;

namespace Ui {
class Notepad;
}

class Notepad : public QMainWindow
{
    Q_OBJECT


public:
    explicit Notepad(QWidget *parent = 0);
    ~Notepad();

protected:
           // MENU
       QMenu *fileMenu;
       QMenu *editMenu;
       QMenu *encodingMenu;
       QMenu *fontMenu;
          // PLIK
       QAction *newAct;
       QAction *openAct;
       QAction *saveAct;
       QAction *saveAsAct;
       QAction *exitAct;
          // EDYCJA
       QAction *undoAct;
       QAction *redoAct;
       QAction *cutAct;
       QAction *copyAct;
       QAction *pasteAct;
          // KODOWANIE
       QAction *utfAct;
       QAction *ansiAct;
       QAction *cppAct;
       QAction *javaAct;
       QAction *cssAct;
          // CZCIONKI
       QAction *sizeAct;
       QAction *typeAct;
       QAction *boldAct;
       QAction *italicAct;
       QAction *underlineAct;

       QActionGroup *alignmentGroup;
private slots:
       // PLIK
    void newFile();
    void open();
    void save();
    void saveas();
    void exit();

       // EDYCJA
    void mundo();
    void mredo();
    void cut();
    void copy();
    void paste();

       // KODOWANIE
    void utf();
    void ansi();
    void cpp();
    void java();
    void css();

       // CZCIONKI
    void size();
    void type();
    void bold();
    void italic();
    void underline();


private:
    void createActions();
    void createMenus();
    void repaintTekst(int newFormat);

    Ui::Notepad *ui;

    int         format;
    QString     currentFileName;
    QMessageBox mgbox;

};

#endif // NOTEPAD_H
