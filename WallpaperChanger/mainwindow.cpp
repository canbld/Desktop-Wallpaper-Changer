#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDebug>
#include <QGraphicsOpacityEffect>
#include <QPropertyAnimation>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent),
    ui(new Ui::MainWindow),
    timer(new QTimer(this)),
    remainingTime(30),
    currentWallpaperIndex(0) {

    ui->setupUi(this);

    countdownTimer = new QTimer(this);
    connect(countdownTimer, &QTimer::timeout, this, &MainWindow::updateRemainingTime);
    connect(ui->startButton, &QPushButton::clicked, this, &MainWindow::startCountdown);
    connect(timer, &QTimer::timeout, this, &MainWindow::updateWallpaperTimer);

    //Design Section

    this->setStyleSheet("background-color: #2c3e50;");

    QString buttonStyle =
        "QPushButton {"
        "    background-color: #FFA9E7;"
        "    color: black;"
        "    border: 0px;"
        "    padding: 5px 10px;"
        "    font-size: 11px;"
        "    border-radius: 10px;"
        "}"
        "QPushButton:hover {"
        "    background-color: #2980b9;"
        "}"
        "QPushButton:pressed {"
        "    background-color: #1f618d;"
        "}";
    ui->nextBtn->setStyleSheet(buttonStyle);
    ui->previousBtn->setStyleSheet(buttonStyle);
    ui->startButton->setStyleSheet(buttonStyle);

    ui->exitBtn->setStyleSheet(
        "QPushButton {"
        "    background-color: tomato;"
        "    color: black;"
        "    padding: 5px 10px;"
        "    font-size: 11px;"
        "    border-radius: 10px;"
        "}"
        "QPushButton:hover {"
        "    background-color: #2980b9;"
        "}"
        "QPushButton:pressed {"
        "    background-color: #1f618d;"
        "}"
        );


    ui->currentImage->setStyleSheet(
        "QLabel {"
        "    border: 4px solid #FFA9E7;"
        "    border-radius:10px;"
        "}"
        );
    ui->nextImage->setStyleSheet(
        "QLabel {"
        "    border: 4px solid #FFA9E7;"
        "    border-radius:10px;"
        "}"
        );
    ui->previousImage->setStyleSheet(
        "QLabel {"
        "    border: 4px solid #FFA9E7;"
        "    border-radius:10px;"
        "}"
        );

    QString textStyle =
        "QLabel {"
        "    color: white;"
        "    padding: 5px 10px;"
        "    font-size: 12px;"
        "    font-weight: bold;"
        "}";
    ui->label->setStyleSheet(textStyle);
    ui->label_2->setStyleSheet(textStyle);
    ui->label_3->setStyleSheet(textStyle);
    ui->label_4->setStyleSheet(textStyle);
    ui->label_6->setStyleSheet(textStyle);

    ui->label_5->setStyleSheet(
        "QLabel {"
        "    font-size: 20px;"
        "    font-weight: bold;"
        "}"
        );


    //Design Section


    // Arkaplan resimlerini yükle
    loadWallpapers();

    // Eğer en az 1 resim varsa ilkini göster
    if (!wallpaperPaths.isEmpty()) {
        setWallpaper(wallpaperPaths[currentWallpaperIndex]);
    }

    // Timer ayarları
    connect(timer, &QTimer::timeout, this, &MainWindow::updateWallpaperTimer);
    timer->start(1000); // 1 saniyede bir geri sayım

    // Buton bağlantıları
    connect(ui->nextBtn, &QPushButton::clicked, this, &MainWindow::changeToNextWallpaper);
    connect(ui->previousBtn, &QPushButton::clicked, this, &MainWindow::changeToPreviousWallpaper);
    connect(ui->exitBtn, &QPushButton::clicked, this, &MainWindow::exitBtn);
}

MainWindow::~MainWindow() {
    delete ui;
}

//Arkaplan resimlerini belirtilen klasörden yükler
void MainWindow::loadWallpapers() {
    QDir directory("#");
    QStringList filters;
    filters << "*.jpg" << "*.png" << "*.bmp";
    wallpaperPaths = directory.entryList(filters, QDir::Files);


    for (QString &path : wallpaperPaths) {
        path = directory.absoluteFilePath(path);
    }

    if (wallpaperPaths.isEmpty()) {
        qDebug() << "Arkaplan resmi bulunamadı!";
    }
}

//Masaüstü arkaplanını değiştirir---
void MainWindow::setWallpaper(const QString &path) {

    bool success = SystemParametersInfoW(SPI_SETDESKWALLPAPER, 0, (void*)path.utf16(), SPIF_UPDATEINIFILE | SPIF_SENDCHANGE);

    if (success) {
        qDebug() << "Arka plan değiştirildi: " << path;
    } else {
        qDebug() << "Arka plan değiştirilemedi!";
    }

    QPixmap pixmap(path);

    if (!pixmap.isNull()) {
        pixmap = pixmap.scaled(ui->currentImage->size(), Qt::KeepAspectRatio, Qt::SmoothTransformation);
        ui->currentImage->setPixmap(pixmap);
        ui->currentImage->setScaledContents(true);  // Resmi QLabel boyutlarına uydur
    }

    //Önceki ve sonraki resimleri ekleme
    if (!wallpaperPaths.isEmpty()) {
        // Önceki ve sonraki indeksleri hesapla
        int previousIndex = (currentWallpaperIndex - 1 + wallpaperPaths.size()) % wallpaperPaths.size();
        int nextIndex = (currentWallpaperIndex + 1) % wallpaperPaths.size();

        // Önceki resmi QLabel'e ekle
        QPixmap previousPixmap(wallpaperPaths[previousIndex]);
        if (!previousPixmap.isNull()) {
            QPixmap scaledPrevious = previousPixmap.scaled(ui->previousImage->size(), Qt::KeepAspectRatio, Qt::SmoothTransformation);
            ui->previousImage->setPixmap(scaledPrevious);
            ui->previousImage->setScaledContents(true);
        }

        // Sonraki resmi QLabel'e ekle
        QPixmap nextPixmap(wallpaperPaths[nextIndex]);
        if (!nextPixmap.isNull()) {
            QPixmap scaledNext = nextPixmap.scaled(ui->nextImage->size(), Qt::KeepAspectRatio, Qt::SmoothTransformation);
            ui->nextImage->setPixmap(scaledNext);
            ui->nextImage->setScaledContents(true);
        }
    }

    // Opaklık efekti oluştur
    QGraphicsOpacityEffect *effect = new QGraphicsOpacityEffect(ui->currentImage);
    QGraphicsOpacityEffect *effect2 = new QGraphicsOpacityEffect(ui->nextImage);
    QGraphicsOpacityEffect *effect3 = new QGraphicsOpacityEffect(ui->previousImage);

    ui->currentImage->setGraphicsEffect(effect);
    ui->nextImage->setGraphicsEffect(effect2);
    ui->previousImage->setGraphicsEffect(effect3);

    // Animasyon ayarları
    QPropertyAnimation *animation = new QPropertyAnimation(effect, "opacity");
    animation->setDuration(1300); // 1300ms sürede değişim
    animation->setStartValue(0.0); // Başlangıç: Görünmez
    animation->setEndValue(1.0);   // Bitiş: Görünür
    animation->setEasingCurve(QEasingCurve::InOutQuad); // Yumuşak geçiş

    QPropertyAnimation *animation2 = new QPropertyAnimation(effect2, "opacity");
    animation2->setDuration(900); // 900ms sürede değişim
    animation2->setStartValue(0.0); // Başlangıç: Görünmez
    animation2->setEndValue(1.0);   // Bitiş: Görünür
    animation2->setEasingCurve(QEasingCurve::InOutQuad); // Yumuşak geçiş

    QPropertyAnimation *animation3 = new QPropertyAnimation(effect3, "opacity");
    animation3->setDuration(2100); // 2100ms sürede değişim
    animation3->setStartValue(0.0); // Başlangıç: Görünmez
    animation3->setEndValue(1.0);   // Bitiş: Görünür
    animation3->setEasingCurve(QEasingCurve::InOutQuad); // Yumuşak geçiş

    // Animasyonu başlat
    animation->start(QPropertyAnimation::DeleteWhenStopped);
    animation2->start(QPropertyAnimation::DeleteWhenStopped);
    animation3->start(QPropertyAnimation::DeleteWhenStopped);

}

//Sonraki arkaplanı ayarlar
void MainWindow::changeToNextWallpaper() {
    if (wallpaperPaths.isEmpty()) return;
    currentWallpaperIndex = (currentWallpaperIndex + 1) % wallpaperPaths.size();
    setWallpaper(wallpaperPaths[currentWallpaperIndex]);
    if (!countdownTimer->isActive()) {
        remainingTime = 30;
        int minutes = remainingTime / 60;
        int seconds = remainingTime % 60;
        ui->label->setText(QString("Sonraki değişime kalan süre : %1.%2 ").arg(minutes, 2, 10, QChar('0')).arg(seconds, 2, 10, QChar('0')));
    }
}

//Önceki arkaplanı ayarlar
void MainWindow::changeToPreviousWallpaper() {
    if (wallpaperPaths.isEmpty()) return;

    if (currentWallpaperIndex == 0) {
        currentWallpaperIndex = wallpaperPaths.size() - 1; // Dizinin sonuna git
    } else {
        currentWallpaperIndex--; // Bir önceki resme git
    }
    setWallpaper(wallpaperPaths[currentWallpaperIndex]);
}

//Geri sayımı günceller
void MainWindow::updateWallpaperTimer() {
    if (!countdownTimer->isActive()) { // Eğer manuel geri sayım aktif DEĞİLSE
        remainingTime--;
        int minutes = remainingTime / 60;
        int seconds = remainingTime % 60;
        ui->label->setText(QString("Sonraki değişime kalan süre : %1.%2 ").arg(minutes, 2, 10, QChar('0')).arg(seconds, 2, 10, QChar('0')));
        if (remainingTime <= 0) {
            changeToNextWallpaper();
            remainingTime = 30; // Sadece manuel geri sayım aktif değilse varsayılanı ayarla
        }
    }
}

//Çıkış tuşu ile çıkar
void MainWindow::exitBtn(){
    QApplication::quit();
}

void MainWindow::startCountdown()
{
    qDebug() << "startCountdown() fonksiyonu çağrıldı.";
    QTime time = ui->timeEdit->time();
    qDebug() << "Alınan dakika:" << time.minute();
    qDebug() << "Alınan saniye:" << time.second();
    remainingTime = time.minute() * 60 + time.second();
    qDebug() << "Toplam saniye:" << remainingTime;
    int minutes = remainingTime / 60;
    int seconds = remainingTime % 60;
    ui->label->setText(QString("Sonraki değişime kalan süre : %1.%2 ").arg(minutes, 2, 10, QChar('0')).arg(seconds, 2, 10, QChar('0')));
    countdownTimer->start(1000);
    timer->stop(); // Otomatik geçiş timer'ını durdur
}


void MainWindow::updateRemainingTime()
{
    if (remainingTime > 0) {
        remainingTime--;
        int minutes = remainingTime / 60;
        int seconds = remainingTime % 60;
        ui->label->setText(QString("Sonraki değişime kalan süre : %1.%2 ").arg(minutes, 2, 10, QChar('0')).arg(seconds, 2, 10, QChar('0')));
    } else {
        countdownTimer->stop();
        ui->label->setText("Süre doldu!");
        changeToNextWallpaper(); // Süre dolunca duvar kağıdını değiştir
        timer->start(30000); // Otomatik geçiş timer'ını tekrar başlat (isteğe bağlı süre)
    }
}









