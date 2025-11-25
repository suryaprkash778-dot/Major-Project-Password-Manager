#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "passwords.h"
#include "encryption.h"

#define FILE_NAME "vault.dat"
#define KEY 'K'

// Add a new credential
void add_credential() {
    Credential c;
    FILE *fp = fopen(FILE_NAME, "ab");

    if (!fp) {
        printf("Error opening file.\n");
        return;
    }

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
    fwrite(&c, sizeof(Credential), 1, fp);
    fclose(fp);

    printf("✅ Credential saved.\n");
}

// View all credentials
void view_credentials() {
    Credential c;
    FILE *fp = fopen(FILE_NAME, "rb");

    if (!fp) {
        printf("No credentials found.\n");
        return;
    }
printf("\n--- Saved Credentials ---\n");
    while (fread(&c, sizeof(Credential), 1, fp)) {
        xor_encrypt(c.password, KEY);
        printf("Website: %s\nEmail: %s\nPassword: %s\n\n",
               c.website, c.email, c.password);
        xor_encrypt(c.password, KEY); // re-encrypt before moving on
    }

    fclose(fp);
}

// Search for a credential by website
void search_credential() {
    char target[50];
    Credential c;
    int found = 0;
    FILE *fp = fopen(FILE_NAME, "rb");

    if (!fp) {
        printf("No credentials found.\n");
        return;
    }

    printf("Enter website to search: ");
    fgets(target, sizeof(target), stdin);
    strtok(target, "\n");

    while (fread(&c, sizeof(Credential), 1, fp)) {
        if (strcmp(c.website, target) == 0) {
            xor_encrypt(c.password, KEY);
            printf("\nWebsite: %s\nEmail: %s\nPassword: %s\n",
                   c.website, c.email, c.password);
            xor_encrypt(c.password, KEY);
            found = 1;
            break;
        }
    }

    fclose(fp);
    if (!found) printf("No record found for '%s'.\n", target);
}

// Delete a credential by website
void delete_credential() {
    char target[50];
 Credential c;
    int found = 0;

    FILE *fp = fopen(FILE_NAME, "rb");
    FILE *temp = fopen("temp.dat", "wb");

    if (!fp || !temp) {
        printf("Error opening files.\n");
        if (fp) fclose(fp);
        if (temp) fclose(temp);
        return;
    }

    printf("Enter website to delete: ");
    fgets(target, sizeof(target), stdin);
    strtok(target, "\n");

    while (fread(&c, sizeof(Credential), 1, fp)) {
        if (strcmp(c.website, target) == 0) {
            found = 1;
            continue; // skip writing this record
        }
        fwrite(&c, sizeof(Credential), 1, temp);
    }

    fclose(fp);
    fclose(temp);

    remove(FILE_NAME);
    rename("temp.dat", FILE_NAME);

    if (found)
        printf("✅ Credential deleted.\n");
    else
        printf("No record found for '%s'.\n", target);
}


  
