# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tsudo <tsudo@student.42tokyo.jp>           +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/03/05 23:50:33 by tsudo             #+#    #+#              #
#    Updated: 2022/03/22 19:11:18 by tsudo            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	:= push_swap
B_NAME	:= checker
CC		:= gcc
CFLAGS	:= -Wall -Wextra -Werror -MMD -MP
RM		:= rm -f
LIBFT	:= libft/libft.a

# **************************************************************************** #

SRCS	+= $(M_SRCS)
M_SRCS	:= \
	srcs/push_swap/main.c \
	srcs/push_swap/ps_bfs_sort.c \
	srcs/push_swap/ps_bfs_sort_4.c \
	srcs/push_swap/ps_bfs_sort_5.c \
	srcs/push_swap/ps_bubble_sort.c \
	srcs/push_swap/ps_merge.c \
	srcs/push_swap/ps_radix_sort.c \
	srcs/push_swap/ps_rmdup.c \
	srcs/push_swap/ps_smart_wheel.c \
	srcs/push_swap/ps_wheel_sort.c \
	srcs/push_swap/ps_almost_sorted.c \
	srcs/push_swap/ps_small_wheel_sort.c \

SRCS	+= $(U_SRCS)
U_SRCS	:= \
	srcs/utils/ps_alloc.c \
	srcs/utils/ps_exit.c \
	srcs/utils/ps_get_stacks.c \
	srcs/utils/ps_op_str.c \
	srcs/utils/ps_store_str.c \
	srcs/utils/push_swap.c \
	srcs/utils/ps_index.c \

SRCS	+= $(B_SRCS)
B_SRCS	:= \
	srcs/checker/main_bonus.c \

INCS	:= \
	includes \
	libft/includes \

# **************************************************************************** #

M_OBJS	= $(patsubst %.c,objs/%.o, $(notdir $(M_SRCS)))
U_OBJS	= $(patsubst %.c,objs/%.o, $(notdir $(U_SRCS)))
B_OBJS	= $(patsubst %.c,objs/%.o, $(notdir $(B_SRCS)))
OBJS	= $(M_OBJS) $(U_OBJS) $(B_OBJS)
DEPS	= $(OBJS:.o=.d)
CFLAGS	+= $(addprefix -I,$(INCS))
vpath %.c $(sort $(dir $(SRCS)))

# **************************************************************************** #

$(NAME): $(LIBFT) $(M_OBJS) $(U_OBJS)
	$(CC) $(CFLAGS) -o $@ $^

$(B_NAME): $(LIBFT) $(B_OBJS) $(U_OBJS)
	$(CC) $(CFLAGS) -o $@ $^

.PHONY: all
all: $(NAME)

.PHONY: _all
_all: $(NAME) $(B_NAME)

-include $(DEPS)

objs/%.o: %.c
	$(CC) $(CFLAGS) -c -o $@ $<

$(LIBFT):
	make -C $(dir $(LIBFT))

.PHONY: clean
clean:
	$(RM) $(OBJS)
	$(RM) $(DEPS)
	make -C $(dir $(LIBFT)) fclean

.PHONY: fclean
fclean: clean
	$(RM) $(NAME) $(B_NAME)

.PHONY: re
re: fclean all

.PHONY: bonus
bonus: $(B_NAME)

# **************************************************************************** #
