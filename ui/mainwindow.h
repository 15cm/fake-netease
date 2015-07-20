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
//#include "OffMusic.h"
#include "player.h"
#include <QTableWidgetItem>
#include <QTime>

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
    //QTableWidgetItem *tableWidgetItem[50][5];

private slots:
    void on_addLocalMusicBtn_clicked();

    void on_playMusicBtn_clicked();

    void on_soundSlider_valueChanged(int value);

    void on_musicList_clicked(const QModelIndex &index);

    void on_search_returnPressed();

    void on_playMethod_clicked();

    void on_musicList_doubleClicked(const QModelIndex &index);

    void on_lastMusicBtn_clicked();

    void on_nextMusicBtn_clicked();

    void on_musicSlider_valueChanged(int value);

    void on_musicListLocal_doubleClicked(const QModelIndex &index);

    void on_favoriteList_clicked(const QModelIndex &index);


    void on_addMusicFolderBtn_clicked();

    void on_musicListLocal_clicked(const QModelIndex &index);

    void on_lyric_clicked();

private:
    Ui::MainWindow *ui;
    QPoint dragPosition;   bool sta;
    QString lrc;
    int lrcState;
    int loop;
    //Player list;
    void mousePressEvent(QMouseEvent*);
    void mouseMoveEvent(QMouseEvent*);
    void paintEvent(QPaintEvent *);
    void pictolabel(QString pic, QLabel *label, int, int);
    void changePlayMusicBtn();
};

#endif // MAINWINDOW_H
