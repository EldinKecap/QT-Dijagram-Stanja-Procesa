#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QPainter>
#include <QTimer>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
    , m_circleDiameter(200)
    , m_drawCircle(false)
{
    ui->setupUi(this);

    connect(ui->pushButton, &QPushButton::clicked, this, &MainWindow::startAnimation);

    m_timer.setInterval(20);
    connect(&m_timer, &QTimer::timeout, this, &MainWindow::animateCircle);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::paintEvent(QPaintEvent *)
{
    QPainter painter(this);
    painter.setRenderHint(QPainter::Antialiasing);

    if (m_drawCircle) {
        painter.setBrush(Qt::red);
        int x = (width() - m_circleDiameter) / 2;
        int y = (height() - m_circleDiameter) / 2;
        painter.drawEllipse(x, y, m_circleDiameter, m_circleDiameter);
    }
}

void MainWindow::startAnimation()
{
    m_drawCircle = true;
    m_timer.start();
}

void MainWindow::animateCircle()
{
    m_circleDiameter -= 5;
    if (m_circleDiameter <= 0) {
        m_timer.stop();
        m_circleDiameter = 0;
    }
    update();
}

int MainWindow::circleDiameter() const
{
    return m_circleDiameter;
}
