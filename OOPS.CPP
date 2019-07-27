// OOPS CONCEPT CLASS AND THE FUNCTIONS
// CONSTRUCTOR DESTRUCTOR & FUNCTION OVERLOADING

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
	cout<<"\nConstructing CLASS:HOSPITAL";
	strcpy(name,NULL);
	patient_id=0;
	TOT_BILL=0;
	meds=0;
	mediclaim=0;
	noofdays=0;
	roomservice=0;
	OTcharges=7000;
	consult_fees=500;
	}
       void calculate()//FUNCTION IS CALLED WHEN NO PARAMETER IS PASSED
       {
       TOT_BILL=meds+roomservice+OTcharges+consult_fees;
       if(mediclaim>TOT_BILL)
       TOT_BILL=0;
       else
       TOT_BILL=TOT_BILL-mediclaim;
       }

       void calculate(float CF,float medicine) //FUNCTION IS CALLED WHEN ONLY MEDS AND CONSULT_FEES IS PASSED
       { TOT_BILL=CF+medicine;	}

       void calculate(float RS)  //FUNCTION IS CALLED ONLY WHEN MEDICLAIM IS O
       {  RS=0.2*RS;   //20% DISCOUNT ON ROOMSERVICE
	  TOT_BILL=RS+meds+consult_fees+OTcharges;
       }

	void get_input()
	{
	char ch;
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



       if(roomservice==0&&OTcharges==0) //FUNCTION 'CALCULATE'
       calculate(meds,consult_fees); 			 //IS BEING OVERLOADED
       else if(mediclaim==0)
       calculate(roomservice);
       else
       calculate();

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

       ~HOSPITAL()
       {cout<<"\n\n\nDESTRUCTING CLASS:HOSPITAL :D" ;}
} ;

void main()
{
clrscr();
HOSPITAL H1;
char check;
do
{
H1.get_input();
H1.print_invoice();
cout<<"DO YOU WANT TO PRINT MORE BILLS : ";
cin>>check;
}
while(check=='y'||check=='Y');
getch();
}

