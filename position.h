#ifndef POSITION_H
#define POSITION_H


class Position
{
 private:
    int x_;
    int y_;
 public:
    Position() : x_(-1), y_(-1) {}
    Position(int x, int y) : x_(x), y_(y){}

    int getX() const {return x_;}
    int getY() const {return y_;}
    void move(int x, int y) { x_ = x; y_ = y;}
};

#endif // POSITION_H
