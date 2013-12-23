#ifndef MAINWINDOW_HH
# define MAINWINDOW_HH

#include <QtGui/QMainWindow>

class MainWindow : public QMainWindow
{
    Q_OBJECT

    public:
        MainWindow(QWidget *parent = 0);
        ~MainWindow();

    private:
        QString title;
        QString icon;
        QString url;
        int width;
        int height;
        QString mode;
};

#endif /* !MAINWINDOW_HH */
