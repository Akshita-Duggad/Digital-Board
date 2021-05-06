#ifndef TMLINECOMPONENT_H
#define TMLINECOMPONENT_H

#include<drawablecomponent.h>
class TMLineComponent : public DrawableComponent
{
private:
    int x1Cordinate;
    int y1Cordinate;
    int x2Cordinate;
    int y2Cordinate;
    int x1diff;
    int y1diff;
    int x2diff;
    int y2diff;

public:
    TMLineComponent();
    void draw(QPainter *painter);
    QString toString();
    void select(QPainter *painter);
    bool isOwnedByYou(int x, int y);
    void drag(int x, int y);
    void setDragPoint(int x, int y);
    QJsonObject createJson();
    void setX1Cordinate(int value);
    void setY1Cordinate(int value);
    void setX2Cordinate(int value);
    void setY2Cordinate(int value);
    int getX1Cordinate() const;
    int getY1Cordinate() const;
    int getX2Cordinate() const;
    int getY2Cordinate() const;
};

#endif // TMLINECOMPONENT_H
