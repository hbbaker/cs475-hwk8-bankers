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
//makes a deep clone of a matrix
//takes the original matrix as well as the sizes (rows is the first size cols is the second)
int **cpy(int **original,int rows,int cols){
    int **clone=malloc(rows*sizeof(int*));
    for(int i=0;i<rows;i++){
        clone[i]=malloc(cols*sizeof(int));
        memcpy(clone[i],original[i],cols*sizeof(int));
    }
    return clone;
}
int *cpyvector(int *original,int rows){
    int *clone=malloc(rows*sizeof(int));
    memcpy(clone,original,rows*sizeof(int));
    return clone;
}
int **add(int **matrix1,int **matrix2,int rows, int cols){
    int **sum=malloc(rows*sizeof(int*));
    for(int i=0;i<rows;i++){
        sum[i]=malloc(cols*sizeof(int));
        for(int k=0;k<cols;k++){
            sum[i][k]=matrix1[i][k]+matrix2[i][k];
        }
    }
    return sum;
}
int *addvector(int *vector1, int *vector2, int rows){
    int *sum=malloc(rows*sizeof(int));
    for(int i=0;i<rows;i++){
        sum[i]=vector1[i]+vector2[i];
    }
}

