//PALINDROME
#include <iostream.h>
#include <conio.h>
#include <string.h>
void main()
{
	clrscr();
	int i,j,count=0;
	char word[20],word1[20];
	cout<<"ENTER A WORD TO CHECK WHETHER A PALINDROME OR NOT :"<<endl;
	cin.getline(word,20);
	int l=strlen(word);
	strcpy(word1,word);
	for(i=0,j=l-1;i<l,j>=0;i++,j--)
	{
		if(word[i]!=word1[j])
		{
			count=1;
			break;
		}
	}

	if(count==1)
	{
		cout<<"OOPS THE WORD IS NOT A PALINDROME"<<endl;
	}
	else if(count==0)
	{
		cout<<"THE WORD IS A PALINDROME "<<endl;
	}
	getch();
}