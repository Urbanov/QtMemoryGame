#ifndef CARDANIMATION_H
#define CARDANIMATION_H

#include <QPropertyAnimation>
class Card;

class CardAnimation : public QObject {

    Q_OBJECT

public:
    CardAnimation(Card* card);
    static QVariant boolInterpolator(const bool& from, const bool& to, qreal progress);
    void showFront();
    void showBack();
    void fadeOut();

private:
    static constexpr int FLIP_DURATION = 400;
    static constexpr int COOLDOWN = 400;
    QPropertyAnimation m_image_to_front;
    QPropertyAnimation m_image_to_back;
    QPropertyAnimation m_scale_to_front;
    QPropertyAnimation m_scale_to_back;
    QPropertyAnimation m_fade_out;
};

#endif // CARDANIMATION_H
