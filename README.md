# Ft_Printf

Regardless of the programming language considered, the printf function,(or its equivalents)
is always highly useful. The main reason is the ease of its formatting, and the
support of diverse types in variable numbers. In short, undeniably, printf
is a vital function. In this project, I recodeded it so that I can use it in all my future projects (42 Dosen't allow the use of the original printf)

## Features

Supports the following converters, flags and modifiers:

 Type        | Name
------------ | -------------------------------------------------------------------------------
 Converters  |  %d / %s / %S / %p / %d / %D / %i / %o / %O / %u / %U / %x / %X / %c / %C / %%
 Flags       |  # / 0 / - / +
 Modifiers   |  hh / h / l / ll / j /z

### Prerequisites

42 dosen't allow us to use most lib functions. For this reason most of these are recoded in the Libft folder in srcs.

## Installing

Run `make` command to compile the printf library.

Compile your project with libftprintf.a.
Don't forget to include "ft_printf.h"

```
gcc -Wall -Werror -Wextra project_file.c libftprintf.a -Iincludes/
```
Once compiled, simple use ft_printf the exact same way you would printf.
