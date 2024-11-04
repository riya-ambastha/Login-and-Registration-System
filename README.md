Creating a login and registration system in C++ can be an excellent project for learning about file 
handling, basic encryption, and control flow. Below is a simple implementation that stores user
credentials in a text file, allowing users to register and log in by verifying their credentials.

Project Outline :

Register: Users can register by entering a username and password. The credentials are stored in a file.
Login: Users can log in by entering their credentials, which are verified against the stored data.
File Handling: Usernames and passwords are saved in a file to persist between program runs.
Basic Encryption (optional): Hashing the password before storing it to improve security.

Explanation
registerUser Function:

Prompts the user to enter a username and password.
Hashes the password using hashPassword (a simple hash for demonstration).
Appends the username and hashed password to users.txt.
loadUsers Function:

Reads all usernames and hashed passwords from users.txt.
Stores them in an unordered map for quick access during login.
loginUser Function:

Prompts the user for a username and password.
Hashes the input password and checks it against the stored hashed password in the map.
If it matches, login is successful; otherwise, it fails.
menu Function:

Presents a simple menu to the user for registration, login, or exit.

Security Note
This is a basic demonstration. In a real-world application, consider using a more secure hashing 
library like bcrypt or another cryptographic library for password storage, as std::hash is not 
secure for sensitive data.
