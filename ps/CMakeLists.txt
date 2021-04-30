cmake_minimum_required(VERSION 3.19)
project(ps C)

set(CMAKE_C_STANDARD 99)

add_executable(
        ps push_swap_files/main.c
        push_swap_files/doing_moves.c
        push_swap_files/push_commands_ps.c
        push_swap_files/push_swap.c
        push_swap_files/push_swap.h
        push_swap_files/reverse_rotate_commands_ps.c
        push_swap_files/rotate_commands_ps.c
        push_swap_files/swap_commands_ps.h
        push_swap_files/swap_commands_ps.c
        push_swap_files/data_func.c

        libft/ft_max.c
        libft/ft_min.c
        libft/ft_atoi.c
        libft/ft_bzero.c
        libft/ft_isalnum.c
        libft/ft_isalpha.c
        libft/ft_isascii.c
        libft/ft_isdigit.c
        libft/ft_isprint.c
        libft/ft_memcpy.c
        libft/ft_memset.c
        libft/ft_memccpy.c
        libft/ft_memchr.c
        libft/ft_memcmp.c
        libft/ft_memmove.c
        libft/ft_strchr.c
        libft/ft_strlcat.c
        libft/ft_strlcpy.c
        libft/ft_strlen.c
        libft/ft_strncmp.c
        libft/ft_strnstr.c
        libft/ft_strrchr.c
        libft/ft_tolower.c
        libft/ft_toupper.c
        libft/ft_calloc.c
        libft/ft_strdup.c
        libft/ft_strjoin.c
        libft/ft_substr.c
        libft/ft_strtrim.c
        libft/ft_itoa.c
        libft/ft_putchar_fd.c
        libft/ft_putstr_fd.c
        libft/ft_putnbr_fd.c
        libft/ft_putendl_fd.c
        libft/ft_strmapi.c
        libft/ft_split.c
        libft/ft_putchar.c
        libft/ft_putstr.c
        push_swap_files/count_ways.c push_swap_files/min_way_and_sort_three.c)