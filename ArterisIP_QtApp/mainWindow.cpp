#include "mainWindow.h"

mainWindow::mainWindow(QWidget *parent)
    : QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    // call out GUI objects created in ui_MainWindow.h
    ui->setupUi(this);
    setWindowTitle("Qt Program");
    setStyleSheet("background-color: " + MAINBACKGROUND + "; ");
    setMinimumWidth(800);

    connect(ui->selectBtn, &QToolButton::toggled, this, &mainWindow::onSelect);
    connect(ui->removeBtn, &QPushButton::released, this, &mainWindow::onRemove);
    connect(ui->circleClrBtn, &QPushButton::released, this, &mainWindow::onCircleColor);
    connect(ui->circleBorderClrBtn, &QPushButton::released, this, &mainWindow::onCircleBorderColor);
    connect(ui->radiusSlider, &QSlider::sliderMoved, this, &mainWindow::onRadiusSlider);

}

/* Function: onCircleColor

        Slot to change mode of mouse click to selection mode

    Paramters:

        checked   - check status of tool button
*/
void mainWindow::onSelect(bool checked)
{
    ui->selectBtn->setDown(checked);
    ui->mainLabel->setSelection(checked);
}

/* Function: onCircleColor

        Slot to remove all items in selection
*/
void mainWindow::onRemove()
{
    ui->mainLabel->removeSelection();
}

/* Function: onCircleColor

        Slot to update color of circle
*/
void mainWindow::onCircleColor()
{
    QColorDialog *colorDialog = new QColorDialog(this);
    QColor color = colorDialog->getColor();
    QVariant variant = color;
    QString colcode = variant.toString();

    ui->currCircleClr->setStyleSheet("background-color: " + colcode + ";");
    ui->mainLabel->setCircleColor(color);

    //update selection
    if (ui->mainLabel->rubbBandSelection.size() > 0)
    {
        ui->mainLabel->updateSelection();
    }
}

/* Function: onCircleBorderColor

        Slot to update color of circle border
*/
void mainWindow::onCircleBorderColor()
{
    QColorDialog *colorDialog = new QColorDialog(this);
    QColor color = colorDialog->getColor();
    QVariant variant = color;
    QString colcode = variant.toString();

    ui->currCircleBorderClr->setStyleSheet("background-color:  " + colcode + ";");
    ui->mainLabel->setBorderColor(color);

    //update selection
    if (ui->mainLabel->rubbBandSelection.size() > 0)
    {
        ui->mainLabel->updateSelection();
    }
}

/* Function: onRadiusSlider

        Slot to update circle radius

    Paramters:

        value   - radius of circle
*/
void mainWindow::onRadiusSlider(int value)
{
    ui->mainLabel->setRadius(value);

    //update selection
    if (ui->mainLabel->rubbBandSelection.size() > 0)
    {
        ui->mainLabel->updateSelection();
    }
}

/* Function: onWidthSlider

        Slot to update circle border width

    Paramters:

        value   - width of circle border
*/
void mainWindow::onWidthSlider(int value)
{
    ui->mainLabel->setBorderWidth(value);

    //update selection
    if (ui->mainLabel->rubbBandSelection.size() > 0)
    {
        ui->mainLabel->updateSelection();
    }
}

/* Deconstructor */
mainWindow::~mainWindow()
{
    delete ui;
}
