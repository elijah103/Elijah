#include <stdio.h>
#include <stdlib.h>
#include "word_key.h"

Status get_word_key_value(MY_STRING current_word_family, MY_STRING new_key,
	MY_STRING word, char guess)
{
	My_string* family = (My_string*)current_word_family;
	My_string* pWord = (My_string*)word;
	guess = tolower(guess);
	if (my_string_get_size(family) != my_string_get_size(pWord))
		return FAILURE;
	for (int i = 0; i < my_string_get_size(pWord); i++) {
		if (guess == tolower(pWord->data[i]))
			my_string_push_back(new_key, guess);
		else
			my_string_push_back(new_key, family->data[i]);
	}
	return SUCCESS;
}

//struct node;
//typedef struct node Node;
//struct node
//{
//	MY_STRING key;
//	Node* left;
//	Node* right;
//	int height;
//	int size;
//	GENERIC_VECTOR word_list;
//};
//
//int height(Node* N)
//{
//	if (N == NULL)
//		return 0;
//	return N->height;
//}
//
//int get_max(int a, int b)
//{
//	return(a > b) ? a : b;
//}
//
//Node* newNode(int key)
//{
//	Node* node = newNode();
//	node->key = key;
//	node->left = NULL;
//	node->right = NULL;
//	node->height = 1;
//	return(node);
//}
//
//Node* rightRotate(Node* y)
//{
//	Node* x = y->left;
//	Node* T2 = x->right;
//	x->right = y;
//	y->left = T2;
//	y->height = get_max(height(y->left), height(y->right)) + 1;
//	x->height = get_max(height(x->left), height(x->right)) + 1;
//	return x;
//}
//
//Node* leftRotate(Node* x)
//{
//	Node* y = x->right;
//	Node* T2 = y->left;
//	y->left = x;
//	x->right = T2;
//	x->height = get_max(height(x->left), height(x->right)) + 1;
//	y->height = get_max(height(y->left), height(y->right)) + 1;
//	return y;
//}
//
//int getBalance(Node* N)
//{
//	if (N == NULL)
//		return 0;
//	return height(N->left) - height(N->right);
//}
//
//Node* insert(Node* node, MY_STRING key)
//{
//	if (node == NULL)
//		return(newNode(key));
//	if (key < node->key)
//		node->left = insert(node->left, key);
//	else if (key > node->key)
//		node->right = insert(node->right, key);
//	else
//		return node;
//	node->height = 1 + max(height(node->left), height(node->right));
//	int balance = getBalance(node);
//	if (balance > 1 && key < node->left->key)
//		return rightRotate(node);
//	if (balance<-1 && key>node->right->key)
//		return leftRotate(node);
//	if (balance > 1 && key > node->left->key)
//	{
//		node->left = leftRotate(node->left);
//		return rightRotate(node);
//	}
//	if (balance < -1 && key < node->right->key)
//	{
//		node->right = rightRotate(node->right);
//		return leftRotate(node);
//	}
//	return node;
//}