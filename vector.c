#include <stdio.h>
#include <stdlib.h>
#include "vector.h"

// TODO - Define vector and matrix operations

// returns a 1 if the two vectors are equal and 0 otherwise
//takes two vectors as input to compare
int compare(int *vector1, int *vector2, int size){
    int equal=1;
    for(int i=0;i<size;i++){
        if(vector1[i]!=vector2[i]){
            equal=0;
        }
    }
    return equal;
}
//makes a deep clone of a vector or matrice
//takes the original matrix or vector as well as the sizes (rows is the first size cols is the second)
int **cpy(int **orginal,int rows,int cols){
    int **clone=malloc(rows*sizeof(int));
    for(int i=0;i<rows;i++){
        clone[i]=malloc(cols*sizeof(int));
        memcpy(clone[i],orginal[i],cols*sizeof(int));
    }
    return clone;
}
int **add(int **sum,int **additive,int rows, int cols){
    for(int i=0;i<rows;i++){
        for(int k=0;k<cols;k++){
            sum[i][k]+=additive[i][k];
        }
    }
    return sum;
}
int **subtract(int **sum,int **subtractval, int rows, int cols){
    for(int i=0;i<rows;i++){
        for(int k=0;k<cols;k++){
            sum[i][k]+=subtractval[i][k];
        }
    }
    return sum;
}
