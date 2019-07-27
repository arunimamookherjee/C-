//BINARY SEARCH IN ARRAY

#include<iostream.h>
#include<conio.h>
#include<stdlib.h>
#include<process.h>
#include<stdio.h>

class hospital
{
char name[20];
int patient_id;
public:

	int get_patientid()
	{	return patient_id; }

	void get_input()
	{
	char ch;

	cout<<"\nNAME : ";   gets(name);
	cout<<"\nPATIENT ID : "; cin>>patient_id;
	}
	void display()
	{
	cout<<"\nPATIENT ID : ";cout<<patient_id;
	cout<<"\nNAME	    : ";cout<<name;
	}
}H[25]; //CLASS DEFINITION OVER

int Bsearch(hospital hos[],int size,int item)
//FUNCTION TO PERFORM BINARY SEARCH
{
	int beg=0,last=size-1,mid;

	while(beg<=last)
	{
		mid=(beg+last)/2;

		if(item==hos[mid].get_patientid())
		//IF ORDER NO OF ELEMENT MATCHES ORDER NO TO BE SEARCHED

			return mid;

		else if(item>hos[mid].get_patientid())
			beg=mid+1;
		else
			last=mid-1;
	}
	return -1;//RECORD NOT FOUND

}

void main()
{
	clrscr();

	hospital hosp[50];
	//ARRAY OF OBJECTS OF CLASS 'COMPUTER'( CAN HOLD MAX 50 ELEMENTS )
	int item,n,index;

	cout<<"Enter desired array size (max. 50)...";
	cin>>n;

	cout<<"\nEnter records in ascending order of order number \n";

	for(int i=0;i<n;i++)
	{
		hosp[i].get_input();//GET INPUT FOR Ith INPUT
		cout<<endl;
	}

	cout<<"\nEnter order number of record to be searched for...";
	cin>>item;

	index=Bsearch(hosp,n,item);
	//GET INDEX OF RECORD TO BE SEARCHED IN ARRAY

	if(index==-1) //RECORD NOT FOUND
		cout<<"\nSorry!! Given element could not be found.\n";
	else
		cout<<"\nElement found at index : "<<index<<",Position : "<<index+1<<endl;

	getch();
}




