#include<stdio.h>
#include<stdlib.h> 
typedef struct Node 
{ 
	struct Node *left, *right; 
	int data; 
	bool lthread; 
	bool rthread; 
}node; 
struct Node *insert(struct Node *root, int data) 
{ 
	Node *ptr = root; 
	Node *par = NULL; 
	while (ptr != NULL) 
	{ 
		if (data == (ptr->data)) 
		{ 
			printf("Duplicate Key !\n"); 
			return root; 
		} 

		par = ptr; 

		if (data < ptr->data) 
		{ 
			if (ptr -> lthread == false) 
				ptr = ptr -> left; 
			else
				break; 
		} 
		else
		{ 
			if (ptr->rthread == false) 
				ptr = ptr -> right; 
			else
				break; 
		} 
	} 
	Node *temp = new Node; 
	temp -> data = data; 
	temp -> lthread = true; 
	temp -> rthread = true; 

	if (par == NULL) 
	{ 
		root = temp; 
		temp -> left = NULL; 
		temp -> right = NULL; 
	} 
	else if (data < (par -> data)) 
	{ 
		temp -> left = par -> left; 
		temp -> right = par; 
		par -> lthread = false; 
		par -> left = temp; 
	} 
	else
	{ 
		temp -> left = par; 
		temp -> right = par -> right; 
		par -> rthread = false; 
		par -> right = temp; 
	} 

	return root; 
} 
struct Node *inorderSuccessor(struct Node *ptr) 
{ 
	if (ptr -> rthread == true) 
		return ptr->right; 
	ptr = ptr -> right; 
	while (ptr -> lthread == false) 
		ptr = ptr -> left; 
	return ptr; 
} 
void inorder(struct Node *root) 
{ 
	if (root == NULL) 
		printf("Tree is empty"); 
	struct Node *ptr = root; 
	while (ptr -> lthread == false) 
		ptr = ptr -> left; 
	while (ptr != NULL) 
	{ 
		printf("%d ",ptr -> data); 
		ptr = inorderSuccessor(ptr); 
	} 
} 
int main() 
{ 
	struct Node *root = NULL; 

	root = insert(root, 20); 
	root = insert(root, 10); 
	root = insert(root, 30); 
	root = insert(root, 5); 
	root = insert(root, 16); 
	root = insert(root, 14); 
	root = insert(root, 17); 
	root = insert(root, 13); 

	inorder(root); 

	return 0; 
} 
