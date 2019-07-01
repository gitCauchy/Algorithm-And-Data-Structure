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
Status CreateBiTree(BiTree *T){
	ElemType ch;
	scanf("%c",&ch);
	getchar();// get enter character
	if(ch == '#'){
		*T = NULL
	}else{
		if(! (*T = (TreeNode*)malloc(sizeof(TreeNode)))){
			exit(OVERFLOW);
		}
		(*T) -> data = ch;
		CreateBiTree(&((*T) -> lchild));
		CreateBiTree(&((*T) -> rchild));
	}
	return OK;
}
Status PreOrderTraverse(BiTree *T,Status (*Visit)(ElemType e)){
	if(*T){
		if(Visit((*T) -> data)){
			if(PreOrderTraverse(&((*T) -> lchild),Print)){
				if(PreOrderTraverse(&((*T) -> rchild),Print)){
					return OK;
				}
				return ERROR;
			}
		}
	}
	else{
		return OK;
	}
}
Status InOrderTraverse(BiTree *T,Status (*Visit)(ElemType e)){
	SqStack S;
	InitStack(&S);
	BiTree p = T;
	while(p || StackEmpty(&S)){
		if(p){
			Push(&S,p);
			p = p -> lchild;
		}else{
			Pop(&S,&p);
			if(!Visit(p -> data)){
				return ERROR;
			}
			p = p -> rchild;
		}
	}
}
Status PostOrderTraverse(BiTree *T,Status(*Visit)(ElemType e)){
	if(*T){
		if(PostOrderTraverse(&((*T) -> lchild))){
			if(PostOrderTraverse(&((*T) -> rchild))){
				if(Visit((*T) -> data)){
					return OK;
				}
				return ERROR;
			}
		}
	}else{
		return ERROR;
	}
}
Status Print(ElemType *e){
	printf("%c",*e);
	return OK;
}
int TreeDepth(BiTree *T){
	int lchilddep,rchilddep;
	if(*T == NULL){
		return(0);
	}else{
		lchilddep = TreeDepth((*T) -> lchild);
		rchilddep = TreeDepth((*T) -> rchild);
		return (lchilddep > rchilddep)?(lchilddep + 1):(rchilddep + 1);
	}
}
Status PrintTreeLevel(BiTree *T,int level){
	if( *T == NULL || level < 1){
		return 0;
	}
	if( level == 1){
		Print(T -> data);
		return OK;
	}
}
Status LevelTraverse(BiTree *T,int deepth){
	int i = 0;
	if(*T == NULL){
		return ERROR;
	}
	for(int i = 1;i <= deepth;i++){
		PrintTreeLevel(*T,i);
	}
}
