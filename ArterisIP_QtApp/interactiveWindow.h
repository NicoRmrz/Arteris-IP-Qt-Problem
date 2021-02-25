// Author: Nico Ramirez
// Arteris IP QT Project

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

#define INIT_COLOR      QColor(Qt::blue)
#define INIT_RADIUS      int(15)
#define INIT_BORDER      int(2)

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
    void removeSelection();
    void updateSelection(bool resize);
    QList< QGraphicsItem *> rubbBandSelection;

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
    bool resize;
    bool rubberBandEn, selectBtnEn;
    QRubberBand *rubberBand;
    QColor circleColor, circleBorderColor;
};
