// I started using ifndef instead of pragma once because of the info in the link I sent you
// And you should do so too
// Don't fuck with me about it
// In return, I promise all new variables that I create will be in camelcase

// xoxo Yulia

#ifndef QUEUE_WIDGET
#define QUEUE_WIDGET

#include <QtWidgets>
#include <string>

#include "queue.h"
#include "component.h"

class Component;
class Queue;

class Element : public QListWidgetItem {
    QWidget *widget;

    QHBoxLayout *layoutOuter;
    QVBoxLayout *layoutInner;

    QLabel *labelAlbumCover;
    QLabel *labelTitle;
    QLabel *labelArtist;

    std::string path;

public:
    Element(const Tags &tags);
    ~Element();

    QWidget *getWidget(void) const;
    std::string getPath(void) const;
};


class QueueWidget : public QListWidget, public Component {
    Queue queue;

public:
    QueueWidget(Mediator *mediator, QWidget *parent = nullptr);
};

#endif