#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "encryption.h"

#define MAX_CREDENTIALS 100
#define KEY 'K'

// Struct for credentials
typedef struct {
    char website[50];
    char email[50];
    char password[50];
} Credential;

Credential credentials[MAX_CREDENTIALS];
int count = 0;

// Add a new credential
void add_credential() {
    if (count >= MAX_CREDENTIALS) {
        printf("Storage full!\n");
        return;
    }

    Credential c;

    printf("Website: ");
    fgets(c.website, sizeof(c.website), stdin);
    strtok(c.website, "\n");

    printf("Email: ");
    fgets(c.email, sizeof(c.email), stdin);
    strtok(c.email, "\n");

    printf("Password: ");
    fgets(c.password, sizeof(c.password), stdin);
    strtok(c.password, "\n");

    xor_encrypt(c.password, KEY);
    credentials[count++] = c;

    printf("✅ Credential saved (in memory).\n");
}

// View all credentials
void view_credentials() {
 if (count == 0) {
        printf("No credentials stored.\n");
        return;
    }

    printf("\n--- Saved Credentials ---\n");
    for (int i = 0; i < count; i++) {
        xor_encrypt(credentials[i].password, KEY);
        printf("Website: %s\nEmail: %s\nPassword: %s\n\n",
               credentials[i].website, credentials[i].email, credentials[i].password);
        xor_encrypt(credentials[i].password, KEY); // re-encrypt
    }
}

// Search for a credential by website
void search_credential() {
    char target[50];
    int found = 0;

    printf("Enter website to search: ");
    fgets(target, sizeof(target), stdin);
    strtok(target, "\n");

    for (int i = 0; i < count; i++) {
        if (strcmp(credentials[i].website, target) == 0) {
            xor_encrypt(credentials[i].password, KEY);
            printf("\nWebsite: %s\nEmail: %s\nPassword: %s\n",
                   credentials[i].website, credentials[i].email, credentials[i].password);
            xor_encrypt(credentials[i].password, KEY);
            found = 1;
            break;
        }
    }

    if (!found) printf("No record found for '%s'.\n", target);
}

// Delete a credential by website
void delete_credential() {
    char target[50];
    int found = 0;

    printf("Enter website to delete: ");
    fgets(target, sizeof(target), stdin);
    strtok(target, "\n");

    for (int i = 0; i < count; i++) {
        if (strcmp(credentials[i].website, target) == 0) {
            for (int j = i; j < count - 1; j++) {
                credentials[j] = credentials[j + 1];
            }
            count--;
            found = 1;
            break;
        }
    }

    if (found)
        printf("✅ Credential deleted.\n");
    else
        printf("No record found for '%s'.\n", target);
}


  
