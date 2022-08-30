#define _CRT_SECURE_NO_WARNINGS 1
#include "TreeNode.h"
void BinaryTreeDestory(BTNode** root)
{
	if(*root == NULL) 
	{
		return;
	}

	BTNode cur = **root;
	free(*root);
	*root = NULL;
	BinaryTreeDestory(&(cur._left));
	BinaryTreeDestory(&(cur._right));
}
int BinaryTreeSize(BTNode* root)
{
	if (root == NULL)
	{
		return 0;
	}
	return 1 + BinaryTreeSize(root->_left) + BinaryTreeSize(root->_right);
}

BTNode* createTreeNode(BTDataType val)
{
	BTNode* cur = (BTNode*)malloc(sizeof(BTNode));
	if (cur == NULL)
	{
		printf("malloc fail\n");
		return NULL;
	}
	cur->_data = val;
	cur->_left = NULL;
	cur->_right = NULL;
	return cur;
}

BTNode* BinaryTreeCreate(BTDataType* a, int n, int* pi)
{
	if (a == NULL || n == 0) {
		return NULL;
	}
	BTNode* root = NULL;
	if (a[*pi] != '#')
	{
		root = createTreeNode(a[*pi]);
		(*pi)++;
		root->_left = BinaryTreeCreate(a, n, pi);
		root->_right = BinaryTreeCreate(a, n, pi);
	}
	else
	{
		(*pi)++;
	}
	return root;
}
void BinaryTreePrevOrder(BTNode* root)
{
	if (root == NULL)
	{
		return;
	}
	printf("%c ", root->_data);
	BinaryTreePrevOrder(root->_left);
	BinaryTreePrevOrder(root->_right);
}



void BinaryTreePostOrder(BTNode* root)
{
	if (root == NULL)
	{
		return;
	}
	BinaryTreePostOrder(root->_left);
	BinaryTreePostOrder(root->_right);
	printf("%c ", root->_data);

}

void BinaryTreeInOrder(BTNode* root)
{
	if (root == NULL)
	{
		return;
	}
	BinaryTreeInOrder(root->_left);
	printf("%c ", root->_data);
	BinaryTreeInOrder(root->_right);
}

int BinaryTreeLeafSize(BTNode* root)
{
	if (root == NULL)
	{
		return 0;
	}
	if (root->_left == NULL && root->_right == NULL)
	{
		return 1;
	}
	return BinaryTreeLeafSize(root->_left) + BinaryTreeLeafSize(root->_right);
}

int BinaryTreeLevelKSize(BTNode* root, int k)
{
	if (root == NULL)
	{
		return 0;
	}
	if (k == 1)
	{
		return 1;
	}
	return BinaryTreeLevelKSize(root->_left, k - 1) + BinaryTreeLevelKSize(root->_right, k - 1);
}

BTNode* BinaryTreeFind(BTNode* root, BTDataType x)
{
	if (root == NULL)
	{
		return NULL;
	}
	if (root->_data == x)
	{
		return root;
	}

	BTNode* leftCur = BinaryTreeFind(root->_left, x);
	if (leftCur != NULL)
	{
		return root->_left;
	}

	BTNode* rightCur = BinaryTreeFind(root->_right, x);
	if (rightCur != NULL)
	{
		return root->_left;
	}

	return NULL;
}

int BinaryTreeComplete(BTNode* root)
{
	if (root == NULL)
	{
		return 1;
	}
	if (root->_left == NULL && root->_right == NULL)
	{
		return 1;
	}
	if (root->_left != NULL && root->_right == NULL)
	{
		return 1;
	}
	if (root->_left == NULL && root->_right != NULL)
	{
		return 0;
	}
	return BinaryTreeComplete(root->_left) && BinaryTreeComplete(root->_right);
}

void InitQueue(Queue* ps)
{
	assert(ps);
	ps->head = NULL;
	ps->tail = NULL;
	ps->size = 0;
}

SLNode* createSLNode(BTNode val)
{
	SLNode* cur = (SLNode*)malloc(sizeof(SLNode));
	assert(cur);
	cur->val = val;
	/*cur->val._data = val._data;
	cur->val._left = val._left;
	cur->val._right = val._right;*/
	cur->next = NULL;
	return cur;
}

void add(Queue* ps, BTNode val)
{
	assert(ps);

	SLNode* node = createSLNode(val);

	if (ps->head == NULL)
	{
		ps->head = node;
		ps->tail = ps->head;
		ps->size++;
		return;
	}

	ps->tail->next = node;
	ps->tail = ps->tail->next;
	ps->size++;
}


int size(Queue* ps)
{
	return ps->size;
}

int isEmpty(Queue* ps)
{
	return ps->size == 0;
}

BTNode pop(Queue* ps)
{
	if (isEmpty(ps))
	{
		exit(-1);
	}
	BTNode cur = ps->head->val;
	SLNode* newHead = ps->head->next;
	free(ps->head);
	ps->head = newHead;
	ps->size--;
	return cur;
}

void BinaryTreeLevelOrder(BTNode* root)
{
	if (root == NULL)
	{
		return;
	}
	Queue queue;
	InitQueue(&queue);
	add(&queue, *root);
	while (!isEmpty(&queue))
	{
		int sz = size(&queue);
		while (sz > 0)
		{
			BTNode cur = pop(&queue);
			printf("%c ", cur._data);
			if (cur._left != NULL)
			{
				add(&queue, *(cur._left));
			}
			if (cur._right != NULL)
			{
				add(&queue, *(cur._right));
			}
			sz--;
		}
	}
}