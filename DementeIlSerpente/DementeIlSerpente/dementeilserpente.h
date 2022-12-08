#ifndef DEMENTEILSERPENTE_H
#define DEMENTEILSERPENTE_H
#pragma once

#include <QWidget>
#include <QKeyEvent>

class DementeIlSerpente : public QWidget  {

    public:
        DementeIlSerpente(QWidget *parent = nullptr);

    protected:
        void paintEvent(QPaintEvent *);
        void timerEvent(QTimerEvent *);
        void keyPressEvent(QKeyEvent *);

    private:
        QImage punto;
        QImage testa;
        QImage cibo;

        static const int larghezza = 300;
        static const int altezza = 300;
        static const int dimensione_punto = 10;
        static const int tot_punti = 900;
        static const int rand_posizione = 29;
        static const int ritardo = 140;

        int timerId;
        int punti;
        int cibo_x;
        int cibo_y;

        int x[tot_punti];
        int y[tot_punti];

        bool sinistra;
        bool destra;
        bool sopra;
        bool sotto;
        bool giochino;

        void caricaImmagini();
        void start();
        void mettiCibo();
        void controllaCibo();
        void controllaScontro();
        void mossa();
        void disegno();
        void gameOver(QPainter &);



};

#endif // DEMENTEILSERPENTE_H
