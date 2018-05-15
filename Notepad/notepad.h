#ifndef NOTEPAD_H
#define NOTEPAD_H

#include <QMainWindow>
#include <QFile>
#include <QActionGroup>
#include <QMessageBox>


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
       QMessageBox mgbox;
       QMenu *fileMenu;
       QMenu *editMenu;
       QMenu *encodingMenu;
       QMenu *fontMenu;
       QActionGroup *alignmentGroup;

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


private slots:
    void newFile();
    void open();
    void save();
    void saveas();
    void exit();

    void undo();
    void redo();
    void cut();
    void copy();
    void paste();

private:
    void createActions();
    void createMenus();
    Ui::Notepad *ui;
};

#endif // NOTEPAD_H
