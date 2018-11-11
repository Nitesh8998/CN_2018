/*------------- By G S Nitesh Narayana CED16I044 IIITDM----*/


#include<stdio.h>


#define COLOR_NONE "\033[m"
#define COLOR_RED "\033[1;31m"
#define MAX 100
//void Initialize(int *, int ); // to intialize the bitstuffing array

int main(int argc, char ** argv)
{

	int arr[MAX];
	unsigned long buf_size = 0;
    	 char *buff;
	



	printf("\n Enter the frame\n");
	 
	getline(&buff, &buf_size, stdin);

	printf("\n this is the frame you entered\n %s",buff);

	int i=0,count1=0,k=0;
	for(i=0;i<buf_size;i++)
	{
		if(buff[i]=='1')
		{
			count1++;
			arr[k++]=1;

			if(count1==5)
			{
				arr[k++]=0;
				count1=0;
			}
		}

		else if(buff[i]=='0')
		{
			count1=0;
			arr[k++]=0;
		}
			
	}

	printf("\n this is the stuffed stuff\n");
	count1=0;
	 for(i=0;i<k;i++)
         {
                 if(arr[i]==1)
                 {
                         count1++;
                        printf("%d",arr[i]);

                         if(count1==5)
                         {
                                 printf(COLOR_RED "%d" COLOR_NONE ,arr[++i]);
                                 count1=0;
                         }
                 }

                 else if(arr[i]==0)
		 {
			 count1=0;
			 printf("%d",arr[i]);
		 }
         }

	return 0;

}
