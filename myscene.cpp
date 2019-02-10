#include <QKeyEvent>
#include "myscene.h"

MyScene::MyScene()
{
    // set initial values - these may need to be fixed!
    m_fieldWidth = 500;
    m_minX = 0;
    m_maxX = 500;
    m_currentX = 0;
    m_groundLevel = 0;

    m_timer.setInterval(30);
    connect(&m_timer, &QTimer::timeout,
            this, &MyScene::movePlayer);
}

void MyScene::movePlayer() {
    // do nothing for now
    return;
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
    return;
}
