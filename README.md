# libft
This project is a C library for using in the future School 21's projects. \
According to rules, only basic built-in functions are used, such as: malloc, write, read. \
Here you can find more detailed [description](https://github.com/gdamion/libft/blob/master/libft.en.pdf).
- [ft_is](https://github.com/gdamion/libft/tree/master/src/ft_is): check incoming integer
- [ft_lst](https://github.com/gdamion/libft/tree/master/src/ft_lst): for working with linked lists
- [ft_mem](https://github.com/gdamion/libft/tree/master/src/ft_mem): memory operations
- [ft_printf](https://github.com/gdamion/libft/tree/master/src/ft_printf): self-made printf(), taken from [this project](https://github.com/gdamion/ft_printf)
- [ft_put](https://github.com/gdamion/libft/tree/master/src/ft_put): printing in different ways
- [ft_str](https://github.com/gdamion/libft/tree/master/src/ft_str): string operations
- [get_next_line](https://github.com/gdamion/libft/tree/master/src/get_next_line): read and return one line from file with current fd, taken from [this project](https://github.com/gdamion/get_next_line)
- [translate](https://github.com/gdamion/libft/tree/master/src/translate): changing format of incoming data \
## Scenarios of compilation
- make (compile)
- make clean (delete object files left after compilation)
- make fclean (delete object files and binary library file) 
- make re (recompile all project)
## How to include into your project
gcc -I /libft_path/includes /libft_path/libft.a ...
## Tests
All the code is written accoring to [Norminette rules](https://github.com/gdamion/Norminette) by School 21
