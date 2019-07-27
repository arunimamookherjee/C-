//TO INSERT DATA IN A SORTED FILE

#include<iostream.h>
#include<conio.h>
#include<fstream.h>
#include<string.h>
#include<stdio.h>

class hospital
{
char name[20];
int patient_id;
float TOT_BILL,meds, noofdays, roomservice, OTcharges, consult_fees;
public:
       void calculate()
       {
       TOT_BILL=meds+roomservice+OTcharges+consult_fees;
       }

	void input()
	{
	char ch;
	cout<<"\nNAME : ";   gets(name);
	cout<<"\nPATIENT ID : "; cin>>patient_id;
	cout<<"\nTOTAL COST OF MEDICINE : ";cin>>meds;
	cout<<"\nWas the patient admitted : ";cin>>ch;
	if(ch=='y'||ch=='Y')
	{      	cout<<"\nNO. OF DAYS ADMITTED : "; cin>>noofdays;
		roomservice=noofdays*800;

	}
		cout<<"\nWas the patient OPERATED : ";cin>>ch;
	if(ch=='y'||ch=='Y')
       {	OTcharges=7000; consult_fees=5000;	}
	else
       {	OTcharges=0; consult_fees=500;          }

       calculate();
       }


       void display()
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
       int get_id()
       { return patient_id;}
} ;
void main()
{
	clrscr();

	hospital hosp,ins_hosp;
	char ch='y';
	int check=0;

	ifstream fin;
	ofstream fout("FILE.dat",ios::out|ios::binary);

	ofstream fout2("temp.dat",ios::out|ios::binary);

	cout<<"Enter Record in incr order of order no :\n";
	while(ch=='y'||ch=='Y')
	{
		hosp.input();//GET INPUT FOR RECORD
		cout<<endl;

		fout.write((char*)&hosp,sizeof(hosp));

		cout<<"\nDo you want to enter more records ? ";
		cin>>ch;
	}

	fout.close();

	cout<<"Enter record to be inserted "<<endl;
	ins_hosp.input();//GET INPUT FOR RECORD TO BE INSERTED

	fin.open("file5.dat",ios::in|ios::binary);

	while(!fin.eof())//AS LONG AS END OF FILE IS NOT REACHED
	{
		fin.read((char*)&hosp,sizeof(hosp));

		if(fin.eof())//CHECK IF END OF FILE IS REACHED
			break;

		if(ins_hosp.get_id()<hosp.get_id())

		{
			fout2.write((char*)&ins_hosp,sizeof(hosp));


			check=1;

		}

		fout2.write((char*)&hosp,sizeof(hosp));


	}

	fin.close();
	if(check==0)
		fout2.write((char*)&ins_hosp,sizeof(hosp));


	fout2.close();
	remove("FILE.dat");


	rename("temp.dat","FILE.dat");


	fin.open("FILE.dat",ios::in|ios::binary);


	cout<<"New file "<<endl<<endl;

	while(!fin.eof())//AS LONG AS END OF FILE IS NOT REACHED
	{
		fin.read((char*)&hosp,sizeof(hosp));


		if(fin.eof())//CHECK IF END OF FILE IS REACHED
			break;

		hosp.display();//DISPLAY RECORD
		cout<<endl;
	}

	fin.close();
	getch();
}