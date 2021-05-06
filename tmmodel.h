#ifndef TMMODEL_H
#define TMMODEL_H
#include<drawablecomponent.h>


class TMModel
{
public:
    TMModel();
    void draw(QPainter *painter);
    void add(DrawableComponent *component);
    int pickTool(int x,int y,QPainter *painter);
    void selectComponent(int row,QPainter *painter);
    DrawableComponent * setDragPoint(int x,int y);
    QJsonObject createJson();
    void clear();
    DrawableComponent * groupComponent(int x,int y,QPainter *painter);

private:
    QList<DrawableComponent *> list;

};

#endif // TMMODEL_H
