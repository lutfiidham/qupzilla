/* ============================================================
* QupZilla - WebKit based browser
* Copyright (C) 2010-2011  nowrep
*
* This program is free software: you can redistribute it and/or modify
* it under the terms of the GNU General Public License as published by
* the Free Software Foundation, either version 3 of the License, or
* (at your option) any later version.
*
* This program is distributed in the hope that it will be useful,
* but WITHOUT ANY WARRANTY; without even the implied warranty of
* MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
* GNU General Public License for more details.
*
* You should have received a copy of the GNU General Public License
* along with this program.  If not, see <http://www.gnu.org/licenses/>.
* ============================================================ */
#include "rssnotification.h"
#include "ui_rssnotification.h"
#include "mainapplication.h"
#include "qupzilla.h"

RSSNotification::RSSNotification(QString host, QWidget *parent) :
    Notification(parent),
    ui(new Ui::RSSNotification)
{
    setAttribute(Qt::WA_DeleteOnClose);
    ui->setupUi(this);
    ui->closeButton->setIcon(
#ifdef Q_WS_X11
    style()->standardIcon(QStyle::SP_DialogCloseButton)
#else
    QIcon(":/icons/faenza/close.png")
#endif
    );
    ui->label->setText(tr("You have successfuly added RSS feed \"%1\".").arg(host));

    connect(ui->pushButton, SIGNAL(clicked()), mApp->getWindow(), SLOT(showRSSManager()));
    connect(ui->pushButton, SIGNAL(clicked()), this, SLOT(hide()));
    connect(ui->closeButton, SIGNAL(clicked()), this, SLOT(hide()));
    QTimer::singleShot(1, this, SLOT(startAnimation()));
}

RSSNotification::~RSSNotification()
{
    delete ui;
}
