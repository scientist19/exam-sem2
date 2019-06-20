#ifndef ENTITY_H
#define ENTITY_H

#include "official.h"
#include <QString>

class Entity
{
public:
    Entity();

    virtual QString print() = 0;
    virtual void add(Official* official) = 0;
    virtual QString help() = 0;
    virtual QString parse(QString command) = 0;
};

#endif // ENTITY_H
