# Employee Record Management System

A simple console-based employee record management project written in C for first-year Information Technology programming practice.

## Features

- Add employee records
- Display all employee records
- Search for an employee by ID
- Validate numeric and text input
- Handle names and departments containing spaces
- Display salary using portable ASCII output

## Requirements

- Windows, Linux, or macOS
- A C compiler such as GCC or Clang

## Compile

### GCC

```bash
gcc -std=c11 -Wall -Wextra -Wpedantic SLA-Employee-record-management-c.c -o trialsla
```

### Windows with MinGW

```powershell
gcc -std=c11 -Wall -Wextra -Wpedantic SLA-Employee-record-management-c.c -o trialsla.exe
```

## Run

```text
./trialsla
```

On Windows PowerShell:

```powershell
.\trialsla.exe
```

## Menu

1. Add New Employee
2. Display All Employees
3. Search Employee by ID
4. Exit

## Project Structure

```text
.
|-- README.md
|-- SLA-Employee-record-management-c.c
`-- .gitignore
```

## Notes

Employee records are stored in memory while the program is running. They are not saved to a file after the program exits.
