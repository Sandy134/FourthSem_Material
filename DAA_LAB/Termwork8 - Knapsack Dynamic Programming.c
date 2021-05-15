#include <stdio.h>
#include <stdlib.h>

void knapsack(int items,int *wts,int *profit,int cap)
{
    int **dp,i,j;

    dp = (int**)malloc((items+1)*sizeof(int*));
    for(i=0;i<items+1;i++){
        dp[i] = (int*)malloc((cap+1)*sizeof(int));
    }

    for(i=0;i<=items;i++)
    {
        for(j=0;j<=cap;j++)
        {
            if(i==0 || j==0)
                dp[i][j] = 0;
            else if(j>=wts[i])
            {
                int rem = j - wts[i];
                if(dp[i-1][j]<dp[i-1][rem]+profit[i])
                {
                    dp[i][j] = dp[i-1][rem]+profit[i];
                }
                else
                {
                    dp[i][j] = dp[i-1][j];
                }
            }
            else
                dp[i][j] = dp[i-1][j];
        }
    }

    printf("\nMaximum Profit:%d\n",dp[items][cap]);
}

int main()
{
    int items,*wts,*profit,capacity,i;
    printf("Enter the number of items:");
    scanf("%d",&items);

    wts = (int*)malloc((items+1)*sizeof(int));
    profit = (int*)malloc((items+1)*sizeof(int));

    for(i=1;i<=items;i++){
        printf("Enter the weight and profit of item %d:",i);
        scanf("%d%d",&wts[i],&profit[i]);
    }

    printf("Enter the knapsack(bag) capacity:");
    scanf("%d",&capacity);

    knapsack(items,wts,profit,capacity);

}
