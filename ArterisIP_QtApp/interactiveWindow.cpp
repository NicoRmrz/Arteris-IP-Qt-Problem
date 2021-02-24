#include "interactiveWindow.h"


interactiveWindow::interactiveWindow(QWidget *parent) :QGraphicsView(parent)
{
    rubberBandEn = false;
    selectBtnEn = false;
    circleRadius = 15;
    borderWidth = 2;

   
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
    setRubberBandSelectionMode(Qt::IntersectsItemShape);

    // create scene
    scene = new QGraphicsScene();
    setScene(scene);

    connect(scene, &QGraphicsScene::selectionChanged, this, &interactiveWindow::newSelection);
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
        endPos = event->pos();

        if (selectBtnEn)
        {
            rubberBand->hide();
            rubberBandEn = false;

            // fix ability to rubber band in any orientation
            if (startPos.x() > endPos.x())
            {
                int temp = startPos.x();
                startPos.setX(endPos.x());
                endPos.setX(temp);
            }
            if (startPos.y() > endPos.y())
            {
                int temp = startPos.y();
                startPos.setY(endPos.y());
                endPos.setY(temp);
            }


            rubbBandSelection = items(QRect(startPos, endPos), Qt::IntersectsItemShape);
            showSelectedItems();



        }
        else
        {
            makeCircle(placeCirPos);
        }

    }
    else if (event->button() == Qt::RightButton)
    {

    }
}

/* Function: makeCircle

        Create updated circles for graphics view. 

*/
void interactiveWindow::makeCircle(QPointF circleCord)
{

    QPen pen;
    pen.setWidth(borderWidth);
    pen.setStyle(Qt::SolidLine);
    pen.setBrush(circleBorderColor);
    
    // create ellipse as a Qgraphics item to allow functionality to grab the group of items
    QGraphicsItem *newCircle = scene->addEllipse(circleCord.x(),
                                                        circleCord.y(),
                                                        circleRadius,
                                                        circleRadius,
                                                        pen, 
                                                        QBrush(circleColor));
    newCircle->setFlags(QGraphicsItem::ItemIsSelectable);
    newCircle->setData(0, QPointF(circleCord.x(), circleCord.y()));
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

void interactiveWindow::showSelectedItems()
{
    QList<QGraphicsItem *> allItems;
    allItems = items();

    // reset selection
    for (int i = 0; i < allItems.size(); i++)
    {
        allItems[i]->setSelected(false);
    }

    // show new selection
    for (int i = 0; i < rubbBandSelection.size(); i++)
    {
      
        rubbBandSelection[i]->setSelected(true);

  
        //setBorderColor(Qt::yellow);
        //QPointF position = (rubbBandSelection[i]->data(0)).toPointF();
       // makeCircle(position);
    }

  

        
}
void interactiveWindow::newSelection()
{
    QList<QGraphicsItem *> allItems;
    allItems = scene->selectedItems();
}

