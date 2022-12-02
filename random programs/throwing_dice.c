#include <stdio.h>
#include <stdlib.h>
#include <time.h>
int roll_dice(int x, int s)
{
    srand(s);
    int r = rand();
    int n = 1;
    while (r % 100 != x)
    {
        n++;
        r = rand();
    }

    return n;
}

int main()
{
    int data[500000];
    double geo_mean = 1;
    for (int i = 0; i < 500000; i++)
        data[i] = 0;


    for (int i = 0; i < 500000; i++)
        data[i] = roll_dice(50, time(NULL) * i);

    long long sum = 0;
    for (int i = 0; i < 500000; i++)
    {
        //printf("%d:%lf\n", i, geo_mean);
        sum += data[i];
        geo_mean = pow(geo_mean, (i + 1) / (double)(i + 2)) * pow(data[i], 1.0 / (double)(i + 2));
    }

    printf("mean:%.3f\n", sum / 500000.0);
    printf("geo mean:%.3lf", geo_mean);
    return 1;
}
