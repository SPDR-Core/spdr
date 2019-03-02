#ifndef QTSPDRUPDATER_UPDATEINFODIALOG_H
#define QTSPDRUPDATER_UPDATEINFODIALOG_H

#include "spdrupdater/spdrupdater.h"

#include <QDialog>

namespace Ui {
class UpdateInfoDialog;
}

namespace QtSpiderUpdater
{

class UpdateInfoDialog : public QDialog
{
	Q_OBJECT

public:
	enum DialogResult {
		InstallNow = QDialog::Accepted,
		InstallLater = QDialog::Accepted + 1,
		NoInstall = QDialog::Rejected
	};
	Q_ENUM(DialogResult)

	static DialogResult showUpdateInfo(QList<SpiderUpdater::SpiderUpdateInfo> updates,
									   bool &runAsAdmin,
									   bool editable,
									   bool detailed,
									   QWidget *parent);

private Q_SLOTS:
	void on_acceptButton_clicked();
	void on_delayButton_clicked();

private:
	QScopedPointer<Ui::UpdateInfoDialog> ui;

	explicit UpdateInfoDialog(QWidget *parent = nullptr);
	~UpdateInfoDialog();

	static QString getByteText(qint64 bytes);
};

}

#endif // QTSPDRUPDATER_UPDATEINFODIALOG_H
