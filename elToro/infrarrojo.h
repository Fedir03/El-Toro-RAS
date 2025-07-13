#ifndef INFRARROJO_H
#define INFRARROJO_H


typedef struct 
{
  bool infraData_D;
  bool infraData_I;
  bool infraData_A;
}infraData_t;

void getInfraData(infraData_t * infraData);
 
#endif