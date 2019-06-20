#ifndef OFFICIAL_H
#define OFFICIAL_H

#include <QString>
#include <QVector>

class Official{

    public:
        Official(QString min, QString org, QString div, QString emp);
        Official();

    public:
        QString ministry;
        QString organization;
        QString division;
        QString employee;

        QString printSurname();
        QString printInfo();
        QString getKey();

    friend bool operator== (const Official &p1, const Official &p2);
    friend bool operator!= (const Official &p1, const Official &p2);
    friend bool operator> (const Official &p1, const Official &p2);
    friend bool operator< (const Official &p1, const Official &p2);
    friend bool operator>= (const Official &p1, const Official &p2);
    friend bool operator<= (const Official &p1, const Official &p2);

    static QStringList Ministries;
    static QStringList Organizations;
    static QStringList Divisions;
    static QStringList Employees;

    static QString getRandomMinistry();
    static QString getRandomOrganization();
    static QString getRandomDivision();
    static QString getRandomEmployee();
};

#endif // OFFICIAL_H
