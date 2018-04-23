#include "card.h"

Card::Card(CardData&& data)
    : m_data(std::move(data))
    , m_animation(this)
    , m_active(false)
    , m_scale(1)
{}

void Card::paint(QPainter* painter, const QStyleOptionGraphicsItem* /*option*/, QWidget* /*widget*/)
{
    if (m_active) {
        painter->setBrush(QBrush(m_data.front()));
    }
    else {
        painter->setBrush(QBrush(m_data.back()));
    }
    painter->translate((1.0 - m_scale) * 0.5 * SIZE, 0);
    painter->scale(m_scale, 1);
    painter->drawRoundedRect(rect(), RADIUS, RADIUS);
}

void Card::mousePressEvent(QGraphicsSceneMouseEvent* /*event*/)
{
    emit selected(this);
}

int Card::id() const
{
    return m_data.id();
}

bool Card::state() const
{
    return m_active;
}

void Card::setState(bool state)
{
    m_active = state;
}

qreal Card::scale() const
{
    return m_scale;
}

void Card::setScale(qreal scale)
{
    m_scale = scale;
}

void Card::flip()
{
    if (m_active) {
        m_animation.showBack();
    }
    else {
        m_animation.showFront();
    }
}

void Card::remove()
{
    m_animation.fadeOut();
}
