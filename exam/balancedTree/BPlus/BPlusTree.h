#ifndef BPLUSTREE_H
#define BPLUSTREE_H

#include "Node.h"
#include "../balancedtree.h"

template <typename Tkey, typename Tdata>
class BPlusTree : public BalancedTree<Tkey, Tdata>
{
	public:
		BPlusTree();
		virtual ~BPlusTree();

        void insert(Tkey key, Tdata* cost) override;
        Tdata* find(Tkey key) override;
        QString print() override;

	private:
		int dimension;
		Node<Tkey, Tdata>* root = nullptr;

		Node<Tkey, Tdata>* getLeaf(Tkey key);
		void split(Node<Tkey, Tdata>* node);
        QString print(int deep, Node<Tkey, Tdata>* node);
};

#endif // BPLUSTREE_H
