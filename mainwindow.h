#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include<tmmodel.h>
#include<drawablecomponent.h>
#include <QMainWindow>
#include<QMouseEvent>
#include<QMoveEvent>
#include<QSplashScreen>
#include<groupedcomponent.h>
#include<tmimagecomponent.h>
#include<tmfreehandcomponent.h>
QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    TMModel *tmModel=new TMModel();
    GroupedComponent *groupedComponent=new GroupedComponent();
    int flag=0;
    int mouseFlag=0;
    int dragFlag=0;
    int resizeFlag=0;
    int imageResize=0;
    int oldX=-1;
    int oldY=-1;
    int currentX=0;
    int currentY=0;
    int row;

    QList<int> x;
    QList<int> y;
    QList<DrawableComponent *>groupList;
    DrawableComponent * drawableComponent=NULL;
    TMImageComponent *imgComponent=NULL;
    TMFreeHandComponent * freeHand=NULL;

protected:
    void paintEvent(QPaintEvent *event);
    void mouseMoveEvent(QMouseEvent *eventMove);
    void mousePressEvent(QMouseEvent * eventPress);
    void mouseReleaseEvent(QMouseEvent *releaseEvent);
    void keyPressEvent(QKeyEvent *keyEvent);
private slots:
    void on_freeHandDraw_clicked();

    void on_drawLine_clicked();

    void on_drawRectangle_clicked();

    void on_drawCircle_clicked();

    void on_pickTool_clicked();

    void on_listWidget_clicked(const QModelIndex &index);

    void on_saveButton_clicked();

    void on_openButton_clicked();

    void on_ungroupButton_clicked();

    void on_groupButton_clicked();

    void on_toolButton_clicked();

    void on_toolCaneclButton_clicked();

    void on_imageButton_clicked();

    void on_resizeButton_clicked();

    void on_listWidget_doubleClicked(const QModelIndex &index);



    void on_plusButton_clicked();

    void on_minusButton_clicked();

    void on_multiplyButton_clicked();

    void on_divideButton_clicked();

    void on_equalButton_clicked();

    void on_percentageButton_clicked();

    void on_rootButton_clicked();

    void on_cubeButton_clicked();

    void on_integrationButton_clicked();

    void on_piButton_clicked();

private:
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
