*This project has been created as part of the 42 curriculum by jrosette.*

# get_next_line

## Description

**get_next_line** is a project from the 42 curriculum that involves implementing a function in C that reads a file descriptor one line at a time.

The goal is to develop an understanding of file input/output, static variables, dynamic memory allocation, and string manipulation.

The function reads data in chunks using the `read()` system call and returns one line per function call. It preserves remaining data between calls so that subsequent calls can return the next line without losing previously read content.

The returned line includes the newline character (`\n`) if one is present. When there is no more data to read, the function returns `NULL`.

### Function prototype

```c
char *get_next_line(int fd);
```

- `fd`: The file descriptor to read from.
- **Return value:** A dynamically allocated string containing the next line, or `NULL` when no more lines are available or an error occurs.

## Instructions

### Requirements

- A C compiler, such as `cc`.
- `make`.
- The `ar` utility for creating static libraries.

### Compilation

The project includes a Makefile that compiles the source files into object files and archives them into the static library `get_next_line.a`.

Run the following command from the project directory:

```bash
make
```

This compiles the source files with the following flags:

```bash
-Wall -Wextra -Werror
```

To remove the generated object files:

```bash
make clean
```

To remove both the object files and the static library:

```bash
make fclean
```

To rebuild the library from scratch:

```bash
make re
```

### Using the library

To use `get_next_line()` in another C program, include the header and link the static library when compiling:

```c
#include "get_next_line.h"
```

## Resources

### Documentation and references

- [42 School](https://42.fr/) — Project curriculum and learning environment.
- [`read()` manual](https://man7.org/linux/man-pages/man2/read.2.html) — Documentation on reading data from file descriptors.
- [`open()` manual](https://man7.org/linux/man-pages/man2/open.2.html) — Documentation on opening files.
- [`close()` manual](https://man7.org/linux/man-pages/man2/close.2.html) — Documentation on closing file descriptors.
- [GNU C Library documentation](https://www.gnu.org/software/libc/manual/) — Reference for C library functions and memory management.
- [cppreference: Dynamic memory management](https://en.cppreference.com/w/c/memory) — Reference for `malloc()` and `free()`.

### AI usage

AI tools were used as supplementary learning resources during the development of this project.

They were used to:
- Clarify concepts related to static variables, file descriptors, buffer management, and dynamic memory allocation.
- Explain the behavior of `read()` and the handling of newlines and end-of-file conditions.
