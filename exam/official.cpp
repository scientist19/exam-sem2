#include "official.h"

QStringList Official::Ministries = {
    "Minitrue",
    "Minipax",
    "Miniplenty",
    "Miniluv"
};

QStringList Official::Organizations = {
    "Radiant",
    "Dire"
};

QStringList Official::Divisions = {
    "Div1",
    "Div2",
    "Div3",
    "Div4"
};

QStringList Official::Employees = {
    "Ivanov",
    "Petrov",
    "Smith",
    "Johnson",
    "Williams",
    "Jones",
    "Brown",
    "Davis",
    "Miller",
    "Wilson",
    "Moore",
    "Taylor",
    "Anderson",
    "Thomas",
    "Jackson",
    "Harris",
    "Martin",
    "Thompson",
    "Garcia",
    "Martinez",
    "Robinson",
    "Clark",
    "Rodriguez",
    "Lewis",
    "Lee",
    "Walker"
};

Official::Official(QString min, QString org, QString div, QString emp) :
    ministry(min),
    organization(org),
    division(div),
    employee(emp)
{

}

Official::Official()
{
    ministry = getRandomMinistry();
    organization = getRandomOrganization();
    division = getRandomDivision();
    employee = getRandomEmployee();
}

QString Official::printSurname()
{
    return employee + " [" + ministry + ", " + organization + ", " + division + "]";
}

QString Official::printInfo()
{
    return "[" + ministry + ", " + organization + ", " + division + ", " + employee + "]";
}

QString Official::getKey()
{
    return employee;
}

QString Official::getRandomMinistry()
{
    return Ministries[rand() % Ministries.length()];
}

QString Official::getRandomOrganization()
{
    return Organizations[rand() % Organizations.length()];
}

QString Official::getRandomDivision()
{
    return Divisions[rand() % Divisions.length()];
}

QString Official::getRandomEmployee()
{
    return Employees[rand() % Employees.length()];
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

