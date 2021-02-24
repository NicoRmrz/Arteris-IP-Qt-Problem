#include "mainWindow.h"

mainWindow::mainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    // call out GUI objects created in ui_MainWindow.h
    ui->setupUi(this);
    setWindowTitle("Qt Program");


    connect(ui->selectBtn, &QToolButton::toggled, this, &mainWindow::onSelect);
    connect(ui->removeBtn, &QPushButton::released, this, &mainWindow::onRemove);
    connect(ui->updateBtn, &QPushButton::released, this, &mainWindow::onUpdate);

}

void mainWindow::onSelect(bool checked)
{
    ui->mainLabel->setSelection(checked);
}

void mainWindow::onRemove()
{
    QColorDialog *circleColorDialog = new QColorDialog();
    ui->mainLabel->setCircleColor(circleColorDialog->getColor());
}

void mainWindow::onUpdate()
{

}