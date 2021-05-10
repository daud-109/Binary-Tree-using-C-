/*Muhammad Daud R01763243 BCS370 - Data Strucutres - 22226 Capstone Porject
* This file has Expression Tree class.

* Expression Tree class:
* This class will inherit form the Binary Tree, and it will
* have all of the function declartion and variable declaration 
* in this file.
*/

#ifndef EXPRESSIONTREE_H
#define EXPRESSIONTREE_H

//include the BinaryTree file to have access 
//to the class member function and varaible
#include "BinaryTree.h"

//this will inherit from Binary class
class ExpressionTree : public BinaryTree{

private:
	int arraySize;

	//This function will create a take in algebraExpression and turn into the tree
	void privateExpressionToTree(char algebraExpression[], Node* currentNode);

	void privateTreeToExpression(Node* currentNode);

public:

	//default construct
	ExpressionTree()
	{
		arraySize = 0;
	}

	~ExpressionTree()
	{
		arraySize = 0;
	}

	//Expression to tree function and it will call the private function
	void expressionToTree(char algebraExpression[]);

	//Tree to expression function and it will call the private function
	void treeToExpression();

	//check if the charater is an operator
	bool isOperator(char c);

	//check if the the charater is an 
	bool isNumBetweenZeroAndNine(char num);

	//may be add function that will make a new node
	//only if the root node is full and we need to add something 
	//to the new node
	void addNewRootNode();
};

#endif // EXPRESSIONTREE_H