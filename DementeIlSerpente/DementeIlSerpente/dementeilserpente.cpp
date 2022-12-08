
#include <QPainter>
#include <QTime>
#include "dementeilserpente.h"

DementeIlSerpente::DementeIlSerpente(QWidget *parent) : QWidget(parent) {

    setStyleSheet("background-color:blue;");
    sinistra = false;
    destra = true;
    sopra = false;
    sotto = false;
    giochino = true;

    setFixedSize(larghezza, altezza);
    caricaImmagini();
    start();
}

void DementeIlSerpente::caricaImmagini() {

    punto.load("dot.png");
    testa.load("head.png");
    cibo.load("apple.png");
}

void DementeIlSerpente::start() {

    punti = 2;

    for (int i = 0; i < punti; i++) {
        x[i] = 50 - i * 10;
        y[i] = 50;
    }

    mettiCibo();

    timerId = startTimer(ritardo);
}

void DementeIlSerpente::paintEvent(QPaintEvent *e) {

    Q_UNUSED(e);

    disegno();
}

void DementeIlSerpente::disegno() {

    QPainter qp(this);

    if (giochino) {

        qp.drawImage(cibo_x, cibo_y, cibo);

        for (int i = 0; i < punti; i++) {
            if (i == 0) {
                qp.drawImage(x[i], y[i], testa);
            } else {
                qp.drawImage(x[i], y[i], punto);
            }
        }

    } else {

        gameOver(qp);
    }
}

void DementeIlSerpente::gameOver(QPainter &qp) {

    QString message = "Hai perso,riprova";

    QFont font("Courier", 10, QFont::DemiBold);
    QFontMetrics fm(font);
    int textWidth = fm.width(message);

    qp.setFont(font);
    int h = height();
    int l = width();

    qp.translate(QPoint(l/2, h/2));
    qp.drawText(-textWidth/2, 0, message);

}

void DementeIlSerpente::controllaCibo() {

    if ((x[0] == cibo_x) && (y[0] == cibo_y)) {

        punti++;
        mettiCibo();
    }
}

void DementeIlSerpente::mossa() {

    for (int i = punti; i > 0; i--) {
        x[i] = x[(i - 1)];
        y[i] = y[(i - 1)];
    }

    if (sinistra) {
        x[0] -= dimensione_punto;
    }

    if (destra) {
        x[0] += dimensione_punto;
    }

    if (sopra) {
        y[0] -= dimensione_punto;
    }

    if (sotto) {
        y[0] += dimensione_punto;
    }
}

void DementeIlSerpente::controllaScontro() {

    for (int i = punti; i > 0; i--) {

        if ((i > 4) && (x[0] == x[i]) && (y[0] == y[i])) {
            giochino = false;
        }
    }

    if (y[0] >= altezza) {
        giochino = false;
    }

    if (y[0] < 0) {
        giochino = false;
    }

    if (x[0] >= larghezza) {
        giochino = false;
    }

    if (x[0] < 0) {
        giochino = false;
    }

    if(!giochino) {
        killTimer(timerId);
    }
}

void DementeIlSerpente::mettiCibo() {

    QTime time = QTime::currentTime();
    qsrand((uint) time.msec());

    int r = qrand() % rand_posizione;
    cibo_x = (r * dimensione_punto);

    r = qrand() % rand_posizione;
    cibo_y = (r * dimensione_punto);
}

void DementeIlSerpente::timerEvent(QTimerEvent *e) {

    Q_UNUSED(e);

    if (giochino) {

        controllaCibo();
        controllaScontro();
        mossa();
    }

    repaint();
}

void DementeIlSerpente::keyPressEvent(QKeyEvent *e) {

    int key = e->key();

    if ((key == Qt::Key_Left) && (!destra)) {
        sinistra = true;
        sopra = false;
        sotto = false;
    }

    if ((key == Qt::Key_Right) && (!sinistra)) {
        destra = true;
        sopra = false;
        sotto = false;
    }

    if ((key == Qt::Key_Up) && (!sotto)) {
        sopra = true;
        destra = false;
        sinistra = false;
    }

    if ((key == Qt::Key_Down) && (!sopra)) {
        sotto = true;
        destra = false;
        sinistra = false;
    }

    QWidget::keyPressEvent(e);
}
