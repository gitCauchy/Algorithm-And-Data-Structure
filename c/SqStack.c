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
int main( int argc ,char *argv[]){

}
Status InitStack(SqStack *S){
	S -> base = (ElemType *)malloc(STACK_INIT_SIZE * sizeof(ElemType));
	if(!S -> base){
		return OVERFLOW;
	}
	S -> top = S -> base;
	S -> stackSize = STACK_INIT_SIZE;
	return OK;
}
Status GetTop(SqStack *S ,ElemType *e){
	if(S -> base = S -> top){// 空栈
		return ERROR;
	}
	*e = *(S -> top - 1);
	return OK;
}
Status Push(SqStack *S,ElemType *e){
	if(S -> top - S -> base >= S -> stackSize){
		S -> base = (ElemType *)realloc(S -> base,(STACK_INCREMENT + S -> stackSize)*sizeof(ElemType));
		if(! S -> base){
			return OVERFLOW;
		}
		S -> top = S -> base + S -> stackSize;
		S -> stackSize += STACK_INCREMENT;
	}
	* (S -> top ++) = *e;
	return OK;
}
Status Pop(SqStack *S,ElemType *e){
	if(S -> top == S -> base){
		return ERROR;
	}
	*e = *(S -> top -1);
	S -> top --;
	return OK;
}
Status StackEmpty(SqStack *S){
	if(S -> top == S -> base){
		return TRUE;
	}else{
		return FALSE;
	}
}

