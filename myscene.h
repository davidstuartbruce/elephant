#ifndef MYSCENE_H
#define MYSCENE_H

#include <QGraphicsScene>



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

};

#endif // MYSCENE_H
