#include<stdio.h>
#include<conio.h>
int frequency_count(char*s, char c)
{
    int count=0, i;
    for (i=0; s[i]!='\0'; i++)
{
if (s[i]==c)
 count++;
}
return count;
}
int main()
{
    int f;
    char s[]="everything is gonna be okay";
    printf("characters \t frequency \n");
    char i;
    for (i='a'; i<='z ; i++')
    {
        for (i=0; s[i]!='\0';i++)
        {
            if (s[i]==c)
            count++;
        }
        return count;
    }
    int main()
    {
        int f;
        char s[] = "everything is gonna be okay";
        printf("characters \t frequency \n");
        char i;
        for (i='a'; i<='z'; i++)
        {
            f = frequency_count(s,i);
            printf("%c \t %d\n", i, f);
        }
    }
    return 0;
}