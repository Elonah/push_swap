# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ejacquel <ejacquel@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/04/02 23:28:53 by ejacquel          #+#    #+#              #
#    Updated: 2023/04/26 06:23:13 by ejacquel         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME			=	push_swap

NAME_BONUS		=	checker

LIBFT			=	libft.a

PRINTF			=	libft.a


DIR_SRCS		=	srcs/mandatory

DIR_BONUS		=	srcs/bonus

DIR_OBJS		=	objs

DIR_OBJS_M		=	objs/mandatory

DIR_OBJS_BONUS	=	objs/bonus

SRCS_NAMES		=	main.c \
					parsing.c \
					parsing2.c \
					movement_swap.c \
					movement_push.c \
					movement_rotate.c \
					movement_reverse_rotate.c \
					algo.c \
					big_algo.c \
					big_algo2.c \
					utils.c \
					median.c

SRCS_NAMES_B	=	main.c \
					parsing.c \
					parsing2.c \
					movement_swap.c \
					movement_push.c \
					movement_rotate.c \
					movement_reverse_rotate.c \
					checker.c \
					get_next_line.c \
					get_next_line_utils.c \
					fonctions_libft.c \
					split.c

OBJS_NAMES		=	${SRCS_NAMES:.c=.o}

OBJS_NAMES_B	=	${SRCS_NAMES_B:.c=.o}

DEPS			=	${SRCS_NAMES:.c=.d}

DEPS_BONUS		=	${SRCS_NAMES_B:.c=.d}

SRCS			=	$(addprefix $(DIR_SRCS)/,$(SRCS_NAMES))

SRCS_BONUS		=	$(addprefix $(DIR_BONUS)/,$(SRCS_NAMES_B))

OBJS			=	$(addprefix $(DIR_OBJS_M)/,$(OBJS_NAMES))

OBJS_BONUS		=	$(addprefix $(DIR_OBJS_BONUS)/,$(OBJS_NAMES_B))

INC				=	-Iincludes -Ilibft -Ift_printf/includes

LIB				=	-Llibft -lft -Lft_printf -lftprintf

CC				=	cc

CDFLAGS 		=	-MMD -MP

CFLAGS			=	-g3 -Wall -Werror -Wextra

all:	${NAME}

$(NAME): $(DIR_OBJS_M) $(OBJS)
	make -C libft
	make -C ft_printf
	$(CC) ${INC} $(OBJS) $(LIB) -o $(NAME)
	@echo "\033[31;5mpush_swap\033[0m"

$(OBJS) : $(DIR_OBJS_M)/%.o : $(DIR_SRCS)/%.c
	$(CC) -g3 $(CDFLAGS) $(INC) -c $< -o $@

$(DIR_OBJS_M):
	mkdir -p $(DIR_OBJS_M)

bonus:	${NAME_BONUS}

$(NAME_BONUS): $(DIR_OBJS_BONUS) $(OBJS_BONUS)
	$(CC) ${INC} $(OBJS_BONUS) -o $(NAME_BONUS)
	@echo "\033[31;5mchecker\033[0m"

$(OBJS_BONUS) : $(DIR_OBJS_BONUS)/%.o : $(DIR_BONUS)/%.c
	$(CC) -g3 $(CDFLAGS) $(INC) -c $< -o $@

$(DIR_OBJS_BONUS):
	mkdir -p $(DIR_OBJS_BONUS)

clean:
	make clean -C libft
	make clean -C ft_printf
	rm -rf ${DIR_OBJS}

fclean:	clean
	make fclean -C libft
	make fclean -C ft_printf
	rm -rf ${LIBFT}
	rm -rf ${PRINTF}
	rm -rf ${NAME}
	rm -rf ${NAME_BONUS}

re:	fclean all

-include $(DEPS)

.PHONY:	all clean fclean re bonus
