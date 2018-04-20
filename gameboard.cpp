#include "gameboard.h"
#include <QGraphicsView>

GameBoard::GameBoard(QObject* parent)
    : QGraphicsScene(parent)
    , m_width(DEFAULT_WIDTH)
    , m_height(DEFAULT_HEIGHT)
    , m_type(DEFAULT_TYPE)
    , m_first_card(nullptr)
    , m_second_card(nullptr)
    , m_manager()
    , m_enabled(true)
{
    setBackgroundBrush(QPixmap(":/images/default/background.png"));
    start();
}

void GameBoard::start()
{
    m_manager.initializeGenerator(m_width * m_height);
    m_manager.loadImages(m_type);
    for (int pos_x = 0; pos_x < m_width; ++pos_x) {
        for (int pos_y = 0; pos_y < m_height; ++pos_y) {
            Card* card = new Card(std::forward<CardData>(m_manager.nextCard()));
            card->setRect(0, 0, Card::SIZE, Card::SIZE);
            card->setPos(Card::TILE_SIZE * pos_x, Card::TILE_SIZE * pos_y);
            connect(card, &Card::selected, this, &GameBoard::cardSelected);
            connect(card, &Card::animationFinished, this, &GameBoard::animationFinished);
            addItem(card);
        }
    }
    setSceneRect(0, 0, m_width * Card::TILE_SIZE - Card::SPACE, m_height * Card::TILE_SIZE - Card::SPACE);
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
}

void GameBoard::newGame()
{
    m_first_card = nullptr;
    m_second_card = nullptr;
    m_enabled = true;
    QGraphicsScene::clear();
    start();
}

void GameBoard::setSize(int width, int height)
{
    m_width = width;
    m_height = height;
    m_type = CardData::ImageType::animals;
}


