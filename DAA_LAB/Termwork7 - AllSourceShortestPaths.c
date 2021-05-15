#include<stdio.h>
#include<stdlib.h>
#define INF 30000


int min(int a,int b)
{
  if(a<b)
   return a;
  else
   return b;
}


void shortestPaths(int **graph,int ver)
{
 int i,j,k;
 for(k=0;k<ver;k++){
    for(i=0;i<ver;i++){
        for(j=1;j<ver;j++){
         if(i!=j)
            graph[i][j]=min(graph[i][j],graph[i][k]+graph[k][j]);
     }
   }
 }
}

int main()
{
    int ver,**graph,edges,i,j;
    printf("Enter the number of vertices:");
    scanf("%d",&ver);
    graph = (int**)malloc(ver*sizeof(int*));
    for(i=0;i<ver;i++)
        graph[i]=(int*)malloc(ver*sizeof(int));

    for(i=0;i<ver;i++){
        for(j=0;j<ver;j++){
            if(i==j)
                graph[i][j]=0; //distance of a vertex to itself is 0
            else
                graph[i][j]=INF; //Initially let them be infinity
    }
    }

    printf("Enter the number of edges:");
    scanf("%d",&edges);
    for(i=0;i<edges;i++){
        int s,d,wt;
        printf("Enter the source vertex,destination vertex and weight of the edge:");
        scanf("%d%d%d",&s,&d,&wt);
        graph[s][d]=wt;
    }

    printf("\nAll source paths before applying Floyd's algorithm:\n");
    for(i=0;i<ver;i++){
        for(j=0;j<ver;j++){
            if(graph[i][j]==INF)
                printf("INF\t");
            else
                printf("%d\t",graph[i][j]);
        }
        printf("\n");
    }

    shortestPaths(graph,ver);

    printf("\nAll source shortest paths after applying Floyd's algorithm:\n");
    for(i=0;i<ver;i++){
        for(j=0;j<ver;j++){
            if(graph[i][j]==INF)
                printf("INF\t");
            else
                printf("%d\t",graph[i][j]);
        }
        printf("\n");
    }


}
