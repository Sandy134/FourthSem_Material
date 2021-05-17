#include <stdio.h>
#include <stdlib.h>
#include<string.h>



void TargetSumSubsets(int *arr,int i,int *included,int sum,int target,int n)
{
   if(i==n){
        if(target == sum){
            int j;
            printf("{");
            for(j=0;j<n;j++){
                if(included[j]==1)
                    printf("%d ",arr[j]);
            }
            printf("}\n");
        }
        return;
   }
   included[i]=1;
   TargetSumSubsets(arr,i+1,included,sum+arr[i],target,n);
   included[i]=0;
   TargetSumSubsets(arr,i+1,included,sum,target,n);
}

int main()
{
    int n,*arr,target,i,*included;
    printf("Enter the size of the array:");
    scanf("%d",&n);
    arr = (int *)malloc(n*sizeof(int));
    included = (int*)malloc(n*sizeof(int));
    for(i=0;i<n;i++){
        included[i] = 0;
    }

    printf("Enter the array elements:");
    for(i=0;i<n;i++){
        scanf("%d",&arr[i]);
    }
    printf("Enter the target:");
    scanf("%d",&target);

    TargetSumSubsets(arr,0,included,0,target,n);

    return 0;
}
