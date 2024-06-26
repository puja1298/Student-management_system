---

This C++ program is a simple Student Management System that allows users to manage student records. It provides functionality to add, display, update, and delete student details using a command-line interface. The program uses a `Student` class to encapsulate the student information and a `vector` to store multiple student records.

### Features:
1. **Add Student**: Enter student ID, name, age, and course to add a new student.
2. **Display Students**: View all students currently stored in the system.
3. **Update Student**: Modify the details of an existing student by providing their ID.
4. **Delete Student**: Remove a student from the system using their ID.
5. **Exit**: Terminate the program.

### Usage:
Run the program and follow the on-screen instructions to manage student records through the menu-driven interface.

## Example

```
STUDENT MANAGEMENT SYSTEM
1. Add student
2. Display Student
3. Update Student
4. Delete Student
5. Exit

Enter your choice..
```

---
#include <iostream>
#include <thread>
#include <vector>
#include <cstring>
#include <winsock2.h>
#include <ws2tcpip.h>

#pragma comment(lib, "ws2_32.lib")

#define PORT 8080

using namespace std;

void handle_client(SOCKET client_socket) {
    char buffer[1024];
    int bytes_received;
    while (true) {
        memset(buffer, 0, sizeof(buffer));
        bytes_received = recv(client_socket, buffer, sizeof(buffer), 0);
        if (bytes_received <= 0) {
            cout << "Client disconnected." << endl;
            closesocket(client_socket);
            return;
        }
        cout << "Client: " << buffer << endl;
    }
}

int main() {
    WSADATA wsa_data;
    SOCKET server_fd, client_socket;
    struct sockaddr_in server_addr, client_addr;
    int opt = 1;
    int addrlen = sizeof(client_addr);
    vector<thread> client_threads;

    // Initialize Winsock
    if (WSAStartup(MAKEWORD(2, 2), &wsa_data) != 0) {
        cerr << "WSAStartup failed." << endl;
        return EXIT_FAILURE;
    }

    // Create socket
    if ((server_fd = socket(AF_INET, SOCK_STREAM, 0)) == INVALID_SOCKET) {
        cerr << "Socket creation failed." << endl;
        WSACleanup();
        return EXIT_FAILURE;
    }

    // Set socket options
    if (setsockopt(server_fd, SOL_SOCKET, SO_REUSEADDR | SO_REUSEPORT, (char *)&opt, sizeof(opt)) == SOCKET_ERROR) {
        cerr << "setsockopt failed." << endl;
        closesocket(server_fd);
        WSACleanup();
        return EXIT_FAILURE;
    }

    // Server address structure
    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = INADDR_ANY;
    server_addr.sin_port = htons(PORT);

    // Bind socket to address
    if (bind(server_fd, (struct sockaddr *)&server_addr, sizeof(server_addr)) == SOCKET_ERROR) {
        cerr << "Bind failed." << endl;
        closesocket(server_fd);
        WSACleanup();
        return EXIT_FAILURE;
    }

    // Listen for incoming connections
    if (listen(server_fd, SOMAXCONN) == SOCKET_ERROR) {
        cerr << "Listen failed." << endl;
        closesocket(server_fd);
        WSACleanup();
        return EXIT_FAILURE;
    }

    cout << "Server listening on port " << PORT << endl;

    // Accept and handle incoming client connections
    while (true) {
        if ((client_socket = accept(server_fd, (struct sockaddr *)&client_addr, &addrlen)) == INVALID_SOCKET) {
            cerr << "Accept failed." << endl;
            closesocket(server_fd);
            WSACleanup();
            return EXIT_FAILURE;
        }
        cout << "New connection established." << endl;
        client_threads.emplace_back(handle_client, client_socket);
    }

    // Join all client threads
    for (auto& t : client_threads) {
        if (t.joinable()) {
            t.join();
        }
    }

    // Cleanup
    closesocket(server_fd);
    WSACleanup();

    return 0;
}
