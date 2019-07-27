//SELECTION SORT IN ARRAY

#include<iostream.h>
#include<conio.h>
#include<stdio.h>

class hospital
{
char name[20];
int patient_id,TOT_bill;
public:

	int get_patientid()//ACECSSOR FUNCTION TO GET patient_id
	{	return patient_id; }

	void input()
	{
	char ch;

	cout<<"\nNAME : ";   gets(name);
	cout<<"\nPATIENT ID : "; cin>>patient_id;
	cout<<"\nBILL : "; cin>>TOT_bill;
	}
	void display()
	{
	cout<<"\nPATIENT ID : ";cout<<patient_id;
	cout<<"\nNAME	    : ";cout<<name;
	cout<<"\nBILL : "; cout<<TOT_bill;
	}


}; //CLASS DEFINITION OVER

void selsort(hospital hosp[],int size)
//FUNCTION TO PERFORM SELECTION SORT
{
	int small,pos;

	hospital tmp;

	for(int i=0;i<size;i++)
	{
		small=hosp[i].get_patientid();
		pos=i;

		for(int j=i+1;j<size;j++)
		/* TO SEARCH FOR ELEMENT WITH SMALLEST 'patient_id' IN REMAINING
		   UNSORTED ARRAY */
		{
			if(hosp[j].get_patientid()<small)
			//IF 'patient_id' OF Jth ELEMENT < 'SMALL'
			{
				small=hosp[j].get_patientid();//'SMALL' UPDATED
				pos=j;
				//POSITION OF ELEMENT WITH 'patient_id' < 'SMALL'
			}
		}

		/*SWAP Ith ELEMENT AND ELEMENT WITH LEAST 'patient_id' IN REMAINING
		  UNSORTED ARRAY */
		tmp=hosp[i];
		hosp[i]=hosp[pos];
		hosp[pos]=tmp;

		cout<<endl<<"array after pass"<<i+1<<"is"<<endl;

		for(j=0;j<size;j++)
		{
			hosp[j].display();//DISPLAY ELEMENT
			cout<<endl;
		}
	}
}

void main()
{
	clrscr();

	hospital hosp[50];
	//ARRAY OF OBJECTS OF CLASS 'HOSPITAL' ( CAN HOLD MAX 50 ELEMENTS )
	int item,n,index;

	cout<<"Enter no. of elements  ;";
	cin>>n;

	cout<<endl<<"Enter Records "<<endl;

	for(int i=0;i<n;i++)
	{
		hosp[i].input();//GET INPUT
		cout<<endl;
	}

	selsort(hosp,n);//PERFORM SELECTION SORT

	cout<<endl<<"The array is"<<endl;

	for(i=0;i<n;i++)
	{
		hosp[i].display();//DISPLAY ELEMENT
		cout<<endl;
	}

	getch();
}


