#include<stdio.h>
#include<stdlib.h>
#include<time.h>

void swap(int *a,int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

void heapify(int *arr, int n, int i)
{
    int largest = i;
    int l = 2 * i + 1;
    int r = 2 * i + 2;

    if (l < n && arr[l] > arr[largest])
        largest = l;

    if (r < n && arr[r] > arr[largest])
        largest = r;

    if (largest != i) {
        swap(&arr[i], &arr[largest]);
        heapify(arr, n, largest);
    }
}


void heapSort(int *arr, int n)
{
    for (int i = n / 2 - 1; i >= 0; i--)
        heapify(arr, n, i);

    for (int i = n - 1; i > 0; i--) {
        swap(&arr[0],&arr[i]);
        heapify(arr, i, 0);
    }
}

int main()
{
    int n,*arr,i;
    time_t start,end;
    printf("Enter the size of an array:");
    scanf("%d",&n);
    arr = (int*)malloc(n*sizeof(int));

    for(i=0;i<n;i++){
        arr[i] = rand()%100;
    }

    printf("\nArray before Sorting:\n");
    for(i=0;i<n;i++){
        printf("%d ",arr[i]);
    }

    start = clock();
    for(i=0;i<1000000;i++)
    heapSort(arr, n);
    end = clock();
    printf("\nArray after Sorting:\n");
    for(i=0;i<n;i++){
        printf("%d ",arr[i]);
    }
    printf("\nExecution Time:%.2lf",(double)(end-start)/CLOCKS_PER_SEC);


}
