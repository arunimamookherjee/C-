//INSERTION AT END OF LIST

#include<iostream.h>
#include<process.h>
#include<conio.h>
#include<stdio.h>

struct hospital
{
char name[20];
int patient_id;
float TOT_BILL;
hospital *next;
}*start,*newptr,*save,*ptr,*rear;

void input(hospital *hosp)//TO GET INPUT
{
		cout<<"Enter patient id "<<endl;
		cin>>hosp->patient_id;

		cout<<"Enter name"<<endl;
		gets(hosp->name);

		cout<<"Enter the Total Bill "<<endl;
		cin>>hosp->TOT_BILL;

}
void display(hospital *hosp)//TO DISPLAY RECORD
{
		cout<<"NAME OF PATIENT : "<<hosp->name<<endl;
		cout<<"PATIENT ID"<<hosp->patient_id<<endl;
		cout<<"TOTAL BILL "<<hosp->TOT_BILL<<endl;
}





hospital * create()//TO CREATE NODE
{
		ptr=new hospital;

		cout<<"Enter Record "<<endl;
		input(ptr);

		ptr->next=NULL;

		return ptr;
}

void insert(hospital *np) //TO INSERT NODE
{
		if(start==NULL)
			start=np;
		else
		{
			save=start;
			start=np;
			np->next=save;
		}
}

void main()
{
	clrscr();
	start=rear=NULL;
	char ch='y';

	while(ch=='y'||ch=='Y')
	{
		newptr=create();

		if(newptr==NULL)
		{
			cout<<"Cannot create ";
			getch();
			exit(1);
		}

		insert(newptr);

		cout<<"Current list "<<endl;
		display(start);

		cout<<"Do you want to insert more records "<<endl;
		cin>>ch;
	 }
	 getch();
}






