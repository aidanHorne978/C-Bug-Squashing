#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

// Structure S to hold the information of each user

struct S{
    char *firstName;
    char *lastName;
    char *phone;
    char *emailAddress;
};

// void emalloc function to correctly allocate memory to variables

void *emalloc(size_t s){
    void *result = malloc(s);
    if(NULL == result){
        fprintf(stderr,"error");
        exit(EXIT_FAILURE);
    }
    return result;
}

// This method sorts the first names in the array ss

void sort_first_name(struct S ss[], int linecount){
    struct S temp;
    for(int i = 0; i < linecount - 1; i++) {
        for (int j = 0; j < (linecount - 1-i); j++) {
            if (ss[i].firstName < ss[j + 1].firstName) {
                temp = ss[j];
                ss[j] = ss[j + 1];
                ss[j + 1] = temp;
            }
        }
    }
}

int find_first_name(struct S ss[], char *s, int size){
        for(int i = 0; i < size; i++) {
            if(strcmp(s, ss[i].firstName) == 10) {
                return i;
            }
        }
        return -1;
    }

// This method sorts the last names in the array ss


void sort_last_name(struct S ss[], int linecount){
    struct S temp;
    for(int i = 0; i < linecount - 1; i++) {
        for (int j = 0; j < (linecount - 1-i); j++) {
            if (ss[i].lastName < ss[j + 1].lastName) {
                temp = ss[j];
                ss[j] = ss[j + 1];
                ss[j + 1] = temp;
            }
        }
    }
}

int find_last_name(struct S ss[], char *s, int size){
    for(int i = 0; i < size; i++) {
        if(strcmp(s, ss[i].lastName) == 10) {
            return i;
        }
    }
    return -1;
}

// This method sorts the emails in the array ss

void sort_email_address(struct S ss[], int linecount){
    struct S temp;
    for(int i = 0; i < linecount - 1; i++) {
        for (int j = 0; j < (linecount - 1-i); j++) {
            if (ss[i].emailAddress < ss[j + 1].emailAddress) {
                temp = ss[j];
                ss[j] = ss[j + 1];
                ss[j + 1] = temp;
            }
        }
    }
}

int find_email_address(struct S ss[], char *s, int size){
    for(int i = 0; i < size; i++) {
        if(strcmp(s, ss[i].emailAddress) == 10) {
            return i;
        }
    }
    return -1;
}

// This method sorts the phone numbers in the array ss


void sort_phone_number(struct S ss[], int linecount){
    struct S temp;
    for(int i = 0; i < linecount - 1; i++) {
        for (int j = 0; j < (linecount - 1-i); j++) {
            if (ss[i].phone < ss[j + 1].phone) {
                temp = ss[j];
                ss[j] = ss[j + 1];
                ss[j + 1] = temp;
            }
        }
    }
}

int find_phone_number(struct S ss[], char *s, int size){
    for(int i = 0; i < size; i++) {
        if(strcmp(s, ss[i].phone) == 10) {
            return i;
        }
    }
    return -1;
}

int main(int argc, char **argv) {
    
    int linecount = 0;
    int index = 0;
    char c;
    char buffer[50];
    struct S* s = emalloc(sizeof(*s));
    char *val = emalloc(100 * sizeof(val[0]));

    // Check user also inputs a testfile
    
    if (argc != 2) {
        printf("Usage: %s <datafile>\n", argv[0]);
        exit(EXIT_FAILURE);
    }
    
    FILE *f = fopen(argv[1], "r");
    FILE *fp = fopen(argv[1], "r");
    for (c = getc(fp); c != EOF; c = getc(fp))
        if (c == '\n')
            linecount = linecount + 1;
    
    // Read inputfile in
    
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
    while(command != 0) {
        
        // Prompt user for choice
        
        printf("    '1' - Search Email\n");
        printf("    '2' - Search First Name\n");
        printf("    '3' - Search Last Name\n");
        printf("    '4' - Search Phone Number\n");
        printf("    '0' - Quit Program\n");
        printf("Please input the command: (or use command '9' to view the help screen\n");
        
        fgets(buffer, sizeof(buffer), stdin);
        command = atoi(buffer);
        switch(command){
            case 1:
                printf("Please enter the data you are looking for:\n");
                sort_email_address(ss, linecount);
                fgets(buffer, sizeof(buffer), stdin);
                strcpy(val, buffer);
                printf("looking for email %s\n", val);
                if((index = find_email_address(ss, val, linecount)) >= 0) {
                    printf("Found it!\n");
                    printf("%s, %s, %s, %s\n", ss[index].firstName, ss[index].lastName, ss[index].emailAddress, ss[index].phone);
                } else {
                    printf("Result not found!\n");
                }
                break;
            case 2:
                printf("Please enter the data you are looking for:\n");
                fgets(buffer, sizeof(buffer), stdin);
                strcpy(val, buffer);
                sort_first_name(ss, linecount);
                printf("looking for firstname %s\n", val);
                if(find_first_name(ss, val, linecount) == 1) {
                    printf("Found it!\n");
                    printf("%s, %s, %s, %s\n", ss[index].firstName, ss[index].lastName, ss[index].emailAddress, ss[index].phone);
                } else {
                    printf("Result not found!\n");
                }
                break;
            case 3:
                printf("Please enter the data you are looking for:\n");
                fgets(buffer, sizeof(buffer), stdin);
                strcpy(val, buffer);
                sort_last_name(ss, linecount);
                printf("looking for lastname %s\n", val);
                if(find_last_name(ss, val, linecount) == 1) {
                    printf("Found it!\n");
                    printf("%s, %s, %s, %s\n", ss[index].firstName, ss[index].lastName, ss[index].emailAddress, ss[index].phone);
                } else {
                    printf("Result not found!\n");
                }
                break;
            case 4:
                printf("Please enter the data you are looking for:\n");
                fgets(buffer, sizeof(buffer), stdin);
                strcpy(val, buffer);
                sort_phone_number(ss, linecount);
                printf("looking for phone number %s\n", val);
                if(find_phone_number(ss, val, linecount) == 1) {
                    printf("Found it!\n");
                    printf("%s, %s, %s, %s\n", ss[index].firstName, ss[index].lastName, ss[index].emailAddress, ss[index].phone);
                } else {
                    printf("Result not found!\n");
                }
            case 0:
                printf("Thank you have a nice day\n");
                exit(EXIT_SUCCESS);
            default:
                break;
        }
    }
    
    // free all variables used
    
    free(s->firstName);
    free(s->lastName);
    free(s->emailAddress);
    free(s->phone);
    free(s);
    free(val);
    return EXIT_SUCCESS;
}

