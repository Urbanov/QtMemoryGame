#ifndef SETTINGS_H
#define SETTINGS_H

#include "carddata.h"

class Settings : public QObject {

    Q_OBJECT

public:
    enum SizeType {
        small,
        medium,
        big
    };
    Q_ENUM(SizeType)

    Settings();
    int width() const;
    int height() const;
    SizeType sizeType() const;
    void setSizeType(SizeType type);
    CardData::ImageType imageType() const;
    void setImageType(CardData::ImageType type);

private:
    static constexpr SizeType DEFAULT_SIZE = SizeType::small;
    static constexpr CardData::ImageType DEFAULT_TYPE = CardData::ImageType::animals;
    static std::vector<std::pair<int, int>> m_size_lut;
    SizeType m_size_type;
    CardData::ImageType m_image_type;
};

#endif // SETTINGS_H
