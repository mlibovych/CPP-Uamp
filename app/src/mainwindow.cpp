#include "mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
                        QMainWindow(parent)
{
    central_widget = new QWidget(this);
    setCentralWidget(central_widget);
    setGeometry(200, 200, 1800, 1000);

    sidebar_widget = new QWidget(central_widget);
    content_widget = new QWidget(central_widget);


    initToolbar();
    menuBar = new QMenuBar(this);

    layout_outer = new QHBoxLayout(central_widget);
    splitter = new QSplitter(central_widget);
    layout_outer->addWidget(splitter);

    splitter->addWidget(sidebar_widget);
    splitter->addWidget(content_widget);
    splitter->setSizes({150, 700});

}

MainWindow::~MainWindow()
{


}

void MainWindow::initToolbar() {
    toolBar = new QToolBar(this);
    toolBar->setAllowedAreas(Qt::LeftToolBarArea);
    toolBar->setFloatable(false);
    toolBar->setOrientation(Qt::Vertical);
    toolBar->setMovable(false);
    toolBar->addAction("foo");
    toolBar->addAction("bar");
    addToolBar(Qt::LeftToolBarArea, toolBar);
}

void MainWindow::paintEvent(QPaintEvent *)
{
    QStyleOption opt;
    opt.init(this);
    QPainter p(this);
    style()->drawPrimitive(QStyle::PE_Widget, &opt, &p, this);
}