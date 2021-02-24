#pragma once
#pragma once

#include <QWidget>
#include <QtWidgets/QLabel>
#include <QGraphicsView>
#include <QGraphicsScene>
#include <QMouseEvent>
#include <QPaintEvent>
#include <QToolTip>
#include <QList>
#include <QGraphicsEllipseItem>
#include <QRubberBand>

#define colorIcon QString(":/mainWindow/icons/colorIcon.jpg")

class interactiveWindow : public QGraphicsView
{
    Q_OBJECT

public:
    interactiveWindow(QWidget *parent);
    ~interactiveWindow() {};
    void setRadius(int radius);
    void setCircleColor(QColor color);

    void setBorderColor(QColor color);
    void setBorderWidth(int width);
    void setSelection(bool selectStatus);

protected:
    void mouseMoveEvent(QMouseEvent *event);
    void mousePressEvent(QMouseEvent *event);
    void mouseReleaseEvent(QMouseEvent *event);

private:

    void makeCircle(QPointF circleCord);
    void showSelectedItems();
    QGraphicsScene *scene;
    QPoint startPos, endPos;
    QPointF placeCirPos;
    int circleRadius, borderWidth;
    bool rubberBandEn, selectBtnEn;
    QList< QGraphicsItem *> rubbBandSelection;
    QRubberBand *rubberBand;
    QColor circleColor, circleBorderColor;
};
