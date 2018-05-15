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

       QMenu *fileMenu;
       QMenu *editMenu;
       QMenu *encodingMenu;
       QMenu *fontMenu;

       QAction *newAct;
       QAction *openAct;
       QAction *saveAct;
       QAction *saveAsAct;
       QAction *exitAct;

       QAction *undoAct;
       QAction *redoAct;
       QAction *cutAct;
       QAction *copyAct;
       QAction *pasteAct;

       QActionGroup *alignmentGroup;
private slots:
       // PLIK
    void newFile();
    void open();
    void save();
    void saveas();
    void exit();

       //EDYCJA
    void undo();
    void redo();
    void cut();
    void copy();
    void paste();

private:
    void createActions();
    void createMenus();

    Ui::Notepad *ui;

    int         format;
    QString     currentFileName;
    QMessageBox mgbox;

};

#endif // NOTEPAD_H
