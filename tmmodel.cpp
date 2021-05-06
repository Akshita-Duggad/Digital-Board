#include "tmmodel.h"
#include<QJsonObject>
#include<tmlinecomponent.h>
#include<tmfreehandcomponent.h>
#include<tmellipsecomponent.h>
#include<tmrectanglecomponent.h>
#include<QJsonObject>
#include<QJsonValue>
#include<QString>
#include<QVariant>
#include<QJsonArray>

TMModel::TMModel()
{
}
void TMModel::draw(QPainter *painter)
{

    //painter->eraseRect(0,0,800,600);
    painter->setPen(QPen(Qt::black,3));
    painter->drawRect(70,30,1200,650);
    painter->setPen(QPen(Qt::black,1));
    painter->setClipRect(70,30,1200,650);
    DrawableComponent *c;
    for(int i=0;i<list.size();i++)
    {
        c=list[i];
        c->draw(painter);
    }

}

void TMModel::add(DrawableComponent *component)
{
    list.push_back(component);
}


int TMModel::pickTool(int x, int y, QPainter *painter)
{
    DrawableComponent *d;
    painter->setPen(QPen(Qt::red,1));
    for(int i=0;i<list.size();i++)
    {
        d=list[i];
        if(d->isOwnedByYou(x,y))
        {
            d->select(painter);
            return list.size()-1-i;
        }
    }
    return -1;

}

void TMModel::selectComponent(int row, QPainter *painter)
{
    painter->setPen(QPen(Qt::red,1));
    DrawableComponent * d;
    d=list[list.size()-1-row];
    d->select(painter);
}



DrawableComponent * TMModel::setDragPoint(int x, int y)
{
    DrawableComponent *d;
    for(int i=0;i<list.size();i++)
    {
        d=list[i];
        if(d->isOwnedByYou(x,y))
        {
            d->setDragPoint(x,y);
            return d;
        }
    }
    return NULL;
}

QJsonObject TMModel::createJson()
{
   QJsonObject jsonObject;
   DrawableComponent *d;
   QJsonArray lineArray;
   QJsonArray circleArray;
   QJsonArray rectangleArray;
   QJsonArray freehandArray;
   QJsonArray imageArray;
   for(int x=0;x<list.size();x++)
   {
       QJsonObject obj;
       d=list[x];
       obj=d->createJson();
       if(d->toString().compare("Line",Qt::CaseInsensitive)==0)
       {
           lineArray.append(obj);
       }
       if(d->toString().compare("Circle",Qt::CaseInsensitive)==0)
       {
           circleArray.append(obj);
       }
       if(d->toString().compare("Rectangle",Qt::CaseInsensitive)==0)
       {
           rectangleArray.append(obj);
       }
       if(d->toString().compare("Free hand",Qt::CaseInsensitive)==0)
       {
           freehandArray.append(obj);
       }
       if(d->toString().compare("Image",Qt::CaseInsensitive)==0)
       {
           imageArray.append(obj);
       }
   }
   jsonObject.insert("Line",lineArray);
   jsonObject.insert("Circle",circleArray);
   jsonObject.insert("Rectangle",rectangleArray);
   jsonObject.insert("Free hand",freehandArray);
   jsonObject.insert("Image",imageArray);

   return jsonObject;
}

void TMModel::clear()
{
    list.clear();
}

DrawableComponent *TMModel::groupComponent(int x, int y, QPainter *painter)
{
    DrawableComponent *d;
    painter->setPen(QPen(Qt::red,1));
    for(int i=0;i<list.size();i++)
    {
        d=list[i];
        if(d->isOwnedByYou(x,y))
        {
            d->select(painter);
            return d;
        }
    }
    return NULL;

}


