#include <stdio.h>
#include <stdlib.h>
#include<time.h>

int temp[100];

void merge(int *arr,int low,int mid,int high)
{
    int i=low,j=mid+1,k=low;
    while(i<=mid && j<=high)
    {
        if(arr[i]<=arr[j]){
            temp[k++] = arr[i++];
        }
        else
            temp[k++] = arr[j++];
    }


    while(j<=high){
        temp[k++] = arr[j++];
    }


    while(i<=mid){
        temp[k++] = arr[i++];
    }


    for(i=low;i<=high;i++){
        arr[i] = temp[i];
    }

}

void mergeSort(int *arr,int low,int high)
{
    if(low<high)
    {
        int mid = (low+high)/2;
        mergeSort(arr,low,mid);
        mergeSort(arr,mid+1,high);
        merge(arr,low,mid,high);
    }
}

int main()
{
   int n,*arr,i;
   time_t start,end;
   printf("Enter the array size:");
   scanf("%d",&n);
   arr = (int*)malloc(n*sizeof(int));
   for(i=0;i<n;i++){
      arr[i] = rand()%100+1;
   }
   printf("\nArray before sorting:\n");
   for(i=0;i<n;i++){
        printf("%d ",arr[i]);
   }
   start = clock();
   for(i=0;i<100000;i++)
   mergeSort(arr,0,n-1);
   end = clock();
   printf("\nArray before sorting:\n");
   for(i=0;i<n;i++){
        printf("%d ",arr[i]);
   }
   printf("\nExecution time:%.2lf",(double)(end-start)/CLOCKS_PER_SEC);
}
