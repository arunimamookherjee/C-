//INHERITANCE (multiple)

#include<iostream.h>
#include<conio.h>
#include<stdio.h>
#include<string.h>

class patient
{

protected:

	int patient_id;
	char name[20];

public:

	void patient_ip()//FUNCTION TO GET INPUT
	{
		cout<<"Enter patient ID: ";
		cin>>patient_id;
		cout<<"\nEnter patient name: ";
		gets(name);
	}

	void patient_op()//FUNCTION TO DISPLAY OUTPUT
	{
		cout<<"Patient ID: ";
		cout<<patient_id;
		cout<<"\nPatient name: ";
		cout<<name;
	}

};

class COST
{

protected:
	int meds,consult_fees;

public:

	void get_COST()
	{
		cout<<"\nEnter total cost of Medicine: ";
		cin>>meds;
		cout<<"\nEnter consulting fees: ";
		cin>>consult_fees;
	}

	void disp_COST()
	{
		cout<<"\nCost of Medicine: ";
		cout<<meds;
		cout<<"\nConsulting fees: ";
		cout<<consult_fees;

	}

};

class hosp_bill:public patient,public COST
{
	char doc_name[50];
	int waitlist_num;

public:

	void input() //FUNCTION TO GET INPUT
	{

		cout<<"\nEnter name of consulting Doctor: ";
		gets(doc_name);

		cout<<"\nEnter waitlist Number: ";
		cin>>waitlist_num;
	}

	void display()//FUNCTION TO DISPLAY
	{
		cout<<"\nName of consulting Doctor: ";
		cout<<doc_name;

		cout<<"\nEnter waitlist Number: ";
		cout<<waitlist_num;
	}

};
void main ()
{
	  clrscr ();

	  hosp_bill hosp;

	  cout<<"Enter details "<<endl;
	  hosp.input();
	  hosp.patient_ip();
	  hosp.get_COST();

	  cout<<endl;

	  hosp.display();
	  hosp.patient_op();
	  hosp.disp_COST();

	  getch();

}






