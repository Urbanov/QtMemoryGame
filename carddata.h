#ifndef CARDDATA_H
#define CARDDATA_H

#include <QPixmap>

class CardData : public QObject {

    Q_OBJECT

public:
    enum ImageType {
        animals,
        cars,
        fruits,
        none
    };
    Q_ENUM(ImageType)

    CardData(int id, QPixmap front, QPixmap back);
    CardData(CardData&& data);
    int id() const;
    QPixmap front() const;
    QPixmap back() const;

private:
    int m_id;
    QPixmap m_front;
    QPixmap m_back;
};

#endif // CARDDATA_H
