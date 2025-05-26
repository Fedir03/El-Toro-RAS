#ifndef INFRARROJO_H
#define INFRARROJO_H


typedef struct 
{
  infraData_D;
  infraData_I;
  infraData_A;
}infraData_t;

void getInfraData(infraData_t * infraData);
 
#endif