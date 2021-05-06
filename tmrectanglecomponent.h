#ifndef TMRECTANGLECOMPONENT_H
#define TMRECTANGLECOMPONENT_H
#include<drawablecomponent.h>
class TMRectangleComponent : public DrawableComponent
{
private:
    int xCordinate;
    int yCordinate;
    int width;
    int height;
    int xdiff;
    int ydiff;
public:
    TMRectangleComponent();
    void draw(QPainter *painter);
    QString toString();
    void select(QPainter *painter);
    bool isOwnedByYou(int x, int y);
    void drag(int x, int y);
    void setDragPoint(int x, int y);
    QJsonObject createJson();
    void setXCordinate(int value);
    void setYCordinate(int value);
    void setWidth(int value);
    void setHeight(int value);
    int getXCordinate() const;
    int getYCordinate() const;
    int getWidth() const;
    int getHeight() const;
};

#endif // TMRECTANGLECOMPONENT_H
