#include "mainwindow.h"
#include "ui_mainwindow.h"
#include<QPixmap>
#include<QPainter>
#include<tmlinecomponent.h>
#include<tmrectanglecomponent.h>
#include<tmellipsecomponent.h>
#include<tmfreehandcomponent.h>
#include<tmimagecomponent.h>
#include<drawablecomponent.h>
#include<QMouseEvent>
#include<QSplashScreen>
#include<QFileDialog>
#include<QJsonObject>
#include<QJsonDocument>
#include<QJsonArray>
#include<QScrollArea>
#include<QScrollBar>
#include<QKeyEvent>
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    showMaximized();
    ui->setupUi(this);
    QPixmap freeHand(":/images/draw-icon.png");
    this->ui->freeHandDraw->setIcon(freeHand);
    this->ui->freeHandDraw->setToolTip("Free hand tool");
    QPixmap line(":/images/draw-line-icon.png");
    this->ui->drawLine->setIcon(line);
    this->ui->drawLine->setToolTip("Draw Line");
    QPixmap rectangle(":/images/draw-rectangle-icon.png");
    this->ui->drawRectangle->setIcon(rectangle);
    this->ui->drawRectangle->setToolTip("Draw ractangle");
    QPixmap circle(":/images/draw-circle-icon.png");
    this->ui->drawCircle->setIcon(circle);
    this->ui->drawCircle->setToolTip("Draw circle");
    QPixmap pickTool(":/images/pick-icon.png");
    this->ui->pickTool->setIcon(pickTool);
    this->ui->pickTool->setToolTip("Pick tool");
    QPixmap save(":/images/save-icon");
    this->ui->saveButton->setIcon(save);
    this->ui->saveButton->setToolTip("Save file");
    QPixmap open(":/images/open-icon");
    this->ui->openButton->setIcon(open);
    this->ui->openButton->setToolTip("Open file");
    QPixmap group(":/images/group-icon");
    this->ui->groupButton->setIcon(group);
    this->ui->groupButton->setToolTip("Group components");
    QPixmap ungroup(":/images/ungroup-icon");
    this->ui->ungroupButton->setIcon(ungroup);
    this->ui->ungroupButton->setToolTip("Ungroup components");
    QPixmap close(":/images/close-icon.png");
    this->ui->toolCaneclButton->setIcon(close);
    this->ui->toolPanel->setVisible(false);
    this->ui->resizeButton->setVisible(false);
    QPixmap  toolBox(":/images/toolbox-icon.png");
    this->ui->toolButton->setIcon(toolBox);
    this->ui->toolButton->setToolTip("Tool Box");
    QPixmap image(":/images/image-icon.png");
    this->ui->imageButton->setIcon(image);
    this->ui->imageButton->setToolTip("Insert Image");
    QPixmap plus(":/images/plus-icon.png");
    this->ui->plusButton->setIcon(plus);
    QPixmap minus(":/images/minus-icon.png");
    this->ui->minusButton->setIcon(minus);
    QPixmap multiply(":/images/multiply-icon.png");
    this->ui->multiplyButton->setIcon(multiply);
    QPixmap divide(":/images/divide-icon.png");
    this->ui->divideButton->setIcon(divide);
    QPixmap equal(":/images/equal-icon.png");
    this->ui->equalButton->setIcon(equal);
    QPixmap percentage(":/images/percentage-icon.png");
    this->ui->percentageButton->setIcon(percentage);
    QPixmap root(":/images/root-icon.png");
    this->ui->rootButton->setIcon(root);
    QPixmap cube(":/images/cube-icon.png");
    this->ui->cubeButton->setIcon(cube);
    QPixmap integration(":/images/integration-icon.png");
    this->ui->integrationButton->setIcon(integration);
    QPixmap pi(":/images/pi-icon.png");
    this->ui->piButton->setIcon(pi);

    this->ui->listWidget->setSelectionMode(QAbstractItemView::SelectionMode::SingleSelection);
    this->ui->listWidget->setEditTriggers(QAbstractItemView::AllEditTriggers);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::paintEvent(QPaintEvent *event)
{
    QPainter *painter=new QPainter(this);
    painter->fillRect(70,30,1200,650,Qt::white);
//    painter->setCompositionMode(QPainter::CompositionMode_SourceOver);
    painter->setPen(QPen(QColor(230,230,230),1));
    for(int y=30;y<=680;y=y+40)
    {
        painter->drawLine(70,y,1270,y);
    }
        tmModel->draw(painter);
        if(flag==1)
        {
            if(currentX!=0)
            {
            x.append(currentX);
            y.append(currentY);
            for(int i=0;i<(x.size()-1);i++)
            {
                painter->drawLine(x.at(i),y.at(i),x.at(i+1),y.at(i+1));
            }
            }
        }

    if(flag==2)
    {
        if(mouseFlag==1)
        {
           painter->drawLine(oldX,oldY,currentX,currentY);
        }
        else
        {
            TMLineComponent *lineComponent=new TMLineComponent();
            lineComponent->setX1Cordinate(oldX);
            lineComponent->setY1Cordinate(oldY);
            lineComponent->setX2Cordinate(currentX);
            lineComponent->setY2Cordinate(currentY);
            tmModel->add(lineComponent);
            this->ui->listWidget->insertItem(0,lineComponent->toString());
            mouseFlag=1;
            oldX=-1;
            oldY=-1;
            currentX=0;
            currentY=0;
            QWidget::update();

        }

    }
    if(flag==3)
    {
        if(mouseFlag==1)
        {
           painter->drawRect(oldX,oldY,currentX-oldX,currentY-oldY);
        }
        else
        {
            TMRectangleComponent *rectComponent=new TMRectangleComponent();
            rectComponent->setXCordinate(oldX);
            rectComponent->setYCordinate(oldY);
            rectComponent->setWidth(currentX-oldX);
            rectComponent->setHeight(currentY-oldY);
            tmModel->add(rectComponent);
            this->ui->listWidget->insertItem(0,rectComponent->toString());
            mouseFlag=1;
            oldX=-1;
            oldY=-1;
            currentX=0;
            currentY=0;
            QWidget::update();

        }

    }
    if(flag==4)
    {
        if(mouseFlag==1)
        {
           painter->drawEllipse(oldX,oldY,currentX-oldX,currentX-oldX);
        }
        else
        {
            TMEllipseComponent *ellipseComponent=new TMEllipseComponent();
            ellipseComponent->setXCordinate(oldX);
            ellipseComponent->setYCordinate(oldY);
            ellipseComponent->setWidth(currentX-oldX);
            ellipseComponent->setHeight(currentX-oldX);
            tmModel->add(ellipseComponent);
            this->ui->listWidget->insertItem(0,ellipseComponent->toString());
            mouseFlag=1;
            oldX=-1;
            oldY=-1;
            currentX=0;
            currentY=0;
            QWidget::update();

        }

    }
    if(flag==5)
    {
        int index;
        index=tmModel->pickTool(currentX,currentY,painter);
        if(index>-1)
        {
        this->ui->listWidget->setCurrentRow(index);
        }

      }
    if(flag==6)
    {
        tmModel->selectComponent(row,painter);
    }
    if(flag<5)
    {
        this->ui->listWidget->clearSelection();
    }
    if(flag==7)
    {
        DrawableComponent * d;
        d=tmModel->groupComponent(currentX,currentY,painter);
        if(d!=NULL)
        {
            groupList.push_back(d);
            DrawableComponent *draw;
            for(int i=0;i<groupList.size();i++)
            {
                draw=groupList[i];
                draw->select(painter);

            }
        }
        else
        {
            groupList.clear();
            QWidget::update();
        }


    }

    painter->end();
}

void MainWindow::mouseMoveEvent(QMouseEvent *eventMove)
{
    if(flag==1)
    {
    oldX=currentX;
    oldY=currentY;
    currentX=eventMove->x();
    currentY=eventMove->y();
    if(freeHand!=NULL)
    {
    freeHand->setX1Cordinate(oldX);
    freeHand->setY1Cordinate(oldY);
    freeHand->setX1Cordinate(currentX);
    freeHand->setY1Cordinate(currentY);
    }
    }
    if(flag==2)
    {
        currentX=eventMove->x();
        currentY=eventMove->y();
    }
    if(flag==3)
    {
        currentX=eventMove->x();
        currentY=eventMove->y();
    }
    if(flag==4)
    {
        currentX=eventMove->x();
        currentY=eventMove->y();
    }
    if(flag==5)
    {
        if(drawableComponent!=NULL)
        {
            currentX=eventMove->x();
            currentY=eventMove->y();
            drawableComponent->drag(currentX,currentY);
        }
    }
    if(flag==8)
    {
        currentX=eventMove->x();
        currentY=eventMove->y();
        DrawableComponent *d;
        QList<DrawableComponent *> l;
        l=groupedComponent->getAll();
        for(int i=0;i<l.size();i++)
        {
            d=l[i];
            d->drag(currentX,currentY);
        }
    }
    if(resizeFlag==2)
    {
        currentX=eventMove->x();
        currentY=eventMove->y();
        imgComponent->resize(currentX,currentY);
        imageResize=1;
        //resizeFlag=3;

    }
    QWidget::update();

}

void MainWindow::mousePressEvent(QMouseEvent *eventPress)
{
    mouseFlag=1;
    if(flag==1)
    {
    oldX=eventPress->x();
    oldY=eventPress->y();
    currentX=eventPress->x();
    currentY=eventPress->y();   
    freeHand=new TMFreeHandComponent();
    freeHand->setX1Cordinate(oldX);
    freeHand->setY1Cordinate(oldY);
    freeHand->setX1Cordinate(currentX);
    freeHand->setY1Cordinate(currentY);
    this->ui->listWidget->insertItem(0,freeHand->toString());
    }
    if(flag==2)
    {
        oldX=eventPress->x();
        oldY=eventPress->y();
        currentX=eventPress->x();
        currentY=eventPress->y();

    }
    if(flag==3)
    {
        oldX=eventPress->x();
        oldY=eventPress->y();
        currentX=eventPress->x();
        currentY=eventPress->y();

    }
    if(flag==4)
    {
        oldX=eventPress->x();
        oldY=eventPress->y();
        currentX=eventPress->x();
        currentY=eventPress->y();

    }
    if(flag==5)
    {
        currentX=eventPress->x();
        currentY=eventPress->y();
        drawableComponent=tmModel->setDragPoint(currentX,currentY);
        if(drawableComponent->toString().compare("Image",Qt::CaseInsensitive)==0)
        {
            if(eventPress->button()==Qt::RightButton)
            {
             imgComponent=dynamic_cast<TMImageComponent *>(drawableComponent);
             this->ui->resizeButton->setGeometry(imgComponent->getXCordinate(),imgComponent->getYCordinate(),70,40);
             this->ui->resizeButton->setVisible(true);
             drawableComponent=NULL;
            }
        }

    }
    if(flag==7)
    {
        currentX=eventPress->x();
        currentY=eventPress->y();

    }
    if(flag==8)
    {
        int xDragPoint=0;
        int yDragPoint=0;
        int drag=0;
        currentX=eventPress->x();
        currentY=eventPress->y();
        DrawableComponent *d;
        QList<DrawableComponent *> l;
        l=groupedComponent->getAll();
        for(int i=0;i<l.size();i++)
        {
            d=l[i];
            if(d->isOwnedByYou(currentX,currentY))
            {
                drag=1;
                xDragPoint=currentX;
                yDragPoint=currentY;
                break;
            }
        }
        if(drag==1)
        {
            for(int i=0;i<l.size();i++)
            {
                d=l[i];
                d->setDragPoint(xDragPoint,yDragPoint);
            }

        }
    }


    if(resizeFlag==1)
    {
        currentX=eventPress->x();
        currentY=eventPress->y();
        if(imgComponent->isOwnedByYou(currentX,currentY))
        {
            resizeFlag=2;
            imageResize=0;
        }

    }


    QWidget::update();

}

void MainWindow::mouseReleaseEvent(QMouseEvent *releaseEvent)
{

    mouseFlag=3;
    if(flag==1)
    {
    oldX=currentX;
    oldY=currentY;
    currentX=releaseEvent->x();
    currentY=releaseEvent->y();
    if(freeHand!=NULL)
    {
        freeHand->setX1Cordinate(oldX);
        freeHand->setY1Cordinate(oldY);
        freeHand->setX1Cordinate(currentX);
        freeHand->setY1Cordinate(currentY);
        tmModel->add(freeHand);
        freeHand=NULL;
        x.clear();
        y.clear();
        oldX=-1;
        oldY=-1;
        currentX=0;
        currentY=0;

    }
    }
    if(flag==2)
    {
        currentX=releaseEvent->x();
        currentY=releaseEvent->y();
    }
    if(flag==3)
    {
        currentX=releaseEvent->x();
        currentY=releaseEvent->y();
    }
    if(flag==4)
    {
        currentX=releaseEvent->x();
        currentY=releaseEvent->y();
    }
    if(flag==5)
    {
        dragFlag=0;
        drawableComponent=NULL;
        drawableComponent=nullptr;
    }
    if(imageResize==1)
    {
        resizeFlag=0;
        imgComponent=NULL;
    }

    QWidget::update();

}

void MainWindow::keyPressEvent(QKeyEvent *keyEvent)
{
    if(flag==5)
    {
if(keyEvent->key()==Qt::Key_Control)
{
    flag=7;
    this->ui->listWidget->clearSelection();

}
    }
}


void MainWindow::on_freeHandDraw_clicked()
{
    oldX=-1;
    oldY=-1;
    currentX=0;
    currentY=0;
    flag=1;
    groupList.clear();
    groupedComponent->clear();

}

void MainWindow::on_drawLine_clicked()
{
    mouseFlag=1;
    oldX=-1;
    oldY=-1;
    currentX=0;
    currentY=0;
    flag=2;
    groupList.clear();
    groupedComponent->clear();
}

void MainWindow::on_drawRectangle_clicked()
{
    mouseFlag=1;
    oldX=-1;
    oldY=-1;
    currentX=0;
    currentY=0;
    flag=3;
    groupList.clear();
    groupedComponent->clear();
}

void MainWindow::on_drawCircle_clicked()
{
    oldX=-1;
    oldY=-1;
    currentX=0;
    currentY=0;
    flag=4;
}

void MainWindow::on_pickTool_clicked()
{
    currentX=0;
    currentY=0;
    flag=5;
}

void MainWindow::on_listWidget_clicked(const QModelIndex &index)
{
    flag=6;
    row=index.row();
    QWidget::update();
    groupList.clear();
    groupedComponent->clear();
}

void MainWindow::on_saveButton_clicked()
{
    QString fileName=QFileDialog::getSaveFileName(this,"save","C:\\qteg","*.json");
    QJsonObject object=tmModel->createJson();
    QJsonDocument document(object);
    QFile file(fileName);
    file.open(QFile::WriteOnly);
    file.write(document.toJson());
    file.close();
    groupList.clear();
    groupedComponent->clear();
}

void MainWindow::on_openButton_clicked()
{
    QString fileName=QFileDialog::getOpenFileName(this,"save","C:\\qteg","*.json");
    QFile file(fileName);
    file.open(QFile::ReadOnly);
    QJsonDocument document;
    document=QJsonDocument().fromJson(file.readAll());
    QJsonObject object=document.object();
    if(object.isEmpty()==false)
    {
        tmModel->clear();
        this->ui->listWidget->clear();
    }

    QJsonValue lineValue=object.value("Line");
    QJsonArray lineArray=lineValue.toArray();

    QJsonValue circleValue=object.value("Circle");
    QJsonArray circleArray=circleValue.toArray();

    QJsonValue rectValue=object.value("Rectangle");
    QJsonArray rectArray=rectValue.toArray();

    QJsonValue freehandValue=object.value("Free hand");
    QJsonArray freehandArray=freehandValue.toArray();

    QJsonValue imageValue=object.value("Image");
    QJsonArray imageArray=imageValue.toArray();

    if(lineArray.isEmpty()==false)
    {
        TMLineComponent *lineComponent;
        QJsonObject obj;
        QJsonValue value;
        for(int i=0;i<lineArray.size();i++)
        {
            value=lineArray.at(i);
            obj=value.toObject();
            lineComponent=new TMLineComponent();
            lineComponent->setX1Cordinate(obj.value("x1Cordinate").toInt());
            lineComponent->setY1Cordinate(obj.value("y1Cordinate").toInt());
            lineComponent->setX2Cordinate(obj.value("x2Cordinate").toInt());
            lineComponent->setY2Cordinate(obj.value("y2Cordinate").toInt());
            tmModel->add(lineComponent);
            this->ui->listWidget->insertItem(0,lineComponent->toString());
        }
    }

    if(circleArray.isEmpty()==false)
    {
        TMEllipseComponent *circleComponent;
        QJsonObject obj;
        QJsonValue value;
        for(int i=0;i<circleArray.size();i++)
        {
            value=circleArray.at(i);
            obj=value.toObject();
            circleComponent=new TMEllipseComponent();
            circleComponent->setXCordinate(obj.value("xCordinate").toInt());
            circleComponent->setYCordinate(obj.value("yCordinate").toInt());
            circleComponent->setWidth(obj.value("width").toInt());
            circleComponent->setHeight(obj.value("height").toInt());
            tmModel->add(circleComponent);
            this->ui->listWidget->insertItem(0,circleComponent->toString());
        }
    }

    if(rectArray.isEmpty()==false)
    {
        TMRectangleComponent *rectComponent;
        QJsonObject obj;
        QJsonValue value;
        for(int i=0;i<rectArray.size();i++)
        {
            value=rectArray.at(i);
            obj=value.toObject();
            rectComponent=new TMRectangleComponent();
            rectComponent->setXCordinate(obj.value("xCordinate").toInt());
            rectComponent->setYCordinate(obj.value("yCordinate").toInt());
            rectComponent->setWidth(obj.value("width").toInt());
            rectComponent->setHeight(obj.value("height").toInt());
            tmModel->add(rectComponent);
            this->ui->listWidget->insertItem(0,rectComponent->toString());
        }
    }

    if(imageArray.isEmpty()==false)
    {
        TMImageComponent *imageComponent;
        QJsonObject obj;
        QJsonValue value;
        for(int i=0;i<imageArray.size();i++)
        {
            value=imageArray.at(i);
            obj=value.toObject();
            imageComponent=new TMImageComponent();
            imageComponent->setXCordinate(obj.value("xCordinate").toInt());
            imageComponent->setYCordinate(obj.value("yCordinate").toInt());
            imageComponent->setWidth(obj.value("width").toInt());
            imageComponent->setHeight(obj.value("height").toInt());
            imageComponent->setImageFileName(obj.value("imageFileName").toString());
            tmModel->add(imageComponent);
            this->ui->listWidget->insertItem(0,imageComponent->toString());
        }
    }

    if(freehandArray.isEmpty()==false)
    {
        TMFreeHandComponent *freehandComponent;
        QJsonObject obj;
        QJsonValue value;
        QJsonArray xArray;
        QJsonArray yArray;
        QJsonValue x;
        QJsonValue y;
        for(int i=0;i<freehandArray.size();i++)
        {
            value=freehandArray.at(i);
            obj=value.toObject();
           x=obj.value("XList");
           xArray=x.toArray();
           y=obj.value("YList");
           yArray=y.toArray();
           freehandComponent=new TMFreeHandComponent();
           for(int a=0;a<xArray.size();a++)
           {
               freehandComponent->setX1Cordinate(xArray.at(a).toInt());
               freehandComponent->setY1Cordinate(yArray.at(a).toInt());
           }
           tmModel->add(freehandComponent);
           this->ui->listWidget->insertItem(0,freehandComponent->toString());

        }
    }

    groupList.clear();
    groupedComponent->clear();
       QWidget::update();
}

void MainWindow::on_ungroupButton_clicked()
{
    groupList.clear();
    groupedComponent->clear();
    QWidget::update();
}

void MainWindow::on_groupButton_clicked()
{
    DrawableComponent *d;
    for(int i=0;i<groupList.size();i++)
    {
        d=groupList[i];
        groupedComponent->add(d);

    }
    flag=8;

}

void MainWindow::on_toolButton_clicked()
{
   // QScrollArea *scrollArea=new QScrollArea;
    //scrollArea->setBackgroundRole(QPalette::Dark);
    //scrollArea->setWidget(this->ui->toolPanel);
    this->ui->toolPanel->setVisible(true);
}

void MainWindow::on_toolCaneclButton_clicked()
{
    this->ui->toolPanel->setVisible(false);
}

void MainWindow::on_imageButton_clicked()
{
    QString *selectedFilter=new QString;
    selectedFilter->append("Images (*.png *.xpm *.jpg)");
    QString fileName=QFileDialog::getOpenFileName(this,"Image","C:\\qteg","Images (*.png *.xpm *.jpg)");
    TMImageComponent *imageComponent=new TMImageComponent();
    imageComponent->setImageFileName(fileName);
    tmModel->add(imageComponent);
    this->ui->listWidget->insertItem(0,imageComponent->toString());
    groupList.clear();
    groupedComponent->clear();
}

void MainWindow::on_resizeButton_clicked()
{
    resizeFlag=1;
    flag=0;
    this->ui->resizeButton->setVisible(false);
}

void MainWindow::on_listWidget_doubleClicked(const QModelIndex &index)
{
    QListWidgetItem * item=this->ui->listWidget->item(index.row());
    item->setFlags(item->flags() | Qt::ItemIsEditable);

}



void MainWindow::on_plusButton_clicked()
{
    TMImageComponent *imageComponent=new TMImageComponent();
    imageComponent->setImageFileName("C:\\qteg\\ExmampleSeven\\plus-icon.png");
    tmModel->add(imageComponent);
    this->ui->listWidget->insertItem(0,imageComponent->toString());
    groupList.clear();
    groupedComponent->clear();
    QWidget::update();
}

void MainWindow::on_minusButton_clicked()
{
    TMImageComponent *imageComponent=new TMImageComponent();
    imageComponent->setImageFileName("C:\\qteg\\ExmampleSeven\\minus-icon.png");
    tmModel->add(imageComponent);
    this->ui->listWidget->insertItem(0,imageComponent->toString());
    groupList.clear();
    groupedComponent->clear();
    QWidget::update();
}

void MainWindow::on_multiplyButton_clicked()
{
    TMImageComponent *imageComponent=new TMImageComponent();
    imageComponent->setImageFileName("C:\\qteg\\ExmampleSeven\\multiply-icon.png");
    tmModel->add(imageComponent);
    this->ui->listWidget->insertItem(0,imageComponent->toString());
    groupList.clear();
    groupedComponent->clear();
    QWidget::update();
}

void MainWindow::on_divideButton_clicked()
{
    TMImageComponent *imageComponent=new TMImageComponent();
    imageComponent->setImageFileName("C:\\qteg\\ExmampleSeven\\divide-icon.png");
    tmModel->add(imageComponent);
    this->ui->listWidget->insertItem(0,imageComponent->toString());
    groupList.clear();
    groupedComponent->clear();
    QWidget::update();
}

void MainWindow::on_equalButton_clicked()
{
    TMImageComponent *imageComponent=new TMImageComponent();
    imageComponent->setImageFileName("C:\\qteg\\ExmampleSeven\\equal-icon.png");
    tmModel->add(imageComponent);
    this->ui->listWidget->insertItem(0,imageComponent->toString());
    groupList.clear();
    groupedComponent->clear();
    QWidget::update();
}

void MainWindow::on_percentageButton_clicked()
{
    TMImageComponent *imageComponent=new TMImageComponent();
    imageComponent->setImageFileName("C:\\qteg\\ExmampleSeven\\percentage-icon.png");
    tmModel->add(imageComponent);
    this->ui->listWidget->insertItem(0,imageComponent->toString());
    groupList.clear();
    groupedComponent->clear();
    QWidget::update();
}

void MainWindow::on_rootButton_clicked()
{
    TMImageComponent *imageComponent=new TMImageComponent();
    imageComponent->setImageFileName("C:\\qteg\\ExmampleSeven\\root-icon.png");
    tmModel->add(imageComponent);
    this->ui->listWidget->insertItem(0,imageComponent->toString());
    groupList.clear();
    groupedComponent->clear();
    QWidget::update();
}

void MainWindow::on_cubeButton_clicked()
{
    TMImageComponent *imageComponent=new TMImageComponent();
    imageComponent->setImageFileName("C:\\qteg\\ExmampleSeven\\cube-icon.png");
    tmModel->add(imageComponent);
    this->ui->listWidget->insertItem(0,imageComponent->toString());
    groupList.clear();
    groupedComponent->clear();
    QWidget::update();
}

void MainWindow::on_integrationButton_clicked()
{
    TMImageComponent *imageComponent=new TMImageComponent();
    imageComponent->setImageFileName("C:\\qteg\\ExmampleSeven\\integration-icon.png");
    tmModel->add(imageComponent);
    this->ui->listWidget->insertItem(0,imageComponent->toString());
    groupList.clear();
    groupedComponent->clear();
    QWidget::update();
}

void MainWindow::on_piButton_clicked()
{
    TMImageComponent *imageComponent=new TMImageComponent();
    imageComponent->setImageFileName("C:\\qteg\\ExmampleSeven\\pi-icon.png");
    tmModel->add(imageComponent);
    this->ui->listWidget->insertItem(0,imageComponent->toString());
    groupList.clear();
    groupedComponent->clear();
    QWidget::update();
}
