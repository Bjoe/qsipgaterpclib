#ifndef QSIPGATERPCLIB_SYSTEMMETHODHELPRESPONSE_H
#define QSIPGATERPCLIB_SYSTEMMETHODHELPRESPONSE_H

#include <QString>

namespace qsipgaterpclib {

class SystemMethodHelpResponse
{
public:
    SystemMethodHelpResponse(const QString &aHelpMessage);

    QString getHelp() const;

private:
    QString helpMessage;
};

} // namespace qsipgaterpclib

#endif // QSIPGATERPCLIB_SYSTEMMETHODHELPRESPONSE_H
