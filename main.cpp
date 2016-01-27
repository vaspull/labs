#include <stdio.h>

int ex1_1()
{
    printf("Hello, World!\n");
    return(0);
}

int ex1_2()
{
    printf("Hello, World!\a");
    printf("\n");
    printf("Hello, World!\b");
    printf("\n");
    printf("\n");
    printf("Hello, World!\f");
    printf("\n");
    printf("Hello, World!\n");
    printf("\n");
    printf("Hello, World!\r");
    printf("\n");
    printf("Hello, World!\t");
    printf("\n");
    printf("Hello, World!\v");
    printf("\n");
    return(0);
}

int ex1_3()
{
    printf ("Transfer Program Fahrenheit to Celsius\n\n");
    float fahr, celsius;
    int lower, upper, step;
    lower = 0;
    upper = 300;
    step = 20;
    fahr = lower;
    while (fahr <= upper)
    {
        celsius = (5.0/9.0) * (fahr-32.0);
        printf ("%3.0f %6.1f\n", fahr, celsius);
        fahr = fahr + step;
    }

    return(0);
}

int ex1_4()
{
    printf ("Transfer Program Celsius to Fahrenheit\n\n");
    float fahr, celsius;
    int lower, upper, step;
    lower = -273.15;
    upper = 300;
    step = 20;
    celsius = lower;
    while (celsius <= upper)
    {
        fahr = (9.0/5.0) * celsius + 32;
        printf("%7.2f %7.2f\n", celsius, fahr);
        celsius = celsius + step;
    }
    return(0);
}

int ex1_5()
{
    int fahr;
    for (fahr = 300; fahr >= 0; fahr = fahr - 20)
        printf ("%3d %6.1f\n", fahr, (5.0/9.0)*(fahr-32));
    return(0);
}

int ex1_6()
{
    int c;
    while ( c == 0 )
    {
        c = ( getchar() == EOF );
        printf("%d\n", c);
    }
    return(0);
}

int ex1_7()
{
    int b;
    b = EOF;
    printf("%d", b);
    return(0);
}

int ex1_8()
{
    int c;
    int space = 0;
    int tab = 0;
    int newline = 0;
    while ((c = getchar()) != '0')
    {
        if (c == '\n')
            ++newline;
        else if (c == '\t')
            ++tab;
        else if (c == ' ')
            ++space;
    }
    printf("Space: ");
    printf("%d\n", space);
    printf("Tab: ");
    printf("%d\n", tab);
    printf("Newline: ");
    printf("%d\n", newline);
    return(0);
}

int ex1_9()
{
    int c;
    int space = 0;
    while ( c != EOF )
    {
        c = getchar();
        if (c != ' ')
        {
            putchar(c);
            space = 0;
        }
        else if ( space == 0 )
        {
            putchar(c);
            space = 1;
        }
    }
    return(0);
}

int ex1_10()
{
    int c;
    while (c != EOF)
    {
        c = getchar();
        if (c == '\t')
        {
            printf("%c", 92 );
            printf("%c", 116 );
        }
        else if (c == '\b')
        {
            printf("%c", 92);
            printf("%c", 98);
        }
        else if ( c == 92 )
        {
            printf("%c", 92);
            printf("%c", 92);
        }
        else
            putchar(c);
    }
    return(0);
}

#define IN 1
#define OUT 0
#define NADO 2
#define NENADO 3

int ex1_12()
{
    int c = 1;
    int state;
    int state2 = NENADO;
    state = OUT;
    while ( c != EOF )
    {
        c = getchar();
        if ( c == ' ' )
        {
            state = OUT;
            state2 = NADO;
            putchar('\n');
        }
        else if ( c == '\t' && state2 == NENADO)
        {
            putchar('\n');
        }

        else if ( state == OUT )
        {
            state = IN;
            putchar(c);
        }
        else
            putchar(c);
    }
    return(0);
}

int ex1_13()
{
    int wlen = 0;
    char c;
    int i;
    while( c  != EOF )
    {
        c = getchar();
        if ( c != ' ' && c != '\n' && c != '\t' )
            wlen++;
        else
        {
            for(i = 0; i < wlen; i++) printf("|");
            printf("\n");
            wlen = 0;
        }
    }
    return 0;
}



float celfahr(float cel)
{
    float fahr = (9.0/5.0) * cel + 32;
    return fahr;
}

int ex1_15()
{
    printf ("Transfer Program Celsius to Fahrenheit\n\n");
    float fahr, celsius;
    int lower, upper, step;
    lower = -273.15;
    upper = 100;
    step = 20;
    celsius = lower;
    while (celsius <= upper)
    {
        fahr = celfahr(celsius);
        printf("%7.2f %7.2f\n", celsius, fahr);
        celsius = celsius + step;
    }
    return(0);
}



#define MAXLINE 1000
int getline(char s[], int lim)
{
    int c = 1;
    int i;
    for (i = 0; i < lim-1 && (c = getchar()) != EOF && c != '\n'; ++i)
        s[i] = c;
    if (c == 'n')
    {
        s[i] = c;
        ++i;
    }
    s[i] = '\0';
    return i;
}
void copy(char to[], char from[])
{
    int i;
    i = 0;
    while ((to[i] = from[i]) != '\0')
        ++i;
}

int ex1_16()
{
    int len;
    int max;
    char line[MAXLINE];
    char longest[MAXLINE];
    max = 0;
    while ((len = getline(line, MAXLINE)) > 0)
        if (len > max) {
            max = len;
            copy(longest, line);
        }
    if (max > 0)
        printf("%s\n", longest);
    printf("The legth of the longest string: ");
    printf("%d",max);
    return 0;
}



int ex1_17()
{
    int len;
    char line[MAXLINE];
    while ((len = getline(line, MAXLINE)) != EOF)
        if (len > 80) {
            printf("%s\n", line);
            printf("The legth of the string: ");
            printf("%d\n\n",len);
        }
    return 0;
}



int ex1_18()
{
    return(0);
}

int main()
{
    ex1_1();
    return(0);
}
