#ifndef BALANCEDTREE_H
#define BALANCEDTREE_H

#include "../entity.h"

template <typename Tkey, typename Tdata>
class BalancedTree : public Entity
{
public:
    BalancedTree();

    virtual void insert(Tkey key, Tdata data) = 0;
    virtual Tdata* find(Tkey key) = 0;

    QString print() override;
    void add(Official official) override;
    void fillWithRandom(int n) override;
    QString parse(QString command) override;
    void clear() override;
    QString help() override;
};

#endif // BALANCEDTREE_H
