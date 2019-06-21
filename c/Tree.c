#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>
#include<time.h>
#include<malloc.h>
#include<errno.h>
#define TRUE 1
#define FALSE 0
#define OVERFLOW 0
#define OK 1
#define ERROR -1
#define STACK_INIT_SIZE 100
#define STACKINCREMENT 10
typedef int Status;
typedef char ElemType;
typedef struct TreeNode{
	ElemType data;
	struct TreeNode *lchild;
	struct TreeNode *rchild;
}TreeNode,*BiTree;
typedef BiTree SElemType;
typedef struct{
	SElemType *base;
	SElemType *top;
	int stackSize;
}SqStack;
int TreeDepth(BiTree *T);
Status Print(ElemType *e);
Status CreateBiTree(BiTree *T);
Status InitStack(SqStack *S);
Status GetTop(SqStack *S,SElemType *e);
Status Push(SqStack *S,SElemType *e);
Status Pop(SqStack *S,SElemType *e);
Status StakEmpty(SqStack *S);
