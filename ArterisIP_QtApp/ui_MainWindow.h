// Author: Nico Ramirez
// Arteris IP QT Project

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
#include <QLineEdit>
#include "interactiveWindow.h"
#include <QColorDialog>
#include <QColor>
#include <QSplitter>
#include <QSlider>

#define MAINBACKGROUND  QString("rgba(62, 62, 66, 240)")
#define SPLITTER_PRESSED  QString("rgba(72,146,73,100)")
#define SPLITTER_ICON  QString(":/mainWindow/icons/openSplitter.png")
#define BUTTON_IDLE   QString("qlineargradient(spread:pad x1 : 0, y1 : 0, x2 : 0, y2 : 1, "\
                                            "stop:0 rgba(62, 62, 62, 200), "\
                                            "stop:0.3 rgba(100, 100, 100, 200), "\
                                            "stop:1 rgba(255,255,255,200)) ")

#define BUTTON_PRESSED   QString("qlineargradient(spread:pad x1 : 0, y1 : 0, x2 : 0, y2 : 1, "\
                                            "stop:0 rgba(255, 255, 255, 200), "\
                                            "stop:0.7 rgba(100, 100, 100, 200), "\
                                            "stop:1 rgba(62,62,62,200)) ")


QT_BEGIN_NAMESPACE

/* Class: Ui_MainWindow

    Creates GUI object that will be displayed on MainWindow
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
    QSplitter       *horizontalSplitter;
    QWidget         *rightContainer;
    QHBoxLayout     *circleClrLayout;
    QHBoxLayout     *circleBorderClrLayout;
    QVBoxLayout     *circleRadiusLayout;
    QVBoxLayout     *circleBorderWidthLayout;
    QSlider         *radiusSlider;
    QSlider         *widthSlider;
    QPushButton      *circleClrBtn;
    QPushButton      *circleBorderClrBtn;
    QLabel          *currCircleClr;
    QLabel          *currCircleBorderClr;
    QLabel          *radiusLabel;
    QLabel          *widthLabel;


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
        mainLabel->setMinimumSize(600, 500);
        mainLabel->setSceneRect(50, 50, 600, 500);

        // create buttons to go on status bar
        selectBtn = new QToolButton(MainWindow);
        selectBtn->setObjectName(QString::fromUtf8("selectBtn"));
        selectBtn->setMinimumWidth(100);
        selectBtn->setMaximumWidth(100);
        selectBtn->setMinimumHeight(30);
        selectBtn->setText("Select");
        selectBtn->setCheckable(true);
        selectBtn->setStyleSheet(   "QToolButton {background-color: " + BUTTON_IDLE + "; color: black; border: 1px solid black; border-radius: 4px; } "\
                                    "QToolButton:hover{color: white; } "\
                                    "QToolButton:pressed {background-color:  " + BUTTON_PRESSED + "; color: white; border: 1px solid gray;} "\
                                    "QToolButton:off { background-color:  " + BUTTON_IDLE + "; color: gray; } ");

        removeBtn = new QPushButton(MainWindow);
        removeBtn->setObjectName(QString::fromUtf8("removeBtn"));
        removeBtn->setMinimumWidth(125);
        removeBtn->setMaximumWidth(125);
        removeBtn->setMinimumHeight(30);
        removeBtn->setText("Remove Selection");
        removeBtn->setStyleSheet(   "QPushButton {background-color: " + BUTTON_IDLE + "; color: black; border: 1px solid black; border-radius: 4px; } "\
                                    "QPushButton:hover{color: white; } "\
                                    "QPushButton:pressed {background-color:  " + BUTTON_PRESSED + "; color: white; border: 1px solid gray;} "\
                                    "QPushButton:off {background-color:  " + BUTTON_IDLE + "; color: gray; } ");


        // circle color
        QVariant *variant = new QVariant(INIT_COLOR);
        QString *colcode = new QString(variant->toString());

        circleClrBtn = new QPushButton(MainWindow);
        circleClrBtn->setObjectName(QString::fromUtf8("circleClrBtn"));
        circleClrBtn->setMinimumWidth(125);
        circleClrBtn->setMaximumWidth(125);
        circleClrBtn->setMinimumHeight(30);
        circleClrBtn->setText("Circle Color");
        circleClrBtn->setStyleSheet("QPushButton {background-color: " + BUTTON_IDLE + "; color: black; border: 1px solid black; border-radius: 4px; } "\
                                    "QPushButton:hover{color: white; } "\
                                    "QPushButton:pressed {background-color:  " + BUTTON_PRESSED + "; color: white; border: 1px solid gray;} "\
                                    "QPushButton:off {background-color:  " + BUTTON_IDLE + "; color: gray; } ");

        currCircleClr = new QLabel(MainWindow);
        currCircleClr->setMinimumSize(30, 30);
        currCircleClr->setMaximumSize(30, 30);
        currCircleClr->setStyleSheet("background-color: "+ *colcode +";");

        circleClrLayout = new QHBoxLayout();
        circleClrLayout->setObjectName(QString::fromUtf8("circleClrLayout"));
        circleClrLayout->setContentsMargins(0, 0, 0, 0);
        circleClrLayout->setSpacing(10);
        circleClrLayout->addWidget(circleClrBtn);
        circleClrLayout->addWidget(currCircleClr);
        

        // circle border
        circleBorderClrBtn = new QPushButton(MainWindow);
        circleBorderClrBtn->setObjectName(QString::fromUtf8("circleBorderClrBtn"));
        circleBorderClrBtn->setMinimumWidth(125);
        circleBorderClrBtn->setMaximumWidth(125);
        circleBorderClrBtn->setMinimumHeight(30);
        circleBorderClrBtn->setText("Circle Border Color");
        circleBorderClrBtn->setStyleSheet(  "QPushButton {background-color: " + BUTTON_IDLE + "; color: black; border: 1px solid black; border-radius: 4px; } "\
                                            "QPushButton:hover{color: white; } "\
                                            "QPushButton:pressed {background-color:  " + BUTTON_PRESSED + "; color: white; border: 1px solid gray;} "\
                                            "QPushButton:off {background-color:  " + BUTTON_IDLE + "; color: gray; } ");

        currCircleBorderClr = new QLabel(MainWindow);
        currCircleBorderClr->setMinimumSize(30, 30);
        currCircleBorderClr->setMaximumSize(30, 30);
        currCircleBorderClr->setStyleSheet("background-color:  " + *colcode + ";");

        circleBorderClrLayout = new QHBoxLayout();
        circleBorderClrLayout->setObjectName(QString::fromUtf8("circleBorderClrLayout"));
        circleBorderClrLayout->setContentsMargins(0, 0, 0, 0);
        circleBorderClrLayout->setSpacing(10);
        circleBorderClrLayout->addWidget(circleBorderClrBtn);
        circleBorderClrLayout->addWidget(currCircleBorderClr);

        // circle radius
        radiusSlider = new QSlider(MainWindow);
        radiusSlider->setMinimumSize(150, 25);
        radiusSlider->setMaximumSize(150, 25);
        radiusSlider->setMaximum(100);
        radiusSlider->setMinimum(5);
        radiusSlider->setOrientation(Qt::Horizontal);
        radiusSlider->setValue(INIT_RADIUS);

        radiusLabel = new QLabel(MainWindow);
        radiusLabel->setMinimumSize(150, 25);
        radiusLabel->setMaximumSize(150, 25);
        radiusLabel->setAlignment(Qt::AlignCenter);
        radiusLabel->setText("Radius");
        radiusLabel->setStyleSheet("color: white;font: 14px bold;");

        circleRadiusLayout = new QVBoxLayout();
        circleRadiusLayout->setObjectName(QString::fromUtf8("circleRadiusLayout"));
        circleRadiusLayout->setContentsMargins(0, 0, 0, 0);
        circleRadiusLayout->setSpacing(0);
        circleRadiusLayout->addWidget(radiusLabel, Qt::AlignCenter);
        circleRadiusLayout->addWidget(radiusSlider);

        // circle border width
        widthSlider = new QSlider(MainWindow);
        widthSlider->setMinimumSize(150, 25);
        widthSlider->setMaximumSize(150, 25);
        widthSlider->setMaximum(20);
        widthSlider->setMinimum(0);
        widthSlider->setOrientation(Qt::Horizontal);
        widthSlider->setValue(INIT_BORDER);

        widthLabel = new QLabel(MainWindow);
        widthLabel->setMinimumSize(150, 25);
        widthLabel->setMaximumSize(150, 25);
        widthLabel->setAlignment(Qt::AlignCenter);
        widthLabel->setText("Border Width");
        widthLabel->setStyleSheet("color: white;font: 14px bold;");

        circleBorderWidthLayout = new QVBoxLayout();
        circleBorderWidthLayout->setObjectName(QString::fromUtf8("circleBorderWidthLayout"));
        circleBorderWidthLayout->setContentsMargins(0, 0, 0, 0);
        circleBorderWidthLayout->setSpacing(0);
        circleBorderWidthLayout->addWidget(widthLabel, Qt::AlignCenter);
        circleBorderWidthLayout->addWidget(widthSlider);


        // final right settings layout
        rightLayout = new QVBoxLayout();
        rightLayout->setObjectName(QString::fromUtf8("rightLayout"));
        rightLayout->setContentsMargins(10, 10, 10, 10);
        rightLayout->setSpacing(0);
        rightLayout->addLayout(circleClrLayout);
        rightLayout->addLayout(circleBorderClrLayout);
        rightLayout->addLayout(circleRadiusLayout);
        rightLayout->addLayout(circleBorderWidthLayout);

        rightContainer = new QWidget(MainWindow);
        rightContainer->setLayout(rightLayout);
        rightContainer->setMaximumWidth(200);

        horizontalSplitter = new QSplitter(MainWindow);
        horizontalSplitter->addWidget(mainLabel);
        horizontalSplitter->addWidget(rightContainer);
        horizontalSplitter->setStyleSheet(  "QSplitter::handle {image:url("+ SPLITTER_ICON +");}"\
                                            "QSplitter::handle:horizontal{width: 10px;} "\
                                            "QSplitter::handle:vertical{height: 20px; }"\
                                            "QSplitter::handle:pressed{background-color: "+ SPLITTER_PRESSED +";}");

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
        statusbar->setStyleSheet("QStatusBar::item {border: none; }");

       // statusbar->addPermanentWidget(updateBtn, 0);
        MainWindow->setStatusBar(statusbar);

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
