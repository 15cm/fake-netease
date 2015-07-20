#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QPainter>
#include <QColor>
#include <QDebug>
#include <QFile>
#include <QFileDialog>
#include <QUrl>
#include <commander.h>
#include "hintdialog.h"

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
    //搜索栏设置
    int l, r, t, b;
    ui->search->getTextMargins(&l, &t, &r, &b);
    ui->search->setTextMargins(5, t, r + 6, b);
    ui->search->setPlaceholderText("SEARCH");
    //音量调设置
    ui->soundSlider->setMinimum(0);
    ui->soundSlider->setMaximum(100);
    ui->soundSlider->setValue(20);

    //在线列表设置
    ui->musicList->setRowCount(50);
    ui->musicList->setColumnCount(5);
    ui->musicList->setHorizontalHeaderLabels(QStringList() <<
                                             tr("") <<
                                             tr("Name") <<
                                             tr("Album") <<
                                             tr("Artist") <<
                                             tr("Duration"));

    ui->musicList->setColumnWidth(0, 30);
    ui->musicList->setColumnWidth(1, 200);
    ui->musicList->setColumnWidth(2, 200);
    ui->musicList->setColumnWidth(3, 140);
    ui->musicList->verticalHeader()->setVisible(false);
    ui->musicList->setSelectionBehavior(QAbstractItemView::SelectRows);
    ui->musicList->setShowGrid(false);
    ui->musicList->resize(QSize(this->width() - 242, this->height() - 182));
    ui->musicList->setEditTriggers(QTableWidget::NoEditTriggers);
    ui->musicList->horizontalHeader()->setStretchLastSection(true);
    ui->musicList->setAlternatingRowColors(true);
    ui->musicList->horizontalHeader()->setHighlightSections(false);

    //local列表设置
    ui->musicListLocal->setRowCount(50);
    ui->musicListLocal->setColumnCount(5);
    ui->musicListLocal->setHorizontalHeaderLabels(QStringList() <<
                                             tr("") <<
                                             tr("Name") <<
                                             tr("Album") <<
                                             tr("Artist") <<
                                             tr("Duration"));

    ui->musicListLocal->setColumnWidth(0, 30);
    ui->musicListLocal->setColumnWidth(1, 200);
    ui->musicListLocal->setColumnWidth(2, 200);
    ui->musicListLocal->setColumnWidth(3, 140);
    //ui->musicListLocal->setColumnWidth(4, 82);
    ui->musicListLocal->verticalHeader()->setVisible(false);
    ui->musicListLocal->setSelectionBehavior(QAbstractItemView::SelectRows);
    ui->musicListLocal->setShowGrid(false);
    ui->musicListLocal->resize(QSize(this->width() - 242, this->height() - 182));
    ui->musicListLocal->setEditTriggers(QTableWidget::NoEditTriggers);
    ui->musicListLocal->horizontalHeader()->setStretchLastSection(true);
    ui->musicListLocal->setAlternatingRowColors(true);
    ui->musicListLocal->horizontalHeader()->setHighlightSections(false);

    //歌单设置
    ui->musicListLocal->setFrameShape(QListWidget::NoFrame);
    ui->favoriteList->addItem(new QListWidgetItem(QIcon(QObject::tr(":/icon/images/favorite.png")), QObject::tr("收藏歌曲")));
    ui->favoriteList->addItem(new QListWidgetItem(QIcon(QObject::tr(":/icon/images/localList.png")), QObject::tr("本地列表")));
    ui->favoriteList->addItem(new QListWidgetItem(QIcon(QObject::tr(":/icon/images/playList.png")), QObject::tr("播放列表")));
    for (int i = 0; i < ui->musicList->rowCount(); i++)
        for (int j = 0; j < ui->musicList->columnCount(); j++)
        {
            if (j > 0)
                ui->musicList->setItem(i, j, new QTableWidgetItem(" "));
            else
                ui->musicList->setCellWidget(i, j, new QLabel);
            if (j == 4)
                ui->musicList->item(i, j)->setTextAlignment(Qt::AlignCenter);
        }
    for (int i = 0; i < ui->musicListLocal->rowCount(); i++)
        for (int j = 0; j < ui->musicListLocal->columnCount(); j++)
        {
            if (j > 0)
                ui->musicListLocal->setItem(i, j, new QTableWidgetItem(" "));
            else
                ui->musicListLocal->setCellWidget(i, j, new QLabel);
            if (j == 4)
                ui->musicListLocal->item(i, j)->setTextAlignment(Qt::AlignCenter);
        }
    ui->musicList->hide();
    ui->musicListLocal->hide();

    //循环方式
    ui->playMethod->setIcon(QIcon(":/icon/images/loopPlay.png"));
    loop = 0;

    pictolabel(":/icon/images/album.png", ui->musicPic, 238, 238);

    // table init
    Commander c;
    QImage deleteIcon1(":/icon/images/delete.png");
    QImage deleteIcon = deleteIcon1.scaled(25,25,Qt::KeepAspectRatio,Qt::SmoothTransformation);
    c.PlayerInit(ui->musicListLocal,deleteIcon);
    ui->musicListLocal->show();
    connect(&Player::MediaPlayer, &QMediaPlayer::durationChanged, ui->musicSlider, [=](qint64 duration){
       ui->musicSlider->setMaximum(duration);
    });
    connect(&Player::MediaPlayer, &QMediaPlayer::positionChanged, ui->musicSlider, [=](qint64 progress){
       ui->musicSlider->setValue(progress);
       QTime t = QTime::fromMSecsSinceStartOfDay(progress);
       QString ss = t.toString();
       ss.remove(0, 3);
       ui->position->setText(ss);
       ui->musicSlider->update();
    });

    //lyric table
    ui->lyricLabel1->setAlignment(Qt::AlignCenter);
    ui->lyricLabel1->hide();
    ui->lyricLabel2->setAlignment(Qt::AlignCenter);
    ui->lyricLabel2->hide();
    ui->lyricLabel3->setAlignment(Qt::AlignCenter);
    ui->lyricLabel3->hide();
    lrcState = 0;
}

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow),
    sta(false)
{

    ui->setupUi(this);

    setFixedSize(this->width(), this->height());
    setWindowFlags(Qt::FramelessWindowHint);

        ui->musicListLocal->setFocusPolicy(Qt::NoFocus);
        ui->musicList->setFocusPolicy(Qt::NoFocus);
//        ui->search->setFocusPolicy();
        ui->favoriteList->setFocusPolicy(Qt::NoFocus);
}

MainWindow::~MainWindow()
{
    Commander c;
    c.PlayerTerminate();

    for (int i = 0; i < ui->musicList->rowCount(); i++)
        for (int j = 1; j < ui->musicList->columnCount(); j++)
        {
            delete ui->musicList->item(i, j);
        }
    for (int i = 0; i < ui->musicListLocal->rowCount(); i++)
        for (int j = 1; j < ui->musicListLocal->columnCount(); j++)
        {
            delete ui->musicListLocal->item(i, j);
        }
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
    if (event->buttons() && Qt::LeftButton && this ->dragPosition.x()  >= 0 && this->dragPosition.y() <= 40 && this ->dragPosition.y()  >= 0 && this ->dragPosition.x()  <= this->width())
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

void MainWindow::changePlayMusicBtn()
{
    Commander c;
    if (c.GetCurrentPlayState())
    {
        ui->playMusicBtn->setStyleSheet("\
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
                                        }");
    }else
    {
        ui->playMusicBtn->setStyleSheet("\
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
                                        }");
    }
}

void MainWindow::on_addLocalMusicBtn_clicked()
{
    Commander c;
    QImage deleteIcon1(":/icon/images/delete.png");
    QImage deleteIcon = deleteIcon1.scaled(25,25,Qt::KeepAspectRatio,Qt::SmoothTransformation);
    c.AddLocalMusic(ui->musicListLocal,deleteIcon);
    ui->musicList->hide();
    ui->musicListLocal->show();
}

void MainWindow::on_playMusicBtn_clicked()
{
    Commander c;
    c.PlayOrPauseCurrentMusic();
    changePlayMusicBtn();
}

void MainWindow::on_soundSlider_valueChanged(int value)
{
    Commander c;
    c.SetVolume(value);

    if (value == 0)
    {
        pictolabel(":/icon/images/noSound.png", ui->soundIcon, 20, 20);
    }else
    {
        pictolabel(":/icon/images/soundIcon.png", ui->soundIcon, 20, 20);
    }
}

void MainWindow::on_musicList_clicked(const QModelIndex &index)
{
   // ui->musicList->selectRow(index.row());
}

void MainWindow::on_search_returnPressed()
{
    Commander *p = new Commander;
    QVector<bool> res = p->FillOnlineMusicTable(ui->musicList, ui->search->text());
    ui->musicList->show();
    ui->musicListLocal->hide();
    ui->favoriteList->setCurrentRow(2);
}

void MainWindow::on_playMethod_clicked()
{
    loop = (loop +  1) % 3;
    switch (loop)
    {
        case 0:
            ui->playMethod->setIcon(QIcon(":/icon/images/loopPlay.png"));
        break;
        case 1:
            ui->playMethod->setIcon(QIcon(":/icon/images/singlePlay.png"));
        break;
        case 2:
            ui->playMethod->setIcon(QIcon(":/icon/images/randomPlay.png"));
        break;
    }
    Commander c;
    c.ChangePlayModel(loop);
}

void MainWindow::on_musicList_doubleClicked(const QModelIndex &index)
{
   Commander p;
   QImage img;
   p.PlaySelectedOnMusic(index.row(), lrc, img);
    QImage a_img = img.scaled(238, 238, Qt::KeepAspectRatio, Qt::SmoothTransformation);
    ui->musicPic->setPixmap(QPixmap::fromImage(a_img));
    ui->musicPic->resize(a_img.width(), a_img.height());
    changePlayMusicBtn();
}

void MainWindow::on_lastMusicBtn_clicked()
{
    Commander c;
    c.PreviousMusic();
}

void MainWindow::on_nextMusicBtn_clicked()
{
    Commander c;
    c.NextMusic();
}

void MainWindow::on_musicSlider_valueChanged(int value)
{
    /*Player list;
    list.SetPositon((qint64)value);*/
    // slider bar
    Commander c;
    c.SliderBarUpdate(qint64(value));
}

void MainWindow::on_musicListLocal_doubleClicked(const QModelIndex &index)
{
    Commander c;
    c.PlaySelectedMusic(index.row());
    pictolabel(":/icon/images/album.png",ui->musicPic,238,238);
    changePlayMusicBtn();
}

void MainWindow::on_favoriteList_clicked(const QModelIndex &index)
{
    qDebug() << index.row() << endl;
   if (index.row() == 1)
   {
       ui->musicListLocal->show();
       ui->musicList->hide();
   }else
   if (index.row() == 2)
   {
       ui->musicList->show();
       ui->musicListLocal->hide();
   }
}

void MainWindow::on_addMusicFolderBtn_clicked()
{
    Commander c;
    QImage deleteIcon1(":/icon/images/delete.png");
    QImage deleteIcon = deleteIcon1.scaled(25,25,Qt::KeepAspectRatio,Qt::SmoothTransformation);
    c.AddLocalMusicFolder(ui->musicListLocal, deleteIcon);
}

void MainWindow::on_musicListLocal_clicked(const QModelIndex &index)
{

    if (index.column() == 0)
    {
        Commander c;
        c.DeleteSelectedOffMusic(index.row(),ui->musicListLocal);
    }
}

void MainWindow::on_lyric_clicked()
{
    if (lrcState == 0)
    {
        ui->lyricLabel1->hide();
        ui->lyricLabel2->hide();
        ui->lyricLabel3->hide();
    }
    else
    {
        ui->lyricLabel1->show();
        ui->lyricLabel2->show();
        ui->lyricLabel3->show();
    }
    lrcState ^= 1;
}
