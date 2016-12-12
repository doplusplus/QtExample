#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QRect>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    void updateColorCode();

public slots:
    void draw(int R, int G, int B);

    void onRedChanged(int r);
    void onBlueChanged(int r);
    void onGreenChanged(int r);

protected:
    void paintEvent(QPaintEvent *event) Q_DECL_OVERRIDE;

private:
    Ui::MainWindow *ui;
    QRect toDisplay;
};

#endif // MAINWINDOW_H
