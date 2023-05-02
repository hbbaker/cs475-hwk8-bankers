#include <stdio.h>
#include <stdlib.h>
#include "vector.h"
#include "banker.h"

// TODO - Safety Algorithm goes here

isSafe(int Available[5][3], int Alloc[5][3], int Need[5][3])
{
    // m = number of resource types (3)
    // n = number of threads (5)
    int m = 3;
    int n = 5;

    // Worked threads
    int Work[n];

    // Cleared threads
    int ans[n];

    // Index values used later
    int ind = 0;
    int y = 0;

    // Populate work with 0s in each slot
    for (int k = 0; k < 5; k++)
    {
        Work[k] = 0;
    }

    // Compares all needed values to available
    for (int k = 0; k < 5; k++)
    {
        for (int i = 0; i < n; i++)
        {
            // If the thread has not already finished...
            if (Work[i] == 0)
            {
                // Used for checking thread completion safety
                int unsafe = 0;

                // Loops through and checks if the available resources are enough
                // Flags unsafe if not enough resources and exits
                for (int j = 0; j < m; j++)
                {
                    if (Need[i][j] > Available[j])
                    {
                        unsafe = 1;
                        break;
                    }
                }

                // If there is a sufficient amount of avaiable resources...
                // Frees up resources and adds the completed thread name to the "answer"
                if (unsafe == 0)
                {
                    ans[ind++] = i;
                    for (y = 0; y < m; y++)
                        Available[i][y] += Alloc[i][y];
                    Work[i] = 1;
                }
            }
        }
    }

    // Used to check if a thread is safe
    int safe = 1;

    // Iterates thrugh the work values to make sure all values are 1...
    // If there are any 0s left, this is not a safe path, and the loop exits
    for (int i = 0; i < n; i++)
    {
        if (Work[i] == 0)
        {
            safe = 0;
            break;
        }
    }

    // If no values in work were 0 (all threads complete)...
    // Write the safe order to the file
    if (safe == 1)
    {
        FILE *safes = fopen("safe.txt", "w");
        for (int i = 0; i < n - 1; i++)
        {
            fprintf(" T%d ", ans[i]);
        }
        fprintf(" T%d", ans[n - 1]);
    }
    else
    {
        printf("UNSAFE : ");
        for (int i = 0; i < n - 1; i++)
        {
            printf(" T%d ", ans[i]);
        }
        fprintf(" T%d", ans[n - 1]);
    }
    return (0);
}
