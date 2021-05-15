#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void swap(int *a,int *b){
    int temp;
    temp = *a;
    *a = *b;
    *b = temp;
}

void insertion(int *arr,int n)
{
    int i,j;
    for(i=1;i<n;i++){
        for(j=i-1;j>=0;j--){
            if(arr[j]>arr[j+1]){
                swap(&arr[j],&arr[j+1]);
            }
            else
                break;
        }
    }
}

int main()
{
   int n,i;
   int *arr;
   printf("Enter the size of the array:");
   scanf("%d",&n);
   arr = (int*)malloc(n*sizeof(int));
   for(i=0;i<n;i++){
        arr[i] = rand()%100;
   }
   printf("Array before Sorting:\n");
   for(i=0;i<n;i++){
        printf("%d ",arr[i]);
   }
   time_t start,end;
   start = clock();
   for(i=0;i<3000000;i++)
   insertion(arr,n);
   end = clock();
   printf("\nArray after Sorting:\n");
   for(i=0;i<n;i++){
        printf("%d ",arr[i]);
   }
   printf("\nExecution time:%.2lf",(double)(end-start)/CLOCKS_PER_SEC);
}
