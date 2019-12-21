#ifndef BS_TREE_NODE_H_INCLUDED
#define BS_TREE_NODE_H_INCLUDED

template<class T>
struct BSTreeNode {
	T key;

	int correlativo=1;
	int id;

	BSTreeNode<T>* left;
	BSTreeNode<T>* right;
	BSTreeNode<T>* parent;


	   BSTreeNode()
         {

             this->id = correlativo++;
         }



};

#endif // BS_TREE_NODE_H_INCLUDED
