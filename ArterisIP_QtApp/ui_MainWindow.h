#pragma once
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QHBoxLayout>
#include <QWidget>
#include <QStatusBar>
#include <QPushButton>
#include <QToolButton>
#include "interactiveWindow.h"
#include <QColorDialog>
#include <QSplitter>

#define MAINBACKGROUND  QString("rgba(62, 62, 66, 240)")


QT_BEGIN_NAMESPACE

/* Class: Ui_MainWindow

    Creates most GUI object that will be displayed on MainWindow
*/
class Ui_MainWindow
{
public:
    QWidget     *centralwidget;
    QHBoxLayout *mainLayout;
    QVBoxLayout *rightLayout;
    interactiveWindow      *mainLabel;
    QStatusBar      *statusbar;
    QToolButton      *selectBtn;
    QPushButton      *removeBtn;
    QPushButton      *updateBtn;
    QColorDialog    *circleColorDialog;
    QColorDialog    *circleBorderColorDialog;
    QSplitter       *horizontalSplitter;
    QWidget         *rightContainer;

    /* Function: setupUi

        Function creating and laying out all UI Objects
    */
    void setupUi(QMainWindow *MainWindow)
    {
        // Create main central widget 
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        MainWindow->setCentralWidget(centralwidget);

        // make main label with for user interaction
        mainLabel = new interactiveWindow(MainWindow);
        mainLabel->setObjectName(QString::fromUtf8("mainLabel"));
        mainLabel->setMinimumSize(500,500);
        mainLabel->setSceneRect(50, 50, 500, 500);



        // create buttons to go on status bar
        selectBtn = new QToolButton(MainWindow);
        selectBtn->setObjectName(QString::fromUtf8("selectBtn"));
        selectBtn->setCheckable(true);       
        selectBtn->setMinimumWidth(100);
        selectBtn->setMaximumWidth(100);
        selectBtn->setText("select");       
        
        removeBtn = new QPushButton(MainWindow);
        removeBtn->setObjectName(QString::fromUtf8("removeBtn"));
        removeBtn->setMinimumWidth(100);
        removeBtn->setMaximumWidth(100);
        removeBtn->setText("remove");

        updateBtn = new QPushButton(MainWindow);
        updateBtn->setObjectName(QString::fromUtf8("updateBtn"));
        updateBtn->setMinimumWidth(100);
        updateBtn->setMaximumWidth(100);
        updateBtn->setText("update");


        rightLayout = new QVBoxLayout();
        rightLayout->setObjectName(QString::fromUtf8("mainVLayout"));
        rightLayout->setContentsMargins(10, 10, 10, 10);
        rightLayout->setSpacing(0);
        rightLayout->addWidget(updateBtn);

        rightContainer = new QWidget(MainWindow);
        rightContainer->setLayout(rightLayout);
        rightContainer->setMaximumWidth(200);

        horizontalSplitter = new QSplitter(MainWindow);
        horizontalSplitter->addWidget(mainLabel);
        horizontalSplitter->addWidget(rightContainer);

    // create layout for window
        mainLayout = new QHBoxLayout();
        mainLayout->setObjectName(QString::fromUtf8("mainVLayout"));
        mainLayout->setContentsMargins(10, 10, 10, 10);
        mainLayout->setSpacing(0);
        mainLayout->addWidget(horizontalSplitter);

        // set status bar with buttons
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        statusbar->addPermanentWidget(selectBtn, 0);
        statusbar->addPermanentWidget(removeBtn, 0);
       // statusbar->addPermanentWidget(updateBtn, 0);
        MainWindow->setStatusBar(statusbar);

        MainWindow->setStyleSheet("background-color: "+ MAINBACKGROUND + "; ");

        // Set final layout on central UI widget
        centralwidget->setLayout(mainLayout);
        centralwidget->isWindow();

    }    // setupUi
};

namespace Ui
{
    class MainWindow : public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE
