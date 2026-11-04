# Password Manager (C++)

A console password manager written in C++17 for PROG23762 at Sheridan College. It stores login entries in memory, organizes them by category, and keeps every password encoded instead of as plain text.

## Features

Menu-driven console app:

1. Display all password items
2. Add a new item (a random 5-digit ID is generated)
3. Remove an item by ID
4. Update an item's name, category, username or password
5. Find an item by ID
6. Find an item by name
7. Find all items in a category
8. Test the encoder and decoder
9. Exit

Every field is validated before it is saved. IDs must be 5 digits, names and categories may only contain letters and spaces, and usernames can't be empty.

## Design

| Class | Responsibility |
|---|---|
| `EncryptPassword` | Encodes a password by reversing it and converting each character to its ASCII code (`"abc"` → `"99,98,97"`), and decodes it back |
| `PasswordItem` | One entry: ID, name, category, username and encoded password, with validating setters |
| `PasswordStorage` | Holds all entries in a `std::map<int, PasswordItem>` keyed by ID; handles add, update, delete and the search functions (category search returns a `std::vector`) |

> **Note:** the encoding is a learning exercise about classes and string manipulation, not real cryptographic security.

## Build and run

Requires `g++` with C++17 support.

```bash
make        # build
make run    # build and run
make clean  # remove build files
```

## Tech
C++17 · STL (`map`, `vector`, `string`) · Make
