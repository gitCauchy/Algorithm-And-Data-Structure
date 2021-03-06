#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define SIZE 10
#define OK 0
#define ERROR -1

typedef int Status;
typedef int* ElemType;

Status DataStore(ElemType *Data);
Status BubbleSort(ElemType *Data);
int GetDataLength(ElemType *Data);
Status DataDisplay(ElemType *Data);

int main(int argc,char* argv[]){
	ElemType Data;
	DataStore(&Data);
	printf("The data before sort are:\n");
	DataDisplay(&Data);
	BubbleSort(&Data);
	printf("The data after sort are:\n");
	DataDisplay(&Data);
}
Status DataStore(ElemType *Data){
	ElemType p = NULL;
	ElemType q = NULL;
	*Data = (ElemType) malloc (SIZE * sizeof(ElemType));
	memset(*Data,0,SIZE * sizeof(ElemType));
	q = *Data + SIZE;
	printf("please input the data which you want to sort:\n");
	for(p = *Data; p < q ; p ++){
		scanf("%d",p);
	}
}
Status BubbleSort(ElemType *Data){
	int temp = 0;
	for(int i = 0; i < SIZE - 1; i ++){
		for( int j = 0; j < SIZE - i - 1; j ++){
			if((*Data)[j] > (*Data)[j + 1]){
				temp = (*Data)[j + 1];
				(*Data)[j + 1] = (*Data)[j];
				(*Data)[j] = temp;
			}
		}
	}
}
Status GetDataLength(ElemType *Data){

}
Status DataDisplay(ElemType *Data){
	ElemType p = NULL;
	ElemType q = *Data + SIZE;
	for( p = *Data; p < q; p ++){
		printf("%d ",*p);
	}
	printf("\n");
}
