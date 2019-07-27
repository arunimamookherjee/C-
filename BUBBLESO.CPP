//BUBBLESORT IN ARRAY

#include<iostream.h>
#include<conio.h>
#include<limits.h>
#include<stdio.h>

class hospital
{
char name[20];
int patient_id;
public:

	int get_patientid()//ACECSSOR FUNCTION TO GET patient_id
	{	return patient_id; }

	void get_input()
	{
	char ch;

	cout<<"\nNAME : ";   gets(name);
	cout<<"\n
	PATIENT ID : "; cin>>patient_id;
	}
	void display()
	{
	cout<<"\nPATIENT ID : ";cout<<patient_id;
	cout<<"\nNAME	    : ";cout<<name;
	}
}H[25]; //CLASS DEFINITION OVER


void bubblesort(hospital hos[],int size)
//FUNCTION TO PERFORM BUBBLE SORT
{
      hospital tmp;

      for(int i=0;i<size;i++)
      {
		for(int j=0;j<(size-1)-i;j++)
		{
			if(hos[j].get_patientid()>hos[j+1].get_patientid())
			/*IF 'patient_id' OF J+1 th ELEMENT < 'patient_id OF Jth ELEMENT
			  SWAP CONSECUTIVE ELEMENTS */
			{
				tmp=hos[j];
				hos[j]=hos[j+1];
				hos[j+1]=tmp;
			}
		}

		cout<<endl<<"Array after iteration-" <<i+1<<"-is"<<endl;

		for (int k=0;k<size;k++)
		{
			hos[k].display();//DISPLAY ELEMENT
			cout<<endl;
		}
      }
}

void main ()
{
	clrscr ();

	hospital hosp[50];
	//ARRAY OF OBJECTS OF CLASS 'COMPUTER' ( CAN HOLD MAX 50 ELEMENTS)
	int n;

	cout<<"Enter array size "<<endl;
	cin>>n;

	cout<<"Enter array elements"<<endl;

	for(int i=0;i<n;i++)
	{
		hosp[i].get_input();//GET INPUT FOR ELEMENT
	}


	bubblesort(hosp,n);//TO PERFORM BUBBLE SORT

	cout<<"\n\n Sorted array is"<<endl;

	for(i=0;i<n;i++)
	{
		hosp[i].display();//DISPLAY ELEMENT

	}
	getch();
}



