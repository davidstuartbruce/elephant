#ifndef MYSCENE_H
#define MYSCENE_H

#include <QGraphicsScene>
#include <QTimer>
#include "player.h"



class MyScene : public QGraphicsScene
{
public:
    MyScene();
private:
    int m_fieldWidth;
    qreal m_minX;
    qreal m_maxX;
    qreal m_currentX;
    qreal m_groundLevel;
    QTimer m_timer;
    Player* m_player;
    int m_horizontalInput;

    void addHorizontalInput(int input);
    void checkTimer();

private slots:
    void movePlayer();


    // QGraphicsScene interface
protected:
    void keyPressEvent(QKeyEvent *event);
};

#endif // MYSCENE_H
