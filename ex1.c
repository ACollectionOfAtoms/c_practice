#include <stdlib.h>
#include <stdio.h>
#define A(i,j) a[(i) + (j)*n]
void dgetrf_();void dgetrs_();
void dgesv_();
int main()
{
  int i,j,n=10,one=1,info;
  double *a=malloc(n*n*sizeof(double));
  double *b=malloc(n*sizeof(double));
  int *ipiv=malloc(n*sizeof(int));
  char trans[1]={'N'};
  A(0,0)=0.400000000000000;  A(0,1)=0.500000000000000;  A(0,2)=0.600000000000000; A(0,3)=0.700000000000000; A(0,4)=0.800000000000000; A(0,5)=0.900000000000000; A(0,6)=1.000000000000000; A(0,7)=1.100000000000000; A(0,8)=1.200000000000000; A(0,9)=1.300000000000000;
  b[0]=-0.976798125297645;   b[1]=-1.100869770567809;    b[2]=-1.153517976992553; b[3]=-1.171014611491842; b[4]=-1.170406254407191; b[5]=-1.160412786280990; b[6]=-1.145758813825982; b[7]=-1.129119870077057; b[8]=-1.112067541332630; b[9]=-1.095549013746680;
  printf("\n\n");
 /* dgetrf_(&n,&n,a,&n,ipiv,&info);
    dgetrs_(trans,&n,&one,a,
            &n,ipiv,b,&n,&info); */
 dgesv_(&n,&one,a,&n,ipiv,b,&n,&info);
  for(i=0;i<n;++i)
  {
  printf("%8.5g \n",b[i]);
  }
return(0);
}

