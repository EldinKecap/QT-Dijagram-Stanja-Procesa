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
    MainWindow(QWidget *parent = NULL);
    ~MainWindow();

    int circleDiameter() const;

protected:
    void paintEvent(QPaintEvent *) override;

private slots:
    void startAnimation();
    void animateCircle();

private:
    Ui::MainWindow *ui;
    int m_circleDiameter;
    bool m_drawCircle;
    QTimer m_timer;
};

#endif // MAINWINDOW_H
