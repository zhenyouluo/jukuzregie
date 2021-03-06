#ifndef VIDEOEFFECTDIALOG_H
#define VIDEOEFFECTDIALOG_H

#include <QDialog>
#include <QList>

#include "mediasourcebase.h"

namespace Ui {
class VideoEffectDialog;
}

class VideoEffectDialog : public QDialog
{
    Q_OBJECT

public:
    explicit VideoEffectDialog(QList<MediaSourceBase*> cams, QWidget *parent = 0);
    ~VideoEffectDialog();

private:
    Ui::VideoEffectDialog *ui;
};

#endif // VIDEOEFFECTDIALOG_H
