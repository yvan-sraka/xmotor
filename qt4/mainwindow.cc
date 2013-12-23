#include "mainwindow.hh"

#include <QtWebKit/QWebView>
#include <QDir>

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent)
{
    this->title = "";
    this->icon = "";
    this->url = "";
    this->width = 0;
    this->height = 0;
    this->mode = "";

    QWidget *xmotor = new QWidget();
    QWebView *xmotorWebView = new QWebView(xmotor);

    QWebSettings::globalSettings()->setAttribute(QWebSettings::PluginsEnabled, true);
    QWebSettings::globalSettings()->setAttribute(QWebSettings::JavascriptEnabled, true);

    xmotor->setWindowTitle(this->title);
    xmotor->setWindowIcon(QIcon(QDir::currentPath() + this->icon));

    if (this->mode == "tool")
        xmotor->setWindowFlags(Qt::Tool);

    if (this->url == "localhost")
        xmotorWebView->load(QUrl(QDir::currentPath()));
    else
        xmotorWebView->load(QUrl(url));

    xmotor->setFixedSize(this->width, this->height);
    xmotorWebView->setGeometry(0, 0, this->width, this->height);

    setCentralWidget(xmotor);
}

MainWindow::~MainWindow()
{

}
