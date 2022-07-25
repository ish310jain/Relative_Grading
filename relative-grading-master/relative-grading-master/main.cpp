/*Project Topic - Relative Grading
  Topic Description - Using this program we would be able to find the relative grade of a particular student from a given group of students
  Group No. - 1003
  Group Members - Gaurav , Margi , Priyanshu , Anica , Kushal , Ish */
#include <iostream>
#include<cmath>
#include"Mark.hpp"  /* Header file */
using namespace std;
Marks A[10]; 
/*This code has been written to give data for 6 students and get the grade of one student.*/
int main()
{
    int i,j;
    cout<<"Total Students - 1: ";
    cin>>j;  /*Total number of students to be entered*/
    cout<<endl;

    float m1,m2,m3,m4,m5,m6;
    string name;
   /*Name of students with marks to be entered*/
    for(i = 0; i < j; i++)
    {
     cout<<"Name of student: ";
     cin>>name;
    a:
    cout<<"CAT 1: "; /*Marks for CAT 1*/
    cin>>m1;
    if(m1>50||m1<0)
    {
        cout<<"Marks Entered are invalid"<<endl;
        goto a;
    }
    b:
    cout<<"CAT 2: ";  /*Marks for CAT 2*/
    cin>>m2;
    if(m2>50||m2<0)
    {
        cout<<"Marks Entered are invalid"<<endl;
        goto b;
    }
    c:
    cout<<"Quiz 1: ";  /*Marks for Quiz 1*/
    cin>>m3;
    if(m3>10||m3<0)
    {
        cout<<"Marks Entered are invalid"<<endl;
        goto c;
    }
    d:
    cout<<"Quiz 2: ";   /*Marks for Quiz 2*/
    cin>>m4;
    if(m4>10||m4<0)
    {
        cout<<"Marks Entered are invalid"<<endl;
        goto d;
    }
    e:
    cout<<"DA: ";  /*Marks for DA*/
    cin>>m5;
    if(m5>10||m5<0)
    {
        cout<<"Marks Entered are invalid"<<endl;
        goto e;
    }
    f:
    cout<<"FAT: ";  /*Marks for FAT*/
    cin>>m6;
    if(m6>100||m6<0)
    {
        cout<<"Marks Entered are invalid"<<endl;
        goto f;
    }

    Marks st(m1,m2,m3,m4,m5,m6); /*Class used to define objects*/
    A[i]= st;
    }
    
    cout<<endl;
 /* Entering the marks of student whose grade has to be calculated*/
    cout<<"Student's name whose grade is to be compiled: ";
    cin>>name;
    cout<<endl;
    l:
    cout<<"CAT 1: ";  /*Marks for CAT 1*/
    cin>>m1;
    if(m1>50||m1<0)
    {
        cout<<"Marks Entered are invalid"<<endl;
        goto l;
    }
    k:
    cout<<"CAT 2: "; /*Marks for CAT 2*/
    cin>>m2;
    if(m2>50||m2<0)
    {
        cout<<"Marks Entered are invalid"<<endl;
        goto k;
    }
    j:
    cout<<"Quiz 1: ";  /*Marks for Quiz 1*/
    cin>>m3;
    if(m3>10||m3<0)
    {
        cout<<"Marks Entered are invalid"<<endl;
        goto j;
    }
    i:
    cout<<"Quiz 2: "; /*Marks for Quiz 2*/
    cin>>m4;
    if(m4>10||m4<0)
    {
        cout<<"Marks Entered are invalid"<<endl;
        goto i;
    }
    h:
    cout<<"DA: "; /*Marks for DA*/
    cin>>m5;
    if(m5>10||m5<0)
    {
        cout<<"Marks Entered are invalid"<<endl;
        goto h;
    }
    g:
    cout<<"FAT: ";  /*Marks for FAT*/
    cin>>m6;
    if(m6>100||m6<0)
    {
        cout<<"Marks Entered are invalid"<<endl;
        goto g;
    }
    
    Marks M(m1,m2,m3,m4,m5,m6);/* Class used to define object*/
    A[i+1]= M;
    for(i=0; i<=j; i++)
    {
       A[i].standardDeviation();
    }
    Marks::standardDev = sqrt(Marks:: variance);/*defining standard deviation in terms of variance*/
    cout<<M.final()<<endl; /*final marks*/
    cout<<Marks::variance<<endl; /*variance*/
    cout<<Marks::standardDev<<endl; /*standard deviation*/
    cout<<Marks::average<<endl; /*average*/
    /* Marks checking to provide the relative grade*/
    if((M.fat==0)||(M.fat<40))  /*Condition for N grade*/
    {
        cout<<"N grade"<<endl;                                                
    }
    else if(M.final()>Marks::average+1.5*(Marks::standardDev))  /*Condition for S grade*/
    {
        cout<<"S grade"<<endl;
    }
    else if(M.final()<=Marks::average+1.5*(Marks::standardDev)&&M.final()>Marks::average+0.5*(Marks::standardDev))  /*Condition for A grade*/
    {
        cout<<"A grade"<<endl;
    }
    else if(M.final()<=Marks::average+0.5*(Marks::standardDev)&&M.final()>Marks::average-0.5*(Marks::standardDev)|| Marks::standardDev==0)  /*Condition for B grade*/
    {
        cout<<"B grade"<<endl;
    }
    else if(M.final()<=Marks::average-0.5*(Marks::standardDev)&&M.final()>Marks::average-1.0*(Marks::standardDev))  /*Condition for C grade*/
    {
        cout<<"C grade"<<endl;
    }
                                                                                                                    
    else if(M.final()<=Marks::average-1.0*(Marks::standardDev)&&M.final()>Marks::average-1.5*(Marks::standardDev))  /*Condition for D grade*/ 
    {
        cout<<"D grade"<<endl;
    }
    else if(M.final()<=Marks::average-1.5*(Marks::standardDev)&&M.final()>Marks::average-2.0*(Marks::standardDev))  /*Condition for E grade*/
    {
        cout<<"E grade"<<endl;
    }
    else if(M.final()<Marks::average-2.0*(Marks::standardDev))    /*Condition for F grade*/
    {
        cout<<"F grade"<<endl;
    }

  return 0;
}
