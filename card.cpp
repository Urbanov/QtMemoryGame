#include "card.h"
#include <QtDebug>

void Card::paint(QPainter* painter, const QStyleOptionGraphicsItem* option, QWidget* widget)
{
    if (m_active) {
        painter->setBrush(QBrush((Qt::magenta)));
    }
    else {
        painter->setBrush(QBrush((Qt::black)));
    }
    painter->drawRect(rect());
}

void Card::mousePressEvent(QGraphicsSceneMouseEvent* event)
{
    if (!m_active) {
        m_active = true;
        emit selected(this);
    }
}

void Card::show()
{
    m_active = true;
    update();
}

void Card::hide()
{
    m_active = false;
    update();
}
