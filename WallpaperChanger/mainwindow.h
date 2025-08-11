#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QLabel>
#include <QPushButton>
#include <QTimer>
#include <QDir>
#include <QList>
#include <QString>
#include <windows.h>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow {
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void changeToNextWallpaper(); // Sonraki arkaplanı ayarla
    void changeToPreviousWallpaper(); // Önceki arkaplanı ayarla
    void updateWallpaperTimer(); // Geri sayımı güncelle
    void exitBtn(); // Çıkış tuşu ile çıkar

private:
    Ui::MainWindow *ui;
    QTimer *timer;
    int remainingTime; // Sonraki değişime kalan süre
    QList<QString> wallpaperPaths; // Arkaplan resimlerinin dosya yolu
    int currentWallpaperIndex; // Şu anki gösterilen resmin indexi

    void loadWallpapers(); // Arkaplan resimlerini yükle
    void setWallpaper(const QString &path); // Masaüstü arkaplanını ayarla

    void applySlideAnimation(QLabel *from, QLabel *to, int direction); // **Animasyon fonksiyonu**

private:
    QTimer *countdownTimer;       // Her saniyede çalışan zamanlayıcı
    int remainingSeconds;         // Kalan süreyi saniye cinsinden tutar

private slots:
    void startCountdown();        // Geri sayımı başlatan fonksiyon
    void updateRemainingTime();   // Her saniye çağrılan güncelleme fonksiyonu

};



#endif // MAINWINDOW_H
