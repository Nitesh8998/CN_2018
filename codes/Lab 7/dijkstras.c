/*------------- By G S Nitesh Narayana CED16I044 IIITDM----*/


#include<stdio.h>

/*typedef struct Graph
{
	int d;
	int p;
}G;*/

int main()
{
	printf("\n Enter the number of nodes you want to enter\n");
	int n, V;
	
	scanf("%d",&V);
	V++;
	
	int Graph[V][V],u,v,w;

	printf("\n Enter the number of edges you want to enter \n");
	scanf("%d",&n);


	printf("\n Enter the u , v , w values");

	for(int i=0;i<V;i++)
	for(int j=0;j<V;j++)
	Graph[i][j]=9999;

	
	for(int i=0;i<n;i++)
	{
		scanf("%d %d %d",&u,&v,&w);

		Graph[u][v]=w;
		
		//Graph[v][u]=w;
	}

	int source;
	printf("\n Enter the source \n");
	scanf("%d",&source);

	int dist[V],fin[V];


	for(int i=0;i<V;i++)
	{
		for (int j = 0; j < V; ++j)
		
		
		if(Graph[i][j]!=9999)
		printf("%d_%d :%d\n",i,j,Graph[i][j]);

		
		
		
	}

	for (int i = 0; i < V; i++)
        dist[i] =Graph[source][i], fin[i] = 0;


	dist[source]=0;
		
		int flag=0;
	for(int k=0;k<V-1;k++)
	{
		int min_i;
		int min=9999;

			flag=0;

		for(int i=0;i<V;i++)
		{
			if(min>Graph[source][i] && fin[i]==0)
				{
					min=Graph[source][i];
					min_i=i;
					printf("\nfor min%d   min_i%d\n",min,min_i );
				flag=1;
				}
				
		}

		if(!flag)
			break;
// 		printf("min %d\n fin %d",min_i ,fin[min_i]);
// 		fin[min_i]=1;
// printf("min %d\n fin %d",min_i ,fin[min_i]);
		
		for(int i=0;i<V;i++)
	
		if(!fin[i] && dist[i]!=9999 && (dist[min]+Graph[min][i]<dist[i]) && Graph[min][i]!=9999)
		dist[min]=Graph[min][i]+dist[i];

		//printf("dist u:%d v:%d dist:%d\n");
	printf("\n Vertex\t Distance\n");
	for(int i=0;i<V;i++)
	if(dist[i]!=9999)
	printf("%d\t%d\n",i,dist[i]);
	}

				
	printf("\n This is the shortest distance from the source %d\n",source);
	printf("\n Vertex\t Distance\n");
	for(int i=0;i<V;i++)
	if(dist[i]!=9999)
	printf("%d\t%d\n",i,dist[i]);
		return 0;
}
