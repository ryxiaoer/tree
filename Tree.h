#pragma once
#ifndef  _TREE_H_
#define _TREE_H_

#include"common.h"

typedef struct BinTreeNode
{
	ElemType data;
	struct BinTreeNode* leftChild;
	struct BinTreeNode* rightChild;
}BinTreeNode;

typedef struct BinTree
{
	BinTreeNode* root;
}BinTree;
//======================函数接口=====================///
//初始化
void BinTreeInit(BinTree *pbt);
//创建
void BinTreeCreate(BinTree* pbt);
BinTreeNode* BinTreeCreate0();
//根据输入字符创建二叉树
void BinTreeCreatByStr(BinTree *bt, const char* str);
BinTreeNode* BinTreeCreatByStr0(const char* str,int* index);
//二叉树的遍历
void PreOrder(BinTree* bt);
void PreOrder_1(BinTreeNode* t);
void InOrder(BinTree* bt);
void InOrder_1(BinTreeNode* t);
void PostOrder(BinTree* bt);
void PostOrder_1(BinTreeNode* t);
void LeveOrder(BinTree* bt);
void LeveOrder_1(BinTreeNode* t);
//二叉树的查询
BinTreeNode* BinTreeFind(BinTree *bt, ElemType x);
BinTreeNode* BinTreeFind_1(BinTreeNode* t, ElemType x);
BinTreeNode* BinTreeParent(BinTree* bt, ElemType x);
BinTreeNode* BinTreeParent_1(BinTreeNode* bt, ElemType x);
//拷贝二叉树
void BinTreeCopy(BinTree* bt1,BinTree* bt2);//bt2=bt1
BinTreeNode* BinTreeCopy_1(BinTreeNode* t);
//判断二叉树是否相等
bool BinTreeEqual(BinTree *bt1, BinTree *bt2);
bool BinTreeEqual_1(BinTreeNode* t1, BinTreeNode* t2);
//求二叉树的节点个数和树的高度
int BinTreeCount(BinTree* bt);
int BinTreeCount_1(BinTreeNode* t);
int BinTreeHeigh(BinTree* bt);
int BinTreeHeigh_1(BinTreeNode* t);
//摧毁二叉树
void BinTreeDestroy(BinTree* bt);
void BinTreeDestroy_1(BinTreeNode* t);
//========================/函数接口定义/=====================//
//初始化
void BinTreeInit(BinTree *pbt)
{
	pbt->root = NULL;
}
//创建
//"ABC##DE##F##G#H##";
inline void BinTreeCreate(BinTree * bt)
{
	bt->root = BinTreeCreate0();
}
inline BinTreeNode * BinTreeCreate0()
{
	ElemType tmp;
	scanf("%c", &tmp);
	if(tmp=='#')
		return NULL;
	else
	{
		BinTreeNode* t = (BinTreeNode*)malloc(sizeof(BinTreeNode));
		assert(t != NULL);
		t->data = tmp;

		//然后以t为根节点创建左右树
		t->leftChild = BinTreeCreate0();
		t->rightChild = BinTreeCreate0();
		return t;
	}
}


//根据字符创建二叉树
inline void BinTreeCreatByStr(BinTree * bt, const char * str)
{
	int index = 0;
	bt->root = BinTreeCreatByStr0(str,&index);
	return;
}

inline BinTreeNode * BinTreeCreatByStr0(const char * str,int* index)
{
	if(str[*index]=='#'||str[*index]=='\0')
	return NULL;
	else
	{
		BinTreeNode* t = (BinTreeNode*)malloc(sizeof(BinTreeNode));
		assert(t != NULL);
		t->data = str[*index];
		(*index)++;
		//直接传会导致str位置不变，所以需要加入index
		t->leftChild = BinTreeCreatByStr0(str, index);
		(*index)++;
		t->rightChild= BinTreeCreatByStr0(str, index);
		return t;
	}
}

//先序遍历
inline void PreOrder(BinTree * bt)
{
	PreOrder_1(bt->root);
}
inline void PreOrder_1(BinTreeNode * t)
{
	if (t != NULL)
	{
		printf("%c", t->data);
		PreOrder_1(t->leftChild);
		PreOrder_1(t->rightChild);
	}
	return;
}

//中序遍历
inline void InOrder(BinTree * bt)
{
	InOrder_1(bt->root);
}
inline void InOrder_1(BinTreeNode * t)
{
	if (t != NULL)
	{
		InOrder_1(t->leftChild);
		printf("%c", t->data);
		InOrder_1(t->rightChild);
	}
	return;
}

//后序遍历
inline void PostOrder(BinTree * bt)
{
	PostOrder_1(bt->root);
}
inline void PostOrder_1(BinTreeNode * t)
{
	if (t != NULL)
	{
		PostOrder_1(t->leftChild);
		PostOrder_1(t->rightChild);
		printf("%c", t->data);
	}
	return;
}

//查找x，并返回所在地址
inline BinTreeNode * BinTreeFind(BinTree* bt, ElemType x)
{
	return BinTreeFind_1(bt->root, x);
}
inline BinTreeNode * BinTreeFind_1(BinTreeNode * t, ElemType x)
{
	if (NULL == t)
	{
			return NULL;
	}
	if (t->data == x) return t;
	BinTreeNode* p = BinTreeFind_1(t->leftChild, x);
	if (p != NULL)
	{
		return p;
	}
	else
	{	
		return BinTreeFind_1(t->rightChild, x);
	}
}

//查找父节点并返回地址
inline BinTreeNode* BinTreeParent(BinTree* bt, ElemType x)
{
	return BinTreeParent_1(bt->root, x);
}
inline BinTreeNode * BinTreeParent_1(BinTreeNode * t, ElemType x)
{
	BinTreeNode* p = NULL;
	//如果不存在或者查找的是根节点，无父节点
	if(t==NULL || t->data==x) 
		return NULL;

	if ((t->leftChild!=NULL&&t->leftChild->data == x) 
		|| (t->rightChild!=NULL&&t->rightChild->data == x))
		return t;
	p = BinTreeParent_1(t->leftChild, x);
	if (p != NULL)
		return p;
	return BinTreeParent_1(t->rightChild, x);
}

//拷贝二叉树bt2=bt1
inline void BinTreeCopy(BinTree * bt1, BinTree * bt2)
{
	bt2->root = BinTreeCopy_1(bt1->root);
	return;
}
inline BinTreeNode * BinTreeCopy_1(BinTreeNode * t)
{
	if (t == NULL)
		return NULL;
	BinTreeNode* tmp = (BinTreeNode*)malloc(sizeof(BinTreeNode));
	assert (tmp != NULL);
	tmp->data = t->data;
	tmp->leftChild = BinTreeCopy_1(t->leftChild);
	tmp->rightChild = BinTreeCopy_1(t->rightChild);
	return tmp;
}

//判断两个二叉树是否相等

inline bool BinTreeEqual(BinTree * bt1, BinTree * bt2)
{
	return BinTreeEqual_1(bt1->root, bt2->root);
}
inline bool BinTreeEqual_1(BinTreeNode * t1, BinTreeNode * t2)
{
	///有NULL存在时
	if (t1 == NULL && t2 == NULL)
		return true;
	if (t1 == NULL || t2 == NULL)
		return false;
	///无NULL
	if (t1->data == t2->data
		&&BinTreeEqual_1(t1->leftChild, t2->leftChild) 
		&& BinTreeEqual_1(t1->rightChild, t2->rightChild))
		return true;
	else
		return false;
}

//节点个数
inline int BinTreeCount(BinTree * bt)//根+左树+右树
{
	return BinTreeCount_1(bt->root);
}
inline int BinTreeCount_1(BinTreeNode * t)
{
	if (NULL == t) return 0;
	else
	{
		return (1 + BinTreeCount_1(t->leftChild) + BinTreeCount_1(t->rightChild));
	}
}

//求高度
inline int BinTreeHeigh(BinTree * bt)
{
	return BinTreeHeigh_1(bt->root);
}
inline int BinTreeHeigh_1(BinTreeNode * t)
{
	if (NULL == t) return 0;
	else
	{
		return 1 + (BinTreeHeigh_1(t->leftChild)>BinTreeHeigh_1(t->rightChild)? BinTreeHeigh_1(t->leftChild): BinTreeHeigh_1(t->rightChild));
	}
}

//摧毁二叉树
inline void BinTreeDestroy(BinTree * bt)
{
	BinTreeDestroy_1(bt->root);
}
inline void BinTreeDestroy_1(BinTreeNode * t)
{
	if (t == NULL)
		return;
	BinTreeDestroy_1(t->leftChild);
	BinTreeDestroy_1(t->rightChild);
	free(t);
}

//层次遍历需要先建立一个队列。
//根节点入队，出队，判断出队其左右树是否为空，不为空时入队新节点
/*
inline void LeveOrder(BinTreeNode * t)
{
	if (NULL != t)
	{
		LinkQueue Q;
		LinkQueueInit(&Q);
		LinkQueueEnQue(&Q, t);//根将节点入队
		while (!LinkQueueEmpty(&Q))
		{
			BinTreeNode* p = LinkQueueFront(&Q); //取队头元素
			LinkQueueDeQue(&Q);//出队
			printf("%c", p->data);
			if (p->leftChild != NULL )
			{
				LinkQueueEnQue(&Q, p->leftChild);
			}
			if (p->rightChild != NULL)
			{
				LinkQueueEnQue(&Q, p->rightChild);
			}
		}
	}
}
inline void LeveOrder_1(BinTreeNode * t)
{
}
*/
#endif // ! _TREE_H_

