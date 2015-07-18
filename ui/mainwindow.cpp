#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QPainter>
#include <QColor>
#include <QDebug>
#include <QFile>
#include <QFileDialog>
#include <QUrl>

void MainWindow::initial()
{
    QFile style(":/icon/view.qss");
    if (!style.exists())
    {
        qDebug() << "qss file not exisits";
        exit(1);
    }

    if (!style.open((QIODevice::ReadOnly)))
    {
        qDebug() << "cannot open qss file.";
        exit(1);
    }

    qApp->setStyleSheet(style.readAll());
    style.close();

    pictolabel(":/icon/images/format.png", ui->format, 30, 30);
    pictolabel(":/icon/images/search.png", ui->searchIcon, 20, 20);
    pictolabel(":/icon/images/soundIcon.png", ui->soundIcon, 20, 20);

    int l, r, t, b;
    ui->search->getTextMargins(&l, &t, &r, &b);
    ui->search->setTextMargins(5, t, r + 6, b);
    ui->search->setPlaceholderText("SEARCH");

    ui->soundSlider->setMinimum(0);
    ui->soundSlider->setMaximum(100);
    ui->soundSlider->setValue(20);

    ui->musicList->setColumnCount(5);
    ui->musicList->setHorizontalHeaderLabels(QStringList() <<
                                             tr("") <<
                                             tr("Name") <<
                                             tr("Album") <<
                                             tr("Artist") <<
                                             tr("Duration"));
    ui->musicList->setColumnWidth(0, 60);
    ui->musicList->setColumnWidth(1, 230);
    ui->musicList->setColumnWidth(2, 150);
    ui->musicList->setColumnWidth(3, 120);
    ui->musicList->verticalHeader()->setVisible(false);
    ui->musicList->setSelectionBehavior(QAbstractItemView::SelectRows);
}

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow),
    sta(false)
{
    ui->setupUi(this);

    setFixedSize(this->width(), this->height());
    setWindowFlags(Qt::FramelessWindowHint);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::pictolabel(QString pic, QLabel *label, int width, int height)
{
    QImage img(pic);
    QImage a_img = img.scaled(width, height, Qt::KeepAspectRatio, Qt::SmoothTransformation);
    label->setPixmap(QPixmap::fromImage(a_img));
    label->resize(a_img.width(), a_img.height());
}

void MainWindow::mousePressEvent(QMouseEvent *event)
{
    if (event->button() == Qt::LeftButton)
    {
        this->dragPosition = event->globalPos() - this->frameGeometry().topLeft();
        event->accept();
    }
}

void MainWindow::mouseMoveEvent(QMouseEvent *event)
{
    if (event->buttons() & Qt::LeftButton)
    {
        move(event->globalPos() - this->dragPosition);
        event->accept();
    }
}

void MainWindow::paintEvent(QPaintEvent *)
{
    QPainter painter(this);
    QBrush brush(Qt::SolidPattern);
    //上部
    brush.setColor(QColor(153,51,51));
    painter.setBrush(brush);
    painter.drawRect(QRect(0,0, this->width(), 100));
    painter.setBrush(Qt::NoBrush);
    //中间右半
    brush.setColor(QColor(75,75,75));
    painter.setBrush(brush);
    painter.drawRect(QRect(240,100, this->width(), this->height() - 180));
    //中间左半
    brush.setColor(QColor(118, 118, 118));
    painter.setBrush(brush);
    painter.drawRect(QRect(0,100, 240, this->height() - 180));
    painter.setBrush(Qt::NoBrush);
    //下部
    brush.setColor(QColor(153,51,51));
    painter.setBrush(brush);
    painter.drawRect(QRect(0,this->height() - 80, this->width(), this->height()));
    painter.setBrush(Qt::NoBrush);
}

void MainWindow::on_addLocalMusicBtn_clicked()
{
    QUrl url;
    url = QFileDialog::getOpenFileUrl(this, tr("Open Music File"), tr("."), tr("mp3 music files(*.mp3)"));
    list.addToList(url);
}

void MainWindow::on_playMusicBtn_clicked()
{
    list.Retreat();
    sta = list.GetPlayingState();
    if (!sta)
    {
        ui->playMusicBtn->setStyleSheet
        ("\
            QPushButton#playMusicBtn:!hover\
            {\
                border-image: url(:/icon/images/playMusicBtn.png);\
                background-color:white;\
                border-radius: 30px;\
                outline: 10px;\
            }\
            QPushButton#playMusicBtn:hover\
            {\
                border-image: url(:/icon/images/playMusicBtn.png);\
                background-color:white;\
                border-radius: 30px;\
                outline: 10px;\
            }\
            QPushButton#playMusicBtn:pressed\
            {\
                border-image: url(:/icon/images/playMusicBtn.png);\
                background-color:white;\
                border-radius: 30px;\
                outline: 10px;\
            }\
        ");
    }else
    {
        ui->playMusicBtn->setStyleSheet
        ("\
            QPushButton#playMusicBtn:!hover\
            {\
                border-image: url(:/icon/images/pauseMusicBtn.png);\
                background-color:white;\
                border-radius: 30px;\
                outline: 10px;\
            }\
            QPushButton#playMusicBtn:hover\
            {\
                border-image: url(:/icon/images/pauseMusicBtn.png);\
                background-color:white;\
                border-radius: 30px;\
                outline: 10px;\
            }\
            QPushButton#playMusicBtn:pressed\
            {\
                border-image: url(:/icon/images/pauseMusicBtn.png);\
                background-color:white;\
                border-radius: 30px;\
                outline: 10px;\
            }\
        ");
    }
}

void MainWindow::on_soundSlider_valueChanged(int value)
{
    list.SetVolume(value);
}
