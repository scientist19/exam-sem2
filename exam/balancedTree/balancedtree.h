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

    virtual QString print() override;
    virtual void fillWithRandom(int l, int r) = 0;
    virtual QString parse(QString command) override;
    virtual void clear() override;
    virtual QString help() override;
};

#endif // BALANCEDTREE_H
