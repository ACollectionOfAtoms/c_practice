#include <stdlib.h>
#include <stdio.h>
#define A(i,j) a[(i) + (j)*n]
void dgetrf_();void dgetrs_();
void dgesv_();
int main()
{
  int i,j,n=3,one=1,info;
  double *a=malloc(n*n*sizeof(double));
  double *b=malloc(n*sizeof(double));
  int *ipiv=malloc(n*sizeof(int));
  char trans[1]={'N'};
  A(0,0)=6.;  A(0,1)=-2.;  A(0,2)=2.;
  A(1,0)=12.; A(1,1)=-8.;  A(1,2)=6.;
  A(2,0)=3.;  A(2,1)=-13.; A(2,2)=3.;
  b[0]=16.;   b[1]=26.;    b[2]=-19.;
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
