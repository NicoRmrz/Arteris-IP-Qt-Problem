#pragma once
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QVBoxLayout>
#include <QStatusBar>
#include <QPushButton>
#include <QToolButton>
#include "interactiveWindow.h"
#include <QColorDialog>

#define MAINBACKGROUND  QString("rgba(62, 62, 66, 240)")


QT_BEGIN_NAMESPACE

/* Class: Ui_MainWindow

    Creates most GUI object that will be displayed on MainWindow
*/
class Ui_MainWindow
{
public:
    QWidget     *centralwidget;
    QVBoxLayout *mainVLayout;
    interactiveWindow      *mainLabel;
    QStatusBar      *statusbar;
    QToolButton      *selectBtn;
    QPushButton      *removeBtn;
    QPushButton      *updateBtn;
    QColorDialog    *circleColorDialog;
    QColorDialog    *circleBorderColorDialog;

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
     //   mainLabel->setMaximumSize(600,600);
        mainLabel->setSceneRect(50, 50, 500, 500);

        // create layout for window
        mainVLayout = new QVBoxLayout();
        mainVLayout->setObjectName(QString::fromUtf8("mainVLayout"));
        mainVLayout->setContentsMargins(10, 10, 10, 10);
        mainVLayout->setSpacing(0);
        mainVLayout->addWidget(mainLabel);

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



        // set status bar with buttons
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        statusbar->addPermanentWidget(selectBtn, 0);
        statusbar->addPermanentWidget(removeBtn, 0);
        statusbar->addPermanentWidget(updateBtn, 0);
        MainWindow->setStatusBar(statusbar);

        MainWindow->setStyleSheet("background-color: "+ MAINBACKGROUND + "; ");

        // Set final layout on central UI widget
        centralwidget->setLayout(mainVLayout);
        centralwidget->isWindow();

    }    // setupUi
};

namespace Ui
{
    class MainWindow : public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE
