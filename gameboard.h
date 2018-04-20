#ifndef GAMEBOARD_H
#define GAMEBOARD_H

#include <QGraphicsScene>
#include "card.h"
#include "carddatamanager.h"

class GameBoard : public QGraphicsScene {
public:
    GameBoard(QObject* parent);
    void start();

private:
    static constexpr int DEFAULT_WIDTH = 3;
    static constexpr int DEFAULT_HEIGHT = 4;
    static constexpr CardData::ImageType DEFAULT_TYPE = CardData::ImageType::cars;

    int m_width;
    int m_height;
    CardData::ImageType m_type;
    Card* m_first_card;
    Card* m_second_card;
    CardDataManager m_manager;
    bool m_enabled;

public slots:
    void newGame();
    void setSize(int width, int height);

private slots:
    void cardSelected(Card* card);
    void animationFinished();
};

#endif // GAMEBOARD_H
