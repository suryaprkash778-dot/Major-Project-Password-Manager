#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "encryption.h"   // your xor_encrypt() function

#define MAX_CREDENTIALS 100
#define KEY 'K'
#define FILE_NAME "credentials.txt"

// Struct for credentials
typedef struct {
    char website[50];
    char email[50];
    char password[50];
} Credential;

Credential credentials[MAX_CREDENTIALS];
int count = 0;

// Save credentials to text file
void save_to_file() {
    FILE *fp = fopen(FILE_NAME, "w");
    if (!fp) {
        printf("Error saving file!\n");
        return;
    }
    for (int i = 0; i < count; i++) {
        // store encrypted password in file
        fprintf(fp, "%s|%s|%s\n",
                credentials[i].website,
                credentials[i].email,
                credentials[i].password);
    }
    fclose(fp);
    printf("✅ Credentials saved to text file.\n");
}

// Load credentials from text file
void load_from_file() {
    FILE *fp = fopen(FILE_NAME, "r");
    if (!fp) return; // no file yet

    char line[200];
    while (fgets(line, sizeof(line), fp)) {
        Credential c;
        // parse line: website|email|password
        sscanf(line, "%49[^|]|%49[^|]|%49[^\n]",
               c.website, c.email, c.password);
        credentials[count++] = c;
    }
    fclose(fp);
    if (count > 0)
        printf("✅ Loaded %d credentials from text file.\n", count);
}

// Add a new credential
void add_credential() {
    if (count >= MAX_CREDENTIALS) {
        printf("Storage full!\n");
        return;
    }

    Credential c;

    printf("Website: ");
    fgets(c.website, sizeof(c.website), stdin);
    c.website[strcspn(c.website, "\n")] = '\0';

    printf("Email: ");
    fgets(c.email, sizeof(c.email), stdin);
    c.email[strcspn(c.email, "\n")] = '\0';

    printf("Password: ");
    fgets(c.password, sizeof(c.password), stdin);
    c.password[strcspn(c.password, "\n")] = '\0';

    xor_encrypt(c.password, KEY); // encrypt before storing
    credentials[count++] = c;

    printf("✅ Credential saved (in memory).\n");
    save_to_file(); // persist immediately
}

// View all credentials
void view_credentials() {
    if (count == 0) {
        printf("No credentials stored.\n");
        return;
    }

    printf("\n--- Saved Credentials ---\n");
    for (int i = 0; i < count; i++) {
        xor_encrypt(credentials[i].password, KEY); // decrypt temporarily
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
    target[strcspn(target, "\n")] = '\0';

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
    target[strcspn(target, "\n")] = '\0';
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

    if (found) {
        printf("✅ Credential deleted.\n");
        save_to_file(); // update file after deletion
    } else {
        printf("No record found for '%s'.\n", target);
    }
}
