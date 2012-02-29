/****************************************************************************
** This file is part of Sync-my-L2P.
**
** Sync-my-L2P is free software: you can redistribute it and/or modify
** it under the terms of the GNU Lesser General Public License as published by
** the Free Software Foundation, either version 3 of the License, or
** (at your option) any later version.
**
** Sync-my-L2P is distributed in the hope that it will be useful,
** but WITHOUT ANY WARRANTY; without even the implied warranty of
** MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
** GNU Lesser General Public License for more details.
**
** You should have received a copy of the GNU Lesser General Public License
** along with Sync-my-L2P.  If not, see <http://www.gnu.org/licenses/>.
****************************************************************************/

#ifndef DATEIDOWNLOADER_H
#define DATEIDOWNLOADER_H

#include <QDialog>
#include <QNetworkAccessManager>
#include <QNetworkRequest>
#include <QNetworkReply>
#include <QUrl>
#include <QAuthenticator>
#include <QTimer>
#include <QEventLoop>
#include <QStringBuilder>
#include <QFile>
#include <QMessageBox>
#include <QCloseEvent>

namespace Ui {
    class DateiDownloader;
}

class DateiDownloader : public QDialog
{
    Q_OBJECT

public:
    explicit DateiDownloader(QString username,
                             QString password,
                             int itemNumber,
                             QWidget *parent= 0);
    ~DateiDownloader();
    int startNextDownload(QString, QString, QString, QUrl, int);

private:
    void keyPressEvent(QKeyEvent *);
    Ui::DateiDownloader *ui;
    QNetworkAccessManager* manager;
    QNetworkReply* reply;

    QEventLoop loop;

    QString username;
    QString password;

    int itemNumber;

    QFile output;

private slots:
    void authenticate(QNetworkReply*, QAuthenticator*);
    void downloadProgressSlot(qint64,qint64);
    void readyReadSlot();
    void finishedSlot();
};

#endif // DATEIDOWNLOADER_H
