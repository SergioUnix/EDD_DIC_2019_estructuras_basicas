#ifndef BS_TREE_H_INCLUDED
#define BS_TREE_H_INCLUDED


#include <experimental/optional>
#include "bs_tree_node.h"

template <class T>
class BSTree {
private:
	BSTreeNode<T>* root;

	BSTreeNode<T>* insert_node(BSTreeNode<T>* node, const T& key);
	void traverse_nodes_in_order(BSTreeNode<T>* node);
	BSTreeNode<T>* search_node(BSTreeNode<T>* node, const T& key);

	std::experimental::optional<T> min_node(BSTreeNode<T>* node);
	std::experimental::optional<T> max_node(BSTreeNode<T>* node);


public:



	void insert(const T& key);
	void traverse_in_order();
	bool search(const T& key);
	std::string grafic_codigo();
};

template<class T>
BSTreeNode<T> * BSTree<T>::insert_node(BSTreeNode<T>* node, const T& key) {
	if (node == nullptr)
	{
		node = new BSTreeNode<T>{};
		node->key = key;
		node->left = nullptr;
		node->right = nullptr;
		node->parent = nullptr;
	}
	else if (node->key < key)
	{
		node->right = insert_node(node->right, key);
		node->right->parent = node;
	}
	else
	{
		node->left = insert_node(node->left, key);
		node->left->parent = node;
	}

	return node;
}

template<class T>
void BSTree<T>::insert(const T& key) {
	root = insert_node(root, key);
}

template<class T>
void BSTree<T>::traverse_nodes_in_order(BSTreeNode<T>* node) {
	if (!node) {
		return;
	}

	traverse_nodes_in_order(node->left);
	std::cout << node->key << " ";
	traverse_nodes_in_order(node->right);
}

template<class T>
void BSTree<T>::traverse_in_order() {
	traverse_nodes_in_order(root);
	std::cout << std::endl;
}

template<class T>
BSTreeNode<T>* BSTree<T>::search_node(BSTreeNode<T>* node, const T& key) {
	if (!node) {
		return nullptr;
	}
	else if (node->key == key) {
		return node;
	}
	else if (node->key < key) {
		return search_node(node->right, key);
	}
	else {
		return search_node(node->left, key);
	}
}

template<class T>
bool BSTree<T>::search(const T& key) {
	return search_node(root, key);
}

template<class T>
std::string BSTree<T>::grafic_codigo() {
  BSTreeNode<T>* node=this->root;
    std::string etiqueta;


    if(node->left==0&&node->right==0){
        etiqueta="nodo"+std::to_string(node->id)+"[ label =\""+node->key+"\"]; \n";
    }else{
     etiqueta="nodo"+to_string(node->id)+" [ label =\"<C0>|"+node->key+"|<C1>\"]; \n";
    }
    node->left->id;

        if(node->left!=0){
                etiqueta=etiqueta+ this->grafic_codigo()+"nodo"+to_string(node->id)+":C0->nodo"+to_string(node->left->id)+"\n";

        }
        if(node->right!=0){
              etiqueta =etiqueta + this->grafic_codigo() + "nodo"+to_string(node->id)+":C1->nodo"+to_string(node->right->id)+"\n";

        }
        return etiqueta;
    }







#endif // BS_TREE_H_INCLUDED
