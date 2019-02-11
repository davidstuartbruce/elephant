#include <QKeyEvent>
#include "myscene.h"
#include "player.h"


MyScene::MyScene(QObject* parent) :
    QGraphicsScene(parent),
    m_fieldWidth(1500),
    m_minX(0),
    m_maxX(1500),
    m_groundLevel(300),
    m_velocity(0)

{
    m_timer.setInterval(30);
    connect(&m_timer, &QTimer::timeout,
            this, &MyScene::movePlayer);
}

void MyScene::movePlayer() {
    const int direction = m_player->direction();
    if (0 == direction) {
        return;
    }
    const int dx = direction * m_velocity;
    qreal newX = qBound(m_minX, m_currentX + dx, m_maxX);
    if (newX == m_currentX) {
        return;
    }
    m_currentX = newX;
}

void MyScene::keyPressEvent(QKeyEvent *event) {
    if (event->isAutoRepeat()) {
        return;
    }
    switch (event->key()) {
    case Qt::Key_Right:
        addHorizontalInput(1);
        break;
    case Qt::Key_Left:
        addHorizontalInput(-1);
        break;
    }
    return;
}

void MyScene::addHorizontalInput(int input) {
    m_horizontalInput += input;
    m_player->setDirection(qBound(-1, m_horizontalInput, 1));
    checkTimer();
}
void MyScene::checkTimer() {
    if (m_player->direction() == 0) {
        m_timer.stop();
    } else if (!m_timer.isActive()) {
        m_timer.start();
    }
}
