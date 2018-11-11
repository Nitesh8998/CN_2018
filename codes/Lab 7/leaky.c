/*------------- By G S Nitesh Narayana CED16I044 IIITDM----*/

#include<stdio.h>


int main(int argc, char const *argv[])
{
	int n;

	printf("%s\n","enter the number of packets" );
	scanf("%d",&n);

	printf("Enter the packets sizes");

	int arr[n];
	for (int i = 0; i < n; ++i)
	{
		scanf("%d",&arr[i]);
	}

	printf("\n%s\n","This is yourpacket list " );
	for (int i = 0; i < n; ++i)
	{
		printf("\n%d",arr[i]);
	}

	int j=0;
	int bucket;
	printf("\n Enter the bucket size");
	scanf("%d",&bucket);
	int temp=bucket;
	int i=0;

	// preforming the algo
	while(1)
	{
		printf("\ntick no%d",i++);

		while(1)
		{
		if(arr[j]<temp)
			{
				temp-=arr[j];
				printf("\n Packet %dsent with size %d",j,arr[j++]);
			}

			// when the vucket size is less
			else
			{
					printf("%s\n","\ncannot send more refilling" );
					break;
				}

			printf("\n%s\n%d","Last bucket size",temp );
		}

		temp=bucket;

		// when wevery packet is sent
		if(j>=n)
		{
			printf("\n%s\n","All packets sent" );
			break;
		}
	}

	return 0;
}