/********************************************************************************
** Form generated from reading UI file 'notepad.ui'
**
** Created by: Qt User Interface Compiler version 5.10.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_NOTEPAD_H
#define UI_NOTEPAD_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Notepad
{
public:
    QAction *nowy;
    QAction *otworz;
    QAction *zapisz;
    QAction *zapiszjako;
    QAction *utf;
    QAction *ansi;
    QAction *c;
    QAction *java;
    QAction *css;
    QAction *rozmiar;
    QAction *typ;
    QAction *pogrub;
    QAction *pochyl;
    QAction *podkresl;
    QAction *kopiuj;
    QAction *wytnij;
    QAction *wklej;
    QAction *znajdz;
    QAction *zamien;
    QWidget *centralWidget;
    QTextEdit *tekst;
    QStatusBar *statusBar;
    QMenuBar *menuBar;

    void setupUi(QMainWindow *Notepad)
    {
        if (Notepad->objectName().isEmpty())
            Notepad->setObjectName(QStringLiteral("Notepad"));
        Notepad->resize(523, 385);
        nowy = new QAction(Notepad);
        nowy->setObjectName(QStringLiteral("nowy"));
        otworz = new QAction(Notepad);
        otworz->setObjectName(QStringLiteral("otworz"));
        zapisz = new QAction(Notepad);
        zapisz->setObjectName(QStringLiteral("zapisz"));
        zapiszjako = new QAction(Notepad);
        zapiszjako->setObjectName(QStringLiteral("zapiszjako"));
        utf = new QAction(Notepad);
        utf->setObjectName(QStringLiteral("utf"));
        utf->setCheckable(false);
        utf->setEnabled(true);
        ansi = new QAction(Notepad);
        ansi->setObjectName(QStringLiteral("ansi"));
        c = new QAction(Notepad);
        c->setObjectName(QStringLiteral("c"));
        java = new QAction(Notepad);
        java->setObjectName(QStringLiteral("java"));
        css = new QAction(Notepad);
        css->setObjectName(QStringLiteral("css"));
        rozmiar = new QAction(Notepad);
        rozmiar->setObjectName(QStringLiteral("rozmiar"));
        typ = new QAction(Notepad);
        typ->setObjectName(QStringLiteral("typ"));
        pogrub = new QAction(Notepad);
        pogrub->setObjectName(QStringLiteral("pogrub"));
        pochyl = new QAction(Notepad);
        pochyl->setObjectName(QStringLiteral("pochyl"));
        podkresl = new QAction(Notepad);
        podkresl->setObjectName(QStringLiteral("podkresl"));
        kopiuj = new QAction(Notepad);
        kopiuj->setObjectName(QStringLiteral("kopiuj"));
        wytnij = new QAction(Notepad);
        wytnij->setObjectName(QStringLiteral("wytnij"));
        wklej = new QAction(Notepad);
        wklej->setObjectName(QStringLiteral("wklej"));
        znajdz = new QAction(Notepad);
        znajdz->setObjectName(QStringLiteral("znajdz"));
        zamien = new QAction(Notepad);
        zamien->setObjectName(QStringLiteral("zamien"));
        centralWidget = new QWidget(Notepad);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        tekst = new QTextEdit(centralWidget);
        tekst->setObjectName(QStringLiteral("tekst"));
        tekst->setGeometry(QRect(0, 0, 511, 331));
        Notepad->setCentralWidget(centralWidget);
        statusBar = new QStatusBar(Notepad);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        Notepad->setStatusBar(statusBar);
        menuBar = new QMenuBar(Notepad);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 523, 26));
        Notepad->setMenuBar(menuBar);

        retranslateUi(Notepad);

        QMetaObject::connectSlotsByName(Notepad);
    } // setupUi

    void retranslateUi(QMainWindow *Notepad)
    {
        Notepad->setWindowTitle(QApplication::translate("Notepad", "Notepad", nullptr));
        nowy->setText(QApplication::translate("Notepad", "Nowy", nullptr));
        otworz->setText(QApplication::translate("Notepad", "Otw\303\263rz", nullptr));
        zapisz->setText(QApplication::translate("Notepad", "Zapisz", nullptr));
        zapiszjako->setText(QApplication::translate("Notepad", "Zapisz jako...", nullptr));
        utf->setText(QApplication::translate("Notepad", "UTF-8", nullptr));
        ansi->setText(QApplication::translate("Notepad", "ANSI", nullptr));
        c->setText(QApplication::translate("Notepad", "c++", nullptr));
        java->setText(QApplication::translate("Notepad", "java", nullptr));
        css->setText(QApplication::translate("Notepad", "css", nullptr));
        rozmiar->setText(QApplication::translate("Notepad", "Rozmiar", nullptr));
        typ->setText(QApplication::translate("Notepad", "Typ", nullptr));
        pogrub->setText(QApplication::translate("Notepad", "Pogrubienie", nullptr));
        pochyl->setText(QApplication::translate("Notepad", "Pochylenie", nullptr));
        podkresl->setText(QApplication::translate("Notepad", "Podkre\305\233lenie", nullptr));
        kopiuj->setText(QApplication::translate("Notepad", "Kopiuj", nullptr));
        wytnij->setText(QApplication::translate("Notepad", "Wytnij", nullptr));
        wklej->setText(QApplication::translate("Notepad", "Wklej", nullptr));
        znajdz->setText(QApplication::translate("Notepad", "Znajd\305\272", nullptr));
        zamien->setText(QApplication::translate("Notepad", "Zamie\305\204", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Notepad: public Ui_Notepad {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_NOTEPAD_H
