#ifndef TMELLIPSECOMPONENT_H
#define TMELLIPSECOMPONENT_H

#include<drawablecomponent.h>
class TMEllipseComponent : public DrawableComponent
{
private:
    int xCordinate;
    int yCordinate;
    int width;
    int height;
    int xdiff;
    int ydiff;
public:
    TMEllipseComponent();
    void setXCordinate(int value);
    void setYCordinate(int value);
    void setWidth(int value);
    void setHeight(int value);
    void draw(QPainter *painter);
    void setDragPoint(int x, int y);
    QString toString();
    void select(QPainter *painter);
    bool isOwnedByYou(int x, int y);
    void drag(int x, int y);
    QJsonObject createJson();
    int getXCordinate() const;
    int getYCordinate() const;
    int getWidth() const;
    int getHeight() const;
};

#endif // TMELLIPSECOMPONENT_H
