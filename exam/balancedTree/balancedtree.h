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
    virtual void clear() = 0;
    virtual QString help() = 0;
};

#endif // BALANCEDTREE_H
