#ifndef SPLAYTREE_H
#define SPLAYTREE_H

#include "Node.h"
#include "entity.h"
#include "../../official.h"

template <typename Tkey, typename Tdata>
class SplayTree : public Entity
{
	public:
		SplayTree();
		virtual ~SplayTree();

        void insert(const Tkey& key, Tdata* data);
		void remove(const Tkey& key);
        Tdata* find(const Tkey& key);

        QString print() override;
        QString print(Node<Tkey, Tdata>* node, int deep);
        QString printTab(int k);

        QString parse(QString command) override;
        void add(Official* official) override;
        QString help() override;

	private:

		Node<Tkey, Tdata>* root = nullptr;

		Node<Tkey, Tdata>* find_(const Tkey& key);
		Node<Tkey, Tdata>* successor(Node<Tkey, Tdata>* node);
		Node<Tkey, Tdata>* predecessor(Node<Tkey, Tdata>* node);
		void replace(Node<Tkey, Tdata>* localParent, Node<Tkey, Tdata>* localChild);
		Node<Tkey, Tdata>* minimum(Node<Tkey, Tdata>* node);
		Node<Tkey, Tdata>* maximum(Node<Tkey, Tdata>* node);
		void leftRotate(Node<Tkey, Tdata>* n);
		void rightRotate(Node<Tkey, Tdata>* n);
		void splay(Node<Tkey, Tdata>* node);
};

#endif // SPLAYTREE_H
