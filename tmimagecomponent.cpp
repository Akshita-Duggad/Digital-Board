#include "tmimagecomponent.h"
#include<QJsonObject>
#include<QJsonValue>
#include<QVariant>
int TMImageComponent::getXCordinate() const
{
    return xCordinate;
}

void TMImageComponent::setXCordinate(int value)
{
    xCordinate = value;
}

int TMImageComponent::getYCordinate() const
{
    return yCordinate;
}

void TMImageComponent::setYCordinate(int value)
{
    yCordinate = value;
}

int TMImageComponent::getWidth() const
{
    return width;
}

void TMImageComponent::setWidth(int value)
{
    width = value;
}

int TMImageComponent::getHeight() const
{
    return height;
}

void TMImageComponent::setHeight(int value)
{
    height = value;
}

int TMImageComponent::getXdiff() const
{
    return xdiff;
}

void TMImageComponent::setXdiff(int value)
{
    xdiff = value;
}

int TMImageComponent::getYdiff() const
{
    return ydiff;
}

void TMImageComponent::setYdiff(int value)
{
    ydiff = value;
}

QString TMImageComponent::getImageFileName() const
{
    return imageFileName;
}

void TMImageComponent::setImageFileName(const QString &value)
{
    imageFileName = value;
}

TMImageComponent::TMImageComponent()
{

}

void TMImageComponent::draw(QPainter *painter)
{
    QPixmap pixmap(imageFileName);
     painter->drawPixmap(xCordinate,yCordinate,width,height,pixmap);

}

QString TMImageComponent::toString()
{
    return "Image";
}

void TMImageComponent::select(QPainter *painter)
{
    painter->setPen(QPen(Qt::red,1));
    painter->drawRect(xCordinate,yCordinate,5,5);
    painter->drawRect(xCordinate,height+yCordinate,5,5);
    painter->drawRect(width+xCordinate,yCordinate,5,5);
    painter->drawRect(width+xCordinate,height+yCordinate,5,5);
}

bool TMImageComponent::isOwnedByYou(int x, int y)
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

void TMImageComponent::drag(int x, int y)
{
    setXCordinate(x+xdiff);
    setYCordinate(y+ydiff);
}

void TMImageComponent::setDragPoint(int x, int y)
{
    xdiff=xCordinate-x;
    ydiff=yCordinate-y;
}


void TMImageComponent::resize(int x, int y)
{
        setWidth(x-xCordinate);
        setHeight(y-yCordinate);
}

QJsonObject TMImageComponent::createJson()
{
    QJsonObject obj;
    obj.insert("xCordinate",QJsonValue::fromVariant(xCordinate));
    obj.insert("yCordinate",QJsonValue::fromVariant(yCordinate));
    obj.insert("width",QJsonValue::fromVariant(width));
    obj.insert("height",QJsonValue::fromVariant(height));
    obj.insert("imageFileName",QJsonValue::fromVariant(imageFileName));
    return obj;

}


