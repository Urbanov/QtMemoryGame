#ifndef VIEW_H
#define VIEW_H

#include <QGraphicsView>

class View : public QGraphicsView {

public:
    View();
    void resizeEvent(QResizeEvent* event) override;
};
#endif // VIEW_H
