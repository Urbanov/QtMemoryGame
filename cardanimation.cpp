#include "cardanimation.h"
#include "card.h"

CardAnimation::CardAnimation(Card* card)
    : m_image_to_front(card, "state")
    , m_image_to_back(card, "state")
    , m_scale_to_front(card, "scale")
    , m_scale_to_back(card, "scale")
    , m_fade_out(card, "opacity")
{
    qRegisterAnimationInterpolator(boolInterpolator);

    m_image_to_front.setDuration(FLIP_DURATION);
    m_image_to_front.setStartValue(false);
    m_image_to_front.setEndValue(true);
    m_image_to_front.setEasingCurve(QEasingCurve::OutQuad);

    m_image_to_back.setDuration(FLIP_DURATION + COOLDOWN);
    m_image_to_back.setStartValue(true);
    m_image_to_back.setEndValue(false);
    m_image_to_back.setEasingCurve(QEasingCurve::InQuint);

    m_scale_to_front.setDuration(FLIP_DURATION);
    m_scale_to_front.setKeyValueAt(0, 1);
    m_scale_to_front.setKeyValueAt(0.5, 0);
    m_scale_to_front.setKeyValueAt(1, 1);
    m_scale_to_front.setEasingCurve(QEasingCurve::OutQuad);
    connect(&m_scale_to_front, &QPropertyAnimation::valueChanged, card, [=]() { card->update(); });
    connect(&m_scale_to_front, &QPropertyAnimation::finished, card, &Card::animationFinished);

    m_scale_to_back.setDuration(FLIP_DURATION + COOLDOWN);
    m_scale_to_back.setKeyValueAt(0, 1);
    m_scale_to_back.setKeyValueAt(0.5, 0);
    m_scale_to_back.setKeyValueAt(1, 1);
    m_scale_to_back.setEasingCurve(QEasingCurve::InQuint);
    connect(&m_scale_to_back, &QPropertyAnimation::valueChanged, card, [=]() { card->update(); });
    connect(&m_scale_to_back, &QPropertyAnimation::finished, card, &Card::animationFinished);

    m_fade_out.setDuration(FLIP_DURATION + COOLDOWN);
    m_fade_out.setStartValue(1.0);
    m_fade_out.setEndValue(0.0);
    m_fade_out.setEasingCurve(QEasingCurve::InCubic);
    connect(&m_fade_out, &QPropertyAnimation::finished, card, &Card::animationFinished);
}

QVariant CardAnimation::boolInterpolator(const bool& from, const bool& to, qreal progress)
{
    return progress < 0.5 ? from : to;
}

void CardAnimation::showFront()
{
    m_image_to_front.start();
    m_scale_to_front.start();
}

void CardAnimation::showBack()
{
    m_image_to_back.start();
    m_scale_to_back.start();
}

void CardAnimation::fadeOut()
{
    m_fade_out.start();
}
