#include "carddatamanager.h"
#include <QDebug>
#include <QDirIterator>
#include <QMetaEnum>
#include <algorithm>
#include "card.h"
#include <random>

CardDataManager::CardDataManager()
{
    m_back_image.load(":/generic/card_back.png");
    m_back_image = m_back_image.scaled(Card::SIZE, Card::SIZE, Qt::IgnoreAspectRatio, Qt::SmoothTransformation);
}

void CardDataManager::loadImages(CardData::ImageType type)
{
    if (type == m_current_type) {
        return;
    }

    m_front_images.clear();
    m_current_type = type;
    QString path = QString(":/") + QMetaEnum::fromType<CardData::ImageType>().valueToKey(type);
    QDirIterator it(path, QDirIterator::Subdirectories);
    while (it.hasNext()) {
        QPixmap pixmap(it.next());
        m_front_images.push_back(pixmap.scaled(Card::SIZE, Card::SIZE, Qt::IgnoreAspectRatio, Qt::SmoothTransformation));
    }
}

void CardDataManager::initializeGenerator(int amount)
{
    m_gen_id.clear();
    m_gen_id.reserve(amount);
    for (int i = 0; i < amount/2; ++i) {
        m_gen_id.push_back(i);
        m_gen_id.push_back(i);
    }
    std::random_device rd;
    std::mt19937 gen(rd());
    std::shuffle(m_front_images.begin(), m_front_images.end(), gen);
    std::shuffle(m_gen_id.begin(), m_gen_id.end(), gen);  
    m_gen_iter = m_gen_id.begin();
}

CardData CardDataManager::nextCard()
{
    int id = *m_gen_iter++ % m_front_images.size();
    return { id, m_front_images.at(id), m_back_image };
}
