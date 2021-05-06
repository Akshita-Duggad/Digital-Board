#include "tmfreehandcomponent.h"
#include<QJsonObject>
#include<QJsonValue>
#include<QString>
#include<QVariant>
#include<QJsonArray>



void TMFreeHandComponent::setX1Cordinate(int value)
{
    xList.append(value);
}


void TMFreeHandComponent::setY1Cordinate(int value)
{
   yList.append(value);
}


TMFreeHandComponent::TMFreeHandComponent()
{

}

void TMFreeHandComponent::draw(QPainter *painter)
{
    for(int i=0;i<(xList.size()-1);i++)
    {
        painter->drawLine(xList.at(i),yList.at(i),xList.at(i+1),yList.at(i+1));
    }
}

QString TMFreeHandComponent::toString()
{
    return "Free hand";
}

void TMFreeHandComponent::select(QPainter *painter)
{
    painter->setPen(QPen(Qt::red,1));
    painter->drawRect(xList.at(0),yList.at(0),3,3);
    painter->drawRect(xList.at(xList.size()-1),yList.at(yList.size()-1),3,3);
}

bool TMFreeHandComponent::isOwnedByYou(int x, int y)
{
   return false;
}
void TMFreeHandComponent::drag(int x, int y)
{

}

void TMFreeHandComponent::setDragPoint(int x, int y)
{
    xdiff=x;
    ydiff=y;
}

QJsonObject TMFreeHandComponent::createJson()
{
    QJsonObject obj;
    QJsonArray xArray;
    QJsonArray yArray;
    for(int i=0;i<xList.size();i++)
    {
        xArray.append(QJsonValue::fromVariant(xList.at(i)));
        yArray.append(QJsonValue::fromVariant(yList.at(i)));
    }
    obj.insert("XList",xArray);
    obj.insert("YList",yArray);
    return obj;
}


