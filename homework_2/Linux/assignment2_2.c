// Peter Zhou
#include <stdlib.h>
#include "assignment2_2.h"

void swapD(int* ptr1, int* ptr2) {
    int temp = *ptr1;
    *ptr1 = *ptr2;
    *ptr2 = temp;
}

void swapT(float* ptr1, float* ptr2) {
    float temp = *ptr1;
    *ptr1 = *ptr2;
    *ptr2 = temp;
}

void qsortTD(float* leftT, float* rightT, int* leftD, int* rightD) {
    float* ptrT = NULL;
    float* lastT = NULL; 
    float* middleT = NULL; 
    int* ptrD = NULL;
    int* lastD = NULL;
    int* middleD = NULL;

    if (leftT >= rightT || leftD >= rightD) {
        return;
    }

    middleT = leftT + (rightT - leftT) / 2;
    middleD = leftD + (rightD - leftD) / 2;
    
    swapT(leftT, middleT);
    swapD(leftD, middleD);

    lastT = leftT;
    lastD = leftD;

    ptrT = leftT + 1;
    ptrD = leftD + 1;
    while (ptrT <= rightT) {
        if (*ptrT < *leftT) {
            swapT(++lastT, ptrT);
            swapD(++lastD, ptrD);
        }
        ptrT++;
        ptrD++;
    }

    swapT(leftT, lastT); 
    swapD(leftD, lastD);

    qsortTD(leftT, lastT-1, leftD, lastD-1);
    qsortTD(lastT+1, rightT, lastD+1, rightD);
};