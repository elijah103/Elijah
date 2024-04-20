#include <stdio.h>
#include <stdlib.h>
#include "vector.h"

struct generic_vector
{
	int size;
	int capacity;
	ITEM* data;
	void(*item_destroy)(ITEM* phItem);
	void(*item_assignment)(ITEM* pLeft, ITEM right);
};
typedef struct generic_vector Generic_vector;

GENERIC_VECTOR generic_vector_init_default(
	void(*item_assignment)(ITEM* pLeft, ITEM right),
	void(*item_destroy)(ITEM* phItem))
{
	int i;
	Generic_vector* pVector = (Generic_vector*)malloc(sizeof(Generic_vector));
	if (pVector != NULL) {
		pVector->size = 0;
		pVector->capacity = 1;
		pVector->data = (ITEM*)malloc(sizeof(ITEM)*pVector->capacity);
		if (pVector->data == NULL) {
			free(pVector);
			return NULL;
		}
		for (i = 0; i < pVector->capacity; i++) {
			pVector->data[i] = NULL;
		}
		pVector->item_assignment = item_assignment;
		pVector->item_destroy = item_destroy;
	}
	return (GENERIC_VECTOR)pVector;
}

void generic_vector_destroy(GENERIC_VECTOR* phVector)
{
	Generic_vector* pVector = (Generic_vector*)*phVector;
	int i;
	for (i = 0; i < pVector->size; i++) {
		pVector->item_destroy(&(pVector->data[i]));
	}
	free(pVector->data);
	free(pVector);
	*phVector = NULL;
}

Status generic_vector_push_back(GENERIC_VECTOR hVector, ITEM value)
{
	Generic_vector* pVector = (Generic_vector*)hVector;
	ITEM* temp;
	int i;
	if (pVector->size >= pVector->capacity) {
		temp = (ITEM*)malloc(sizeof(ITEM)*pVector->capacity * 2);
		if (temp == NULL) {
			return FAILURE;
		}
		for (i = 0; i < pVector->size; i++) {
			temp[i] = pVector->data[i];
		}
		pVector->capacity *= 2;
		for (; i < pVector->capacity; i++) {
			temp[i] = NULL;
		}
		free(pVector->data);
		pVector->data = temp;
	}
	pVector->item_assignment(&(pVector->data[pVector->size]), value);
	pVector->size++;
	return SUCCESS;
}

int generic_vector_get_size(GENERIC_VECTOR hVector)
{
	Generic_vector* pVector = (Generic_vector*)hVector;
	return pVector->size;
}

int generic_vector_get_capacity(GENERIC_VECTOR hVector)
{
	Generic_vector* pVector = (Generic_vector*)hVector;
	return pVector->capacity;
}

ITEM generic_vector_at(GENERIC_VECTOR hVector, int index)
{
	Generic_vector* pVector = (Generic_vector*)hVector;
	if (index < 0 || index >= pVector->size) {
		return NULL;
	}
	return pVector->data[index];
}

Status generic_vector_pop_back(GENERIC_VECTOR hVector)
{
	Generic_vector* pVector = (Generic_vector*)hVector;
	if (generic_vector_empty(hVector)) {
		return FAILURE;
	}
	pVector->item_destroy(&(pVector->data[pVector->size - 1]));
	pVector->size--;
	return SUCCESS;
}

Boolean generic_vector_empty(GENERIC_VECTOR hVector)
{
	Generic_vector* pVector = (Generic_vector*)hVector;
	if (pVector->size <= 0) {
		return TRUE;
	}
	return FALSE;
}

void clear_keyboard_buffer(void)
{
	char c;
	scanf("%c", &c);
	while (c != '\n')
		scanf("%c", &c);
}

Boolean do_you_wish_to_continue(void)
{
	char a;
	printf("Do you wish to continue?(y/n): ");
	scanf("%c", &a);
	while (a != 'y'&&a != 'Y'&&a != 'n'&&a != 'N') {
		printf("You must enter either \"y\" or \"n\": ");
		scanf("%c", &a);
	}
	if (a == 'n' || a == 'N')
		return 0;
	if (a == 'y' || a == 'Y')
		return 1;
}