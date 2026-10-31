This project has been created as part of the 42 curriculum by zzouhri.

Libft — Custom C Standard Library

Description

Libft is the foundational project of the 42 curriculum, requiring the recreation of essential standard C library (libc) functions alongside custom utility functions for string manipulation, memory management, file descriptor output, and singly linked list operations.

The primary goal of this project is to build a deep, mechanical understanding of low-level data structures, memory allocation, pointer arithmetic, and compilation pipelines in C—without relying on standard external libraries. The resulting static archive (libft.a) serves as a self-contained foundational toolkit for future C projects in the curriculum.

Detailed Library Overview

This implementation integrates all mandatory libc recreations, additional utility functions, and the complete suite of linked list manipulation functions directly into a unified core archive (libft.a). The header (libft.h) relies strictly on <stdlib.h> (for malloc and free) and <unistd.h> (for write).

1. Character Checks & Conversions (<ctype.h> equivalents)

All character-checking functions accept an int rather than a char to properly handle standard default argument promotion and safely accommodate the out-of-band EOF (-1) signal returned by stream-reading functions without truncating -1 into 255 (0xFF).

ft_isalpha: Checks for an alphabetic character (A-Z or a-z).

ft_isdigit: Checks for a numeric digit (0-9).

ft_isalnum: Checks for an alphanumeric character.

ft_isascii: Checks whether c fits into the 7-bit US-ASCII character set (0 to 127).

ft_isprint: Checks for any printable character including space (32 to 126).

ft_toupper: Converts a lowercase letter to uppercase.

ft_tolower: Converts an uppercase letter to lowercase.

2. Memory Manipulation (<string.h> & <strings.h> equivalents)

Raw memory operations cast generic void * pointers to unsigned char * to inspect and manipulate memory sequentially byte-by-byte.

ft_memset: Fills the first len bytes of a memory area with a constant byte c.

ft_bzero: Erases data in the n bytes of the memory starting at the location pointed to by s by writing null bytes (\0).

ft_memcpy: Copies n bytes from memory area src to memory area dst.

ft_memmove: Copies len bytes from src to dst, safely handling overlapping memory blocks by copying backward when dst > src.

ft_memchr: Scans the initial n bytes of a memory block for the first instance of byte c.

ft_memcmp: Compares the first n bytes of two memory areas, returning their unsigned byte difference.

ft_calloc: Contiguously allocates enough space for nitems objects of size bytes each and zeroes the allocated memory using ft_bzero. Includes a library-less multiplication overflow guard (nitems > (((size_t) - 1) / size)) to avoid <stdint.h> dependencies.

3. String Manipulation & Examination (<string.h> & <stdlib.h> equivalents)

ft_strlen: Computes the length of a null-terminated string.

ft_strlcpy: Size-bounded string copying that guarantees null-termination when dstsize > 0 and returns the total length of src.

ft_strlcat: Size-bounded string concatenation that appends src to dst of size dstsize, guaranteeing null-termination and returning the initial length of dst plus the length of src.

ft_strchr: Locates the first occurrence of character c (including the terminating \0) in a string.

ft_strrchr: Locates the last occurrence of character c in a string.

ft_strncmp: Lexicographically compares up to n characters of two null-terminated strings using unsigned characters.

ft_strnstr: Locates the first occurrence of the null-terminated string needle in haystack, searching at most len characters.

ft_strdup: Allocates sufficient memory for a copy of string s1, copies it, and returns a pointer to it.

ft_atoi: Converts the initial portion of a string pointed to by str to an int representation, skipping leading whitespace (ASCII 9-13 and 32) and handling a single optional + or - sign.

4. Additional String Utilities & Type Conversions

ft_substr: Allocates and returns a substring from string s, starting at index start and of maximum size len.

ft_strjoin: Allocates and returns a new string resulting from the concatenation of s1 and s2.

ft_strtrim: Allocates and returns a copy of s1 with the characters specified in set removed from both the beginning and the end of the string.

ft_split: Allocates and returns a null-terminated array of strings obtained by splitting s using the character c as a delimiter.

ft_itoa: Allocates and returns a string representing the integer received as an argument, safely handling negative numbers and INT_MIN.

ft_strmapi: Applies function f to each character of string s (passing its index as the first argument) to create a new dynamically allocated string resulting from successive applications of f.

ft_striteri: Applies function f on each character of the string passed as argument, passing its index as first argument and the character's address for in-place modification.

5. File Descriptor Output Functions

Built directly atop the <unistd.h> system call write:

ft_putchar_fd: Outputs the character c to the given file descriptor.

ft_putstr_fd: Outputs the string s to the given file descriptor.

ft_putendl_fd: Outputs the string s to the given file descriptor, followed by a newline.

ft_putnbr_fd: Outputs the integer n to the given file descriptor.

6. Singly Linked List Manipulation (t_list)

Operates on the custom node structure defined in libft.h:

typedef struct s_list
{
    void            *content;
    struct s_list   *next;
}                   t_list;


ft_lstnew: Allocates and returns a new node with content initialized to the parameter and next set to NULL.

ft_lstadd_front: Adds the node new at the beginning of the list.

ft_lstsize: Counts the number of nodes in a list.

ft_lstlast: Returns the last node of the list.

ft_lstadd_back: Adds the node new at the end of the list.

ft_lstdelone: Takes a node as parameter and frees the memory of the node's content using the function del given as a parameter, then frees the node itself without freeing next.

ft_lstclear: Deletes and frees the given node and every successor of that node using del and free, setting the initial pointer to NULL.

ft_lstiter: Iterates the list lst and applies the function f on the content of each node.

ft_lstmap: Iterates the list lst and applies the function f on the content of each node, creating a new list resulting from the successive applications of f. Uses del to clear the new list if an allocation fails partway through.

Technical Choices & Design Highlights

Zero Unauthorized Header Dependencies: Rather than pulling in <stdint.h> or <stddef.h> for SIZE_MAX or size_t—which can cause evaluation disputes—size_t is resolved natively via <stdlib.h> and <unistd.h>, and SIZE_MAX in ft_calloc is calculated dynamically using unsigned integer wrap-around ((size_t) - 1).

Unified Build System: All 43 functions (Part 1, Part 2, and Linked Lists) are compiled directly into the primary $(NAME) target (libft.a), ensuring the entire toolkit is immediately accessible without requiring separate build rules.

Header Dependency Tracking: The Makefile tracks libft.h as a prerequisite alongside .c files so any changes to prototypes or struct s_list automatically trigger incremental recompilation.

Instructions

Compilation via Makefile

The included Makefile compiles all source files using cc with strict flags (-Wall -Wextra -Werror) and bundles the resulting object files into libft.a using ar rcs.

Build the library:

make


Remove compiled object files (.o):

make clean


Remove object files (.o) and the static archive (libft.a):

make fclean


Force a full rebuild from scratch:

make re


Manual Compilation & Linking Workflow

To understand what happens under the hood of the Makefile:

Compile .c source files into .o object files (Preprocess, Compile, Assemble without linking):

cc -Wall -Wextra -Werror -c *.c


Bundle .o files into the indexed static archive libft.a:

ar rcs libft.a *.o


Compile a test main.c and link it against libft.a:

cc -Wall -Wextra -Werror main.c libft.a -o test_program
./test_program


Barebones Usage Example

#include <stdio.h>
#include "libft.h"

int main(void)
{
    char *str = (char *)ft_calloc(5, sizeof(char));
    if (!str)
        return (1);
    printf("ft_atoi: %d\n", ft_atoi("   -42"));
    printf("ft_isalpha: %d\n", ft_isalpha('A'));
    printf("ft_calloc zeroes: %d %d %d %d %d\n", str[0], str[1], str[2], str[3], str[4]);
    free(str);
    return (0);
}


Resources

Classic References & Documentation

Linux Man Pages (man 3): Primary reference for standard C library behavior, prototypes, return values, and edge cases (man atoi, man calloc, man bzero, man strlcpy, man ctype).

GNU Make Manual: Reference for pattern rules (%.o: %.c), automatic variables ($<, $@), and .PHONY targets.

42 Norm (v4): Official coding standard documentation governing formatting, function length, variable declarations, and header structures.

Tripouille libftTester: Automated unit-testing suite used locally to verify edge cases and memory safety (excluded from the Git repository prior to submission).

AI Usage Declaration

In accordance with the 42 curriculum guidelines, AI tools were utilized strictly as an interactive technical sounding board to explore low-level theoretical concepts and verify edge-case behaviors—never to generate or write project source code:

Deep Workings of Compilation & Linking: Explored the theoretical mechanics of the C compilation pipeline (how the preprocessor expands headers, how the compiler and assembler generate object files with unresolved symbol placeholders, and how the linker stitches archives together), alongside Makefile timestamp dependency tracking, automatic variables ($<, $@), and compiler diagnostic flags (-Wall -Wextra -Werror).

Memory Architecture & Representation: Investigated low-level memory concepts, including how unsigned integer wrap-around ((size_t) - 1) operates at the bit level in ft_calloc, why <ctype.h> functions require int parameters to prevent char truncation of out-of-band EOF (-1) signals, and how null bytes (\0) affect terminal buffer outputs in ft_bzero.

Edge-Case & "What-If" Scenario Analysis: Tested theoretical "what-if" scenarios around header dependency chains (such as how size_t resolves natively through <stdlib.h> and <unistd.h> without <stddef.h>) and discussed minimal, barebones main.c test cases to manually stress-test already-written functions against extreme inputs and boundary conditions.