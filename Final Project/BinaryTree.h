/*Muhammad Daud R01763243 BCS370 - Data Strucutres - 22226 Capstone Porject
* This file has the stuct node and Binary class.
* All of the function declartion and variable declaration 
* for the Binary Tree are in the is file.
* 
* Struct:
* The struct node will help us create a binary expression tree.
* It has one char variable which hold either a opeartro or operand [0-9],
* and the two pointer which will point to the subtree.
*/

#ifndef BINARYTREE_H
#define BINARYTREE_H

#include <iostream>

//This struct will help us create a Binary Tree data structure
struct Node 
{
	//The data will hold Binary operator (+,-,*,/) and Binary Operand (0-9)
	char data;
	Node* leftLink; //Left link to the subtree
	Node* rightLink; //Right link to the subtree

	//struct contruct to add data
	Node(char data = '0')
	{
		this->data = data;
		leftLink = nullptr;
		rightLink = nullptr;
	}

	//Test this out becuase this will delete any of the node
	//of the binary tree that is related to the leftLink and
	//rightLink
	~Node() 
	{
		data = 0;

		delete leftLink;
		delete rightLink;
		
		leftLink = nullptr;
		rightLink = nullptr;
	}
};

//this class will help to create a struct of expression tree
class BinaryTree {

	//make private function which will overload other function 
private:


	//make the variable protected so it can be inherted by sub class
protected:

	//this variable will point to top of the binary tree
	Node* root;
	int numberOfNode;

public:

	//default construct to make pointer null
	BinaryTree();

	//delete the tree
	~BinaryTree();

	//check if tree is empty
	bool isEmpty() const;

	//Use dept-first travers (inorder)
	void inorder(Node* p) const;

	//This function will delete the tree
	void deleteTree(Node* p);

	//print the number of node
	void totalNode() const;

	//add other functionlity here
};

#endif // BINARYTREE_H

