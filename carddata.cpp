#include "carddata.h"

CardData::CardData(int id, QPixmap front, QPixmap back)
    : m_id(id)
    , m_front(std::move(front))
    , m_back(std::move(back))
{}

CardData::CardData(CardData&& data)
    : m_id(data.m_id)
    , m_front(std::move(data.m_front))
    , m_back(std::move(data.m_back))
{}

int CardData::id() const
{
    return m_id;
}

QPixmap CardData::front() const
{
    return m_front;
}

QPixmap CardData::back() const
{
    return m_back;
}
