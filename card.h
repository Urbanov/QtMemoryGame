#ifndef CARD_H
#define CARD_H

#include <QGraphicsRectItem>
#include <QPainter>
#include <QGraphicsScene>
#include "carddata.h"
#include "cardanimation.h"

class Card : public QObject, public QGraphicsRectItem {

    Q_OBJECT
    Q_PROPERTY(bool state MEMBER m_active READ state WRITE setState)
    Q_PROPERTY(qreal opacity READ opacity WRITE setOpacity)
    Q_PROPERTY(qreal scale READ scale WRITE setScale)

public:
    static constexpr int SIZE = 90;
    static constexpr int SPACE = 10;
    static constexpr int TILE_SIZE = SIZE + SPACE;
    static constexpr int RADIUS = 10;

    Card(CardData&& data);
    void flip();
    void remove();
    void paint(QPainter* painter, const QStyleOptionGraphicsItem* option, QWidget* widget) override;
    void mousePressEvent(QGraphicsSceneMouseEvent* event) override;
    int id() const;
    bool state() const;
    void setState(bool state);
    qreal scale() const;
    void setScale(qreal scale);

private:
    CardData m_data;
    bool m_active;
    CardAnimation m_animation;
    qreal m_scale;

signals:
    void selected(Card* card) const;
    void animationFinished() const;
};

#endif // CARD_H
