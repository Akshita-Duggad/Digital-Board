#include "tmrectanglecomponent.h"
#include<QJsonObject>
#include<QJsonValue>
#include<QString>
#include<QVariant>

void TMRectangleComponent::setXCordinate(int value)
{
    xCordinate = value;
}

void TMRectangleComponent::setYCordinate(int value)
{
    yCordinate = value;
}

void TMRectangleComponent::setWidth(int value)
{
    width = value;
}

void TMRectangleComponent::setHeight(int value)
{
    height = value;
}

int TMRectangleComponent::getXCordinate() const
{
    return xCordinate;
}

int TMRectangleComponent::getYCordinate() const
{
    return yCordinate;
}

int TMRectangleComponent::getWidth() const
{
    return width;
}

int TMRectangleComponent::getHeight() const
{
    return height;
}

TMRectangleComponent::TMRectangleComponent()
{

}

void TMRectangleComponent::draw(QPainter *painter)
{
    painter->drawRect(xCordinate,yCordinate,width,height);
}

QString TMRectangleComponent::toString()
{
    return "Rectangle";
}

void TMRectangleComponent::select(QPainter *painter)
{
    painter->setPen(QPen(Qt::red,1));
    painter->drawRect(xCordinate,yCordinate,5,5);
    painter->drawRect(xCordinate,height+yCordinate,5,5);
    painter->drawRect(width+xCordinate,yCordinate,5,5);
    painter->drawRect(width+xCordinate,height+yCordinate,5,5);
}

bool TMRectangleComponent::isOwnedByYou(int x, int y)
{
    if(x>=xCordinate && x<=width+xCordinate)
    {
        if(y>=yCordinate && y<=height+yCordinate)
        {
            return true;
        }
    }
    return false;

}

void TMRectangleComponent::drag(int x, int y)
{
    setXCordinate(x+xdiff);
    setYCordinate(y+ydiff);
}

void TMRectangleComponent::setDragPoint(int x, int y)
{
    xdiff=xCordinate-x;
    ydiff=yCordinate-y;
}

QJsonObject TMRectangleComponent::createJson()
{
    QJsonObject obj;
    obj.insert("xCordinate",QJsonValue::fromVariant(xCordinate));
    obj.insert("yCordinate",QJsonValue::fromVariant(yCordinate));
    obj.insert("width",QJsonValue::fromVariant(width));
    obj.insert("height",QJsonValue::fromVariant(height));
    return obj;
}


