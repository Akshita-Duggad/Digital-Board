#include "tmlinecomponent.h"
#include<QJsonObject>
#include<QJsonValue>
#include<QString>
#include<QVariant>


void TMLineComponent::setX1Cordinate(int value)
{
    x1Cordinate = value;
}

void TMLineComponent::setY1Cordinate(int value)
{
    y1Cordinate = value;
}

void TMLineComponent::setX2Cordinate(int value)
{
    x2Cordinate = value;
}

void TMLineComponent::setY2Cordinate(int value)
{
    y2Cordinate = value;
}

int TMLineComponent::getX1Cordinate() const
{
    return x1Cordinate;
}

int TMLineComponent::getY1Cordinate() const
{
    return y1Cordinate;
}

int TMLineComponent::getX2Cordinate() const
{
    return x2Cordinate;
}

int TMLineComponent::getY2Cordinate() const
{
    return y2Cordinate;
}

TMLineComponent::TMLineComponent()
{

}

void TMLineComponent::draw(QPainter *painter)
{
    painter->drawLine(x1Cordinate,y1Cordinate,x2Cordinate,y2Cordinate);
}

QString TMLineComponent::toString()
{
    return "Line";
}

void TMLineComponent::select(QPainter *painter)
{
    painter->setPen(QPen(Qt::red,1));
    painter->drawRect(x1Cordinate,y1Cordinate,5,5);
    painter->drawRect(x2Cordinate,y2Cordinate,5,5);
}

bool TMLineComponent::isOwnedByYou(int x, int y)
{
    int x1=x1Cordinate;
    int x2=x2Cordinate;
    int y1=y1Cordinate;
    int y2=y2Cordinate;
    int dx;
    int dy;
    int p;
    int xt;
    int yt;
    int xe;
    int ye;
    if(x1>x2)
    {
        xt=x2;
        xe=x1;
        dx=x1-x2;
    }
    else
    {
        xt=x1;
        xe=x2;
        dx=x2-x1;
    }
    if(y1>y2)
    {
        yt=y2;
        ye=y1;
        dy=y1-y2;
    }
    else
    {
        yt=y1;
        ye=y2;
        dy=y2-y1;
    }

    if(dx>dy)
    {
        p=2*dy-dx;

        while(xt<=xe)
        {
            if(x==xt && y==yt)
            {
               return true;
            }
            xt++;
            if(p<0)
            {
                p=p+2*dy;
            }
            else
            {
                p=p+2*dy-2*dx;
                yt++;
            }
        }
    }
    else
    {
        p=2*dx-dy;
        while(yt<=ye)
        {
            if(x==xt && y==yt)
            {
               return true;
            }
            yt++;
            if(p<0)
            {
                p=p+2*dx;
            }
            else
            {
                p=p+2*dx-2*dy;
                xt++;
            }
        }

    }
    return false;
}

void TMLineComponent::drag(int x, int y)
{
    setX1Cordinate(x+x1diff);
    setY1Cordinate(y+y1diff);
    setX2Cordinate(x+x2diff);
    setY2Cordinate(y+y2diff);
}

void TMLineComponent::setDragPoint(int x, int y)
{
    x1diff=x1Cordinate-x;
    y1diff=y1Cordinate-y;
    x2diff=x2Cordinate-x;
    y2diff=y2Cordinate-y;
}

QJsonObject TMLineComponent::createJson()
{
    QJsonObject obj;
    obj.insert("x1Cordinate",QJsonValue::fromVariant(x1Cordinate));
    obj.insert("y1Cordinate",QJsonValue::fromVariant(y1Cordinate));
    obj.insert("x2Cordinate",QJsonValue::fromVariant(x2Cordinate));
    obj.insert("y2Cordinate",QJsonValue::fromVariant(y2Cordinate));
    return obj;
}



