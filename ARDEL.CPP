//DELETION IN ARRAY

#include<iostream.h>
#include<conio.h>
#include<process.h>
#include<stdio.h>

class hospital
{
char name[20];
int patient_id;
float TOT_BILL,meds, mediclaim, noofdays, roomservice, OTcharges, consult_fees;
public:
	void input()
	{
	char ch;

	cout<<"\nNAME : ";   gets(name);
	cout<<"\nPATIENT ID : "; cin>>patient_id;
	cout<<"\nTOTAL COST OF MEDICINE : ";cin>>meds;
	cout<<"\nWas the patient admitted : ";cin>>ch;
	if(ch=='y'||ch=='Y')
	{
		cout<<"\nNO. OF DAYS ADMITTED : "; cin>>noofdays;
		roomservice=noofdays*400;

	}
		cout<<"\nWas the patient OPERATED : ";cin>>ch;
	if(ch=='y'||ch=='Y')
       {	OTcharges=7000; consult_fees=5000;	}
	else
       {	OTcharges=0; consult_fees=500;          }


       }

	  int get_id()
       {	return patient_id;	}
       void calculate()
       {
       TOT_BILL=meds+roomservice+OTcharges+consult_fees;
       if(mediclaim>TOT_BILL)
       TOT_BILL=0;
       else
       TOT_BILL=TOT_BILL-mediclaim;
       }

       void display()
       {
       calculate();
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
};

int lsearch(hospital hosp[],int size,int srch_id)
 //FUNCTION TO SEARCH FOR patient_id WITH GIVEN ORDER NO ie srch_id
{
	for(int i=0;i<size;i++)
	{
		if(hosp[i].get_id()==srch_id)
		//TO RETURN INDEX OF RECORD WHOSE patient_id MATCHES
			return i;
	}
	return -1; //IF RECORD WITH MATCHING patient_id IS NOT FOUND
}


void main()
{
	clrscr();

	hospital hosp[50]; //ARRAY OF OBJECTS OF 'HOSPITAL' CLASS ( CAN HOLD MAX 50 ELEMENTS )

	int n,index,del_id;

	char ch='y';

	cout<<"Enter array size ( less than 50 ) ";
	cin>>n;

	cout<<"Enter array elements "<<endl<<endl;

	for(int i=0;i<n;i++)
	{
		hosp[i].input();//TO GET INPUT
		cout<<endl;
	}


	while(ch=='y'||ch=='Y')
	{
		cout<<"Enter patient_id  of record to be deleted ";
		cin>>del_id;
		cout<<endl;

		if(n==0) //TO CHECK IF ARRAY IS EMPTY
		{
			cout<<"underflow";
			exit(1);
		}

		index=lsearch(hosp,n,del_id);
		 //TO GET INDEX OF RECORD WITH GIVEN patient_id i.e del_id

		if(index!=-1) //RECORD WITH GIVEN patient_id ie del_id IS FOUND
		{
			for(i=index;i<n;i++)
			{
				hosp[i]=hosp[i+1];
				//TO SHIFT ELEMENTS TO BRING EMPTY SPACE AT END
			}

			n=n-1;//TO UPDATE NUMBER OF ELEMENTS IN ARRAY

			cout<<"The array is now "<<endl<<endl;

			for(i=0;i<n;i++)
			{
				hosp[i].display();//TO DISPLAY RECORD
				cout<<endl;
			}
		}

		else //RECORD WITH GIVEN patient_id del_id IS NOT FOUND
			cout<<"No such element "<<endl;

		cout<<"Want to delete more elements :";
		cin>>ch;

	}

	getch();
}




