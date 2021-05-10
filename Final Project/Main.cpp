/*Muhammad Daud R01763243 BCS370 - Data Strucutres - 22226 Capstone Porject
* Final Project Specifications Expression Tree: Binary Tree and Expression Tree
* 
* Two header file:
*			-BinaryTree.h
*			-ExpressionTree.h
* Two C plus plus file:
*			-BinaryTree.cpp
*			-ExpressionTree.cpp
* 
* In this main.cpp file all of the code will be excuted
*/

//includeing the header file
#include"BinaryTree.h";
#include "ExpressionTree.h";


int main()
{

	//all of the possible value to be test with the algebra expression:

	char algebraicExpression[] = "(2+3)*(1+(5-4))";
	//char algebraicExpression[] = "((2+3)*(1+(5-4)))";
	//char algebraicExpression[] = "((2+3)*(4-5)+(1+(5-4)))";
	//char algebraicExpression[] = "(2+3)*(4+5)+(9-3)/(5*5)";
	//char algebraicExpression[] = "((2+3)*(1-(4-5))+(5-6)*(1*(9/3)))";
	
	//create exression tree class object
	ExpressionTree e;
		
	//make the algebraic expression into a tree
	e.expressionToTree(algebraicExpression);

	//display the tree 
	e.treeToExpression();
	
	std::cout << "\n"; //make it look neat

	//display the number of node
	e.totalNode();
	
//	b.deleteTree(binaryTreeTop);
	//if (binaryTreeTop != nullptr) std::cout << binaryTreeTop->data << std::endl;
	return 0;
}