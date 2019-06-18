#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<malloc.h>

#define OK 0
#define ERROR -1
#define TRUE 0
#define FALSE -1
#define INFEASIBLE 0
#define OVERFLOW -1
#define LIST_INIT_SIZE 100
#define LIST_INCREMENT 10

typedef int Status ;
typedef int ElemType ;
typedef struct{
	ElemType *elem ;
	int length;
	int listSize;
}SqList;

Status InitList_Sq(SqList *L);
Status CreateList_Sq(SqList *L);
Status ListEmpty_Sq(const SqList *L);
int ListLength_Sq( SqList *L);
Status DestroyList_Sq( SqList *L);
Status ClearList_Sq( SqList *L);
Status GetElem_Sq( SqList *L , int i , ElemType *e);
Status LocateElem_Sq(const SqList *L ,const ElemType *e ,Status (*compare) (const ElemType *,const ElemType *));
Status PriorElem_Sq(const SqList *L ,const ElemType *cur_e, ElemType *pre_e);
Status NextElem_Sq(const SqList *L , const ElemType *cur_e, ElemType *pre_e);
Status ListInsert_Sq( SqList *L , int i , const ElemType *e);
Status ListDelete_Sq( SqList *L , int i , ElemType *e);
int compare(const ElemType *e1, const ElemType *e2);
Status ListTraverse_Sq(const SqList *L , Status (*pvisit)(const ElemType *));
Status outElem_Sq(const ElemType e);

int main( int argc , char *argv[] ){
	SqList LA;
	int s1 = CreateList_Sq(&LA);
	int length_of_LA = ListLength_Sq(&LA);
	printf("length is %d\n",length_of_LA);
	int tp = 3;
	int tt = 0;
	int s2 = NextElem_Sq(&LA,&tp,&tt);
	printf ("the elem tt is %d",tt);
}


Status InitList_Sq( SqList *L){
	L -> elem = (ElemType *) malloc (LIST_INIT_SIZE * sizeof(ElemType));
	if(! L -> elem){
		exit(OVERFLOW);
	}	
	memset(L -> elem , 0x00,LIST_INIT_SIZE * sizeof(ElemType));
	L -> length = 0;
	L -> listSize = LIST_INIT_SIZE;
	return OK;
}

Status CreateList_Sq(SqList *L){
	ElemType *p = NULL;
	ElemType *q = NULL;
	ElemType k = 0;
	InitList_Sq(L);
	printf("Input nums of Elements :\n ");
	scanf("%d",&k);
	L -> length = k;
	q = L -> elem + L -> length;
	printf("Input the Element,Press Enter When Finish Input An Element\n");
	for(p = L -> elem; p < q; p ++){
		scanf("%d",p);
	}
	return OK;
}
int ListLength_Sq( SqList *L){
	return L -> length;
}
Status ListEmpty_Sq(const SqList *L){
	if (L -> length == 0){
		return TRUE;
	}else{
		return FALSE;
	}
}
Status DestroyList_Sq( SqList *L){
	free( L -> elem);
	L -> length = 0;
	L -> listSize = 0;
}

Status ClearList_Sq( SqList *L){
	memset( L -> elem,0x00,L -> listSize);
	L -> listSize = 0;
	L -> length = 0;
	return OK;
	for(int i = 0;i < L -> listSize; i++){
		printf("%d\t",L -> elem[i]);
	}
}
Status GetElem_Sq( SqList *L , int i , ElemType *e){
	if( i < 0 || i > L -> length){
		return ERROR;
	}else{
		*e = L -> elem[i - 1];
		return OK;
	}
}
int compare(const ElemType *e1, const ElemType *e2){
	if( *e1 == *e2){
		return 0;
	}else if( *e1 < *e2){
		return 1;
	}else{
		return -1;
	} 
}
Status LocateElem_Sq(const SqList *L ,const ElemType *e ,Status (*compare) (const ElemType *,const ElemType *)){
	int i = 0;
	int flag = 0;
	ElemType *p = NULL;
	for( i = 0, p = L -> elem ; i < L-> length; i++ ){
		if(!(*compare)(p ++,e)){
			flag = 0;
			break;
		}else{
			flag = 1;
		}
	}
	if(flag == 1){
		return 0;
	}else{
		return i + 1;
	}
}
Status PriorElem_Sq(const SqList *L ,const ElemType *cur_e, ElemType *pre_e){
	int loc = 0;
	// L -> elem == NULL
	if (! L -> elem){
		return ERROR;
	}else{// L -> elem != NULL
		loc = LocateElem_Sq(L,cur_e,compare);
		if(loc != 0 && loc != 1 ){// it is not first elem
			*pre_e = L -> elem[loc - 2];
		}else{
			printf("The element %d is not exist or is the first element",*cur_e);
		}
	}
}
Status NextElem_Sq(const SqList *L ,const ElemType *cur_e, ElemType *next_e){
	int loc = 0;
//	int length = ListLength_Sq(L);
	int length = L -> length;
	if (! L -> elem){
		return ERROR;
	}else{// L -> elem != null
		loc = LocateElem_Sq(L,cur_e,compare);
		if(loc != 0 && loc != length){
			*next_e = L -> elem[loc];
			return OK;
		}else{
			printf("The element %d is not exist or is the last element",*cur_e);
			return ERROR;
		}
	}
}
Status ListInsert_Sq( SqList *L , int i , const ElemType *e){
	ElemType temp = 0;
	if ( i < 0 || i > L -> length){
		return ERROR;
	}else{
		for( int flag = L -> length ; flag > L -> length - i + 1;flag --){
			temp = L -> elem[flag + 1];
			L -> elem [flag + 1] = L -> elem[flag];
			L -> elem [flag] = temp;
		}
		L -> elem[i] = *e;
		return OK;
	}
}
Status ListDelete_Sq( SqList *L , int i , ElemType *e){
	ElemType temp = 0;
	*e = L -> elem[i];
	for( int flag = i;flag < L -> length; flag ++){
		temp = L -> elem[flag - 1];
		L -> elem[flag - 1] = L -> elem[flag];
		L -> elem[flag] = temp;
	}
	L -> length --;
	return *e;
}
Status ListTraverse_Sq(const SqList *L , Status (*pvisit)(const ElemType *)){
	for(int i = 0;i < L -> length; i ++){
		outElem_Sq( L -> elem[i]);
	}
}
Status outElem_Sq(const ElemType e){
//	if ( e != NULL){
		printf("%d\n", e);
//	}
	return OK;
}

