#include <stdio.h>
#include <limits.h>
#include <float.h>
#include <math.h>

#define MAXLINE 3000

void ex1_1()
{
    printf("Hello, World!\n");
}
//
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

int deleteEmptySeuquences(char to[], char from[])
{
    int j = 0, isEmptySequence = 0;
    for (int i = 0; from[i] != '\0'; i++) {
        if (from[i] == ' ' || from[i] == '\t' || from[i] == '\n') {
            if (!isEmptySequence) {
                isEmptySequence = 1;
                to[j++] = from[i];
            }
        } else {
            to[j++] = from[i];
            isEmptySequence = 0;
        }
    }
    to[j] = '\0';
    return j;
}

void ex1_18()
{
    printf ("Delete excess spaces, tabulations at the end of the every string and empty strings(EOF for exit):\n");
    char line[1000] = "";
    while ( line[0]  != EOF ) {
        int len = 0;
        while ( (line[len] = getchar()) != '\n')
            len++;
        printf("Result string [length]: ");
        if (len == 0)
            printf("[%d] The string is empty.\n", len);
        else {
            while ( line[len] == '\t' || line[len] == ' ' || line[len] == '\n')
                len--;
            line[++len] = '\0';
            printf("[%d] %s\n", len, line);
        }
    }
    char string_1[] = "Word_1, 3 spaces   2 tabs\t\t. Next line.\n"
                      "Empty two lines.\n\n"
                      "Last line...\n";
    printf("Testing clear function, source string is:\n%s", string_1);
    deleteEmptySeuquences(line, string_1);
    printf("Destination string after calling 'deleteEmptySequences' function:\n%s", line);
}

void reverse(char to[], char from[])
{
    int c = 0;
    int d = 0;
    while (from[c]) c++;
    c--;
    while( c >= 0 )
        to[d++] = from[c--];
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
    int tab = 8, len = 0, j = 0, column = 0;
    for ( int templengthA = 0; from[templengthA] != 0; templengthA++ )
    {
        len = templengthA;
    }
    for ( int i = 0 ; i <= len ; i++) {
        if ( from[i] == '\t' )
            do {
            column++;
            to[j++] = ' ';
        } while (column%tab);
        else {
            if ( from[i] == '\n')
                column = 0;
            else column++;
            to[j++] = from[i];
        }
    }
    to[j] = '\0';
}

void entab(char to[], char from[])
{
    int tab = 8, len = 0, j = 0, column = 0, spaces = 0;
    for ( int templengthA = 0; from[templengthA] != 0; templengthA++ )
    {
        len = templengthA;
    }
    for ( int i = 0 ; i <= len ; i++) {
        if ( from[i] == '\t' )
            column += ( tab - column%tab );
        else
            column++;
        if ( from[i] == ' ' ) {
            spaces++;
            if (!(column%tab)) {
                spaces = 0;
                to[j++] = '\t';
            }
        } else {
            for (int g = 0; g < spaces; g++)
                to[j++] = ' ';
            spaces = 0;
            if ( from[i] == '\n' )
                column = 0;
            to[j++] = from[i];
        }
    }
    to[j] = '\0';
}

void ex1_20_21()
{
    printf("Programm include ex1_20 & ex1_21. Working with tabs and spaces.\n\n");
    printf("Enter string:\n1\t2\t3\t4\t5\t6\t7\n");
    char A[3000];
    for ( int i = 0 ; i < 3000 ; i++) A[i] = 0;
    char B[3000];
    for ( int i = 0 ; i < 3000 ; i++) B[i] = 0;
    int length;
    while ( ( length = getline(A, 3000)) > 0 )
    {
        detab(B,A);
        printf("%s  - ex1_20\n" , B);
        for ( int i = 0 ; i < 3000 ; i++) A[i] = 0;
        entab(A,B);
        printf("%s  - ex1_21\n\n", A);
    }
}

int get_fix_line(char s[], int lim)
{
    int counter = 1;
    int in = 1;
    int c;
    int i = 0;
    int g = 0;
    for ( i = 0 ; g < lim-1 && (c = getchar()) != '\n' ; ++i )
    {
        if ( c == ' ' || c == '\t' )
        {
            counter = 0;
            in = 0;
            s[i] = c;
        }
        else
        {
            s[i] = c;
            counter++;
        }

        if ( (g >= lim-2) && in == 0 )
        {
            s[(i-counter)] = '\n';
            g = counter;
            in = 1;
            g++;
        }
    }
    s[i] = '\0';
    //printf("%s\n", s);
    //printf("%d %d %d %d\n\n", counter, g, i, lim ); //debug line
    return i;
}


void ex1_22()
{
    printf("A string longer than 20 characters is cut and transferred\n");
    int length;
    char line[2000];
    for (int i = 0; i < 2000; i++) line[i]=0;
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


//<--------------Chapter 2--------------------->//

long power(int base, unsigned int n)
{
    long p = 1;
    for (unsigned int i = 1; i <= n; ++i)
        p = p * base;
    return p;
}

void ex2_1()
{
    printf("Integer datatypes:\n\n");
    printf("Signed types:\tmin:\t\t\tmax:\n");
    printf("char\t\t%d\t\t\t%d\n", CHAR_MIN, CHAR_MAX);
    printf("int\t\t%d\t\t%d\n", INT_MIN, INT_MAX);
    printf("long\t\t%ld\t%ld\n", LONG_MIN, LONG_MAX);
    printf("short\t\t%d\t\t\t%d\n\n", SHRT_MIN, SHRT_MAX);
    printf("UnSigned types:\tmin:\tmax:\n");
    printf("unsigned char\t%u\t%u\n", 0, UCHAR_MAX);
    printf("unsigned int\t%u\t%u\n", 0, UINT_MAX);
    printf("unsigned long\t%u\t%lu\n", 0, ULONG_MAX);
    printf("unsigned short\t%u\t%u\n\n", 0, USHRT_MAX);
    printf("Float & double datatypes:\n");
    printf("float\t\t%e\t%e\n", FLT_MIN, FLT_MAX);
    printf("double\t\t%e\t%e\n\n", DBL_MIN, DBL_MAX);
    printf("The calculated values of data types:\n\n");
    printf("Type:\tsigned min:\t\tsigned max:\t\tunsigned max:\n");
    char charValue = 1;
    short shortValue = 1;
    int intValue = 1;
    long longValue = 1;
    int radix = 2, bitCounter = 1;
    while ( (charValue *= radix) )
        bitCounter++;
    printf("char\t%ld\t\t\t%ld\t\t\t%lu\n", power(radix, bitCounter-1)*(-1), power(radix, bitCounter-1)-1, power(radix, bitCounter)-1);
    bitCounter = 1;
    while ( (shortValue *= radix) )
        bitCounter++;
    printf("short\t%ld\t\t\t%ld\t\t\t%lu\n", power(radix, bitCounter-1)*(-1), power(radix, bitCounter-1)-1, power(radix, bitCounter)-1);
    bitCounter = 1;
    while ( (intValue *= radix) )
        bitCounter++;
    printf("int\t%ld\t\t%ld\t\t%lu\n", power(radix, bitCounter-1)*(-1), power(radix, bitCounter-1)-1, power(radix, bitCounter)-1);
    bitCounter = 1;
    while ( (longValue *= radix) )
        bitCounter++;
    printf("long\t%ld\t%ld\t%lu\n", power(radix, bitCounter-1)*(-1), power(radix, bitCounter-1)-1, power(radix, bitCounter)-1);
    float p3;
    float p32 = 1;
    double p4;
    double p42;
    printf("\nFloat & double datatypes:\n\n");
    for (p3 = 1 ; isfinite(p3)==true;)
    {
        p32 = p3;
        p3 *= 1.01;
    };
    printf("float max: %e\n", p32);
    for ( p4 = 1 ; isfinite(p4) == true;)
    {
        p42 = p4;
        p4*=1.01;
    }
    printf("double max: %e\n", p42);
}

void ex2_2()
{
    printf("Some text about this programm...\n");
    const int lim = 10;
    enum End { no, yes };
    End isEnd = no;
    char s[lim];
    for (int x = 0; x < lim; x++) s[x] = 0;
    int c, i = 0;
    while ( isEnd != yes )
        if ( ( c = getchar() ) != EOF && c != '\n' && i < lim-1)
            s[i++] = c;
        else
            isEnd = yes;
    if ( c == '\n' ) {
        s[i] = c;
        ++i;
    }
    s[i] = '\0';
    printf("\nResult string, length = %d: %s\n", i, s);
}

int is_digit(char c)
{
    return ( c >= '0' && c <= '9' );
}

int is_alpha(char c)
{
    return ( ( c >= 'a' && c <= 'z' ) || ( c >= 'A' && c <= 'Z' ) );
}

void small_to_big(char s[])
{
    int a, b;
    for ( a = 0; s[a] != '\0'; a++ ) {
        b = s[a];
        if ( b >= 'a' && b <= 'z' )
            s[a] = b - ('a' - 'A');
    }
}

void big_to_small(char s[])
{
    int a, b;
    for ( a = 0; s[a] != '\0'; a++){
        b = s[a];
        if ( b >= 'A' && b <= 'Z' )
            s[a] = b + ('a' - 'A');
    }
}

char to_upper(char c)
{
    if (c >= 'a' && c <= 'z')
        return c - ('a' - 'A');
    else
        return c;
}

char to_lower(char c)
{
    if (c >= 'A' && c <= 'Z')
        return c + ('a' - 'A');
    else
        return c;
}

int htoi(char s[])
{
    int i = 0, A = 0;
    for( i = 0 ; s[i] != '\0' ; i++ ) {
        char c = to_upper(s[i]);
        if ( is_digit(c) )
            A = A * 16 + (c - '0');
        else if ( c >= 'A' && c <= 'F' )
            A = A * 16 + (10 + c - 'A');
    }
    return A;
}

void ex2_3()
{
    int x = 0;
    int lenght;
    printf("Demostration work function 'htoi' \n");
    char line[MAXLINE];
    while ( ( lenght = getline(line, MAXLINE) ) > 0 )
    {
        small_to_big(line);
        x = htoi(line);
        printf("%d\n", x);
    }
}

void squeeze(char s1[], char s2[])
{
    int a, b, c;
    for ( c = 0; s2[c] != '\0'; c++ ) {
        for ( a = b = 0 ; s1[a] != '\0'; a++ )
            if ( s2[c] != s1[a] )
                s1[b++] = s1[a];
        s1[b] = '\0';
    }
}

void ex2_4()
{
    char s1[] = "dcabcaddda";
    char s2[] = "ddaa";
    printf("Original strings:\ns1 = %s\ns2 = %s\n\n", s1, s2);
    squeeze(s1, s2);
    printf("Result: %s\n\n", s1);
}

int any( char s1[], char s2[])
{
    int a = 0, b = 0;
    while ( s1[a] != '\0' ) {
        b = 0;
        while ( s2[b] != '\0' ) {
            if ( s1[a] == s2[b])
                return (a + 1);
            b++;
        }
        a++;
    }
    return -1;
}

void ex2_5()
{
    printf("Testing function 'int any(char s1[], char s2[]);'\n");
    printf("1234567890 - simple table character position.\n");
    char s1[] = "abccde";
    char s2[] = "edf";
    printf("Source strings:\n%s\n%s\nPosition find at: %d\n",s1, s2, any(s1, s2));
}

void dec_bin (unsigned char dec, char bin2[]) //----myself realization - MORE LINES - MORE POWER! MUA HA HA!
{
/*    const int bitsPerByte = 8;
    for (int i = bitsPerByte-1; i >= 0; i--) {
        bin[i] = '0' + (dec & 0x01);
        dec = dec >> 1;
    }
    bin[bitsPerByte] = '\0';
*/
    char bin[64];
    for (int i = 0; i < 64; i++) bin[i] = '\0';
    for (int i = 0; i < 64; i++) bin2[i] = '\0';
    int a = 0, b = 0;
    while (dec >= 1) {
        if (dec%2)
            bin[a] = '1';
        else
            bin[a] = '0';
        a++;
        dec = dec/2;
    }
    a--;
    while ( a >= 0 )
        bin2[b++] = bin[a--];
    bin2[b] = 0;
}

unsigned int setbits(unsigned x, int p, int n, unsigned y)
{
    unsigned int a = 1, b = 0;
    int z = n;
    while ( n > 0 ) {           // Prepare bit mask...
        b = b | a;
        a = a << 1;
        n--;
    }
    a = b;
    z = ( p - z ) + 1;
    if ( z < 0) {
        printf("\nInvalid value, 'p' must be greater than 'n'\n");
        getchar();
        return (0);
    }
    a = a << z;
    a = ~a;
    x = x & a;
    b = b & y;
    b = b << z;
    x = x | b;
    return x;
}

void ex2_6()
{
    char bin[64];
    unsigned x = 204, x2, y = 179;
    int p = 6, n = 4;
    printf("Result of function 'unsigned int setbits(unsigned x, int p, int n, unsigned y);', where P = %d, N = %d.\n\n", p, n);
    printf("Variable:\tBinary:\t\tDecimal:\n\n");
    dec_bin(x, bin);
    printf("X\t\t%s\t%d\n",bin, x);
    dec_bin(y, bin);
    printf("Y\t\t%s\t%d\n", bin, y);
    x2 = setbits(x,p,n,y);
    dec_bin(x2, bin);
    printf("Result:\t\t%s\t%d\n\n",bin, x2);
}

unsigned int invert(unsigned x,int p, int n)
{
    unsigned int a = 1, b = 0, y;
    int z = n;
    while (n > 0) {                 // bit mask
        b = b | a;
        a = a << 1;
        n--;
    }
    a = b;
    z = ( p - z ) + 1;
    if ( z < 0) {
        printf("\nInvalid value, 'p' must be greater than 'n'\n");
        getchar();
        return (0);
    }
    b = b << z;
    b = b & x;
    b = b >> z;
    b = ~b;
    y = b;
    b = a;
    a = a << z;
    a = ~a;
    x = x & a;
    b = b & y;
    b = b << z;
    x = x | b;
    return x;
}

void ex2_7()
{
    char bin[64];
    unsigned x = 204, x2;
    int p = 6, n = 4;
    printf("Result of function 'unsigned int invert(unsigned x, int p, int n);', where P = %d, N = %d.\n\n", p, n);
    printf("Variable:\tBinary:\t\tDecimal:\n\n");
    dec_bin(x, bin);
    printf("X\t\t%s\t%d\n",bin, x);
    x2 = invert(x,p,n);
    dec_bin(x2, bin);
    printf("Result:\t\t%s\t%d\n\n",bin, x2);
}

unsigned int rightrot( unsigned x, int n)
{
    while ( n > 0 ) {
        x = x >> 1;
        n--;
    }
    return x;
}

void ex2_8()
{

    char bin[64];
    unsigned x = 0xFF, x2;
    int n = 2;
    printf("Result of function 'unsigned int rightrot(unsigned x, int n);', where N = %d.\n\n", n);
    printf("Variable:\tBinary:\t\tDecimal:\n\n");
    dec_bin(x, bin);
    printf("X\t\t%s\t%d\n",bin, x);
    x2 = rightrot(x, n);
    dec_bin(x2, bin);
    printf("Result:\t\t%s\t%d\n\n",bin, x2);
}

int bitcount (unsigned x)
{
    int b;
    for ( b = 0; x != 0; x &= ( x - 1 ) )
        b++;
    return b;
}

void ex2_9()
{
    printf("Count 1 bits in argument of function 'int bitcount(unsigned x);'.\n\n");
    unsigned a = 0xEF, b;
    char bin[64];
    dec_bin(a, bin);
    b = bitcount(a);
    printf("Result: %d, binary %s, 1 bits = %d.\n\n", a, bin, b);
}

int lower(int c)
{
    return (( c >= 'A' && c <= 'Z' ) ? c + ('a' - 'A') : c);
}

void ex2_10()
{
    int a, c;
    char b[] = "MAMA MYLA RAMY";
    printf("Testing function 'int lower(int c);'.\n%s - source string.\n", b);
    for(a = 0; b[a] != 0; a++ ) {
        c = lower(b[a]);
        printf("%c", c);
    }
    printf(" - result string.\n");
}

char* function_1(int a, char s[])
{
    for (int i = 0; i < a; i++)
        s[i] = 'a' + i;
    s[a] = '\0';
    return s;
}


int main()
{
//   ex2_10();
//   char string[16];
//   printf("Result of 'char* function_1(int a, char s[])': %s\n", function_1(7, string));
//   return(0);
    ex2_7();
    return(0);
}
