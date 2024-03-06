/*Gideon Neeman 329924567*/
#include "fmm.h"
void fmm(int n, int* m1, int* m2, int* result) {
    int* col=malloc(n*sizeof(int));
    int s=0;

    for(int j=0; j<n; j++){
        for(int k=0; k<n; k++){
            col[k]=m2[k*n+j];
        }
        for(int i=0; i<n; i++){
            s=0;
            int ilen=i*n;
            for(int k=0; k<n; k++){
                s+=m1[ilen+k]*col[k];
            }
            result[ilen+j]=s;
        }
    }
}

