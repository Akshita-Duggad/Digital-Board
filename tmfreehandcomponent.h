#ifndef TMFREEHANDCOMPONENT_H
#define TMFREEHANDCOMPONENT_H

#include<drawablecomponent.h>
class TMFreeHandComponent : public DrawableComponent
{
private:
    int x1Cordinate;
    int y1Cordinate;
    int xdiff;
    int ydiff;
    QList<int> xList;
    QList<int> yList;
public:
    TMFreeHandComponent();
    void draw(QPainter *painter);
    QString toString();
    void select(QPainter *painter);
    bool isOwnedByYou(int x, int y);
    void drag(int x, int y);
    void setDragPoint(int x, int y);
    QJsonObject createJson();
    void setX1Cordinate(int value);
    void setY1Cordinate(int value);

};

#endif // TMFREEHANDCOMPONENT_H
