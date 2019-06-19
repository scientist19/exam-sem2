#ifndef FORM_H
#define FORM_H


#include "entity.h"
#include <QWidget>

enum EntityEnum {ListType, BalancedTreeType, HashTableType, SortingType, ContainerType, SetType};

namespace Ui {
class Form;
}

class Form : public QWidget
{
    Q_OBJECT

public:
    explicit Form(EntityEnum entityType, QWidget *parent = nullptr);
    ~Form();

private:
    Ui::Form *ui;
    Entity* entity;
};

#endif // FORM_H
