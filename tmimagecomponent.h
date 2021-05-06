#ifndef TMIMAGECOMPONENT_H
#define TMIMAGECOMPONENT_H
#include<drawablecomponent.h>

class TMImageComponent : public DrawableComponent
{
private:
    int xCordinate=150;
    int yCordinate=150;
    int width=100;
    int height=100;
    int xdiff;
    int ydiff;
    int xr;
    int yr;
    QString imageFileName;
public:
    TMImageComponent();
    void draw(QPainter *painter);
    QString toString();
    void select(QPainter *painter);
    bool isOwnedByYou(int x,int y);
    void drag(int x,int y);
    void setDragPoint(int x,int y);
    void resize(int x,int y);
    QJsonObject createJson();

    int getXCordinate() const;
    void setXCordinate(int value);
    int getYCordinate() const;
    void setYCordinate(int value);
    int getWidth() const;
    void setWidth(int value);
    int getHeight() const;
    void setHeight(int value);
    int getXdiff() const;
    void setXdiff(int value);
    int getYdiff() const;
    void setYdiff(int value);
    QString getImageFileName() const;
    void setImageFileName(const QString &value);
};

#endif // TMIMAGECOMPONENT_H
