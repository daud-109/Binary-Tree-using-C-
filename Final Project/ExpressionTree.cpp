/*Muhammad Daud R01763243 BCS370 - Data Strucutres - 22226 Capstone Porject
* This file has all of the Expression Tree function defination
*/

//include the ExpressionTree file to define the function
#include "ExpressionTree.h"

void ExpressionTree::expressionToTree(char algebraExpression[])
{
	//this will make the root have value so it will no be null
	root = new Node();

	//call the private expression to tree fucntion
	privateExpressionToTree(algebraExpression, root);
}

//Overloaded tree to expression function and it will call the private function
void ExpressionTree::treeToExpression()
{
	//call the private tree to expression function
	privateTreeToExpression(root);
}

//this is the private expression to tree function which takes pointer argument
void ExpressionTree::privateExpressionToTree(char algebraExpression[], Node* currentNode)
{
	//first check if the the node is empty
	if (currentNode != nullptr)
	{
		//if the toke is an open parenthesis
		if (algebraExpression[arraySize] == '(')
		{
			//create a new node to left subtree
			currentNode->leftLink = new Node();

			++arraySize;//increment the size

			//move to the left subtree
			privateExpressionToTree(algebraExpression, currentNode->leftLink);
		}

		//this will check if it is number and also the number have to be
		//between 0 and 9
		if (isNumBetweenZeroAndNine(algebraExpression[arraySize]))
		{
			//Add dat to the left subtree
			currentNode->data = algebraExpression[arraySize];

			//add one to the number of nodes
			numberOfNode++;

			++arraySize; //increment the size

			return; //break out of the function
		}

		//if the token is operator
		if (isOperator(algebraExpression[arraySize]))
		{
			//add the operator to the current node
			currentNode->data = algebraExpression[arraySize];

			//add one to the number of nodes
			numberOfNode++;

			//Create a new node to the right
			currentNode->rightLink = new Node();

			++arraySize;//increment the size

			//move to the new node
			privateExpressionToTree(algebraExpression, currentNode->rightLink);
		}
		
		//if the toke is an close parenthesis
		if (algebraExpression[arraySize] == ')')
		{
			//go to the next element
			++arraySize;

			//check if the array is empty (this is a binary zero or end of array) and it has to be an operator also
			if (algebraExpression[arraySize] != 0 && isOperator(algebraExpression[arraySize]))
			{
				//check if root has an operator 
				if (isOperator(root->data))
				{
					//Make sure current point to the root, the first recursion might have 
					//current pionting to the root but after that it will not point to the root
					currentNode = root;

					//add a new root node with the data as an operator
					root = new Node(algebraExpression[arraySize]);

					//add one to the number of nodes
					numberOfNode++;

					//make the left subtree point to the current node
					root->leftLink = currentNode;

					//Make the current node point to the new root node
					currentNode = root;

					//make the array move to the next element
					++arraySize;

					//now have the current node move to the right subtree
					currentNode->rightLink = new Node();

					//Do recursion for the right subtree
					privateExpressionToTree(algebraExpression, currentNode->rightLink);
				}
			}
		}
	}
}

//This is the private tree to expression fucntion which takes pointer as an argument
void ExpressionTree::privateTreeToExpression(Node* currentNode)
{
	//check if current node is not empty
	if (currentNode != nullptr)
	{
		//check if the data is an operator
		//and print open parenthesis
		if (isOperator(currentNode->data))
		{
			std::cout << "(";
		}

		//go to the left node
		privateTreeToExpression(currentNode->leftLink);

		//print the data
		std::cout << currentNode->data;

		//go to the right node
		privateTreeToExpression(currentNode->rightLink);


		//check if the data is an operator
		//and print close parenthesis
		if (isOperator(currentNode->data))
		{
			std::cout << ")";
		}
	} //end of the beinging if
}

//check if the charater is an operator
bool ExpressionTree::isOperator(char c)
{
	return (c == '+' || c == '-' || c == '*' || c == '/');
}

//check if the the charater is an 
bool ExpressionTree::isNumBetweenZeroAndNine(char num)
{
	return (num >= '0' && num <= '9');
}
