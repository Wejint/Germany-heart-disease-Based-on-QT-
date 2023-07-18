#ifndef CHOOSELEVELSCENE_H
#define CHOOSELEVELSCENE_H

#include <QMainWindow>

class ChooseLevelScene : public QMainWindow
{
    Q_OBJECT
public:
    explicit ChooseLevelScene(QWidget *parent = nullptr);
    void paintEvent(QPaintEvent *);
signals:
    //写一个自定义的信号告诉主场景点击了返回按钮
    void chooseSceneBack();
    void chooseEasyScene();
    void chooseComplexScene();
    void chooseDifficultScene();
public slots:
};

#endif // CHOOSELEVELSCENE_H
