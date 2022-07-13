#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

struct S{
    char *firstName;
    char *lastName;
    char *phone;
    char *emailAddress;
};

static int i, j;
static int count;

void first_name(struct S ss[]){
    for(i = 0; i < count; i++) {
        for (j = 0; j < count; j++) {
            if (ss[i].firstName > ss[j].firstName)
                ss[i] = ss[j];
                ss[j] = ss[i];
        }
    }
}

void *emalloc(size_t s){
    void *result = malloc(s);
    if(NULL == result){
        fprintf(stderr,"error");
        exit(EXIT_FAILURE);
    }
    return result;
}

int ffn(struct S ss[], char *s, int size){
        for(int i = 0; i < size; i++) {
            if(strcmp(s, ss[i].firstName) == 10) {
                return 1;
            }
        }
        return 0;
    }

void last_name(struct S ss[]){
    for(i = 0; i < count; i++) {
        for (j = 0; j < count; j++) {
            if (ss[i].lastName > ss[j].lastName) {
                ss[i] = ss[j];
                ss[j] = ss[i];
            }
        }
    }
}

int fln(struct S ss[], char *s, int size){
    for(int i = 0; i < size; i++) {
        if(strcmp(s, ss[i].lastName) == 10) {
            return 1;
        }
    }
    return 0;
}

void email_address(struct S ss[], int size){
    for(i = 0; i < size; i++) {
        for(j = 1; j < size; j++) {
            if(ss[i].emailAddress > ss[j].emailAddress) {
                struct S *s = &ss[i];
                ss[j] = ss[i];
                ss[j] = *s;
            }
        }
    }
}

int fem(struct S ss[], char *s, int size){
    for(int i = 0; i < size; i++) {
        if(strcmp(s, ss[i].emailAddress) == 10) {
            return 1;
        }
    }
    return 0;
}

void phone_number(struct S ss[]){
    for(i = 0; i < count; i++) {
        for (j = 0; j < count; j++) {
            if (ss[i].phone > ss[j].phone) {
                struct S *s = &ss[i];
                ss[i] = ss[j];
                ss[j] = *s;
            }
        }
    }
}

int fph(struct S ss[], char *s, int size){
    for(int i = 0; i < size; i++) {
        if(strcmp(s, ss[i].phone) == 10) {
            return 1;
        }
    }
    return 0;
}

int main(int argc, char **argv) {
    int linecount = 0;
    char c;
    char buffer[50];
    struct S* s = emalloc(sizeof(*s));
    char *val = emalloc(sizeof(val[0]));

    if (argc != 2) {
        printf("Usage: %s <datafile>\n", argv[0]);
        exit(EXIT_FAILURE);
    }
    
    FILE *f = fopen(argv[1], "r");
    FILE *fp = fopen(argv[1], "r");
    for (c = getc(fp); c != EOF; c = getc(fp))
        if (c == '\n')
            linecount = linecount + 1;
    
    struct S ss[linecount + 5];
    for(int i = 0; i < linecount; i++){
        
        s->firstName = emalloc(sizeof(s->firstName[0]));
        s->lastName = emalloc(sizeof(s->lastName[0]));
        s->emailAddress = emalloc(sizeof(s->emailAddress[0]));
        s->phone = emalloc(sizeof(s->phone[0]));
        
        fscanf(f, "%s %s %s %s", s->firstName, s->lastName, s->phone, s->emailAddress);
        
        ss[i] = *s;
    }

    int command = 10;
    while(command != 0){
        
        printf("    '1' - Search Email\n");
        printf("    '2' - Search First Name\n");
        printf("    '3' - Search Last Name\n");
        printf("    '4' - Search Phone Number\n");
        printf("Please input the command: (or use command '9' to view the help screen\n");
        
        fgets(buffer, sizeof(buffer), stdin);
        command = atoi(buffer);
        switch(command){
            case 1:
                printf("Please enter the data you are looking for:\n");
                fgets(buffer, sizeof(buffer), stdin);
                strcpy(val, buffer);
                printf("looking for email %s\n", val);
                if(fem(ss, val, linecount) == 1) {
                    printf("Found it!\n");
                } else {
                    printf("Result not found!\n");
                }
                break;
            case 2:
                printf("Please enter the data you are looking for:\n");
                fgets(buffer, sizeof(buffer), stdin);
                strcpy(val, buffer);
                printf("looking for firstname %s\n", val);
                if(ffn(ss, val, linecount) == 1) {
                    printf("Found it!\n");
                } else {
                    printf("Result not found!\n");
                }
                break;
            case 3:
                printf("Please enter the data you are looking for:\n");
                fgets(buffer, sizeof(buffer), stdin);
                strcpy(val, buffer);
                printf("looking for lastname %s\n", val);
                if(fln(ss, val, linecount) == 1) {
                    printf("Found it!\n");
                } else {
                    printf("Result not found!\n");
                }
                break;
            case 4:
                printf("Please enter the data you are looking for:\n");
                fgets(buffer, sizeof(buffer), stdin);
                strcpy(val, buffer);
                printf("looking for phone number %s\n", val);
                if(fph(ss, val, linecount) == 1) {
                    printf("Found it!\n");
                } else {
                    printf("Result not found!\n");
                }
            default:
                break;
        }
    }
    free(s->firstName);
    free(s->lastName);
    free(s->emailAddress);
    free(s->phone);
    free(ss);
    free(s);
    return EXIT_SUCCESS;
}

