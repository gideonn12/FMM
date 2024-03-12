#include "fmm.h"
void fmm(int n, int* m1, int* m2, int* result) {
    int* col=malloc(n*sizeof(int));
    int s=0;
    int s1=0;

    for(int j=0; j<n; j++){
        for(int k=0; k<n; k+=2){
            col[k]=m2[k*n+j];
            col[k+1]=m2[(k+1)*n+j];
        }
        for(int i=0; i<n; i++){
            s=0;
            s1=0;
            int ilen=i*n;
            for(int k=0; k<n; k+=2){
                s+=m1[ilen+k]*col[k];
                s1+=m1[ilen+k+1]*col[k+1];
            }
            result[ilen+j]=s+s1;
        }
    }
}