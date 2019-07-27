//MATRIX MULTIPLICATION
#include<iostream.h>
#include<conio.h>
void main()
{
clrscr();;
int m,n;
int A[6][6],B[6][6],C[6][6], i,j,k;
cout<<"\nENTER THE NO OF ELEMENTS OF MATRIX 1";
cin>>m;
cout<<"\NENTER THE NO OF ELEMENTS OF MATRIX 2";
cin>>n;
if(n==m)
{
cout<<"\n\tEnter contents of 1st matrix(max6) :\n ";
for(i=0;i<m;i++)
	for(j=0;j<m;j++)
	cin>>A[i][j];
cout<<"\n\tEnter contents of 2nd matrix(max 6) : \n";
for(i=0;i<n;i++)
	for(j=0;j<n;j++)
	cin>>B[i][j];

cout<<"\n\tProduct of the two matrix is: ";
for(i=0;i<m;i++)
{
	cout<<"\n";
	for(j=0;j<m;j++)
		{
		C[i][j]=0;
		for(k=0;k<m;k++)
		C[i][j]=C[i][j]+(A[i][j]*B[i][j]);
		cout<<C[i][j]<<"\t";
		}
}
}
else
cout<<"\n Matrix cannot be multiplied";
getch();
}

