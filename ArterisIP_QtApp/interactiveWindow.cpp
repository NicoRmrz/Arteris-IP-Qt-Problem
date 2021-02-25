#include "interactiveWindow.h"


interactiveWindow::interactiveWindow(QWidget *parent) :QGraphicsView(parent)
{
    rubberBandEn = false;
    selectBtnEn = false;
    updateEn = false;
    circleRadius = INIT_RADIUS;
    borderWidth = INIT_BORDER;
    circleColor = INIT_COLOR;
    circleBorderColor = INIT_COLOR;

    setSizePolicy(QSizePolicy::Minimum, QSizePolicy::Minimum);
    setAlignment(Qt::AlignCenter);
    setBackgroundRole(QPalette::Base);
    setMouseTracking(true);
    setAutoFillBackground(true);
    setStyleSheet("background-color: rgba(211,211,211, 240); border: none;");
    setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setRubberBandSelectionMode(Qt::IntersectsItemShape);

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

    if (updateEn)
    {
        newCircle->setSelected(false);
    }

}

/* Function: setRadius

        Update class radius variable

    Paramters:

        radius   - radius value
*/
void interactiveWindow::setRadius(int radius)
{
    circleRadius = radius;
}

/* Function: setCircleColor

        Update class variable of the circle color

    Paramters:

        color   - color to update circle
*/
void interactiveWindow::setCircleColor(QColor color)
{
    circleColor = color;
}

/* Function: setBorderColor

        Update class variable of the circle border color

    Paramters:

        color   - color to update circle border
*/
void interactiveWindow::setBorderColor(QColor color)
{
    circleBorderColor = color;
}

/* Function: setBorderWidth

        Update class border width variable

    Paramters:

        width   - width value
*/
void interactiveWindow::setBorderWidth(int width)
{
    borderWidth = width;
}

/* Function: setSelection

        Set selection mode of interactive window widget

    Paramters:

        selectStatus   - selectio mode status
*/
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

/* Function: showSelectedItems

        Show new slection on new rubber band 
*/
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
    }
}

/* Function: removeSelection

        Remove items in rubber band
*/
void interactiveWindow::removeSelection()
{
    // remove selection
    for (int i = 0; i < rubbBandSelection.size(); i++)
    {
        delete rubbBandSelection[i];
    }
}

/* Function: updateSelection

        Update Items in rubber band
*/
void interactiveWindow::updateSelection()
{
   // showSelectedItems();
    updateEn = true;
    for (int i = 0; i < rubbBandSelection.size(); i++)
    {
       // rubbBandSelection[i]->hide();
        QPointF position = (rubbBandSelection[i]->data(0)).toPointF();

        makeCircle(position);
        delete rubbBandSelection[i];

    }
    updateEn = false;
}