#include<stdio.h>
#include<stdlib.h>
#include<time.h>


void swap(int* a, int* b)
{
    int t = *a;
    *a = *b;
    *b = t;
}


int partition (int *arr, int low, int high)
{
    int pivot = arr[(low+high)/2];
    while(low <= high)
    {
        while(arr[low]<pivot){
            low++;
        }
        while(arr[high]>pivot){
            high--;
        }
        if(low<=high){
            swap(&arr[low],&arr[high]);
            low++;
            high--;
        }
    }
    return low;
}


void quickSort(int arr[], int low, int high)
{
    if (low < high)
    {
        int pi = partition(arr, low, high);
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi, high);
    }
}


int main()
{
    int n,*arr,i;
    time_t start,end;
    printf("Enter the size of the array:");
    scanf("%d",&n);
    arr = (int*)malloc(n*sizeof(int));
    for(i=0;i<n;i++){
        arr[i] = rand()%100;
    }

    printf("\nArray before Sorting:\n");
    for(i=0;i<n;i++){
        printf("%d ",arr[i]);
    }
    for(i=0;i<100000;i++)
    start = clock();
    quickSort(arr, 0, n - 1);
    end = clock();
    printf("\nArray before Sorting:\n");
    for(i=0;i<n;i++){
        printf("%d ",arr[i]);
    }
    printf("\nExecution time:%.2lf",(double)(end - start)/CLOCKS_PER_SEC);
    return 0;
}
