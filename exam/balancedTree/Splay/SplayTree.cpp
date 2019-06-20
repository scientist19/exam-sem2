#include "SplayTree.h"

#include <iostream>

template <typename Tkey, typename Tdata>
SplayTree<Tkey, Tdata>::SplayTree()
{
	//ctor
}

template <typename Tkey, typename Tdata>
SplayTree<Tkey, Tdata>::~SplayTree()
{
	delete root;
}

template <typename Tkey, typename Tdata>
Node<Tkey, Tdata>* SplayTree<Tkey, Tdata>::successor(Node<Tkey, Tdata>* node){
	Node<Tkey, Tdata>* resultNode = node;

	if (resultNode->right != nullptr) resultNode = minimum(resultNode->right);
	else {
		while (resultNode != root || resultNode != resultNode->parent->left) {
                resultNode = resultNode->parent;
		}
	}
	return resultNode;
}

template <typename Tkey, typename Tdata>
Node<Tkey, Tdata>* SplayTree<Tkey, Tdata>::predecessor(Node<Tkey, Tdata>* node){
	Node<Tkey, Tdata>* resultNode = node;

	if (resultNode->left != nullptr) resultNode = maximum(resultNode->left);
	else {
		while (resultNode != root || resultNode != resultNode->parent->right) {
			resultNode = resultNode->parent;
		}
	}
	return resultNode;
}

template <typename Tkey, typename Tdata>
Node<Tkey, Tdata>* SplayTree<Tkey, Tdata>::minimum(Node<Tkey, Tdata>* node) {

//	std::cout << "BEGIN  minimum\n";
	Node<Tkey, Tdata>* minNode = node;

	while (minNode->left != nullptr)
		minNode = minNode->left;

//	std::cout << "END  minimum\n";
	return minNode;
}

template <typename Tkey, typename Tdata>
Node<Tkey, Tdata>* SplayTree<Tkey, Tdata>::maximum(Node<Tkey, Tdata>* node) {
	Node<Tkey, Tdata>* maxNode = node;

	while (maxNode->right != nullptr)
		maxNode = maxNode->right;

	return maxNode;
}

template <typename Tkey, typename Tdata>
Node<Tkey, Tdata>* SplayTree<Tkey, Tdata>::find_(const Tkey & key) {

	Node<Tkey, Tdata>* searchedElement = root;

	while (searchedElement != nullptr) {
		if (searchedElement->key < key) searchedElement = searchedElement->right;
		else if (key < searchedElement->key) searchedElement = searchedElement->left;
		else {
			splay(searchedElement);
			return searchedElement;
		}
	}

	return nullptr;
}

template <typename Tkey, typename Tdata>
void SplayTree<Tkey, Tdata>::leftRotate(Node<Tkey, Tdata>* node) {

	Node<Tkey, Tdata>* rightChild = node->right;

	node->right = rightChild->left;
	if (rightChild->left != nullptr)
		rightChild->left->parent = node;

	replace(node, rightChild);

	rightChild->left = node;
	rightChild->left->parent = rightChild;
}

template <typename Tkey, typename Tdata>
void SplayTree<Tkey, Tdata>::rightRotate(Node<Tkey, Tdata>* node) {

//	std::cout << "BEGIN rightRotate\n";
	Node<Tkey, Tdata>* leftChild = node->left;

	node->left = leftChild->right;
	if (leftChild->right != nullptr) leftChild->right->parent = node;

	replace(node, leftChild);

	leftChild->right = node;
	leftChild->right->parent = leftChild;

//	std::cout << "END rightRotate\n";
}

template <typename Tkey, typename Tdata>
void SplayTree<Tkey, Tdata>::replace(Node<Tkey, Tdata>* localParent, Node<Tkey, Tdata>* localChild) {

//	std::cout << "BEGIN replace\n" << localParent->parent << '\n';
	if (localParent->parent == nullptr) root = localChild;
	else if (localParent == localParent->parent->left)
		localParent->parent->left = localChild;
	else if (localParent == localParent->parent->right)
		localParent->parent->right = localChild;

	if (localChild != nullptr) localChild->parent = localParent->parent;
//	std::cout << "END replace\n";
}

template <typename Tkey, typename Tdata>
void SplayTree<Tkey, Tdata>::splay(Node<Tkey, Tdata>* pivotElement) {

//	std::cout << "BEGIN splay\n";
	while (pivotElement != root) {
		if (pivotElement->parent == root) {

			if (pivotElement == pivotElement->parent->left) rightRotate(pivotElement->parent);
			else leftRotate(pivotElement->parent);
		}

			else {

                // Zig-Zig
                if (pivotElement == pivotElement->parent->left &&
                    pivotElement->parent == pivotElement->parent->parent->left) {

                    rightRotate(pivotElement->parent->parent);
                    rightRotate(pivotElement->parent);

                } else if (pivotElement == pivotElement->parent->right &&
                           pivotElement->parent == pivotElement->parent->parent->right) {

                    leftRotate(pivotElement->parent->parent);
                    leftRotate(pivotElement->parent);
                }

                // Zig-Zag
                else if (pivotElement == pivotElement->parent->right &&
                    pivotElement->parent == pivotElement->parent->parent->left) {

                    leftRotate(pivotElement->parent);
                    rightRotate(pivotElement->parent);

                } else if (pivotElement == pivotElement->parent->left &&
                           pivotElement->parent == pivotElement->parent->parent->right) {

                    rightRotate(pivotElement->parent);
                    leftRotate(pivotElement->parent);
                }
            }

    }

//	std::cout << "END splay\n";
}

template <typename Tkey, typename Tdata>
void SplayTree<Tkey, Tdata>::insert(const Tkey& key, Tdata* data ) {

//	std::cout << "BEGIN insert\n";
	Node<Tkey, Tdata>* preInsertPlace = nullptr;
	Node<Tkey, Tdata>* insertPlace = root;

	while (insertPlace != nullptr) {
		preInsertPlace = insertPlace;

		if (insertPlace->key < key) insertPlace = insertPlace->right;
		else insertPlace = insertPlace->left;
	}

	Node<Tkey, Tdata>* insertElement = new Node<Tkey, Tdata>(key, data);
	insertElement->parent = preInsertPlace;

	if (preInsertPlace == nullptr) root = insertElement;
	else if (preInsertPlace->key < insertElement->key)
		preInsertPlace->right = insertElement;
	else preInsertPlace->left = insertElement;

	splay(insertElement);
//	std::cout << "END insert\n";
}

template <typename Tkey, typename Tdata>
void SplayTree<Tkey, Tdata>::remove(const Tkey& key) {
	Node<Tkey, Tdata>* removeElement = find_(key);

	if (removeElement != nullptr) {
		if (removeElement->right == nullptr) replace(removeElement, removeElement->left);
		else if (removeElement->left == nullptr) replace(removeElement, removeElement->right);
		else {
			Node<Tkey, Tdata>* newLocalRoot = minimum(removeElement->right);

			if (newLocalRoot->parent != removeElement) {

				replace(newLocalRoot, newLocalRoot->right);

				newLocalRoot->right = removeElement->right;
				newLocalRoot->right->parent = newLocalRoot;
			}

			replace(removeElement, newLocalRoot);

			newLocalRoot->left = removeElement->left;
			newLocalRoot->left->parent = newLocalRoot;

			splay(newLocalRoot);
		}

		removeElement->left = nullptr;
		removeElement->right = nullptr;
		delete removeElement;
	}
}

template <typename Tkey, typename Tdata>
Tdata* SplayTree<Tkey, Tdata>::find(const Tkey& key){

	Node<Tkey, Tdata>* node = find_(key);

	if (node) return node->data;
	return nullptr;
}

template <typename Tkey, typename Tdata>
QString SplayTree<Tkey, Tdata>::print(Node<Tkey, Tdata>* node, int deep){

    if (!node) return "";
    QString result = "";

    result += print(node->left, deep+1);

    result += printTab(deep);
    result += node->data->printSurname() + "\n";
//	std::cout << ">" << node->data->surname << "(" << node->data->mean << ")\n";

    result += print(node->right, deep+1);

    return result;
}

template <typename Tkey, typename Tdata>
QString SplayTree<Tkey, Tdata>::print(){

    QString result = "";

    result += "--------------------------------------------------------------------\n";
    result += print(root, 0);
    result += "--------------------------------------------------------------------\n";

    return result;
}

template <typename Tkey, typename Tdata>
QString SplayTree<Tkey, Tdata>::printTab(int k){

    QString result = "";
	for (int i = 0; i < k; i++)
        result += "        ";
    return result;
}

template<typename Tkey, typename Tdata>
QString SplayTree<Tkey, Tdata>::parse(QString command)
{
    QStringList list = command.split(' ', QString::SkipEmptyParts);
    if (list.empty()) return "";
    if (list[0] == "add" && list.length() == 1){
        Official* official = new Official();
        insert(official->getKey(), official);
        return "Official " + official->printSurname() + " is successfully added to the tree.\n";
    }
    else if (list[0] == "add"){
        int n = list[1].toInt();
        QString res = "";
        for (int i = 0; i < n; i++){
            Official* official = new Official();
            insert(official->getKey(), official);
            res += "Official " + official->printSurname() + " is successfully added to the tree.\n";
        }
        return res;
    }
    else if (list[0] == "find" && list.length() > 1){
        QString key = list[1];
        Tdata* result = find(key);
        if (!result) return "There is no official with key " + key + "\n";
        return "Official " + result->printSurname() + " is found.\n";
    }
    else if (list[0] == "re" && list.length() > 1){
        QString key = list[1];
        Tdata* result = find(key);
        if (!result) return "There is no official with key " + key + "\n";
        QString toPrint = result->printSurname();
        remove(key);
        return "Official " + toPrint + " is removed.\n";
    }
    else if (list[0] == "find" || list[0] == "re"){
        return "There are too few arguments. Look at the helpMe section.\n";
    }
    else if (list[0] == "clear"){
        return "Not available yet!\n";
    }

    return "Unknown command. Please look at helpMe.\n";
}

template<typename Tkey, typename Tdata>
void SplayTree<Tkey, Tdata>::add(Official* official)
{
    insert(official->getKey(), official);
}

template<typename Tkey, typename Tdata>
QString SplayTree<Tkey, Tdata>::help()
{
    return QString("add - to add random official\n") +
           "find [employee] - to find official by surname\n" +
           "re [employee] - to remove official by surname\n" +
           "add [number] - to add few random officials\n" +
           "clear - to clear tree\n";
}

template class SplayTree<QString, Official>;
