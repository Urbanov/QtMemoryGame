#ifndef CARD_H
#define CARD_H

#include <QGraphicsRectItem>
#include <QPainter>
#include <QGraphicsScene>

class Card : public QObject, public QGraphicsRectItem {

    Q_OBJECT

public:
    enum CardType {
        CARD_XD,
        CARD_TEST
    };

    Card()
    {
        m_active = false;
    }

    void show();
    void hide();
    void paint(QPainter* painter, const QStyleOptionGraphicsItem* option, QWidget* widget) override;
    void mousePressEvent(QGraphicsSceneMouseEvent* event) override;

private:
    bool m_active;
    QGraphicsScene* parent;

signals:
    void selected(Card* card);
};

#endif // CARD_H
