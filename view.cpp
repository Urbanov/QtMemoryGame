#include "view.h"
#include <QGraphicsScene>

View::View()
{
    setRenderHints(QPainter::Antialiasing | QPainter::SmoothPixmapTransform);
}

void View::resizeEvent(QResizeEvent* /*event*/)
{
    fitInView(sceneRect(), Qt::KeepAspectRatio);
}
