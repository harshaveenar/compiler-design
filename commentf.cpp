#include<stdio.h> 
#include<conio.h> 
int main()
{
	char h[30]; 
	int i=2,a=0; 
	printf("\n Enter comment:");
	gets(h); 
	if(h[0]=='/') 
	{
		if(h[1]=='/')
			printf("\n It is a comment"); 
		else if(h[1]=='*') 
		{		
			for(i=2;i<=30;i++)
			{
				if(h[i]=='*'&&h[i+1]=='/')
				{
					printf("\n It is a comment"); 
					a=1; 
					break;	
				}
				else 
					continue; 
			} 
			if(a==0)
				printf("\n It is not a comment");
		}
		else
			printf("\n It is not a comment");
	}
	else 
		printf("\n It is not a comment");
}

