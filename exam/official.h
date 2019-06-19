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

    const QVector<QString> Ministries = {
        "Minitrue",
        "Minipax",
        "Miniplenty",
        "Miniluv"
    };

    const QVector<QString> Organizations = {
        "Radiant",
        "Dire"
    };

    const QVector<QString> Divisions = {
        "Div1",
        "Div2",
        "Div3",
        "Div4"
    };

    const QVector<QString> Employees = {
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
};

#endif // OFFICIAL_H
