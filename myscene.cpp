#include <QKeyEvent>
#include "myscene.h"
#include "player.h"


MyScene::MyScene(QObject* parent) :
    QGraphicsScene(parent),
    m_fieldWidth(1500),
    m_minX(0),
    m_maxX(0),
    m_groundLevel(300),
    m_velocity(4),
    m_worldShift(0),
    m_player(nullptr)

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

    const int shiftBorder = 150;
    const int rightShiftBorder = width() - shiftBorder;

    const int visiblePlayerPos = m_currentX - m_worldShift;

    const int newWorldShiftRight = visiblePlayerPos - rightShiftBorder;
    if (newWorldShiftRight > 0) {
        m_worldShift += newWorldShiftRight;
    }

    const int newWorldShiftLeft = shiftBorder - visiblePlayerPos;
    if (newWorldShiftLeft > 0) {
        m_worldShift -= newWorldShiftLeft;
    }

    const int maxWorldShift = m_fieldWidth - qRound(width());
    m_worldShift = qBound(0, m_worldShift, maxWorldShift);
    m_player->setX(m_currentX - m_worldShift);

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
