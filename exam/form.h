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

    void displayEntity();

public slots:
    void slotParseConsole();
    void slotAddToEntity();

private:
    Ui::Form *ui;
    Entity* entity;

    void init();
};

#endif // FORM_H
