// CLASS AND THE FUNCTIONS

#include<iostream.h>
#include<conio.h>
#include<string.h>
#include<stdio.h>

class HOSPITAL
{
char name[20];
int patient_id;
float TOT_BILL,meds, mediclaim, noofdays, roomservice, OTcharges, consult_fees;
public:
	HOSPITAL()
	{
	char ch;
	clrscr();
	cout<<"\nNAME : ";   gets(name);
	cout<<"\nPATIENT ID : "; cin>>patient_id;
	cout<<"\nTOTAL COST OF MEDICINE : ";cin>>meds;
	cout<<"\nWas the patient admitted : ";cin>>ch;
	if(ch=='y'||ch=='Y')
	{       cout<<"\nIf the room was general PRESS 1";
		cout<<"\nIf the room was executive PRESS 2\n";
		cin>>ch;
		cout<<"\nNO. OF DAYS ADMITTED : "; cin>>noofdays;
		if(ch=='1')
		roomservice=noofdays*400;
		else
		roomservice=noofdays*1500;
	}
		cout<<"\nWas the patient OPERATED : ";cin>>ch;
	if(ch=='y'||ch=='Y')
       {	OTcharges=7000; consult_fees=5000;	}
	else
       {	OTcharges=0; consult_fees=500;          }


       }

       void calculate()
       {
       TOT_BILL=meds+roomservice+OTcharges+consult_fees;
       if(mediclaim>TOT_BILL)
       TOT_BILL=0;
       else
       TOT_BILL=TOT_BILL-mediclaim;
       }

       void print_invoice()
       {
       cout<<"\nNAME	   : "<<name;
       cout<<"\tPATIENT ID : "<<patient_id ;
       cout<<"\n\n::::::::::::::::::::BILL::::::::::::::::";
       cout<<"\nMEDICINE	: "<<meds;
       cout<<"\nROOM SERVICE    : "<<roomservice;
       cout<<"\nOT CHARGES	: "<<OTcharges;
       cout<<"\nCONSULTING FEES : "<<consult_fees;
       cout<<"\n		   ------------------";
       cout<<"\nTOTAL BILL	: "<<TOT_BILL;
       }
} H1;

void main()
{

H1.calculate();
H1.print_invoice();
getch();
}

