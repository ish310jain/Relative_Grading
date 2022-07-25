#include "Mark.hpp" /*Header File*/

#include<cmath>
/*Initialising the static variables*/
float Marks::allMarks = 0.0;
float Marks::variance=0.0;
float Marks::standardDev=0.0;
float Marks::c=0.0;
float Marks::average=0.0;
float Marks::total=0.0;
/*Default Constructor*/
Marks::Marks() {
  /*Initialising variables in default constructor*/ 
  this->cat1 = 0;
  this->cat2 = 0;
  this->quiz1 = 0;
  this->quiz2 = 0;
  this->da = 0;
  this->fat = 0;
}
/*Parameterised Constructor*/
Marks::Marks(float a, float b, float c, float d, float e, float f) {
  /*Initialising variables in parameterised constructor */
  this->cat1 = a;
  this->cat2 = b;
  this->quiz1 = c;
  this->quiz2 = d;
  this->da = e;
  this->fat = f;
  Marks::average=averageCalculator();/* Defining average*/
  Marks::total=((cat1 * 0.30) + (cat2 * 0.30) + (fat * 0.40) +da + quiz1 + quiz2);/*Defining total*/
}
float Marks::final() /* Defining final function*/
{
  Marks::c=((cat1 * 0.30) + (cat2 * 0.30) + (fat * 0.40) +da + quiz1 + quiz2);
  return Marks::c;
}
float Marks::standardDeviation() /*Defining standardDeviation function*/
{
  Marks::variance=(Marks::variance + (pow((Marks::total-Marks::average),2)/6));
  return Marks::variance;
}
float Marks::averageCalculator() /*Defining averageCalculator function*/
{
  Marks::allMarks = Marks::allMarks + ((cat1 * 0.30) + (cat2 * 0.30) + (fat * 0.40) +da + quiz1 + quiz2);
  return (Marks::allMarks)/6;
}
