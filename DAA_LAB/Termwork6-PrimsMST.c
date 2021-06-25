#include <stdio.h>
#include <stdlib.h>
#define I 32000

void MST(int **cost,int n)
{
    int i,j,k,u,v,min = I,tc=0;
    int near[n+1],mst[2][n-1];
    for(i=1;i<=n;i++)near[i] = I;
    for(i=1;i<=n;i++){
        for(j=i;j<=n;j++){
            if(cost[i][j]<min){
                min = cost[i][j];
                u = i;
                v = j;
            }
        }
    }
    mst[0][0] = u;
    mst[1][0] = v;
    near[u] = near[v] = 0;
    for(i=1;i<=n;i++){
        if(near[i]!=0){
            if(cost[i][u]<cost[i][v])
                near[i] = u;
            else
                near[i] = v;
        }
    }

    for(i=1;i<n-1;i++)
    {
        min = I;
        for(j=1;j<=n;j++)
        {
            if(near[j]!=0 && cost[j][near[j]] < min)
            {
                min = cost[j][near[j]];
                k = j;
            }
        }
        mst[0][i] = k;
        mst[1][i] = near[k];
        near[k] = 0;

        for(j=1;j<=n;j++){
            if(near[j]!=0 && cost[j][k] < cost[j][near[j]])
                near[j] = k;
        }
    }
    printf("\nMinimum Cost Spanning Tree:\n");
    for(i=0;i<n-1;i++){
        printf("(%d,%d) with cost %d\n",mst[0][i],mst[1][i],cost[mst[0][i]][mst[1][i]]);
        tc = tc + cost[mst[0][i]][mst[1][i]];
    }
    printf("Total cost:%d",tc);


}

int main()
{
    int n,e,i,j,**cost,src,dest,wt;
    printf("Enter the number of vertices:");
    scanf("%d",&n);
    cost = (int**)malloc((n+1)*sizeof(int*));
    for(i=0;i<=n;i++)
        cost[i] = (int *)malloc((n+1)*sizeof(int));

    for(i=1;i<=n;i++){
        for(j=1;j<=n;j++){
            cost[i][j] = I;
        }
    }

    printf("Enter the number of edges:");
    scanf("%d",&e);
    for(i=0;i<e;i++)
    {
        printf("Enter the src,dest and wt of edge %d:",i+1);
        scanf("%d%d%d",&src,&dest,&wt);
        cost[src][dest] = wt;
        cost[dest][src] = wt;
    }

    MST(cost,n);
    return 0;
}
