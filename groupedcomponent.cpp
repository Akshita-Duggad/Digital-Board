#include "groupedcomponent.h"

GroupedComponent::GroupedComponent()
{

}

void GroupedComponent::add(DrawableComponent *drawableComponent)
{
    list.push_back(drawableComponent);

}

void GroupedComponent::clear()
{
    list.clear();
}

QList<DrawableComponent *> GroupedComponent::getAll()
{
    return list;
}
