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
{
    "version": "2.0.0",
    "tasks": [
        {
            "label": "build",
            "type": "shell",
            "command": "g++",
            "args": [
                "-g",
                "${workspaceFolder}/main.cpp",
                "-o",
                "${workspaceFolder}/main.exe",
                "-std=c++11",
                "-lws2_32"
            ],
            "group": {
                "kind": "build",
                "isDefault": true
            },
            "problemMatcher": ["$gcc"]
        }
    ]
}

@@@
{
    "version": "0.2.0",
    "configurations": [
        {
            "name": "(gdb) Launch",
            "type": "cppdbg",
            "request": "launch",
            "program": "${workspaceFolder}/main.exe",
            "args": [],
            "stopAtEntry": false,
            "cwd": "${workspaceFolder}",
            "environment": [],
            "externalConsole": true,
            "MIMode": "gdb",
            "miDebuggerPath": "C:\\mingw-w64\\bin\\gdb.exe",
            "setupCommands": [
                {
                    "description": "Enable pretty-printing for gdb",
                    "text": "-enable-pretty-printing",
                    "ignoreFailures": true
                }
            ],
            "preLaunchTask": "build",
            "internalConsoleOptions": "neverOpen"
        }
    ]
}
