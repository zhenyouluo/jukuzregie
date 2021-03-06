#include "videoappsrc.h"

VideoAppSrc::VideoAppSrc(QObject *parent) :
    QObject(parent)
{
}

void VideoAppSrc::needData(uint length)
{
    Q_UNUSED(length);

    //qDebug() << "VideoAppSrc NEED DATA. Length:" << length;

    if (!buffer.isNull())
    {
        buffer.clear();
    }
    buffer = QGst::Buffer::create(640*360*4);
    buffer->map(mapInfo, QGst::MapWrite);

    emit sigNeedData(buffer->size(), (char*)mapInfo.data());
}

void VideoAppSrc::enoughData()
{
    //qDebug() << "VideoAppSrc ENOUGH DATA";
}

void VideoAppSrc::pushVideoBuffer()
{
    if (buffer.isNull())
    {
        return;
    }

    buffer->unmap(mapInfo);

    //qDebug() << "VideoAppSrc PUSHBUFFER Length:" << buffer->size();
    pushBuffer(buffer);
}
