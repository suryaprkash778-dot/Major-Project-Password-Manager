// Main menu
int main() {
    int choice;

    load_from_file(); // load existing credentials at startup

    do {
        printf("\n=== Password Manager (Plain Text Storage) ===\n");
        printf("1. Add Credential\n");
        printf("2. View All Credentials\n");
        printf("3. Search by Website\n");
        printf("4. Delete Credential\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        getchar(); // consume newline

        switch (choice) {
            case 1: add_credential(); break;
            case 2: view_credentials(); break;
            case 3: search_credential(); break;
            case 4: delete_credential(); break;
            case 5: printf("Exiting...\n"); break;
            default: printf("Invalid choice. Try again.\n");
        }
    } while (choice != 5);

    return 0;
}
