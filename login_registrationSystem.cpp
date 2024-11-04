#include <iostream>
#include <fstream>
#include <string>
#include <unordered_map>
#include <sstream>

using namespace std;

// Hash function to "encrypt" password (simple hash for demonstration)
string hashPassword(const string& password) {
    hash<string> hash_fn;
    return to_string(hash_fn(password));
}

// Function to register a new user
void registerUser() {
    string username, password;
    cout << "Enter a username: ";
    cin >> username;
    cout << "Enter a password: ";
    cin >> password;

    // Hash the password
    string hashedPassword = hashPassword(password);

    // Save to file
    ofstream file("users.txt", ios::app);
    if (file.is_open()) {
        file << username << " " << hashedPassword << endl;
        file.close();
        cout << "Registration successful!\n";
    } else {
        cerr << "Unable to open file.\n";
    }
}

// Function to load users from file into a map
unordered_map<string, string> loadUsers() {
    unordered_map<string, string> users;
    ifstream file("users.txt");
    string line;
    while (getline(file, line)) {
        stringstream ss(line);
        string username, password;
        ss >> username >> password;
        users[username] = password;
    }
    return users;
}

// Function to log in an existing user
void loginUser() {
    string username, password;
    cout << "Enter your username: ";
    cin >> username;
    cout << "Enter your password: ";
    cin >> password;

    // Hash the input password
    string hashedPassword = hashPassword(password);

    // Load users from file
    unordered_map<string, string> users = loadUsers();

    // Check if the user exists and if the password matches
    if (users.find(username) != users.end() && users[username] == hashedPassword) {
        cout << "Login successful! Welcome, " << username << "!\n";
    } else {
        cout << "Invalid username or password.\n";
    }
}

// Main menu function
void menu() {
    int choice;
    do {
        cout << "1. Register\n";
        cout << "2. Login\n";
        cout << "3. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                registerUser();
                break;
            case 2:
                loginUser();
                break;
            case 3:
                cout << "Exiting...\n";
                break;
            default:
                cout << "Invalid choice. Please try again.\n";
        }
    } while (choice != 3);
}

int main() {
    menu();
    return 0;
}
