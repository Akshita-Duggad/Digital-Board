#include "tmellipsecomponent.h"
#include<QJsonObject>
#include<QJsonValue>
#include<QString>
#include<QVariant>

void TMEllipseComponent::setXCordinate(int value)
{
    xCordinate = value;
}

void TMEllipseComponent::setYCordinate(int value)
{
    yCordinate = value;
}

void TMEllipseComponent::setWidth(int value)
{
    width = value;
}

void TMEllipseComponent::setHeight(int value)
{
    height = value;
}

void TMEllipseComponent::draw(QPainter *painter)
{
    painter->drawEllipse(xCordinate,yCordinate,width,height);
}

void TMEllipseComponent::setDragPoint(int x, int y)
{
    xdiff=xCordinate-x;
    ydiff=yCordinate-y;
}

QString TMEllipseComponent::toString()
{
    return "Circle";
}

void TMEllipseComponent::select(QPainter *painter)
{
    painter->setPen(QPen(Qt::red,1));
    int radius=width/2;
    int xCenter=(width+xCordinate+xCordinate)/2;
    int yCenter=(yCordinate+width+yCordinate)/2;
    painter->drawRect(xCenter,yCenter-radius,5,5);
    painter->drawRect(xCenter,yCenter+radius,5,5);
    painter->drawRect(xCenter-radius,yCenter,5,5);
    painter->drawRect(xCenter+radius,yCenter,5,5);

}

bool TMEllipseComponent::isOwnedByYou(int x, int y)
{
    int radius=width/2;
    int xCenter=(width+xCordinate+xCordinate)/2;
    int yCenter=(yCordinate+width+yCordinate)/2;
    if((x-xCenter)*(x-xCenter)+(y-yCenter)*(y-yCenter)<=radius*radius)
    {
        return true;
    }
    return false;

}

void TMEllipseComponent::drag(int x, int y)
{
    setXCordinate(x+xdiff);
    setYCordinate(y+ydiff);
}

QJsonObject TMEllipseComponent::createJson()
{
    QJsonObject obj;
    obj.insert("xCordinate",QJsonValue::fromVariant(xCordinate));
    obj.insert("yCordinate",QJsonValue::fromVariant(yCordinate));
    obj.insert("width",QJsonValue::fromVariant(width));
    obj.insert("height",QJsonValue::fromVariant(width));
    return obj;
}



int TMEllipseComponent::getXCordinate() const
{
    return xCordinate;
}

int TMEllipseComponent::getYCordinate() const
{
    return yCordinate;
}

int TMEllipseComponent::getWidth() const
{
    return width;
}

int TMEllipseComponent::getHeight() const
{
    return height;
}

TMEllipseComponent::TMEllipseComponent()
{

}
