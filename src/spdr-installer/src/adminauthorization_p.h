#ifndef QTSPDRUPDATER_ADMINAUTHORIZATION_P_H
#define QTSPDRUPDATER_ADMINAUTHORIZATION_P_H

#include "spdrupdater/adminauthoriser.h"

namespace QtSpiderUpdater
{

class AdminAuthorization : public AdminAuthoriser
{
public:
	bool hasAdminRights() override;
	bool executeAsAdmin(const QString &program, const QStringList &arguments) override;
};

}

#endif // QTSPDRUPDATER_ADMINAUTHORIZATION_P_H
