#include <stdio.h>
#include <stdlib.h>
#include "vector.h"
#include "banker.h"

int main(int argc, char *argv[])
{
  // TODO: attempt to open scenario file and scan data into allocated structures

  // Used to handle txt file tokens
  int val;

  // Structure Declarations
  int numResources;
  int numProcesses;

  int *resourceVec;

  int **maxDemandMat;
  int **allocMat;

  FILE *input;

  // Allocate structs to Heap:

  // Allocate ints
  // numResources = (int *)malloc(sizeof(int));
  // numProcesses = (int *)malloc(sizeof(int));

  // Allocate Resource Vector
  resourceVec = (int *)malloc(sizeof(int) * 3);

  // Allocate Max Demand Matrix
  maxDemandMat = (int **)malloc(sizeof(int *) * 5);
  for (int i = 0; i < 5; i++)
  {
    maxDemandMat[i] = (int *)malloc(sizeof(int) * 3);
  }

  // Allocate Allocation Matrix
  allocMat = (int **)malloc(sizeof(int *) * 5);
  for (int i = 0; i < 5; i++)
  {
    allocMat[i] = (int *)malloc(sizeof(int) * 3);
  }

  // Attempt to open input file, if unsuccessful print error and exit.
  if (argc == 2)
  {
    input = fopen(argv[1], "r");
    if (input != NULL)
    {
      // Scan in numResources and numProcesses:
      //---------------------------------
      fscanf(input, "%d", &numResources);
      // printf("Num Resources: %d\n", numResources);

      fscanf(input, "%d", &numProcesses);
      // printf("Num Processes: %d\n", numProcesses);

      for (int i = 0; i < 3; i++)
      {
        fscanf(input, "%d", &val);
        resourceVec[i] = val;
      }

      // printf("Resource Vector: %d %d %d\n", resourceVec[0], resourceVec[1], resourceVec[2]);
      //---------------------------------

      // Scan in Max Demand Matrix:
      //---------------------------------
      for (int i = 0; i < 5; i++)
      {
        for (int j = 0; j < 3; j++)
        {
          fscanf(input, "%d", &val);
          maxDemandMat[i][j] = val;
        }
      }

      // printf("Max Demand Mat:\n");
      // for (int i = 0; i < 5; i++)
      // {
      //   for (int j = 0; j < 3; j++)
      //   {
      //     printf("%d ", maxDemandMat[i][j]);
      //   }
      //   printf("\n");
      // }
      //---------------------------------

      // Scan in Allocation Matrix:
      //---------------------------------
      for (int i = 0; i < 5; i++)
      {
        for (int j = 0; j < 3; j++)
        {
          fscanf(input, "%d", &val);
          allocMat[i][j] = val;
        }
      }

      // printf("Allocation Mat:\n");
      // for (int i = 0; i < 5; i++)
      // {
      //   for (int j = 0; j < 3; j++)
      //   {
      //     printf("%d ", allocMat[i][j]);
      //   }
      //   printf("\n");
      // }
      //---------------------------------
      fclose(input);

      if(sanityCheck(resourceVec,maxDemandMat,allocMat,numResources,numProcesses)){
        // TODO: Run banker's safety algorithm
      }
      else{
        return -1;
      }
    }
    else
    {
      printf("Cannot find input file, please try again.");
      return -1;
    }
  }
  else
  {
    printf("Usage: bankers <input file>\n");
    // printf("%d\n", argc);
    return -1;
  }

  return 0;
}
//returns 1 if sanity check passes 0 if not
int sanityCheck(int *resources, int **max, int **alloc, int numResources, int numThreads){
  for(int i=0;i<numThreads;i++){
    for(int k=0;k<numResources;k++){
      if(max[i][k]>resources[i]){
        printf("Integrity test failed: allocated resources exceed demand for Thread %d\n",i);
        return 0;
      }
    }
  }
  for(int i=0;i<numResources;i++){
    int resource=0;
    for(int k=0;k<numThreads;k++){
      resource+=alloc[i][k];
    }
    if (resource>resources[i]){
      printf("Integrity test failed: allocated resources exceed total resources\n");
      return 0;
    }
  }
  return 1;
}