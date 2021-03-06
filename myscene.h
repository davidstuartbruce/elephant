#ifndef MYSCENE_H
#define MYSCENE_H

#include <QGraphicsScene>
#include <QTimer>

class Player;
class BackgroundItem;
class QPropertyAnimation;

class MyScene : public QGraphicsScene
{
    Q_OBJECT

    Q_PROPERTY(qreal jumpFactor
               READ jumpFactor
               WRITE setJumpFactor
               NOTIFY jumpFactorChanged)


public:
    explicit MyScene(QObject* parent = nullptr);
    qreal jumpFactor() const;
    void setJumpFactor(const qreal &jumpFactor);


private slots:
    void movePlayer();
    void checkTimer();

protected:
    void keyPressEvent(QKeyEvent *event);

signals:
    void jumpFactorChanged(qreal);

private:
    int m_fieldWidth;
    int m_velocity;
    int m_worldShift;
    qreal m_minX;
    qreal m_maxX;
    qreal m_currentX;
    qreal m_groundLevel;
    qreal m_jumpFactor;

    QTimer m_timer;

    Player* m_player;
    BackgroundItem* m_sky;
    BackgroundItem* m_trees;
    BackgroundItem* m_grass;
    QPropertyAnimation* m_jumpAnimation;

    int m_horizontalInput;

    void addHorizontalInput(int input);
    void applyParallax(qreal ratio, QGraphicsItem* item);

};

#endif // MYSCENE_H
