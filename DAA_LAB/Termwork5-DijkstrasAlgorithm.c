#include <stdio.h>
#include <stdlib.h>
#define I 9999

void Dijkstra(int n,int s,int cost[100][100])
{
    int visited[n+1],i,j,sp[n+1],min,pred[n+1],count,next;
    for(i=1;i<=n;i++)
    {
        sp[i] = cost[s][i];
        pred[i] = s;
        visited[i] = 0;
    }

    sp[s] = 0;
    visited[s] = 1;
    count = 1;
    while(count < n - 1)
    {
        min = I;
        for(i=1;i<=n;i++)
        {
            if(sp[i] < min && !visited[i])
            {
                min = sp[i];
                next = i;
            }
        }
         visited[next] = 1;
        for(i=1;i<=n;i++)
        {
            if(!visited[i])
            {
                if(min+cost[next][i] < sp[i])
                {
                    sp[i] = min + cost[next][i];
                    pred[i] = next;
                }
            }

        }
        count++;
    }

    printf("\nShortest Path is:");
    for(i=1;i<=n;i++)
    {
        if(i!=s)
        {
                printf("\nDistance from %d to %d is : %d", s,i,sp[i]);
                printf("\nPath = %d", i);
                 j = i;
            do
            {
                j = pred[j];
                printf("<- %d",j);
            }while(j!=s);
        }
    }
}

int main()
{
    int cost[100][100],i,j,n,src;
    printf("Enter the no of nodes:");
    scanf("%d",&n);
    printf("Enter the cost matrix:");
    for(i=1;i<=n;i++)
    {
        for(j=1;j<=n;j++)
        {
            scanf("%d",&cost[i][j]);
            if(i!=j && cost[i][j]==0)
                cost[i][j] = I;
        }
    }
    printf("Enter the source vertex:");
    scanf("%d",&src);

    Dijkstra(n,src,cost);

    return 0;
}
