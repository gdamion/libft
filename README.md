# libft
This project is a C library for using in the future School 21's projects. \
According to rules, only basic built-in functions are used, such as: malloc, write, read. \ \
[ft_is](): check incoming integer
[ft_lst](): for working with linked lists
[ft_mem](): memory operations
[ft_printf](): self-made printf, taken from [this project](https://github.com/gdamion/ft_printf)
[ft_put](): printing in different ways
[ft_str](): string operations
[get_next_line](): read and return one line from file with current fd, taken from [this project](https://github.com/gdamion/get_next_line)
[translate](): changing format of incoming data
## Scenarios of compilation
make (compile) \
make clean (delete object files left after compilation) \
make fclean (delete object files and binary library file) \
make re (recompile all project)
## How to include into your project
gcc -I /libft_path/includes /libft_path/libft.a ...
## Tests
All the code is written accoring to [Norminette rules](https://github.com/gdamion/Norminette) by School 21
