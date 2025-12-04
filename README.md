# 🔐 Password Manager in C

## 📌 Project Summary
This project is a console-based password manager developed in C. It allows users to store, retrieve, search, and delete login credentials locally. It demonstrates key programming concepts such as file handling, dynamic memory management, and pointer-based string manipulation.  

## ✨ Features
- Add new credentials (website, username, password)
- View all saved credentials
- Search credentials by website or username
- Delete credentials
- Persistent storage in a text file (`credentials.txt`)
  
## 🧠 Concepts Demonstrated
- **Structures and functions**: Used to define and manipulate credential records  
- **File operations**: `fopen`, `fprintf`, `fscanf`, `remove`, `rename` for persistent storage  
- **Pointer-based string manipulation**: For input parsing and dynamic handling  
- **Dynamic memory management**: Allocating memory for credential arrays and strings  
- **Modular programming using header files**: Organized into reusable components for clarity and scalability  

## 📁 Directory Structure
**PasswordManager/**
- `docs/`  
  - `ProjectReport.pdf`
- `include/`  
  - `passwords.h`
- `src/`  
  - `main.c`
  - `passwords.c`
- `README.md`

## 🧾 How to Use
- Compile the program using a C compiler 
- Run the executable from the terminal
- Choose from the menu:
  - Add a new credential  
  - View all credentials  
  - Search by website or username  
  - Delete a credential  
- Credentials are stored in `credentials.txt` in plain text format

## 🔒 Security Notes
- Passwords are stored in plain text for simplicity    

## 👤 Author
- **Surya Prakash Sharma**: Sole developer  
 

## 📄 Report
Refer to `docs/ProjectReport.pdf` for a detailed academic write-up including:  
- System architecture  
- Implementation details    
- Testing and results  
- Future improvements

