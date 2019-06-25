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
Status PreOrderTraverse(BiTree *T,(Status*Visit)(ElemType *e));
Status InOrderTraverse(BiTree *T,Status (*Visit)(ElemType *e));
Status PostOrderTraverse(BiTree *T,Status (*Visit)(ElemType *e));
Status LevelTraverse(BiTree *T,int depth);
Status PrintTreeLevel(BiTree *T,int level);
Status InitStack(SqStack *S){
	S -> base = (SElemType *)malloc(STACK_INIT_SIZE * sizeof(SElemType));
	if(! S -> base){
		return OVERFLOW;
	}
	S -> top = S -> base;
}
Status GetTop(SqStack *S,SElemType *e){
	S -> top --;
	*e = *(S -> top);
}
Status Push(SqStack *S,SElemType *e){
	if( S -> top >= S-> base + stackSize){
		S -> base = (SElemType *)realloc(S -> base,(S -> stackSize + STACKINCREMENT)*sizeof(SElemType));
		if(!S -> top){
			return OVERFLOW;
		}
		S -> top = S -> base + S -> stackSize;
		S -> stackSize += STACKINCREMENT;
	}
	*(S -> top) = *e;
	S -> top ++;
}
Status Pop(SqStack *S,SElemType *e){
	if(S -> top == S -> base){
		return ERROR;
	}
	S ->top -= 1;
	*e = *(S -> top);
	return OK;
}
Status StackEmpty(SqStack *S){
	if(S -> top == S -> base){
		return TRUE;
	}else{
		return FALSE;
	}
}
