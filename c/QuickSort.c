#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define SIZE 10
#define OK 0
#define ERROR -1

typedef int Status;
typedef int* ElemType;

Status DataStore(ElemType *Data);
int GetDataLength(ElemType *Data);
Status quickSort(ElemType *Data, int left, int right);
Status DataDisplay(ElemType *Data);

int main(int argc,char* argv[]){
    // define a pointer for data array
    ElemType Data;
    DataStore(&Data);
    printf("The data before sort are:\n");
    DataDisplay(&Data);
    printf("The data after sort are:\n");
    quickSort(&Data,0,SIZE-1);
    DataDisplay(&Data);
    free(Data);
    return OK;
}
Status DataStore(ElemType *Data){

    ElemType p = NULL;
    ElemType q = NULL;
    *Data = (ElemType) malloc (SIZE * sizeof (ElemType));
    // initialize this array
    memset(*Data,0,SIZE * sizeof(ElemType));
    q = *Data + SIZE ;
    printf("please input the data which you want to sort\n");
    for( p = *Data; p < q; p ++){
        scanf("%d",p);
    }
}
Status DataDisplay(ElemType *Data){
    ElemType p = NULL;
    ElemType q = *Data + SIZE ;
    for ( p = *Data; p < q; p ++){
        printf("%d ",*p);
    }
    printf("\n");
}
Status swap(int *a, int *b){
    int temp;
    temp = *a;
    *a = *b;
    *b = temp;
    return 0;
}
Status quickSort(ElemType *Data, int left, int right){
    int i = left;
    int j = right;
    int temp = 0;
    if(i < j){
        temp = (*Data)[i];
        while(i != j){
            while(j > i && (*Data)[j] >= temp){
                j --;
            }
            (*Data)[i] = (*Data)[j];
            while(i < j && (*Data)[i] <= temp){
                i ++;
            }
            (*Data)[j] = (*Data)[i];
        }
        (*Data)[i] = temp;
        if(left <= i - 1){
            quickSort(Data,left,i - 1);
        }
        if(right >= j + 1){
            quickSort(Data,j + 1 ,right);
        }
    }
}


