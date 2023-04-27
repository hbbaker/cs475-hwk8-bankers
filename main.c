#include <stdio.h>
#include <stdlib.h>
#include "vector.h"
#include "banker.h"

int main(int argc, char *argv[])
{
  // TODO: attempt to open scenario file and scan data into allocated structures

  // Structure Declarations
  int *numResources;
  int *numProcesses;

  int *resourceVec;

  int **maxDemandMat;
  int **allocMat;

  FILE *input;

  // Allocate structs to Heap:

  // Allocate ints
  numResources = (int *)malloc(sizeof(int));
  numProcesses = (int *)malloc(sizeof(int));

  // Allocate Resource Vector
  resourceVec = (int *)malloc(sizeof(int) * 3);

  // Allocate Max Demand Matrix
  maxDemandMat = (int **)malloc(sizeof(int *) * 3);
  for (int i = 0; i < 3; i++)
  {
    maxDemandMat[i] = (int *)malloc(sizeof(int) * 5);
  }

  // Allocate Allocation Matrix
  allocMat = (int **)malloc(sizeof(int *) * 3);
  for (int i = 0; i < 3; i++)
  {
    allocMat[i] = (int *)malloc(sizeof(int) * 5);
  }

  // Attempt to open input file, if unsuccessful print error and exit.
  if (argc == 1)
  {
    input = fopen(argv[0], "r");
    if (input != NULL)
    {
      // TODO: Scan data from input file into the vars and structs.
    }
    else
    {
      printf("Cannot find input file, please try again.");
      return -1;
    }
  }
  else
  {
    printf("Usage: bankers <input file>");
    return -1;
  }

  // TODO: Run banker's safety algorithm

  return 0;
}