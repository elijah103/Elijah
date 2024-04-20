#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "my_string.h"

MY_STRING my_string_init_default(void)
{
	My_string* pMy_string;
	pMy_string = (My_string*)malloc(sizeof(My_string));
	if (pMy_string != NULL) {
		pMy_string->size = 0;
		pMy_string->capacity = 7;
		pMy_string->data = (char*)(malloc(sizeof(char)*pMy_string->capacity));
		if (pMy_string->data == NULL) {
			free(pMy_string);
			pMy_string = NULL;
		}
	}
	return pMy_string;
}

void my_string_destroy(ITEM* pItem)
{
	My_string* pMy_string = (My_string*)*pItem;
	free(pMy_string->data);
	free(pMy_string);
	*pItem = NULL;
}

int my_string_get_capacity(MY_STRING hMy_string)
{
	My_string* pMy_string = (My_string*)hMy_string;
	return pMy_string->capacity;
}

int my_string_get_size(MY_STRING hMy_string)
{
	My_string* pMy_string = (My_string*)hMy_string;
	return pMy_string->size;
}

int my_string_compare(MY_STRING hLeft_string, MY_STRING hRight_string)
{
	int count = 0, i = 0;
	char *lString, *rString;
	int smallest_size;
	lString = ((My_string*)hLeft_string)->data;
	rString = ((My_string*)hRight_string)->data;
	int size1 = my_string_get_size(lString);
	int size2 = my_string_get_size(rString);
	if (size1 < size2) {
		smallest_size = size1;
	}
	else {
		smallest_size = size2;
	}
	for (;i<smallest_size; lString++, rString++,i++) {
		count += *lString - *rString;
		if (count != 0) {
			return count;
		}
	}
	return count;
}

MY_STRING my_string_init_c_string(const char* c_string)
{
	My_string* pMy_string;
	pMy_string = (My_string*)malloc(sizeof(My_string));
	pMy_string->size = strlen(c_string);
	pMy_string->capacity = pMy_string->size + 1;
	pMy_string->data = (char*)malloc(sizeof(char*)*pMy_string->capacity);
	strcpy(pMy_string->data, c_string);
	if (pMy_string->data == NULL) {
		return NULL;
	}
	return pMy_string;
}

Status my_string_extraction(MY_STRING hMy_string, FILE* fp)
{
	char c;
	My_string* pMy_string = (My_string*)hMy_string;
	pMy_string->size = 0;
	int count = 0;
	char* string = NULL;
	c = fgetc(fp);
	while (c == ' ' || c == '\n') {
		c = fgetc(fp);
	}
	if (c == EOF) {
		return FAILURE;
	}
	for (; c != ' '&&c != '\n'&&c != EOF; count++) {
		if (pMy_string->capacity > count + 1) {
			pMy_string->data[count] = c;
			pMy_string->size++;
		}
		else {
			string = pMy_string->data;
			free(pMy_string->data);
			pMy_string->data = (char*)malloc(sizeof(char*)*pMy_string->
				capacity * 2);
			if (pMy_string->data == NULL) {
				free(pMy_string);
				return FAILURE;
			}
			strcpy(pMy_string->data, string);
			pMy_string->capacity *= 2;
			pMy_string->data[count] = c;
			pMy_string->size++;
		}
		c = fgetc(fp);
	}
	ungetc(c, fp);
	return SUCCESS;
}

Status my_string_insertion(MY_STRING hMy_string, FILE* fp)
{
	int i = 0;
	My_string* pMy_string = (My_string*)hMy_string;
	for (; i < pMy_string->size; i++) {
		fputc(pMy_string->data[i], fp);
	}
	if (i == 0) {
		return FAILURE;
	}
	return SUCCESS;
}

Status my_string_push_back(MY_STRING hMy_string, char item)
{
	My_string* pMy_string = (My_string*)hMy_string;
	char* temp;
	int i = 0;
	if (pMy_string->size >= pMy_string->capacity) {
		temp = (char*)malloc(sizeof(char)*pMy_string->capacity * 2);
		if (pMy_string->data == NULL) {
			free(pMy_string);
			return FAILURE;
		}
		for (; i < pMy_string->size; i++) {
			temp[i] = pMy_string->data[i];
		}
		free(pMy_string->data);
		pMy_string->data = temp;
		pMy_string->capacity *= 2;
	}
	pMy_string->data[pMy_string->size] = item;
	pMy_string->size++;
	return SUCCESS;
}

Status my_string_pop_back(MY_STRING hMy_string)
{
	My_string* pMy_string = (My_string*)hMy_string;
	if (pMy_string->size <= 0) {
		return FAILURE;
	}
	pMy_string->size--;
	return SUCCESS;
}

char* my_string_at(MY_STRING hMy_string, int index)
{
	My_string* pMy_string = (My_string*)hMy_string;
	if (index < 0 || index >= pMy_string->size) {
		return NULL;
	}
	return &pMy_string->data[index];
}

char* my_string_c_str(MY_STRING hMy_string)
{
	My_string* pMy_string = (My_string*)hMy_string;
	pMy_string->data[pMy_string->size] = '\0';
	return pMy_string->data;
}

Status my_string_concat(MY_STRING hResult, MY_STRING hAppend)
{
	My_string* pResult = (My_string*)hResult;
	My_string* pAppend = (My_string*)hAppend;
	int i;
	if (pResult->size + pAppend->size >= pResult->capacity) {
		char* tmp;
		int new_capacity = pResult->size + pAppend->size + 1;
		tmp = (char*)malloc(sizeof(char*)*new_capacity);
		if (tmp == NULL) {
			return FAILURE;
		}
		for (i = 0; i < pResult->size; i++) {
			tmp[i] = pResult->data[i];
		}
		free(pResult->data);
		pResult->data = tmp;
		pResult->capacity = new_capacity;
	}
	for (i = 0; i < pAppend->size; i++) {
		my_string_push_back(pResult, pAppend->data[i]);
	}
	return SUCCESS;
}

Boolean my_string_empty(MY_STRING hMy_string)
{
	My_string* pMy_string = (My_string*)hMy_string;
	if (pMy_string->size <= 0) {
		return TRUE;
	}
	return FALSE;
}

void my_string_assignment(ITEM* pLeft, ITEM Right)
{
	My_string* right = (My_string*)Right;
	if (*pLeft == NULL) {
		My_string* DeepCpy = NULL;
		DeepCpy = (My_string*)malloc(sizeof(My_string));
		DeepCpy->capacity = right->capacity;
		DeepCpy->size = right->size;
		DeepCpy->data = (char*)malloc(sizeof(char)*right->capacity);
		if (DeepCpy->data == NULL) {
			free(DeepCpy);
			DeepCpy = NULL;
			return;
		}
		for (int i = 0; i < DeepCpy->size; i++) {
			DeepCpy->data[i] = right->data[i];
		}
		*pLeft = DeepCpy;
	}
	else {
		((My_string*)*pLeft)->size = right->size;
		((My_string*)*pLeft)->capacity = right->capacity;
		free(((My_string*)*pLeft)->data);
		((My_string*)*pLeft)->data = (char*)malloc(sizeof(char)*right->
			capacity);
		if (((My_string*)*pLeft)->data == NULL) {
			free(((My_string*)*pLeft));
			*pLeft = NULL;
			return;
		}
		for (int i = 0; i < right->size; i++) {
			((My_string*)*pLeft)->data[i] = right->data[i];
		}
	}
}