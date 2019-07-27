//DELETION IN LINKED LIST

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

void ins_node(hospital *np) //TO INSERT NODE
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

void del_node()//TO DELETE NODE
{
		if(start==NULL)
		{
			cout<<"UNDERFLOW:";
			getch();
			exit(1);
		}
		else
		{
			save=start;
			start=start->next;
			delete save;
		}
}

void displaylist(hospital *hosp)//TO DISPLAY LIST
{
	while(hosp!=NULL)
	{
		display(hosp);
		cout<<endl;
		hosp=hosp->next;
	}
	cout<<endl;
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

		ins_node(newptr);

		cout<<"Current list "<<endl;
		displaylist(start);

		cout<<"Do you want to insert more records "<<endl;
		cin>>ch;
	 }

	 cout<<"Do you want to delete ? "<<endl;
	 cin>>ch;

	 while(ch=='y'||ch=='Y')
	 {
		del_node();

		cout<<"Current list "<<endl;
		displaylist(start);

		cout<<"Do you want to delete ? "<<endl;
		cin>>ch;
	 }
	 getch();
}




