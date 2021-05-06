#ifndef GROUPEDCOMPONENT_H
#define GROUPEDCOMPONENT_H
#include<drawablecomponent.h>

class GroupedComponent
{
private:
    QList<DrawableComponent *> list;
public:
    GroupedComponent();
    void add(DrawableComponent *drawableComponent);
    void clear();
    QList<DrawableComponent *> getAll();

};

#endif // GROUPEDCOMPONENT_H
