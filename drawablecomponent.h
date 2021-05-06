#ifndef DRAWABLECOMPONENT_H
#define DRAWABLECOMPONENT_H
#include<QPainter>
class DrawableComponent
{
public:
    DrawableComponent();
    virtual void draw(QPainter *painter)=0;
    virtual QString toString()=0;
    virtual void select(QPainter *painter)=0;
    virtual bool isOwnedByYou(int x,int y)=0;
    virtual void drag(int x,int y)=0;
    virtual void setDragPoint(int x,int y)=0;
    virtual QJsonObject createJson()=0;
};

#endif // DRAWABLECOMPONENT_H
