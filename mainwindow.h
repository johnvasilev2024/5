#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QTimer>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

//private slots:
    //void switchToLowerGroup();  // Слот для переключения на нижнюю группу элементов
private slots:
    void startElementSwitchTimer();  // Запуск таймера смены элементов
    void switchElements();           // Слот для смены видимости элементов

private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
