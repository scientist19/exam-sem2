#include "official.h"

Official::Official(QString min, QString org, QString div, QString emp) :
    ministry(min),
    organization(org),
    division(div),
    employee(emp)
{

}

bool operator==(const Official &p1, const Official &p2)
{
    return (p1.division == p2.division &&
            p1.ministry == p2.ministry &&
            p1.organization == p2.organization &&
            p1.employee == p2.employee);
}

bool operator!=(const Official &p1, const Official &p2)
{
    return !(p1 == p2);
}

bool operator>(const Official &p1, const Official &p2)
{
    if (p1.ministry > p2.ministry) return true;
    if (p1.ministry < p2.ministry) return false;

    if (p1.organization > p2.organization) return true;
    if (p1.organization < p2.organization) return false;

    if (p1.division > p2.division) return true;
    if (p1.division < p2.division) return false;

    if (p1.employee > p2.employee) return true;
    if (p1.employee < p2.employee) return false;

    return false;
}

bool operator<(const Official &p1, const Official &p2)
{
    return  !(p1 > p2 || p1 == p2);
}

bool operator>=(const Official &p1, const Official &p2)
{
    return (p1 > p2 || p1 == p2);
}

bool operator<=(const Official &p1, const Official &p2)
{
    return  (p1 < p2 || p1 == p2);
}

