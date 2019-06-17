#ifndef OFFICIAL_H
#define OFFICIAL_H

#include <QString>

class Official{

    public:
        Official(QString min, QString org, QString div, QString emp);

    public:
        QString ministry;
        QString organization;
        QString division;
        QString employee;

    friend bool operator== (const Official &p1, const Official &p2);
    friend bool operator!= (const Official &p1, const Official &p2);
    friend bool operator> (const Official &p1, const Official &p2);
    friend bool operator< (const Official &p1, const Official &p2);
    friend bool operator>= (const Official &p1, const Official &p2);
    friend bool operator<= (const Official &p1, const Official &p2);
};

#endif // OFFICIAL_H
