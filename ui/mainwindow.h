#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QWidget>
#include <QString>
#include <QDebug>
#include <QFont>
#include <QPainter>
#include <QMouseEvent>
#include <QLabel>
#include "OffMusic.h"
#include "player.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    void initial();
    ~MainWindow();

private slots:
    void on_addLocalMusicBtn_clicked();

    void on_playMusicBtn_clicked();

    void on_soundSlider_valueChanged(int value);

private:
    Ui::MainWindow *ui;
    QPoint dragPosition;
    bool sta;
    Player list;
    void mousePressEvent(QMouseEvent*);
    void mouseMoveEvent(QMouseEvent*);
    void paintEvent(QPaintEvent *);
    void pictolabel(QString pic, QLabel *label, int, int);
};

#endif // MAINWINDOW_H
