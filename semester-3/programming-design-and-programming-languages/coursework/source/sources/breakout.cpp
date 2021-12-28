#include <QPainter>
#include <QApplication>
#include <QSound>
#include <QSoundEffect>
#include "breakout.h"
#include <QMediaPlayer>
#include <QMediaPlaylist>
#include <QRandomGenerator>
#include <QDateTime>
#include <QCoreApplication>
#include <QDateTime>
#include <iostream>

Breakout::Breakout(QWidget *parent)
    : QWidget(parent) {
    QSound music(":/music/music.wav");
    music.play(":/music/music.wav");
    music.setLoops(2); // optimal number for ending game by Victory
    QPixmap bkgnd(":/img/g.png");
    bkgnd = bkgnd.scaled(this->size(), Qt::IgnoreAspectRatio);
    QPalette palette;
    palette.setBrush(QPalette::Background, bkgnd);
    this->setPalette(palette);
    x = 0;
    gameOver = false;
    gameWon = false;
    paused = false;
    gameStarted = false;
    ball = new Ball();
    paddle = new Paddle();

    int k = 0;

    QRandomGenerator *rg = QRandomGenerator::global();

    for (int i=0; i<5; i++) {
        for (int j=0; j<6; j++) {
            int e = rg->bounded(1, 10);
            int l = rg->bounded(1, 10);
            if (e%2 == 0){
                bricks[k] = new Brick(j*90+60, i*30+100);
                colors[k] = 0;
            }
            else {
                bricks[k] = new Brick(j*90+60, i*30+100,e);
                colors[k] = 1;
                if (l%2 == 0){
                    bricks[k] = new Brick(j*90+60, i*30+100,e,l);
                    colors[k] = 2;
                }
            }
            coord[k] = (i*10+j);
            k++;
        }
    }
}

Breakout::~Breakout() {
    delete ball;
    delete paddle;

    for (int i=0; i<N_OF_BRICKS; i++) {
        delete bricks[i];
    }
}

void Breakout::paintEvent(QPaintEvent *e) {
    Q_UNUSED(e);

    QPainter painter(this);

    if (gameOver) {
        QSound::play(":/music/lose.wav");
        finishGame(&painter, "Game lost");
    }
    else if(gameWon) {
        QSound::play(":/music/win.wav");
        finishGame(&painter, "Victory");
    }
    else {
        drawObjects(&painter);
    }
}

void Breakout::finishGame(QPainter *painter, QString message) {
    QFont font("Courier", 15, QFont::DemiBold);
    QFontMetrics fm(font);
    int textWidth = fm.width(message);

    painter->setFont(font);
    int h = height();
    int w = width();

    painter->translate(QPoint(w/2, h/2));
    painter->drawText(-textWidth/2, -20, message);

    QFont font1("Courier", 5, QFont::DemiBold);
    painter->setFont(font1);
    painter->drawText(-textWidth/2-25, 20, "Enter space to continue");
}

void Breakout::drawObjects(QPainter *painter) {
    painter->drawImage(ball->getRect(), ball->getImage());
    painter->drawImage(paddle->getRect(), paddle->getImage());

    for (int i=0; i<N_OF_BRICKS; i++) {
        if (!bricks[i]->isDestroyed()) {
            painter->drawImage(bricks[i]->getRect(), bricks[i]->getImage());
        }
    }
}

void Breakout::timerEvent(QTimerEvent *e) {
    Q_UNUSED(e);

    moveObjects();
    checkCollision();
    repaint();
}

void Breakout::moveObjects() {
    ball->autoMove();
    paddle->move();
}

void Breakout::keyReleaseEvent(QKeyEvent *e) {
    int dx = 0;

    switch (e->key()) {
    case Qt::Key_Left:
        dx = 0;
        if(paddle->getRect().left() <= 10)
            paddle->move(10);
        paddle->setDx(dx);
        break;

    case Qt::Key_Right:
        dx = 0;
        if(paddle->getRect().left() >= 634)
            paddle->move(550);
        paddle->setDx(dx);
        break;
    }
}

void Breakout::keyPressEvent(QKeyEvent *e) {
    int dx = 0;
//        std::cout << "left = " << paddle->getRect().left() << " right = " << paddle->getRect().right() << std::endl; -- for debugging
    switch (e->key()) {
    case Qt::Key_Left:
       if(paddle->getRect().left() <= 10) {
           dx = 0;
           paddle->move(10);
       }
        else dx = -2;
        paddle->setDx(dx);
        break;

    case Qt::Key_Right:
        if(paddle->getRect().right() >= 634) {
            dx = 0;
            paddle->move(550);
        }
        else dx = 2;
        paddle->setDx(dx);
        break;

    case Qt::Key_P:
        pauseGame();
        break;

    case Qt::Key_Space:
        startGame();
        break;

    case Qt::Key_Escape:
        qApp->exit();
        break;

    default:
        QWidget::keyPressEvent(e);
    }
}

void Breakout::startGame() {
    if (!gameStarted) {
        ball->resetState();
        paddle->resetState();

        for (int i=0; i<N_OF_BRICKS; i++) {
            bricks[i]->setDestroyed(false);
        }

        gameOver = false;
        gameWon = false;
        gameStarted = true;
        timerId = startTimer(DELAY);
    }
}

void Breakout::pauseGame() {
    if (paused) {
        timerId = startTimer(DELAY);
        paused = false;
    }

    else {
        paused = true;
        std::cout << "Pause" << std::endl;
        killTimer(timerId);

    }
}

void Breakout::stopGame() {
    killTimer(timerId);
    gameOver = true;
    gameStarted = false;

}

void Breakout::victory() {
    killTimer(timerId);
    gameWon = true;
    gameStarted = false;
}

void Breakout::checkCollision() {
    if (ball->getRect().bottom() > BOTTOM_EDGE) {
        stopGame();
    }
    if (ball->getRect().bottom() < 0) { // check collusion with upper borders
        QRandomGenerator *rg = QRandomGenerator::global(); int e = rg->bounded(1, 10);
        if (e % 2 == 0) {
            ball->setXDir(-1);
        }
        else    {
            ball->setXDir(1);
        }
        ball->setYDir(+2);
    }


    for (int i=0, j=0; i<N_OF_BRICKS; i++) {
        if (bricks[i]->isDestroyed()) {
            j++;
        }

        if (j == N_OF_BRICKS) {
            victory();
        }
    }

    if ((ball->getRect()).intersects(paddle->getRect())) {
        int paddleLPos = paddle->getRect().left();
        int ballLPos = ball->getRect().left();

        int first = paddleLPos + 3;
        int second = paddleLPos + 25;
        int third = paddleLPos + 50;
        int fourth = paddleLPos + 75;

        if (ballLPos < first) {
            ball->setXDir(-1);
            ball->setYDir(-2);
        }

        if (ballLPos >= first && ballLPos < second) {
            ball->setXDir(-1);
            ball->setYDir(-1*ball->getYDir());
        }

        if (ballLPos >= second && ballLPos < third) {
            ball->setXDir(0);
            ball->setYDir(-3);
        }

        if (ballLPos >= third && ballLPos < fourth) {
            ball->setXDir(1);
            ball->setYDir(-1*ball->getYDir());
        }

        if (ballLPos > fourth) {
            ball->setXDir(1);
            ball->setYDir(-2);
        }
    }

    for (int i=0; i<N_OF_BRICKS; i++) {
        if ((ball->getRect()).intersects(bricks[i]->getRect())) {
            int ballLeft = ball->getRect().left();
            int ballHeight = ball->getRect().height();
            int ballWidth = ball->getRect().width();
            int ballTop = ball->getRect().top();

            QPoint pointRight(ballLeft + ballWidth + 1, ballTop);
            QPoint pointLeft(ballLeft - 1, ballTop);
            QPoint pointTop(ballLeft, ballTop -1);
            QPoint pointBottom(ballLeft, ballTop + ballHeight + 1);

            if (!bricks[i]->isDestroyed()) {
                //x
                if(bricks[i]->getRect().contains(pointRight)) {
                    ball->setXDir(-1);
                }
                else if(bricks[i]->getRect().contains(pointLeft)) {
                    ball->setXDir(1);
                }
                //y
                if(bricks[i]->getRect().contains(pointTop)) {
                    ball->setYDir(2);
                }
                else if(bricks[i]->getRect().contains(pointBottom)) {
                    ball->setYDir(-2);
                }
                // changing color or destroying
                if (colors[i] == 0){
                    bricks[i]->setDestroyed(true);
                }
                if (colors[i] == 1){
                    int w = coord[i]/10;
                    int h = coord[i]%10;
                    bricks[i] = new Brick(h*90+60, w*30+100);
                    colors[i] = 0;
                }
                if (colors[i] == 2){
                    int w = coord[i]/10;
                    int h = coord[i]%10;
                    bricks[i] = new Brick(h*90+60, w*30+100, 1);
                    colors[i] = 1;
                }
            }
        }
    }
}
