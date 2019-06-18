#ifndef ENTITY_H
#define ENTITY_H

#include <QString>

class Entity
{
public:
    Entity();

    virtual QString print() = 0;
    virtual void fillWithRandom(int l, int r) = 0;
    virtual void clear() = 0;
    virtual QString help() = 0;
    virtual QString parse(QString command) = 0;
};

#endif // ENTITY_H
