/*
 * I am assuming that each frame size is decided by the sender
 * ------------- By G S Nitesh Narayana CED16I044 IIITDM----
 */


#include<stdio.h>
#include<string.h>

#define COLOR_NONE "\033[m"
#define COLOR_RED "\033[1;31m"
#define MAX 100
int main()
{
	int fsize;

	int dsize;
	
	printf("\n Enter the number of frames for your data :\n");
	scanf("%d",&fsize);

	int i=0 ,j,k=0 ,arr[MAX],t;

	// character count taking in 
	do
	{
		printf("\nEnter the size of the %d frame\n",i++);
		scanf("%d",&dsize);
		printf("\n Enter the frame data you have to enter %d more numbers\n",dsize-1);
		arr[k++]=dsize;	
		for(j=1;j<dsize;j++)
		scanf("%d",&arr[k++]);
		
	}while(i<fsize);
	// taking in done 
	
	printf("\n this is the data after implementibg character count\n");
	j=0,t=0;
	for(i=0;i<k;i++)
	{	
		if(t==j)
		{
			j=arr[i];
			printf(COLOR_RED "%d "COLOR_NONE,arr[i]);
			t=0;
		}
		else
		printf("%d ",arr[i]);

		t++;
	}
	
	// extracting each frame
	printf("\n Each frame given\n");
	j=0,t=0;
	for(i=0;i<k;i++)
         {
                 if(t==j)
                 {
                         j=arr[i];
                        printf("\n");
               		t=0;
	       	 }
                 else
                 printf("%d ",arr[i]);

		 t++;
         }

	return(0);
}

