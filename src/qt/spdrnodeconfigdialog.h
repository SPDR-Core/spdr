#ifndef SPDRNODECONFIGDIALOG_H
#define SPDRNODECONFIGDIALOG_H

#include <QDialog>

namespace Ui {
    class SpiderNodeConfigDialog;
}

QT_BEGIN_NAMESPACE
class QModelIndex;
QT_END_NAMESPACE

/** Dialog showing transaction details. */
class SpiderNodeConfigDialog : public QDialog
{
    Q_OBJECT

public:
    explicit SpiderNodeConfigDialog(QWidget *parent = 0, QString nodeAddress = "123.456.789.123:28666", QString privkey="MASTERNODEPRIVKEY");
    ~SpiderNodeConfigDialog();

private:
    Ui::SpiderNodeConfigDialog *ui;
};

#endif // SPDRNODECONFIGDIALOG_H
