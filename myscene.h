#ifndef MYSCENE_H
#define MYSCENE_H

#include <QGraphicsScene>
#include <QTimer>

class Player;
class BackgroundItem;

class MyScene : public QGraphicsScene
{

public:
    explicit MyScene(QObject* parent);
private:
    int m_fieldWidth;
    int m_velocity;
    int m_worldShift;
    qreal m_minX;
    qreal m_maxX;
    qreal m_currentX;
    qreal m_groundLevel;
    QTimer m_timer;

    Player* m_player;
    BackgroundItem* m_sky;
    BackgroundItem* m_trees;
    BackgroundItem* m_grass;

    int m_horizontalInput;

    void addHorizontalInput(int input);
    void applyParallax(qreal ratio, QGraphicsItem* item);

private slots:
    void movePlayer();
    void checkTimer();

protected:
    void keyPressEvent(QKeyEvent *event);
};

#endif // MYSCENE_H
