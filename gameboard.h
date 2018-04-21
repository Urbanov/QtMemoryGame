#ifndef GAMEBOARD_H
#define GAMEBOARD_H

#include <QGraphicsScene>
#include "card.h"
#include "carddatamanager.h"
#include "settings.h"
#include <QElapsedTimer>

class GameBoard : public QGraphicsScene {

    Q_OBJECT

public:
    GameBoard(const Settings* settings, QObject* parent);

private:
    const Settings* m_settings;
    Card* m_first_card;
    Card* m_second_card;
    int m_remaining;
    CardDataManager m_manager;
    bool m_enabled;
    QElapsedTimer m_timer;

    void start();

signals:
    void gameEnded(int time);

public slots:
    void newGame();

private slots:
    void cardSelected(Card* card);
    void animationFinished();
};

#endif // GAMEBOARD_H
