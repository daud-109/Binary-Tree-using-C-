/*Muhammad Daud R01763243 BCS370 - Data Strucutres - 22226 Capstone Porject 
* This file have all the function defination of the class BinaryTree.
* 
* 
* ******	Make sure to debugg and add new functionality at the end	*****
*/
#include "BinaryTree.h"

//defaul construct
BinaryTree::BinaryTree()
{
	root = nullptr;
	numberOfNode = 0;
}

//destructor need to call deleteTree function
BinaryTree::~BinaryTree()
{
	numberOfNode = 0;
	//if (root != nullptr)
	//{
	//	//deleteTree(root); //this will delete the tree
	//	numberOfNode = 0;
	//	//put cout 
	//	//test this out
	//	delete root;
	//	root = nullptr;
	//}
}

//This fucntion will check if the tree is emptry
bool BinaryTree::isEmpty() const
{
	return (root == nullptr); //return flase if emtpy
}

//This function will only print the binary tree in 
//the inorder formate.
void BinaryTree::inorder(Node* p) const
{
	if (p != nullptr) //if p is null break out of the recursion
	{
		inorder(p->leftLink); //go to left subtree first
		std::cout << p->data << " "; //print 
		inorder(p->rightLink); //then go to the right subtree
	}
}

//This function is similar to post order travers but only 
//different is that it delete each node of the tree.
//void BinaryTree::deleteTree(Node* p) //this function I got from the book
//{
//	if (p != nullptr)
//	{
//		deleteTree(p->leftLink); //these line make sure that node point
//		deleteTree(p->rightLink); //to left and right subtree are empty 
//		p->data = 0; //make the data null
//		delete p; //then delete the node
//		p = nullptr; //make it null
//	}
//}

//return the number of node
void BinaryTree::totalNode() const
{
	std::cout << "The total number of node is " << numberOfNode << std::endl;
}