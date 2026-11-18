*This project has been created as part of the 42 curriculum by berpinhe.

**FT_PRINTF**



## Description
A custom C implementation of `printf()` compiled into a static library (`libftprintf.a`). It uses variadic arguments (`<stdarg.h>`) and `write(2)` without dynamic memory allocation, returning the total number of characters printed (or `-1` on error).

Supported conversions: `%c`, `%s`, `%p`, `%d`, `%i`, `%u`, `%x`, `%X`, and `%%`.


## Instructions
Compile the library:
`make`

Other rules: 
`make clean`, `make fclean`, `make re`.

Link `libftprintf.a` when compiling your program:
`cc -Wall -Wextra -Werror main.c libftprintf.a`


## Algorithm & Data Structure
* **Dispatch Architecture:** `ft_printf` iterates through the format string, writing normal characters directly and passing `va_list *` to `ft_select` when encountering `%`.

* **Stack Recursion & Type Widening:** Numbers are printed using call-stack recursion instead of heap buffers. `ft_dig(long n)` handles both signed (`%d`, `%i`, preventing `INT_MIN` overflow) and unsigned (`%u`) base-10 integers. `ft_hex(unsigned long n, char flag)` handles both 32-bit hex (`%x`, `%X`) and 64-bit addresses (`%p`) using base-16 string literals.


## Resources
* `man 3 printf` & `man 3 stdarg`

* [GNU C Library — Variadic Functions](https://www.gnu.org/software/libc/manual/html_node/Variadic-Functions.html)

* **AI Usage:** Used to verify edge cases against `glibc` (`NULL` handling, `INT_MIN`, `va_arg` type promotion), and format this README.
