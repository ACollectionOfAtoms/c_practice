#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#define A(i,j) a[(i) + (j)*n]
void dgesv_();
int main()
{
  int i,j,n=7,one=1,info;
  double *a=malloc(n*n*sizeof(double));
  double *b=malloc(n*sizeof(double));
  int *ipiv=malloc(n*sizeof(int));
  char trans[1]={'N'};
  A(0,0)=1; A(0,1)=exp(-0.400000000000000); A(0,2)=exp(-2*0.400000000000000); A(0,3)=exp(-3*0.400000000000000); A(0,4)=exp(-4*0.400000000000000); A(0,5)=exp(-5*0.400000000000000); A(0,6)=exp(-6*0.400000000000000);
  A(1,0)=1; A(1,1)=exp(-0.500000000000000); A(1,2)=exp(-2*0.500000000000000); A(1,3)=exp(-3*0.500000000000000); A(1,4)=exp(-4*0.500000000000000); A(1,5)=exp(-5*0.500000000000000); A(1,6)=exp(-6*0.500000000000000);
  A(2,0)=1; A(2,1)=exp(-0.600000000000000); A(2,2)=exp(-2*0.600000000000000); A(2,3)=exp(-3*0.600000000000000); A(2,4)=exp(-4*0.600000000000000); A(2,5)=exp(-5*0.600000000000000); A(2,6)=exp(-6*0.600000000000000);
  A(3,0)=1; A(3,1)=exp(-0.700000000000000); A(3,2)=exp(-2*0.700000000000000); A(3,3)=exp(-3*0.700000000000000); A(3,4)=exp(-4*0.700000000000000); A(3,5)=exp(-5*0.700000000000000); A(3,6)=exp(-6*0.700000000000000);
  A(4,0)=1; A(4,1)=exp(-0.800000000000000); A(4,2)=exp(-2*0.800000000000000); A(4,3)=exp(-3*0.800000000000000); A(4,4)=exp(-4*0.800000000000000); A(4,5)=exp(-5*0.800000000000000); A(4,6)=exp(-6*0.800000000000000);
  A(5,0)=1; A(5,1)=exp(-0.900000000000000); A(5,2)=exp(-2*0.900000000000000); A(5,3)=exp(-3*0.900000000000000); A(5,4)=exp(-4*0.900000000000000); A(5,5)=exp(-5*0.900000000000000); A(5,6)=exp(-6*0.900000000000000);
  A(6,0)=1; A(6,1)=exp(-1.000000000000000); A(6,2)=exp(-2*1.000000000000000); A(6,3)=exp(-3*1.000000000000000); A(6,4)=exp(-4*1.000000000000000); A(6,5)=exp(-5*1.000000000000000); A(6,6)=exp(-6*1.000000000000000);
  b[0]=-0.976798125297645;   b[1]=-1.100869770567809;    b[2]=-1.153517976992553; b[3]=-1.171014611491842; b[4]=-1.170406254407191; b[5]=-1.160412786280990; b[6]=-1.145758813825982;
  printf("\n\n");

  dgesv_(&n,&one,a,&n,ipiv,b,&n,&info);
  for(i=0;i<n;++i)
  {
  printf("%16.6g \n",b[i]);
  }
return(0);
}
