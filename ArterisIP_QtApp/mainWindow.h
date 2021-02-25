#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_MainWindow.h"

class mainWindow : public QMainWindow
{
    Q_OBJECT

public:
    mainWindow(QWidget *parent = Q_NULLPTR);
    ~mainWindow();

private:
    Ui::MainWindow *ui;
    void onSelect(bool checked);
    void onRemove();
    void onCircleColor();
    void onCircleBorderColor();
    void onRadiusSlider(int value);
    void onWidthSlider(int value);
};
