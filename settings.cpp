#include "settings.h"

std::vector<std::pair<int, int>> Settings::m_size_lut = {
    { 3, 4 }, // small
    { 4, 5 }, // medium
    { 5, 6 }  // big
};

Settings::Settings()
    : m_size_type(DEFAULT_SIZE)
    , m_image_type(DEFAULT_TYPE)
{}

int Settings::width() const
{
    return m_size_lut[m_size_type].first;
}

int Settings::height() const
{
    return m_size_lut[m_size_type].second;
}

Settings::SizeType Settings::sizeType() const
{
    return m_size_type;
}

void Settings::setSizeType(Settings::SizeType type)
{
    m_size_type = type;
}

CardData::ImageType Settings::imageType() const
{
    return m_image_type;
}

void Settings::setImageType(CardData::ImageType type)
{
    m_image_type = type;
}

