#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDebug>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    //ui->groupBox->setVisible(true);
    // Изначально показываем только верхнюю группу элементов
    ui->G_6_1->setVisible(true);
    // Нижняя группа элементов изначально скрыта
    ui->G_6_2->setVisible(false);

    ui->G_6_3->setVisible(false);
    // Подключаем кнопку "Старт" к слоту переключения группы элементов
    //connect(ui->pushButton, &QPushButton::clicked, this, &MainWindow::switchToLowerGroup);
    connect(ui->pushButton, &QPushButton::clicked, this, &MainWindow::startElementSwitchTimer);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::startElementSwitchTimer()
{
    qDebug() << "Таймер запущен, смена произойдет через 3 секунды";

    // Создаем таймер, который отсрочит выполнение слота switchElements на 3 секунды
    QTimer::singleShot(3000, this, &MainWindow::switchElements);
}

void MainWindow::switchElements()
{
    //qDebug() << "Слот switchElements вызван, скрываем верхнюю группу и показываем нижнюю";

    // Скрываем верхнюю группу элементов
    ui->G_6_1->setVisible(false);

    // Показываем нижнюю группу элементов
    ui->G_6_2->setVisible(true);
}
