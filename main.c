#include <stdio.h>
#include <stdlib.h>
#include "vector.h"
#include "my_string.h"

//void play_evil_hangman(GENERIC_VECTOR starting_family,int size,int guesses);
void init_tree(Node* first_node);
//Node* new_node(void);
void add_node_to_tree(Node* root, Node* new_node);
Node* traverse_the_tree(Node* root,Node* new_node);

struct node;
typedef struct node Node;
struct node
{
	MY_STRING word;
	Node* left;
	Node* right;
};

int main(int argc, char* argv[])
{
	int i, j, a;
	FILE* fp;
	char* key;
	fp = fopen("c:\\comp1010\\dictionary.txt", "r");
	MY_STRING temp = NULL;
	temp = my_string_init_default();
	GENERIC_VECTOR arr[30] = { NULL };
	for (i = 0; i < 30; i++) {
		arr[i] = generic_vector_init_default(my_string_assignment,
			my_string_destroy);
	}
	while (my_string_extraction(temp, fp)) {
		generic_vector_push_back(arr[my_string_get_size(temp) - 1], temp);
	}
	for (i = 0; i < 30; i++) {
		printf("Size of Vector %d: %d\n", i + 1, generic_vector_get_size(
			arr[i]));
	}
	fclose(fp);
	printf("What length word? ");
	scanf("%d", &a);
	while (!(generic_vector_get_size(arr[a]) > 0)) {
		printf("The length must be in bounds: ");
		scanf("%d", &a);
	}
	return 0;
	/*My_string* p = (My_string*)(generic_vector_at(arr[a], 0));
	for (i = 0; i < p->size; i++) {
		printf("%c", p->data[i]);
	}*/
	//for (i = 0; i < generic_vector_get_size(arr[a-1]); i++) {
	//	My_string* p = (My_string*)(generic_vector_at(arr[a - 1], i));
	//	Node* node = new_node(p);
	//	node->word = (char*)malloc(sizeof(char)*(p->size + 1));
	//	for (j = 0; j < p->size; j++) {
	//		printf("%c", p->data[j]);
	//		node->word[j] = p->data[j];
	//	}
	//	node->word[j] = '\0';
	//	printf("\n");
	//}
	//B tree
	//B+ tree
}

void init_tree(Node* first_node)
{
	first_node = NULL;
}

Node* new_node(My_string* pdata)
{
	Node* node = (Node*)malloc(sizeof(Node));
	node->word = (My_string*)malloc(sizeof(My_string*));
	node->word = pdata;
	node->left = NULL;
	node->right = NULL;
	return node;
}

void add_node_to_tree(Node* root,Node* new_node)
{
	Node* last_node;
	if (root == NULL) {
		root = new_node;
	}
	else {
		last_node = traverse_the_tree(root,new_node);
		last_node = new_node;
	}
}

Node* traverse_the_tree(Node* root,Node* new_node)
{
	if (my_string_compare(root->word, new_node->word) <= 0) {
		if (root->right == NULL) {
			return root->right;
		}
		else {
			traverse_the_tree(root->right, new_node);
		}
	}
	else{
		if (root->left == NULL) {
			return root->left;
		}
		else {
			traverse_the_tree(root->left, new_node);
		}
	}
}
















	/*do {
		Printf("What length word? ");
		scanf("%d", &a);
		while (!(generic_vector_get_size(arr[a]) > 0)) {
			Printf("The length must be in bounds: ");
			scanf("%d", &a);
		}
		printf("how many guesses? ");
		scanf("%d", &b);
		play_evil_hangman(arr[a],a,b);
	} while (do_you_wish_to_continue());*/
	//Make an array of generic vectors for real and don't destroy them
	//Ask what length word
	//Check to see if the length is in bounds
	//If it has size greater than zero

	//find the biggest group of words after the guess


//make a stub that calls a function that plays evil hangman
//If they can play that way then make a copy of the vector
//Pick a letter
//Given a guess and a word and a key it will get a new key

//void play_evil_hangman(GENERIC_VECTOR starting_family,int size,int guesses)
//{
//	int c = 0, d = 0, count = 0;
//	FILE* fp;
//	fp = fopen("dictionary.txt", "r");
//	ITEM old_key = NULL, new_key = NULL, current_word = NULL;
//	char guess;
//	printf("current key: ");
//	for(;c<size;c++)
//		old_key = my_string_init_c_string("_");
//	my_string_insertion(old_key, stdout);
//	printf("guess: ");
//	scanf("%c", &guess);
//	for (c = 0;starting_family->data[c]!=NULL;c++)
//	{
//		for (;d<my_string_get_size(starting_family->data[c]); d++) {
//			if (guess == (starting_family->data[c])[d]) {
//				count++;
//			}
//		}
//	}
//}