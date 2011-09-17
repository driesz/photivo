/*******************************************************************************
**
** Photivo
**
** Copyright (C) 2011 Bernd Schoeler <brjohn@brother-john.net>
** Copyright (C) 2011 Michael Munzert <mail@mm-log.com>
**
** This file is part of Photivo.
**
** Photivo is free software: you can redistribute it and/or modify
** it under the terms of the GNU General Public License version 3
** as published by the Free Software Foundation.
**
** Photivo is distributed in the hope that it will be useful,
** but WITHOUT ANY WARRANTY; without even the implied warranty of
** MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
** GNU General Public License for more details.
**
** You should have received a copy of the GNU General Public License
** along with Photivo.  If not, see <http://www.gnu.org/licenses/>.
**
*******************************************************************************/

#ifndef PTFILEMGRTHUMBNAILER_H
#define PTFILEMGRTHUMBNAILER_H

//==============================================================================

#include <QThread>
#include <QQueue>
#include <QGraphicsItem>

//==============================================================================

/*!
  \class ptFileMgrThumbnailer

  \brief Generates image thumbnails in a separate thread.

  This class is used by \c ptFileMgrDM to generate image thumbnails in a separate
  thread. It fills a FIFO buffer with \c QGraphicsItem objects containing the
  thumbnails.
*/
class ptFileMgrThumbnailer: public QThread {
Q_OBJECT

public:
  explicit ptFileMgrThumbnailer();

  /*! Sets the directory for thumbnail generation.
      Actual file system query don’t happen until \c run() is called.
  */
  void setDir(const QString dir);

  /*! Sets the FIFO buffer where the thumbnails are written to.
      Note that the buffer is taken as is, i.e. it is not cleared by the
      thumbnailer.
  */
  void setQueue(QQueue<QGraphicsItem>* queue);


protected:
  /*! This function does the actual thumbnail generating. */
  void run();


private:
  QString m_Dir;
  QQueue<QGraphicsItem>* m_Queue;


signals:
  void newThumbsNotify(const bool isCompleted);


public slots:



};
#endif // PTFILEMGRTHUMBNAILER_H
