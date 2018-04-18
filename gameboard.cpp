#include "gameboard.h"
#include <QtDebug>

GameBoard::GameBoard(int width, int height)
    : m_width(width)
    , m_height(height)
    , m_previous(nullptr)
    , m_timer(new QTimer)
{
    m_timer->setInterval(COOLDOWN_TIME);
    m_timer->setSingleShot(true);
    start();
}

void GameBoard::start()
{
    for (int pos_x = 0; pos_x < m_width; ++pos_x) {
        for (int pos_y = 0; pos_y < m_height; ++pos_y) {
            Card* card = new Card();
            card->setRect(0, 0, CARD_SIZE, CARD_SIZE);
            card->setPos((CARD_SIZE + CARD_SPACE) * pos_x, (CARD_SIZE + CARD_SPACE) * pos_y);
            connect(card, &Card::selected, this, &GameBoard::cardSelected);
            this->addItem(card);
        }
    }
}

void GameBoard::reset()
{
    QGraphicsScene::clear();
}

void GameBoard::cardSelected(Card* card)
{
    qDebug() << "XDDDDDD";

    card->show();

    if (!m_previous) {
        m_previous = card;
    }
    else {


    }
}


