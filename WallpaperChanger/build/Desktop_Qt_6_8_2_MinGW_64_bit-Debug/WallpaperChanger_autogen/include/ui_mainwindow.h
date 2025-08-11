/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.8.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTimeEdit>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QPushButton *previousBtn;
    QPushButton *exitBtn;
    QPushButton *nextBtn;
    QLabel *label;
    QLabel *label_2;
    QLabel *label_3;
    QWidget *layoutWidget;
    QGridLayout *gridLayout;
    QLabel *previousImage;
    QLabel *currentImage;
    QLabel *nextImage;
    QLabel *label_4;
    QLabel *label_5;
    QTimeEdit *timeEdit;
    QLabel *label_6;
    QPushButton *startButton;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(800, 600);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        previousBtn = new QPushButton(centralwidget);
        previousBtn->setObjectName("previousBtn");
        previousBtn->setGeometry(QRect(40, 390, 221, 31));
        exitBtn = new QPushButton(centralwidget);
        exitBtn->setObjectName("exitBtn");
        exitBtn->setGeometry(QRect(680, 500, 81, 31));
        nextBtn = new QPushButton(centralwidget);
        nextBtn->setObjectName("nextBtn");
        nextBtn->setGeometry(QRect(540, 390, 221, 31));
        label = new QLabel(centralwidget);
        label->setObjectName("label");
        label->setGeometry(QRect(500, 450, 261, 41));
        label->setAlignment(Qt::AlignmentFlag::AlignCenter);
        label_2 = new QLabel(centralwidget);
        label_2->setObjectName("label_2");
        label_2->setGeometry(QRect(300, 340, 201, 31));
        label_2->setAlignment(Qt::AlignmentFlag::AlignCenter);
        label_3 = new QLabel(centralwidget);
        label_3->setObjectName("label_3");
        label_3->setGeometry(QRect(40, 340, 221, 31));
        label_3->setAlignment(Qt::AlignmentFlag::AlignCenter);
        layoutWidget = new QWidget(centralwidget);
        layoutWidget->setObjectName("layoutWidget");
        layoutWidget->setGeometry(QRect(20, 80, 761, 231));
        gridLayout = new QGridLayout(layoutWidget);
        gridLayout->setObjectName("gridLayout");
        gridLayout->setContentsMargins(25, 25, 25, 25);
        previousImage = new QLabel(layoutWidget);
        previousImage->setObjectName("previousImage");
        previousImage->setAlignment(Qt::AlignmentFlag::AlignCenter);

        gridLayout->addWidget(previousImage, 0, 0, 1, 1);

        currentImage = new QLabel(layoutWidget);
        currentImage->setObjectName("currentImage");
        currentImage->setAlignment(Qt::AlignmentFlag::AlignCenter);

        gridLayout->addWidget(currentImage, 0, 1, 1, 1);

        nextImage = new QLabel(layoutWidget);
        nextImage->setObjectName("nextImage");
        nextImage->setAlignment(Qt::AlignmentFlag::AlignCenter);

        gridLayout->addWidget(nextImage, 0, 2, 1, 1);

        label_4 = new QLabel(centralwidget);
        label_4->setObjectName("label_4");
        label_4->setGeometry(QRect(540, 340, 221, 31));
        label_4->setAlignment(Qt::AlignmentFlag::AlignCenter);
        label_5 = new QLabel(centralwidget);
        label_5->setObjectName("label_5");
        label_5->setGeometry(QRect(60, 20, 671, 31));
        label_5->setAlignment(Qt::AlignmentFlag::AlignCenter);
        timeEdit = new QTimeEdit(centralwidget);
        timeEdit->setObjectName("timeEdit");
        timeEdit->setGeometry(QRect(420, 450, 81, 41));
        timeEdit->setCurrentSection(QDateTimeEdit::Section::MinuteSection);
        label_6 = new QLabel(centralwidget);
        label_6->setObjectName("label_6");
        label_6->setGeometry(QRect(290, 450, 131, 41));
        startButton = new QPushButton(centralwidget);
        startButton->setObjectName("startButton");
        startButton->setGeometry(QRect(420, 500, 81, 31));
        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 800, 25));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName("statusbar");
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        previousBtn->setText(QCoreApplication::translate("MainWindow", "\303\226nceki", nullptr));
        exitBtn->setText(QCoreApplication::translate("MainWindow", "\303\207\304\261k\304\261\305\237", nullptr));
        nextBtn->setText(QCoreApplication::translate("MainWindow", "Sonraki", nullptr));
        label->setText(QCoreApplication::translate("MainWindow", "Sonraki de\304\237i\305\237ime kalan s\303\274re : 00.00", nullptr));
        label_2->setText(QCoreApplication::translate("MainWindow", "\305\236imdiki masa\303\274st\303\274 arkaplan\304\261", nullptr));
        label_3->setText(QCoreApplication::translate("MainWindow", "\303\226nceki masa\303\274st\303\274 arkaplan\304\261", nullptr));
        previousImage->setText(QCoreApplication::translate("MainWindow", "TextLabel", nullptr));
        currentImage->setText(QCoreApplication::translate("MainWindow", "TextLabel", nullptr));
        nextImage->setText(QCoreApplication::translate("MainWindow", "TextLabel", nullptr));
        label_4->setText(QCoreApplication::translate("MainWindow", "Sonraki masa\303\274st\303\274 arkaplan\304\261", nullptr));
        label_5->setText(QCoreApplication::translate("MainWindow", "Wallpaper Changer", nullptr));
        timeEdit->setDisplayFormat(QCoreApplication::translate("MainWindow", "mm:ss", nullptr));
        label_6->setText(QCoreApplication::translate("MainWindow", "S\303\274reyi de\304\237i\305\237tir :", nullptr));
        startButton->setText(QCoreApplication::translate("MainWindow", "Ayarla", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
