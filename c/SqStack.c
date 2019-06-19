#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<ctype.h>
#include<time.h>
#include<malloc.h>
#include<errno.h>

#define OK 1
#define ERROR 0
#define TRUE 1
#define FALSE 0
#define OVERFLOW 0
#define STACK_INIT_SIZE 100
#define STACK_INCREMENT 10
typedef int ElemType;
typedef int Status;
typedef struct{
	ElemType *base;
	ElemType *top;
	int stackSize;
}SqStack;
Status InitStack(SqStack *S);
Status GetTop(SqStack *S,ElemType *e);
Status Push(SqStack *S,ElemType *e);
Status Pop(SqStack *S,ElemType *e);
Status StackEmpty(SqStack *S);

