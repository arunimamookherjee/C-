//POPPING FROM ARRAY STACK

#include<iostream.h>
#include<conio.h>
#include<stdlib.h>
#include<process.h>
#include<stdio.h>

const int size=50;
class hospital
{
char name[20];
int patient_id,bill;
public:

	int get_patientid()//ACECSSOR FUNCTION TO GET patient_id
	{	return patient_id; }

	void input()
	{
	char ch;

	cout<<"\nNAME	    : ";   gets(name);
	cout<<"\nPATIENT ID : "; cin>>patient_id;
	cout<<"\nBILL	    :";cin>>bill;
	}
	void display()
	{
	cout<<"\nPATIENT ID : ";cout<<patient_id;
	cout<<"\nNAME	    : ";cout<<name;
	cout<<"\nBILL	    : "<<bill ;
	}


}; //CLASS DEFINITION OVER

int push(hospital stack[],int &top,hospital hosp_ele)//FUNCTION TO INSERT OR PUSH ELEMENT INTO THE STACK
{
	if(top==size-1)//TO CHECK IF STACK IS FULL
		return -1;
	else
	{
		top++;//TOP UPDATED
		stack[top]=hosp_ele;//ELEMENT INSERTED
	}

	return 0;//INSERTION SUCCESSFUL
}

void display(hospital stack[],int top)//FUNCTION TO DISPLAY STACK
{
	if(top==-1)//TO CHECK IF STACK IS EMPTY
	{
		cout<<"Stack empty "<<endl;
	}

	for(int i=top;i>=0;i=i-1)
	{
		stack[i].display();//TO DISPLAY RECORD
		cout<<endl;
	}
}


void main()
{
	clrscr();

	hospital stack[size],hosp_item,hosp_res;
	//ARRAY STACK OF OBJECTS OF CLASS 'HOSPITAL'( CAN HOLD MAX 50 ELEMENTS )

	int top=-1 , res;  //TOP INITIALISED AS -1 AS STACK IS EMPTY INITIALLY
	char ch='y';

	while(ch=='y'||ch=='Y')
	{
		cout<<"\nEnter record for insertion\n"<<endl;
		hosp_item.input();//TO GET INPUT
		cout<<endl;

		res=push(stack,top,hosp_item);//TO PUSH ELEMENT INTO STACK

		if(res==-1)//INSERTION UNSUCCESSFUL
		{
			cout<<"OVERFLOW!!! Aborting!!\n";
			exit(1);
		}

		cout<<"\n The stack now is : \n"<<endl;

		display(stack,top);//TO DISPLAY STACK
		cout<<endl;

		cout<<"\n Want to insert more elements ? (y/n)...";
		cin>>ch;
	}


}







