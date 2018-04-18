#include "view.h"
#include <QGraphicsScene>

void View::resizeEvent(QResizeEvent* event)
{
    fitInView(scene()->sceneRect(), Qt::KeepAspectRatio);
}
