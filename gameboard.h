#ifndef GAMEBOARD_H
#define GAMEBOARD_H

#include <QGraphicsScene>
#include <QTimer>
#include "card.h"

class GameBoard : public QGraphicsScene
{
public:
    GameBoard(int width, int height);
    void start();
    void reset();

private:
    static constexpr int CARD_SIZE = 90;
    static constexpr int CARD_SPACE = 10;
    static constexpr int COOLDOWN_TIME = 1000;
    int m_width;
    int m_height;
    Card* m_previous;
    QTimer* m_timer;

private slots:
    void cardSelected(Card* card);
};

#endif // GAMEBOARD_H
