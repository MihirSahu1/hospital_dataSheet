
#include<iostream>
using namespace std;  //space is alloted by the compiler

struct date
  {
    int d,m,y;  //structure for date
  };
 
class hospital   //base class hospital
  {
    char name[100];          //data members
    struct date adm;
    struct date disch;
   protected:
      int age;     //protected member used due to inheritance
   public:
      void getdata()     //function to get patients details
        {
          cout<<"enter the name of the patient:"<<"\n";
          cin>>name;
          cout<<"Enter the age of the patient:"<<"\n";
          cin>>age;
          cout<<"Enter the date of admitting:"<<"\n";
          cin>>adm.d>>adm.m>>adm.y;
          cout<<"enter the date of discharging:"<<"\n";
          cin>>disch.d>>disch.m>>disch.y;
        }
       
       void display()     //function to display details
         {
           cout<<"Name is\t"<<name<<"\n";
           cout<<"Age is\t"<<age<<"\n";
           cout<<"Date of admitting is\t"<<adm.d<<"/"<<adm.m<<"/"<<adm.y<<"\n";
           cout<<"Date of discharge is\t"<<disch.d<<"/"<<disch.m<<"/"<<disch.y<<"\n";
         }
   };
   
class pediatric:public hospital    //derived class derived from hospital
  {
     char vaccine[25];
    public:
      void get()
        {
          getdata();
          cout<<"Enter the name of the vaccine:"<<"\n";  //vaccine is entered
          cin>>vaccine;
        }
        
      void disp()
        {
          if(age<12)      //if age is less than 12 he/she is a pediatric patient
            {
              display();
              cout<<"Vaccine is "<<vaccine;
              cout<<"\n";
            }
         else
           {
             cout<<"Age greater than 12 is not a pediatric patient"<<"\n";   //else not
           }
        }   
  };
  
int main()
  {
    hospital h[2];    //object for parent class
    int n;
    cout<<"Enter the number of patients:"<<"\n";  
    cin>>n;
    for(int i=0;i<n;i++)    //get input
      {
        h[i].getdata();
      }
    
    cout<<"Patient database"<<"\n";
    for(int i=0;i<n;i++)      //display 
      {
        h[i].display();
        cout<<"\n\n";
      };
      
    pediatric p[2];    //object for child class
    cout<<"Enter the number of pediatric patients:"<<"\n";
    cin>>n;
    cout<<"Pediatric Patient database"<<"\n";
    for(int i=0;i<n;i++)   //get input
      {
        p[i].get();
      }
      
   for(int i=0;i<n;i++)   //display data
     {
       p[i].disp();
     }
     
     return 0;
  }
    
