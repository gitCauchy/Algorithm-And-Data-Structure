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
	int e = 0;
	int s1 = CreateList_Sq(&LA);
	int length_of_LA = ListLength_Sq(&LA);
	printf("length is %d\n",length_of_LA);
	int x = 7;
	int s2 = ListInsert_Sq(&LA,3,&x);
	for(int i = 1;i <=length_of_LA + 1;i ++){
		int s3 = GetElem_Sq(&LA,i,&e);
		printf("a[%d] = %d\n",i,e);
	}
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
	ElemType *newbase = NULL;
	ElemType *p = NULL;
	ElemType *q = NULL;
	if(! L -> elem){
		fprintf(stderr,"List is not exists!Please initialize list first!\n");
		return ERROR;
	}
	if( i < 1 || i > L -> length + 1){
		fprintf(stderr,"Insert Failed,Location Of Insert Must In This List");
		return ERROR;
	}
	// 分配一块内存
	if(L -> length >= L -> listSize ){
		newbase = (ElemType *) realloc(L -> elem,(L->listSize + LIST_INCREMENT) * sizeof(ElemType));
		// 如果分配失败
		if(!newbase){
			exit(OVERFLOW);
		}
		L -> elem = newbase;
		L -> listSize += LIST_INCREMENT;
	}
	q = L -> elem + i - 1;
	int testq = *q;
	for(p = L -> elem + L -> length ;p > q; p --){
		*p = *(p-1);
	}
	*p = *e;
	++ L -> length;
	return OK;
}
Status ListDelete_Sq( SqList *L , int i , ElemType *e){
	ElemType *p = NULL;
	ElemType *q = NULL;
	if(! L -> elem){
		return ERROR;
	}
	if(i < 0 || i > L -> length){
		fprintf(stderr,"ERROR,i Should Larger Than 0,And Smaller Than Length Of List");
	}
	q = L -> elem + L -> length - 1; 
	*e = L -> elem[i - 1]; 
	for(p = L -> elem + i - 1;p < q; p ++){
		*p = *(p + 1);
	}
	-- L -> length;
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
