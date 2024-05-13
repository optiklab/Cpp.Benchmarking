#include "stdio.h"
#include "getCPUTime.h"

// https://habr.com/ru/articles/282301/
void main()
{
    double startTime = getCPUTime();

    // Long task
    Sleep(3000);

    double endTime = getCPUTime();

    fprintf(stderr, "CPU time used = %lf\n", (endTime - startTime));
}