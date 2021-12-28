#pragma once

#include <QImage>
#include <QRect>

class Brick {

  public:
    Brick(int, int);
    Brick(int x, int y, int e);
    Brick(int x, int y, int e, int l);
    ~Brick();

  public:
    bool isDestroyed();
    void setDestroyed(bool);
    QRect getRect();
    void setRect(QRect);
    QImage & getImage();

  private:
    QImage image;
    QRect rect;
    bool destroyed;
};
