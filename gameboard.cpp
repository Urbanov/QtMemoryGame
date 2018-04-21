#include "gameboard.h"
#include <QGraphicsView>

GameBoard::GameBoard(const Settings* settings, QObject* parent)
    : m_settings(settings)
    , QGraphicsScene(parent)
    , m_first_card(nullptr)
    , m_second_card(nullptr)
    , m_remaining(0)
    , m_manager()
    , m_enabled(true)
{
    setBackgroundBrush(QPixmap(":/generic/background.png"));
    start();
}

void GameBoard::start()
{
    int width = m_settings->width();
    int height = m_settings->height();

    m_remaining = width * height;
    m_manager.initializeGenerator(width * height);
    m_manager.loadImages(m_settings->imageType());
    for (int pos_x = 0; pos_x < width; ++pos_x) {
        for (int pos_y = 0; pos_y < height; ++pos_y) {
            Card* card = new Card(std::forward<CardData>(m_manager.nextCard()));
            card->setRect(0, 0, Card::SIZE, Card::SIZE);
            card->setPos(Card::TILE_SIZE * pos_x, Card::TILE_SIZE * pos_y);
            connect(card, &Card::selected, this, &GameBoard::cardSelected);
            connect(card, &Card::animationFinished, this, &GameBoard::animationFinished);
            addItem(card);
        }
    }
    setSceneRect(0, 0, width * Card::TILE_SIZE - Card::SPACE, height * Card::TILE_SIZE - Card::SPACE);
    m_timer.start();
}

void GameBoard::cardSelected(Card* card)
{
    // animation running, ignore
    if (!m_enabled) {
        return;
    }

    // first card
    if (!m_first_card) {
        m_first_card = card;
        card->flip();
        m_enabled = false;
        return;
    }

    // same card, ignore
    if (m_first_card == card) {
        return;
    }

    // second card
    m_second_card = card;
    card->flip();
    m_enabled = false;
}

void GameBoard::animationFinished()
{
    // duplicated signal, ignore
    if (m_enabled) {
        return;
    }

    // after second card
    if (m_first_card && m_second_card) {

        // match
        if (m_first_card->id() == m_second_card->id()) {
            m_remaining -= 2;
            m_first_card->remove();
            m_second_card->remove();
        }

        // mismatch
        else {
            m_first_card->flip();
            m_second_card->flip();
        }

        // clean
        m_first_card = nullptr;
        m_second_card = nullptr;
        return;
    }

    // no animations
    m_enabled = true;

    // no more cards remaining
    if (m_remaining == 0) {
        emit gameEnded(m_timer.elapsed() / 1000);
    }
}

void GameBoard::newGame()
{
    m_first_card = nullptr;
    m_second_card = nullptr;
    m_enabled = true;
    m_remaining = 0;
    QGraphicsScene::clear();
    start();
}
