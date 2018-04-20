#ifndef CARDDATAMANAGER_H
#define CARDDATAMANAGER_H

#include <QPixmap>
#include <vector>
#include "carddata.h"

class CardDataManager {

public:
    CardDataManager();
    void loadImages(CardData::ImageType type);
    void initializeGenerator(int amount);
    CardData nextCard();

private:
    std::vector<QPixmap> m_front_images;
    QPixmap m_back_image;
    CardData::ImageType m_current_type = CardData::ImageType::none;
    std::vector<int> m_gen_id;
    std::vector<int>::iterator m_gen_iter;
};

#endif // CARDDATAMANAGER_H
