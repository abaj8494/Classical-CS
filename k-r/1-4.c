#include <stdio.h>

/*
 * prints a celsius to fahrenheit table
 * for farh = 0, 5, 10, ..., 100;
 */
int main()
{
    float fahr, celsius;
    int lower, upper, step;

    lower = 0;
    upper = 100;
    step = 5;

    celsius = lower;
    // heading
    char heading[] = "Celsius to Fahrenheit Table";
    for (int i = 0; i < sizeof(heading); i++) {printf("-");}
    printf("\n%s\n", heading);
    for (int i = 0; i < sizeof(heading); i++, printf("-")); // weirdly you can also put the printf in here too...
    printf("\n");


    while (celsius <= upper) {
        fahr = 9.0 * celsius / 5.0 + 32.0;
        printf("%3.0f %6.1f\n", celsius, fahr);
        // if you put the format code as %3f the compiler will default to 6 decimal places. %3.0 means 0 dp
        celsius += step;
    }

}
