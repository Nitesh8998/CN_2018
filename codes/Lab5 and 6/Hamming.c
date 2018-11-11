/*------------- By G S Nitesh Narayana CED16I044 IIITDM----*/

#include<stdio.h>
#include<string.h>
#include<math.h>

int R_Cal(int);

int Parody(int sum,char*parody);
void make_Hamming(int* arr, int n,char *parody);

#define MAX 100
#define COLOR_NONE "\033[m"
#define COLOR_RED "\033[1;31m"

int main (int argc, char ** argv)
{

	int arr[MAX];
	unsigned long buf_size = 0;
    	 char *buff;
	



	printf("\n Enter the frame\n");
	 
	getline(&buff, &buf_size, stdin);

	printf("\n this is the frame you entered\n %s",buff);

	int r = R_Cal(strlen(buff)-1);
	
	printf("\n THis is the number of redundants bits needed for your dat: %u %u",buf_size,r);
	


	 int k=1,t,i;
	 double j=0;
	for(i=strlen(buff)+1;i>=0;i--)
	{
		if(pow(2,j)==(double)(k))
			{
				arr[k++]=99;
				j++;
				
			}
		if(buff[i]=='1')
			arr[k++]=1;

		

		else if(buff[i]=='0')
				arr[k++]=0;
		
			
	}


	make_Hamming(arr,k,"ODD");


	j=0;
	char logg[100];
	printf("\n%s %d\n","this is th hamming code ",k );
	for(i=1;i<k;i++)
	{
		if(pow(2,j)==(double)(i))
			{
				//printf(COLOR_RED "%d" COLOR_NONE ,arr[i]);
				sprintf(buff,COLOR_RED "%d" COLOR_NONE,arr[i]);
				strcat(logg,buff);
				j++;
			}
		else
			{
				//printf("%d",arr[i]);
				sprintf(buff,"%d",arr[i]);
				strcat(logg,buff);
			}
		
	}
	// for(i=strlen(logg)-1;i>=0;i--)
	// {
	// 	printf("%c",logg[i] );
	// }
	printf("%s\n",logg );
	return 0;
}

int R_Cal(int m)
{
	double r=2;

	while(1)
	{
		if(pow(2,r)>(m+r-1))
			break;
		
	//	printf("\n %lf",r);
		r++;
	}

	return (int)r;
}


int Parody(int sum,char*parody)
{
	if(strcmp(parody,"ODD")==0)
		{
			if((sum%2)!=1)
				return 1;
			else 
				return 0;
		}

	else
	{
		if((sum%2)==0)
			return 0;
		else 
			return 1;
	}
}

void make_Hamming(int* arr, int n,char *parody)
{
	int i,sum1=0,t,t1,count;
	double j=0;
	for(i=1;i<n;i++)
	{
		if(pow(2,j)==i)
			{
				sum1=0;
				t1=i;
				while(t1<n){


					
					count=0;
					while(count<i && t1<n)
					{


					if(arr[t1]==1)
						{
							sum1++;
						
						}
						t1++;
						count++;
					}
				
				t1+=i;
				}
				//arr[i]=Parody(sum1,parody);
				arr[i]=(sum1%2==0)?0:1;
				j++;
			}
		
		
	}
}