#include <stdio.h>

#define MAXLINE 3000

void ex1_1()
{
    printf("Hello, World!\n");
}

void ex1_2()
{
    printf("Hello, World!\a\n");
    printf("Hello, World!\b\n");
    printf("Hello, World!\f\n");
    printf("Hello, World!\n\n");
    printf("Hello, World!\r\n");
    printf("Hello, World!\t\n");
    printf("Hello, World!\v\n");
}

void ex1_3()
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
}

void ex1_4()
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
}

void ex1_5()
{
    printf("Celsius:\tFahrenheit:\n");
    for (int fahr = 300; fahr >= 0; fahr = fahr - 20)
        printf ("%3d\t\t%5.1f\n", fahr, (5.0/9.0)*(fahr-32));
}

void ex1_6()
{
    int c;
    printf("Press Ctrl+D or other keys to evaluate expression '(getchar() == EOF)'.\n");
    while ( c == 0)
    {
        c = ( getchar() == EOF );
        printf("%d\n", c);
    }
}

void ex1_7()
{
    int b;
    b = EOF;
    printf("EOF = %d\n", b);
}

void ex1_8()
{
    int c;
    int space = 0;
    int tab = 0;
    int newLine = 0;
    while ((c = getchar()) != EOF)
    {
        if (c == '\n')
            ++newLine;
        else if (c == '\t')
            ++tab;
        else if (c == ' ')
            ++space;
    }
    printf("Spaces: %d\n", space);
    printf("Tabs: %d\n", tab);
    printf("Newlines: %d\n", newLine);
}

void ex1_9()
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
}

void ex1_10()
{
    int c;
    while (c != EOF)
    {
        c = getchar();
        if (c == '\t')
        {
            putchar(92);
            putchar(116);
        }
        else if (c == '\b')
        {
            putchar(92);
            putchar(98);
        }
        else if ( c == '\\' )
        {
            putchar(92);
            putchar(92);
        }
        else
            putchar(c);
    }
}

#define IN 1
#define OUT 0

void ex1_11()
{
    int c, nl, nw, nc, state;
    state = OUT;
    nl = nw = nc = 2147483645;
    while ( ( c = getchar() ) != EOF )
    {
        ++nc;
        if ( c == '\n' )
            ++nl;
        if ( c == ' ' || c == '\n' || c == '\t' )
            state = OUT;
        else if ( state == OUT )
        {
            state = IN;
            ++nw;
        }
    }
    printf ("%d %d %d\n", nl, nw, nc);
}

void ex1_12()
{
    int c, state = OUT;
    while ( (c = getchar()) != EOF )
    {
        if ( c == ' ' || c == '\t' || c == '\n') {
            if (state == IN)
                putchar('\n');
            state = OUT;
        } else {
            state = IN;
            putchar(c);
        }
    }
}

void ex1_13()
{
    printf("Word's length bar chart:\n");
    int wlen = 0, c;
    while( (c = getchar()) != EOF )
    {
        if ( c != ' ' && c != '\n' && c != '\t' )
            wlen++;
        else
        {
            for(int i = 0; i < wlen; i++)
                printf("|");
            printf("\n");
            wlen = 0;
        }
    }
}

//пример из учебника, раздел 1.6

void exemple()
{
    int c, i, nwhite, nother;
    int ndigit[10];
    nwhite = nother = 0;
    for (i = 0; i < 10; ++i)
        ndigit[i]= 0;
    while ((c = getchar()) != EOF)
        if (c >= '0' && c <= '9' )
            ++ndigit[c - '0' ];
        else if (c == ' ' || c == '\n' || c == '\t')
            ++nwhite;
        else
            ++nother;
    printf ("digit  =");
    for (i=0; i < 10; ++i)
        printf(" %d", ndigit[i]);
    printf (", symbol-separate = %d, another = %d\n", nwhite, nother);
}

//моя функция разбора строк на символы
void exemple2()
{
    int c, i;
    int arr[250];
    int counter = 0;
    int counter2 = 0;
    char arrSymbol[250];
    for ( int v = 0 ; v < 250 ; ++v ) arrSymbol[v] = 0;
    for ( i = 0 ; i < 250 ; ++i ) arr[i]= 0;
    while ( ( c = getchar() ) != EOF )
    {
        if ( c >= 97 && c <= 122 )
        {
            ++arr[c];
            ++counter2;
            arrSymbol[c] = c;
        }
        else if ( c >= 65 && c <= 90 )
        {
            ++arr[c];
            ++counter2;
            arrSymbol[c] = c;
        }
        else if ( c >= 128 && c <= 175 )
        {
            ++arr[c];
            ++counter2;
            arrSymbol[c] = c;
        }
        else if ( c >= 224 && c <= 241 )
        {
            ++arr[c];
            ++counter2;
            arrSymbol[c] = c;
        }
        else ++counter2;
    }
    printf ("Summ of used chars: %d\n", counter2);
    printf ("Used symbols:\n");

    for ( i=0; i < 250; ++i )
    {
        if ( arr[i] != 0)
        {
            counter = counter + arr[i];
            printf(" Sybbol: %c  %d\n", arrSymbol[i], arr[i]);
        }
    }
    printf("Summ of used symbols: %d\n", counter);
}

void ex1_14()
{
    printf("Symbols bar chart (code and 'symbol'), enter string: ");
    int c, i;
#define MAXCHARS 256
    int arr[MAXCHARS];
    for ( i = 0; i < MAXCHARS; ++i )
        arr[i]= 0;
    while ( ( c = getchar() ) != '\n' )
        ++arr[c];
    for ( i = 0 ; i < MAXCHARS ; ++i )
        if ( arr[i] != 0 )
        {
            printf("%3d ", i);
            if (i >= ' ')
                printf("'%c': ", i);
            for (int counter = 0; counter < arr[i] ; counter++ )
                printf("|");
            printf("\n");
        }
}

float celfahr(float cel)
{
    float fahr = (9.0/5.0) * cel + 32;
    return fahr;
}

void ex1_15()
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

void copy(char to[], char from[])
{
    int i;
    i = 0;
    while ((to[i] = from[i]) != '\0')
        ++i;
}

void ex1_16()
{
#define MAX_LINE 3
    printf ("Enter lines(empty for exit): ");
    int readed, max = 0, len = 0;
    char buffer[MAX_LINE], line[MAX_LINE*10], longest[MAX_LINE*10];
    while ((readed = getline(buffer, MAX_LINE)) > 0 || len > 0) {
        copy(line+len, buffer);
        len += readed;
        if ( readed != MAX_LINE-1 ) {
            if (len > max) {
                max = len;
                copy(longest, line);
            }
            len = 0;
        }
    }
    if (max > 0)
        printf("The longest string: %s.\n", longest);
    printf("The length of the longest string is %d.\n", max);
}

void ex1_17()
{
    printf ("Return line if it longest then 5 symbols, enter string(empty for exit):\n");
    int len;
    char line[MAXLINE];
    while ((len = getline(line, MAXLINE)) != 0)
        if (len > 5) {
            printf("String: %s\n", line);
            printf("The length of the string: %d\n", len);
        }
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

void ex1_18()
{
    printf ("Delete excess spaces and tabulation, enter string(empty for exit):\n");
    int len;
    /*
    char line[1000] = "line_1 four    spaces\n"
                      "line_2 \t\t\t with 3 tabs and empty line after\n\n"
                      "line_3 last line";
                      */
    char line[1000];
    char newline[1000];
    len = 0;
    while ( ( len = getline(line, 1000) ) > 0 )
    {
        printf("\n");
        // debug. line with codes...
        for (int i = 0; line[i] != '\0'; i++)
            printf("%d ", line[i]);
        printf("\n");
        del_space(newline, line);
        printf("%s" , newline);
    }
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

void ex1_19()
{
    printf ("It displays the text on the back to front\n\n");
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

void ex1_20()
{
    printf ("Changes tabs to spaces\n\n");
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

void ex1_21()
{
    printf ("Replaces spaces with tabs\n\n");
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

void ex1_22()
{
    printf("A string longer than 20 characters is cut and transferred");
    int length;
    char line[20];
    length = 0;
    while ( ( length = get_fix_line(line, 20) ) > 0 )
    {
        printf("%s\n", line);
    }
}

void ex1_23()
{
    printf("It displays the contents of the file C program without comments\n\n");
    int flagSLASH = 0;
    int flagSTAR = 0;
    int flagSTAR2 = 0;
    int flagSLASH2 = 0;
    int flagKAVICHKA = 0;
    int flagKAVICHKA2 = 0;
    int c;
    const char *fname = "main.cpp";
    FILE* file = fopen(fname, "r");
    if(file == NULL)
    {
        printf("File '%s' does not exist.\n", fname);
        return;
    }
    while ( ( c = getc(file) ) != EOF )
    {
        if ( c == 39 && flagSLASH == 0 && flagSTAR == 0 )
        {
            if ( flagKAVICHKA2 == 1)
            {
                flagKAVICHKA2 = 0;
                printf("%c", c);
            }
            else
            {
                flagKAVICHKA2 = 1;
                printf("%c", c);
            }
        }
        else if ( c == '"' && flagSLASH == 0 && flagSTAR == 0 && flagKAVICHKA2 == 0 )
        {
            if ( flagKAVICHKA == 1)
            {
                flagKAVICHKA = 0;
                printf("%c", c);
            }
            else
            {
                flagKAVICHKA = 1;
                printf("%c", c);
            }
        }
        else if ( c == '/' && flagKAVICHKA == 0 && flagKAVICHKA2 == 0 )
        {
            if (flagSTAR2 == 1)
            {
                flagSTAR = 0;
                flagSTAR2 = 0;
                flagSLASH = 0;
                flagSLASH2 = 0;
            }
            else if ( flagSLASH == 0 )
            {
                flagSLASH = 1;
            }
            else if ( flagSLASH == 1 )
            {
                flagSLASH2 = 1;
            }
        }
        else if ( c == '*' )
        {
            if ( flagSLASH == 1 && flagSTAR == 0 )
            {
                flagSTAR = 1;
                flagSLASH2 = 1;
            }
            else if ( flagSTAR == 1 )
            {
                flagSTAR2 = 1;
            }
            else
            {
                printf("%c", c);
            }
        }
        else if ( c == '\n' )
        {
            flagSLASH = 0;
            printf("%c", c);
        }
        else if ( flagSLASH == 1 && flagSLASH2 == 0)
        {
            flagSLASH = 0;
            printf("/ %c", c);
        }
        else if ( flagSLASH == 0 && flagSTAR == 0 )
        {
            flagSLASH2 = 0;
            flagSTAR = 0;
            flagSTAR2 = 0;
            printf("%c", c);
        }
        else if (flagSTAR2 == 1)
        {
            flagSTAR2 = 0;
        }
    }
    fclose(file);
}

int readFile(FILE *fPtr, char line[])
{
    int c = 0;
    int i = 0;
    int line_counter = 1;
    while ( ( c = getc(fPtr) ) != EOF )
    {
        if ( c == '\n' )
        {
            line_counter++;
            line[i] = c;
            ++i;
        }
        line[i] = c;
        ++i;
    }
    return line_counter;
}

void somefunction()
{
    printf("Some text about this fucking programm \n\n");
    int line_counter;
    char c[30000];
    const char *fname = "main.cpp";
    FILE* file = fopen(fname, "r");
    if(file == NULL)
    {
        printf("File '%s' does not exist.\n", fname);
        return;
    }
    line_counter = readFile(file, c);
    printf("%s\n\n", c);
    printf("%d lines in file '%s'\n", line_counter, fname);
    fclose(file);
}

void ex1_24()
{
    printf("Some text about this fucking programm \n\n");
    int flagSLASH = 0;
    int flagSTAR = 0;
    int flagSTAR2 = 0;
    int flagSLASH2 = 0;
    int flagKAVICHKA = 0;
    int flagKAVICHKA2 = 0;
    int counter_Skobka_Kvadrat, counter_Skobka_krug, counter_Skobka_figura;
    int counter_Skobka_Kvadrat2, counter_Skobka_krug2, counter_Skobka_figura2;
    counter_Skobka_Kvadrat = counter_Skobka_krug = counter_Skobka_figura = 0;
    counter_Skobka_Kvadrat2 = counter_Skobka_krug2 = counter_Skobka_figura2 = 0;
    int c;
    const char *fname = "main.cpp";
    FILE* file = fopen(fname, "r");
    if(file == NULL)
    {
        printf("File '%s' does not exist.\n", fname);
        return;
    }
    while ( ( c = getc(file) ) != EOF )
    {
        if ( c == 39 && flagSLASH == 0 && flagSTAR == 0 )
        {
            if ( flagKAVICHKA2 == 1)
            {
                flagKAVICHKA2 = 0;
            }
            else
            {
                flagKAVICHKA2 = 1;
            }
        }
        else if ( c == 34 && flagSLASH == 0 && flagSTAR == 0 && flagKAVICHKA2 == 0 )
        {
            if ( flagKAVICHKA == 1)
            {
                flagKAVICHKA = 0;
            }
            else
            {
                flagKAVICHKA = 1;
            }
        }
        else if ( c == 47 && flagKAVICHKA == 0 && flagKAVICHKA2 == 0 )
        {
            if (flagSTAR2 == 1)
            {
                flagSTAR = 0;
                flagSTAR2 = 0;
                flagSLASH = 0;
                flagSLASH2 = 0;
            }
            else if ( flagSLASH == 0 )
            {
                flagSLASH = 1;
            }
            else if ( flagSLASH == 1 )
            {
                flagSLASH2 = 1;
            }
        }
        else if ( c == 42 )
        {
            if ( flagSLASH == 1 && flagSTAR == 0 )
            {
                flagSTAR = 1;
                flagSLASH2 = 1;
            }
            else if ( flagSTAR == 1 )
            {
                flagSTAR2 = 1;
            }
            else
            {

            }
        }
        else if ( c == '\n' )
        {
            flagSLASH = 0;
        }
        else if ( c == 40 && flagKAVICHKA == 0 && flagSLASH2 == 0 )
        {
            counter_Skobka_krug++;
        }
        else if ( c == 41 && flagKAVICHKA == 0 && flagSLASH2 == 0 )
        {
            counter_Skobka_krug2++;
        }
        else if ( c == 91 && flagKAVICHKA == 0 && flagSLASH2 == 0 )
        {
            counter_Skobka_Kvadrat++;
        }
        else if ( c == 93 && flagKAVICHKA == 0 && flagSLASH2 == 0 )
        {
            counter_Skobka_Kvadrat2++;
        }
        else if ( c == 123 && flagKAVICHKA == 0 && flagSLASH2 == 0 )
        {
            counter_Skobka_figura++;
        }
        else if ( c == 125 && flagKAVICHKA == 0 && flagSLASH2 == 0 )
        {
            counter_Skobka_figura2++;
        }
        else if ( flagSLASH == 1 && flagSLASH2 == 0)
        {
            flagSLASH = 0;
        }
        else if ( flagSLASH == 0 && flagSTAR == 0 )
        {
            flagSLASH2 = 0;
            flagSTAR = 0;
            flagSTAR2 = 0;
        }
        else if (flagSTAR2 == 1)
        {
            flagSTAR2 = 0;
        }
    }
    fclose(file);
    printf("In file '%s':\n\n", fname);
    if (counter_Skobka_krug != counter_Skobka_krug2)
    {
        printf("%d parentheses, the parentheses are not closed!!!\n", counter_Skobka_krug+counter_Skobka_krug2);
    }
    else printf("%d parentheses, the parentheses are closed.\n", counter_Skobka_krug+counter_Skobka_krug2);

    if (counter_Skobka_Kvadrat != counter_Skobka_Kvadrat2)
    {
        printf("%d square brackets, the brackets are not closed!!!\n", counter_Skobka_Kvadrat+counter_Skobka_Kvadrat2);
    }
    else printf("%d square brackets, the brackets are closed.\n", counter_Skobka_Kvadrat+counter_Skobka_Kvadrat2);

    if (counter_Skobka_figura != counter_Skobka_figura2)
    {
        printf("%d braces, braces are not closed!!!\n\n", counter_Skobka_figura+counter_Skobka_figura2);
    }
    else printf("%d braces, braces are closed.\n\n\n\n\n", counter_Skobka_figura+counter_Skobka_figura2);
}

int main()
{
    ex1_18();
    return(0);
}
