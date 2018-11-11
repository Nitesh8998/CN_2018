/*------------- By G S Nitesh Narayana CED16I044 IIITDM----*/


//#include<stdio.h>
#include"checker.h"
//#include<string.h>

int main()
{
	printf("Enter the size of the key\n");
	int KeyS;
	scanf("%d",&KeyS);
	char Key[KeyS];
	printf("\n ENter the size of the data\n");
	int DataS;

	scanf("%d",&DataS);
	char Data[DataS];
	int EncodeS=DataS+KeyS-1;


	char Encode[EncodeS];

	input(Encode,Key,Data,DataS,KeyS);

	printf("\n This is the Encoded\n");
	puts(Encode);

	char Rem[KeyS];

	Get_Remainder(Encode,Key,EncodeS,KeyS,Rem);		
	
	Creat_encode(Rem,DataS,Encode,EncodeS);

	printf("\n This is the data to be sent %s",Encode);
	return(0);

}
