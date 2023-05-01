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
  if (argc == 2)
  {
    input = fopen(argv[1], "r");
    if (input != NULL)
    {
      // TODO: Scan data from input file into the vars and structs.
      fscanf(input, "%d", &numResources);
      printf("Num Resources: %d\n", numResources);

      fscanf(input, "%d", &numProcesses);
      printf("Num Processes: %d\n", numProcesses);

      for (int i = 0; i < 3; i++)
      {
        fscanf(input, "%d", &val);
        resourceVec[i] = val;
      }

      printf("Resource Vector: %d %d %d\n", resourceVec[0], resourceVec[1], resourceVec[2]);

      fclose(input);
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

  // TODO: Run banker's safety algorithm

  return 0;
}