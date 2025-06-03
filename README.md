# FLMS - File-Based Login Management System
FLMS is a lightweight console-based C++ application designed for managing user authentication via file storage. It provides secure login, user registration, password recovery, and update features, making it a great learning tool for authentication logic and file I/O in C++.

# Features
✅ User Sign Up with password masking

✅ Secure Login verification

✅ Forgot Password functionality

✅ Update Password feature

✅ Password input hidden via * characters

✅ File-based user data storage (logindata.txt)

# Technologies Used
- C++
- OOPs
- File I/O (fstream)
- Windows Console (<conio.h> for password masking)

# Project Structure
FLMS/

├── logindata.txt       # Stores user login data

├── main.cpp            # Main source code file

# How It Works
- File-Based Storage: User credentials are stored in a local text file (logindata.txt) using a simple username:password format.

- User Sign-Up: Prompts new users to create a username and a masked password. The system checks for duplicates before saving.

- Login Authentication: On login, the system reads the file and verifies the entered credentials line-by-line.

- Forgot Password: Allows users to recover their password by verifying their username and offering a reset.

- Update Password: Lets authenticated users change their password, updating the stored data accordingly.

- Console Interface: Operates entirely in the terminal/console using interactive prompts and conio.h for input masking.

# Future Improvements
- Add password encryption (e.g., SHA-256 hashing)
- Migrate storage to a database (e.g., SQLite)
- Develop a GUI version using Qt or C++/CLI
- Implement an admin panel for user management
