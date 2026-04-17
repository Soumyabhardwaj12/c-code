#include<stdio.h>
#include<string.h>
struct regis {
    char name[100];
    char userid[100];
    char passcode[100];
};
typedef struct regis r;
struct item {
    char book_title[100];
    int copies;
};
typedef struct item library;
void new_register() {
    r reg, temp;
    FILE *f1;
    printf("Enter Your Name : \n");
    scanf(" %[^\n]",reg.name);
    printf("Enter username: \n");
    scanf("%s",reg.userid);
    printf("Enter a Password : ");
    scanf("%s",reg.passcode);
    f1 = fopen("user.dat","rb");
    if(f1 != NULL)
    {
        while(fread(&temp,sizeof(temp),1,f1))
        {
            if(strcmp(reg.userid,temp.userid)==0)
            {
                printf("Username already exists! Try another.\n");
                fclose(f1);
                return;
            }
        }
        fclose(f1);
    }
    
    f1 = fopen("user.dat","ab");
    if(f1 == NULL) {
        printf("File error");
        return;
    }
    fwrite(&reg,sizeof(reg),1,f1);
    fclose(f1);
    printf("Registration Completed !!!\n");
}
int login() {
    r log;
    char userid[100],passcode[100];
    FILE *f2;
    f2 = fopen("user.dat","rb");
    if(f2 == NULL) {
        printf("No users registered yet.\n");
        return 0;
    }
    printf("Enter username  : \n");
    scanf("%s",userid);
    printf("Enter password  : ");
    scanf("%s",passcode);
    while(fread(&log,sizeof(log),1,f2)) {
        if(strcmp(userid,log.userid) == 0 && strcmp(passcode,log.passcode)==0) {
            printf("Login Successful !!");
            fclose(f2);
            return 1;
        }
    }
    fclose(f2);
    return 0;
}
void check_invent() {
    library books[4] = {
        {"Harry Potter",50},
        {"1984",200},
        {"The Alchemist",500},
        {"The Great Gatsby",468}
    };
    printf("\nBook List : \n");
    for(int i=0;i<4;i++) {
        printf("Book : %s | Copies : %d\n",books[i].book_title,books[i].copies);
    }
}
void option_list() {
    printf("1. Register (New Member) \n");
    printf("2. Login (Existing Member) \n");
    printf("Enter your choice (1-2) : ");
}
int main() {
    int ch;
    option_list();
    scanf("%d",&ch);
    switch(ch) {
        case 1 : ch == 1;
                 new_register();
                 break;
        case 2 : ch == 2;
                 if(login()) {
                    check_invent();
                 } else {
                    printf("Invalid Username or Password \n");
                 }
                 break;
        default:
                 printf("Invalid Choice Entered , Try Again !");
    }
    return 0;
}