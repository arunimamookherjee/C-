//TO SWAP EVERY TWO CONSECUTIVE ELMENTS IN 1D NUMERIC ARRAY

#include<iostream.h>
#include<conio.h>

void main()
{       clrscr();

	int hosp_id[50] , i , n , temp;

	cout<<"Enter array siz
	0e "<<endl;
	cin>>n;

	cout<<"ENTER ID NUMBER "<<endl;

	for(i=0;i<n;i=i+1)
	{
		cout<<"Enter hospital id "<<endl;
		cin>>hosp_id[i];
	}

	cout<<"Original array "<<endl;

	for(i=0;i<n;i=i+1)
	{
		cout<<hosp_id[i]<<endl;
	}

	for(i=0;i<n-1;i=i+2)         //TO SWAP EVERY 2 CONSECUTIVE ELEMENTS OF ARRAY
	{
		temp=hosp_id[i];
		hosp_id[i]=hosp_id[i+1];
		hosp_id[i+1]=temp;
	}

	cout<<"New array "<<endl;

	for(i=0;i<n;i=i+1)
	{
		cout<<hosp_id[i]<<endl;
	}

	getch();
}
