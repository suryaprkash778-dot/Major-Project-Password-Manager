# 🔐 Password Manager in C

## 📌 Project Summary
This project is a secure, console-based password manager developed in C. It allows users to store, retrieve, search, and delete login credentials locally. Passwords are encrypted using a simple XOR cipher before being saved to a binary file. The program is modular, user-friendly, and demonstrates key programming concepts such as file handling, dynamic memory management, and pointer-based string manipulation.

## ✨ Features
- Add new credentials (website, username, password)
- View all saved credentials
- Search credentials by website or username
- Delete credentials
- Encrypt/decrypt passwords using XOR cipher
- Optional master password protection

## 🧠 Concepts Demonstrated
- **Structures and functions**: Used to define and manipulate credential records
- **File operations**: `fopen`, `fwrite`, `fread`, `remove`, `rename` for persistent storage
- **Pointer-based string manipulation**: For encryption, input parsing, and dynamic handling
- **Dynamic memory management**: Allocating memory for credential arrays and strings
- **Modular programming using header files**: Organized into reusable components for clarity and scalability

## 📁 Directory Structure

**PasswordManager/**
- `docs/`
  - `ProjectReport.pdf`
- `include/`
  - `passwords.h`
  - `encryption.h`
  - `auth.h`
  - `vault.dat`
- `src/`
  - `main.c`
  - `passwords.c`
  - `encryption.c`
  - `storage.c`
  - `auth.c`
- `README.md`

## 🧾 How to Use
- Launch the program and enter the master password (if enabled)
- Choose from the menu:
- Add a new credential
- View all credentials
- Search by site or username
- Delete a credential
- All passwords are encrypted before saving and decrypted when viewed

## 🔒 Security Notes
- Passwords are encrypted using a basic XOR cipher for demonstration purposes
- For real-world applications, consider using stronger encryption algorithms (e.g., AES) and secure storage practices

## 👥 Team Contributions
- Surya: Core logic, encryption module, input handling, documentation
- [Teammate Name]: File I/O, search/delete features, testing and validation

## 📄 Report
Refer to ProjectReport.pdf for a detailed academic write-up including:
- System architecture
- Implementation details
- Challenges faced
- Testing and results
- Future improvements

