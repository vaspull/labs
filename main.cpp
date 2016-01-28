#include <stdio.h>
#include <iostream>
#include <stdlib.h>
using namespace std;
#define windows
#define MAXLINE 3000
int cls()  //crossplatform clear screen
{
    int r;
#ifdef windows
    r = system("cls");
#else
    r = system("clear");
#endif
    return r;
}
int greeting()
{
    cout << "Welcome to the demonstration of the exercises " << endl;
    cout << "from the book by Brian Kernighan and Dennis Ritchie" << endl;
    cout << "<--------C ++ Programming Language-------->" << endl;
#ifdef windows
    cout << "Build mode - Windows.\n" << endl;
#else
    cout << "build mode - Linux.\n" << endl;
#endif
    return(0);
}
int getline(char s[], int lim)
{
    int c = 1;
    int i;
    for ( i = 0; i < lim-1 && ( c = getchar() ) != EOF && c != '\n'; ++i )
        s[i] = c;
    if ( c == 'n' )
    {
        s[i] = c;
        ++i;
    }
    s[i] = '\0';
    return i;
}
int ex1_1()
{
    cls();
    printf("Hello, World!\n");
    return(0);
}
int ex1_2()
{
    cls();
    printf("Hello, World!\a");
    printf("\n");
    printf("Hello, World!\b");
    printf("\n");
    printf("Hello, World!\f");
    printf("\n");
    printf("Hello, World!\n");
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
int ex1_14()
{
    char A[MAXLINE];
    int length = 0;
    while ( ( length = getline(A, MAXLINE)) > 0 )
    {
        char e[100];
        for ( int i = 0 ; i > 100 ; i++ ) e[i] = 0;
        //long d = 0;
        long j = 0;
        char b;
        long o = 0;
        long counter = 0;
        long p = 0;
        printf("The initial line of %d characters.\n" , length ) ;
        for ( int c = 0 ; c < length ; c++ )
        {
            long k = 1;
            int t = 0;
            p = 0;

            b = A[c];
            while( e[j] ) j++;
            for ( int i = 0; i < length; i++)
            {
                char s = e[p];
                char ss = A[i];
                if ( b == ss )
                {
                    counter++;
                }
                if  ( ( p <= j ) && ( k != 0 ) )
                {
                    if ( b == s )
                    {
                        t = 0;
                        k = 0;
                    }
                    else
                    {
                        t = 1;
                        k = 1;
                    }
                }
                p++;
            }
            if ( t == 1 )
            {
                printf("%c " , b);
                for ( int i = 0 ; i < counter ; i++) printf("|");
                printf("\n");
                e[o] = b;
                o++;
            }
            counter = 0;
        }
    }
    return(0);

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
int del_space(char to[], char from[])
{
    int c;
    int i = 0;
    int j = 0;
    int s = 0;
    while ( ( c = from[i] ) != '\n' )
    {
        if ( c == ' ' || c == '\t' )
        {
            if (s == 0)
            {
                to[j] = ' ';
                s = 1;
                j++;
            }
        }
        else
        {
            to[j] = c;
            s = 0;
            j++;
        }
        i++;
    }
    if ( c == '\n' )
    {
        to[j] = c;
        j++;
    }
    to[j] = '\0';
    return j;
}
int ex1_18()
{
    int len;
    char line[1000];
    char newline[1000];
    len = 0;
    while ( ( len = getline(line, 1000) ) > 0 )
    {
        del_space(newline, line);
        printf("%s" , newline);
    }
    return 0;
}
void reverse(char to[], char from[])
{
    int c = 0;
    int d = 0;
    while (from[c]) c++;
    c--;
    while( c >= 0 )
    {
        to[d] = from[c];
        c--;
        d++;
    }
}
int ex1_19()
{
    char A[MAXLINE];
    for ( int i = 0 ; i < MAXLINE ; i++) A[i] = 0;
    char B[MAXLINE];
    for ( int i = 0 ; i < MAXLINE ; i++) B[i] = 0;
    int length;
    while ( ( length = getline(A, MAXLINE)) > 0 )
    {
        reverse(B,A);
        printf("%s\n" , B);
    }
    return(0);
}
void detab(char to[], char from[])
{
    int tab = 4;
    int i = 0;
    int j = 0;
    int k;
    while ( from[i] != 0 )
    {
        if ( from[i] == '\t' )
        {
            for ( k = 0 ; k < tab ; ++k )
            {
                to[j] = ' ';
                j++;
            }
        }
        else
        {
            to[j] = from[i];
            j++;
        }
        i++;
    }
    to[j] = '\0';
}
int ex1_20()
{
    char A[MAXLINE];
    for ( int i = 0 ; i < MAXLINE ; i++) A[i] = 0;
    char B[MAXLINE];
    for ( int i = 0 ; i < MAXLINE ; i++) B[i] = 0;
    int length;
    while ( ( length = getline(A, MAXLINE)) > 0 )
    {
        detab(B,A);
        printf("%s\n" , B);
     }
    return(0);
}
void entab(char to[], char from[])
{
    int tab = 1;
    int i = 0;
    int j = 0;
    int k;
    while ( from[i] != 0 )
    {
        if ( from[i] == ' ' )
        {
            for ( k = 0 ; k < tab ; ++k )
            {
                to[j] = '\t';
                j++;
            }
        }
        else
        {
            to[j] = from[i];
            j++;
        }
        i++;
    }
    to[j] = '\0';
}
int ex1_21()
{
    char A[MAXLINE];
    for ( int i = 0 ; i < MAXLINE ; i++) A[i] = 0;
    char B[MAXLINE];
    for ( int i = 0 ; i < MAXLINE ; i++) B[i] = 0;
    int length;
    while ( ( length = getline(A, MAXLINE)) > 0 )
    {
        entab(B,A);
        printf("%s\n" , B);
     }
    return(0);
}
int get_fix_line(char s[], int lim)
{
    int c;
    int i;
    for ( i = 0 ; i < lim-1 && ( c = getchar() ) != EOF && c != '\n'; ++i )
    {
        s[i] = c;
    }
    if ( i == lim-2 )
    {
        s[i] = '\n';
        i++;
    }
    s[i] = '\0';
    return i;
}
int ex1_22()
{
    int length;
    char line[20];
    length = 0;
    while ( ( length = get_fix_line(line, 20) ) > 0 )
    {
        printf("%s\n", line);
    }
    return 0;
}
int main()
{
    ex1_22();
    return(0);
}



int main_future_idea()
{
re: cls();
    greeting();
    cout << "Choose exercise\n\n";
    cout << " 1. Exercise 1.1" << "     12. Exercise 1.12\n";
    cout << " 2. Exercise 1.2" << "     13. Exercise 1.13\n";
    cout << " 3. Exercise 1.3" << "     14. Exercise 1.14\n";
    cout << " 4. Exercise 1.4" << "     15. Exercise 1.15\n";
    cout << " 5. Exercise 1.5" << "     16. Exercise 1.16\n";
    cout << " 6. Exercise 1.6" << "     17. Exercise 1.17\n";
    cout << " 7. Exercise 1.7" << "     18. Exercise 1.18\n";
    cout << " 8. Exercise 1.8" << "     19. Exercise 1.19\n";
    cout << " 9. Exercise 1.9" << "     20. Exercise 1.20\n";
    cout << "10. Exercise 1.10" << "    21. Exercise 1.21\n\n";
    cout << "11. Exit\n";
    cout << "Selection: ";

    char ch = 'q';
    string str;
    int g;
    getline ( cin , str );
    int strlength = str.length();
    for ( int t = 0 ; t < strlength; t++ )
    {
        ch = str.c_str()[t];
    }
    if ( !isdigit(ch) )
    {
        cerr << "Invalid value, press Enter to try again\n";
        cin.get();
        goto re;
    }
    g = atoi( str.c_str() );

    switch ( g )
    {
    case 1:
        ex1_1();
        cin.get();
        goto re;
        break;
    case 2:
        ex1_2();
        cin.get();
        goto re;
        break;
    case 3:
        ex1_3();
        cin.get();
        goto re;
        break;
    case 4:
        ex1_4();
        cin.get();
        goto re;
        break;
    case 5:
        ex1_5();
        cin.get();
        goto re;
        break;
    case 6:
        ex1_6();
        cin.get();
        goto re;
        break;
    case 7:
        ex1_7();
        cin.get();
        goto re;
        break;
    case 8:
        ex1_8();
        cin.get();
        goto re;
        break;
    case 9:
        ex1_9();
        cin.get();
        goto re;
        break;
    case 10:
        ex1_10();
        cin.get();
        goto re;
        break;
    case 11:
        ex1_12();
        cin.get();
        goto re;
        break;
    case 12:
        ex1_13();
        cin.get();
        goto re;
        break;
    case 13:
        ex1_14();
        cin.get();
        goto re;
        break;
    case 14:
        ex1_15();
        cin.get();
        goto re;
        break;
    case 15:
        ex1_16();
        cin.get();
        goto re;
        break;
    case 16:
        ex1_17();
        cin.get();
        goto re;
        break;
    case 17:
        ex1_18();
        cin.get();
        goto re;
        break;
    case 18:
        ex1_19();
        cin.get();
        goto re;
        break;
    case 19:
        ex1_20();
        cin.get();
        goto re;
        break;
    case 20:
        ex1_21();
        cin.get();
        goto re;
        break;
    case 21:
        ex1_22();
        cin.get();
        goto re;
        break;
    case 99:
        cout << "\nThe End." << endl;
        return(0);
    default:
        cerr << "Invalid value, press Enter to try again\n";
        cin.get();
        goto re;
    }
    return(0);
}
