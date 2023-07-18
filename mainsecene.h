#ifndef MAINSECENE_H
#define MAINSECENE_H

#include <QMainWindow>
#include<chooselevelscene.h>
#include<playscene.h>
#include <QKeyEvent>
namespace Ui {
class MainSecene;
}

class MainSecene : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainSecene(QWidget *parent = nullptr);
    //重新paintEvent事件 画背景图
    void paintEvent(QPaintEvent *);
    void keyPressEvent(QKeyEvent*);
    ChooseLevelScene * chooseScene = NULL;
    easyExplainationScene * explainScene = NULL;
    ~MainSecene();

private:
    Ui::MainSecene *ui;
};

#endif // MAINSECENE_H
