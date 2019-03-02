#ifndef ADDEDITSPDRNODE_H
#define ADDEDITSPDRNODE_H

#include <QDialog>

namespace Ui {
class AddEditSpiderNode;
}


class AddEditSpiderNode : public QDialog
{
    Q_OBJECT

public:
    explicit AddEditSpiderNode(QWidget *parent = 0);
    ~AddEditSpiderNode();

protected:

private Q_SLOTS:
    void on_okButton_clicked();
    void on_cancelButton_clicked();

signals:

private:
    Ui::AddEditSpiderNode *ui;
};

#endif // ADDEDITSPDRNODE_H
