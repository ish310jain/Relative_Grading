/*Header File*/
#ifndef MARK_H
#define MARK_H

#include <string>
/*Declaring class named Marks*/
class Marks {
  /*Declaring in public part*/
 public:
 /*Declaring variables*/
  float cat1;
  float cat2;
  float quiz1;
  float quiz2;
  float da;
  float fat;
  /*Declaring static variables*/
  static float allMarks;
  static float standardDev;
  static float variance;
  static float c;
  static float total;
  static float average;
  float final();/*Declaring Function*/
  float standardDeviation();/*Declaring Function*/
  float averageCalculator();/*Declaring Function*/
  Marks();/*Declaring Default Constructor*/
  Marks(float a, float b, float c, float d, float e, float f);/*Declaring Parameterised Constructor*/
};


#endif


