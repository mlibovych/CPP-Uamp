#pragma once

#include <QSqlDatabase>
#include <QSqlQuery>
#include <QtWidgets>

#include <string>
#include <cstdio>
#include <deque>
#include <list>
#include <fstream>
#include <regex>

#include "component.h"
#include "mediator.h"
#include "tags.h"
#include "playlist.h"

class Component;
class Mediator;

class LibraryManager : public QObject, public Component {
    Q_OBJECT

    QLineEdit *m_ptxtMask = new QLineEdit("*.mp3 *.flac *.wav *.mp4");

    int processSong(const QString& path);
    bool saveToDb(Tags *tags, int *songId);
    bool savePlaylist(const QString& text);

public:
    LibraryManager(Mediator *mediator);
    ~LibraryManager();

    QLineEdit * getMask() const;
    std::deque<Tags *> getUserSongs();
    std::deque<Tags *> getPlaylistSongs(int playlistId);
    void getUserPlaylists();
    void deleteFromLibrary(int songId);
    void deleteFromPlaylist(int playlistId, int songId);

public slots:
    void createPlaylist(const QString& text);
    void addSongsToLibrary(const QString& path, bool recursive);
    void addSongToPlaylist(int playlistId, int songId);
    void deletePlaylist(int id);
    void importPlaylist(QString path);

signals:
    void addSongToTreeView(Tags *tags);
    void addPlaylist(Playlist *playlist);
};