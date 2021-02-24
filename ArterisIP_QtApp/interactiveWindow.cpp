#include "interactiveWindow.h"


interactiveWindow::interactiveWindow(QWidget *parent) :QGraphicsView(parent)
{
    rubberBandEn = false;
    selectBtnEn = false;
    circleRadius = 15;
    borderWidth = 2;

    currPos.setX(0);
    currPos.setY(0);
    circleColor = Qt::blue;
    circleBorderColor = Qt::blue;

    setSizePolicy(QSizePolicy::Minimum, QSizePolicy::Minimum);
    setAlignment(Qt::AlignCenter);
    setBackgroundRole(QPalette::Base);
    setMouseTracking(true);
    //setAutoFillBackground(true);
    setStyleSheet("background-color: rgba(211,211,211, 240); border: none;");
    setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);

    // create scene
    scene = new QGraphicsScene();
    setScene(scene);
}


/* Function: mousePressEvent

        Mouse press event on qgraphics view

    Parameters:

        event - mouse event
*/
void interactiveWindow::mousePressEvent(QMouseEvent *event)
{
    if (event->button() == Qt::LeftButton)
    {
        placeCirPos = mapToScene(event->pos());
        startPos = event->pos();

        if (selectBtnEn)
        {
            if (!rubberBandEn)
            {
                rubberBandEn = true;
                rubberBand = new QRubberBand(QRubberBand::Rectangle, this);
            }
            rubberBand->setGeometry(QRect(startPos, QSize()));
            rubberBand->show();
        }
    }
}

/* Function: mouseMoveEvent

        mouse move event in Qgraphicsview

    Parameters:

        event - mouse event
*/
void interactiveWindow::mouseMoveEvent(QMouseEvent *event)
{
    if (rubberBandEn)
    {
        rubberBand->setGeometry(QRect(startPos, event->pos()).normalized());

    }
}


/* Function: mouseReleaseEvent

        Mouse release event on graphics view

    Parameters:

        event - mouse event
*/
void interactiveWindow::mouseReleaseEvent(QMouseEvent *event)
{
    if (event->button() == Qt::LeftButton)
    {
        if (selectBtnEn)
        {
            rubberBand->hide();
            rubberBandEn = false;

        }
        else
        {
            makeCircle();
        }

    }
    else if (event->button() == Qt::RightButton)
    {

    }
}

/* Function: makeCircle

        Create updated circles for graphics view. 

*/
void interactiveWindow::makeCircle()
{

    QPen pen;
    pen.setWidth(borderWidth);
    pen.setStyle(Qt::SolidLine);
    pen.setBrush(circleBorderColor);
    
    // create ellipse as a Qgraphics item to allow functionality to grab the group of items
    QGraphicsEllipseItem *newCircle = scene->addEllipse(placeCirPos.x(),
                                                        placeCirPos.y(),
                                                        circleRadius,
                                                        circleRadius,
                                                        pen, 
                                                        QBrush(circleColor));
}


void interactiveWindow::setRadius(int radius)
{
    circleRadius = radius;
}

void interactiveWindow::setCircleColor(QColor color)
{
    circleColor = color;
}

void interactiveWindow::setBorderColor(QColor color)
{
    circleBorderColor = color;
}

void interactiveWindow::setBorderWidth(int width)
{
    borderWidth = width;
}

void interactiveWindow::setSelection(bool selectStatus)
{
    selectBtnEn = selectStatus;

    if (selectStatus)
    {
        setCursor(QCursor(Qt::CrossCursor));
    }
    else
    {
        setCursor(QCursor(Qt::ArrowCursor));
    }
}
