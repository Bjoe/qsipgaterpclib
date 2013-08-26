#ifndef QSIPGATERPCLIB_SAMURAIUSERDATAGREETINGGETRESPONSE_H
#define QSIPGATERPCLIB_SAMURAIUSERDATAGREETINGGETRESPONSE_H

#include <QString>
#include <QVariant>

namespace qsipgaterpclib {

class SamuraiUserdataGreetingGetResponse
{
public:
    SamuraiUserdataGreetingGetResponse(const QVariant &aGender, const QVariant &aFirstName, const QVariant &aLastName);

    QString getGender() const
    {
        return gender;
    }

    QString getFirstName() const
    {
        return firstName;
    }

    QString getLastName() const
    {
        return lastName;
    }

private:
    QString gender;
    QString firstName;
    QString lastName;
};

} // namespace qsipgaterpclib

#endif // QSIPGATERPCLIB_SAMURAIUSERDATAGREETINGGETRESPONSE_H
