#include <iostream>
#include<cmath>
using namespace std;
class Marks {
 public:
  float cat1;
  float cat2;
  float quiz1;
  float quiz2;
  float da;
  float fat;
  static float allMarks;
  static float standardDev;
  static float average;
  static float c;
  static float total;
  float final();
  Marks();
  Marks(float a, float b, float c, float d, float e, float f);
};
float Marks::allMarks = 0.0;
float Marks::standardDev=0.0;
float Marks::c=0.0;
float Marks::total=0.0;
float Marks::average=0.0;
Marks::Marks() {
  this->cat1 = 0;
  this->cat2 = 0;
  this->quiz1 = 0;
  this->quiz2 = 0;
  this->da = 0;
  this->fat = 0;
}
Marks::Marks(float a, float b, float c, float d, float e, float f) {
  this->cat1 = a;
  this->cat2 = b;
  this->quiz1 = c;
  this->quiz2 = d;
  this->da = e;
  this->fat = f;
  Marks::allMarks = Marks::allMarks + ((cat1 * 0.33) + (cat2 * 0.33) + (fat * 0.4) +da + quiz1 + quiz2);
  Marks::allMarks = (Marks::allMarks)/5;
  Marks::total=((cat1 * 0.33) + (cat2 * 0.33) + (fat * 0.4) +da + quiz1 + quiz2);
  Marks::standardDev=Marks::standardDev+(sqrt(Marks::total-Marks::allMarks)/5);
}
float Marks::final()
{
    Marks::c=((cat1 * 0.33) + (cat2 * 0.33) + (fat * 0.4) +da + quiz1 + quiz2);
    return Marks::c;
}


int main() 
{
    Marks M[10];
    int i,n;
    cout<<"Enter the number of student's marks you want to calculate"<<endl;
    cin>>n;
    for(i=0;i<n;i++)
    {
        cout<<"Enter the marks scored by the student in CAT-1";
        cin>>M[i].cat1;
        cout<<"Enter the marks scored by the student in CAT-2";
        cin>>M[i].cat2;
        cout<<"Enter the marks scored by the student in DA";
        cin>>M[i].da;
        cout<<"Enter the marks scored by the student in Quiz-1";
        cin>>M[i].quiz1;
        cout<<"Enter the marks scored by the student in Quiz-2";
        cin>>M[i].quiz2;
        cout<<"Enter the marks scored by the student in FAT";
        cin>>M[i].fat;

    }
    for(i=0;i<5;i++)
    {
        if(M[i].fat==0)
        {
            cout<<"N grade"<<endl;
        } 
        else if(M[i].final()>Marks::allMarks+1.5*(Marks::standardDev))
        {
            cout<<"S grade"<<endl;
        }
        else if(M[i].final()<=Marks::allMarks+1.5*(Marks::standardDev)&&M[i].final()>Marks::allMarks+0.5*(Marks::standardDev))
        {
            cout<<"A grade"<<endl;
        }
        else if(M[i].final()<=Marks::allMarks+0.5*(Marks::standardDev)&&M[i].final()>Marks::allMarks-0.5*(Marks::standardDev))
        {
            cout<<"B grade"<<endl;
        }
        else if(M[i].final()<=Marks::allMarks-0.5*(Marks::standardDev)&&M[i].final()>Marks::allMarks-1.0*(Marks::standardDev))
        {
            cout<<"C grade"<<endl;
        }
        else if(M[i].final()<=Marks::allMarks-1.0*(Marks::standardDev)&&M[i].final()>Marks::allMarks-1.5*(Marks::standardDev))
        {
            cout<<"D grade"<<endl;
        }
        else if(M[i].final()<=Marks::allMarks-1.5*(Marks::standardDev)&&M[i].final()>Marks::allMarks-2.0*(Marks::standardDev))
        {
            cout<<"E grade"<<endl;
        }
        else if(M[i].final()<Marks::allMarks-2.0*(Marks::standardDev))
        {
            cout<<"F grade"<<endl;
        }
    }
}