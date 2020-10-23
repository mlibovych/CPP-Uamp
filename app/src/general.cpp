#include "general.h"

GeneralScreen::GeneralScreen(Mediator *mediator, QWidget *parent) :
                        QWidget(parent), Component(mediator)
{
    player = new QPlayer(this);
    menuBar = new QMenuBar(this);
    content_widget = new QWidget(this);
    layout_outer = new QVBoxLayout(this);

    layout_outer->addWidget(player);
    layout_outer->addWidget(content_widget);

    layout_inner = new QHBoxLayout(content_widget);
    splitter = new QSplitter;
    layout_inner->addWidget(splitter);

    sidebar_widget = new QSideBar(content_widget);
    sidebar_widget->setObjectName("sidebar");
    view_songs = new QTableView(content_widget);

    splitter->addWidget(sidebar_widget);
    splitter->addWidget(view_songs);
    splitter->setSizes({150, 700});
}

GeneralScreen::~GeneralScreen()
{

}