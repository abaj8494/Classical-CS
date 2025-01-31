#include <stdio.h>

/*
 * prints a fahrenheit to celcius table
 * for farh = 0, 20, ..., 300;
 */
int main()
{
    float fahr, celsius;
    int lower, upper, step;

    lower = 0;
    upper = 300;
    step = 20;

    fahr = lower;
    // heading
    char heading[] = "Fahrenheit to Celsius Table";
    for (int i = 0; i < sizeof(heading); i++) {printf("-");}
    printf("\n%s\n", heading);
    for (int i = 0; i < sizeof(heading); i++, printf("-")); // weirdly you can also put the printf in here too...
    printf("\n");


    while (fahr <= upper) {
        celsius = (5.0 / 9.0) * (fahr - 32.0);
        printf("%3.0f %6.1f\n", fahr, celsius);
        fahr = fahr + step;
    }

}
