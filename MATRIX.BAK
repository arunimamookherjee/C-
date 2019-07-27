//TO DISPLAY UPPER AND LOWER NUMBERS OF A DIAGONAL

#include<iostream.h>
#include<conio.h>

void main()
{
	clrscr();

	int mat[7][7],c,r,i,j,k,cn=0,ct;

	cout<<"Enter equal number of rows and columns"<<endl;
	cin>>r>>c;

	cout<<"Enter elements of matrix "<<endl;

	for (i=0;i<r;i++)
	{
		for(j=0;j<c;j++)
		{
			cout<<"Enter no ";
			cin>>mat[i][j];
		}
	}

	cout<<"Original matrix "<<endl;

	for (i=0;i<r;i++)
	{
		for(j=0;j<c;j++)
		{

			cout<<mat[i][j]<<'\t';
		}
		cout<<endl;
	}

	cout<<"ELEMENTS ABOVE THE MAJOR DIAGONAL "<<endl;

	ct=c;

	for (i=0;i<r;i++)
	{
		for(j=0;j<ct;j++)
		{
			cout<<mat[i][j]<<'\t';
		}

		cout<<endl;

		ct=ct-1;
	}

	cout<<endl;

	cout<<"ELEMENTS BELOW THE MAJOR DIAGONAL "<<endl;

	for(i=0;i<r;i++)
	{
		for(k=0;k<c-i-1;k=k+1)
		{
			cout<<'\t';
			cn++;

		}
		for(j=cn;j<c;j=j+1)
		{
			cout<<mat[i][j]<<'\t';
		}

		cout<<endl;

		cn=0;
	}

	getch();
}





