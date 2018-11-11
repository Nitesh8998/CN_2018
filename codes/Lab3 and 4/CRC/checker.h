/*------------- By G S Nitesh Narayana CED16I044 IIITDM----*/


#include<stdio.h>
#include<string.h>


void input(char* Edata,char* divisor,char* devidend, int lengthD, int lengthDi)
{
	printf("Enter the Data to be encoded in 1s and 0rs no spaces!\n");
	getchar();
	fgets(devidend,lengthD+1,stdin);
	int i;
puts(devidend);	
	strncpy(Edata,devidend,lengthD);
	for(i=lengthD;i<lengthD+lengthDi-1;i++)
		Edata[i]='0';
	printf("Enter the key for the data\n");
	getchar();
	fgets(divisor,lengthDi+1,stdin);

	}

int XOR( char *Devisor, char * temp,int keyS )
{
	int i ;
	char result[keyS];
	for(i=0;i<keyS;i++)
		if(Devisor[i]==temp[i])
			result[i]='0';
		else
			result[i]='1';

	//strcpy(temp,result);
	
	int num_zero=0;
	printf("result");
	puts(result);
	while(num_zero<=keyS)

	{
		if(result[num_zero]=='0')
		num_zero++;
		else
		break;
	}
	int j;
	for(i=num_zero,j=0;i<keyS;i++)
		temp[j++]=result[i];

	printf("temp:%s and zero:%d",temp,num_zero);
	return(num_zero);
	

}

void Get_Remainder(char * Edata, char* Key ,int EdataS, int KeyS,char * Rem)
{
	int i=KeyS,zero;

	// i am not considering keys starting with zeros
	
	char temp[KeyS];
	strncpy(temp,Edata,KeyS);
	while(i<EdataS)
	{
		if(temp[0]=='1')
		{
			printf("before XOR:");
			puts(temp);
			zero=XOR(Key,temp,KeyS);
			printf("when zero is %d : %d\n",zero,i);
			
			while(zero>0)   
			{
				temp[KeyS-zero--]=Edata[i++];
			}
			//strcat(temp,Edata[i]);
			printf("next dev z%s\n",temp);
		}

		else
		{
			char dummy[i];
			int j;
			for(j=0;j<i;j++)
				dummy[j]='0';
			zero=XOR(dummy,temp,KeyS);
			printf("when zero in zero is %d : %d\n",zero,i);
			
			while(zero-->0)
				temp[KeyS-zero--]=Edata[i++];

			//strcat(temp,Edata[i]);
		}
			
	}

	strcpy(Rem,temp);
	printf("\n this is the reminder");
	puts(Rem);
}

void Creat_encode(char* Rem, int lengthD, char* Encode, int EncodeS)
{
	int i,j;
	for(i=lengthD,j=0;i<EncodeS;i++)
                Encode[i]=Rem[j++];
}

