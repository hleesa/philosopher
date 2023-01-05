# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: salee2 <salee2@student.42seoul.kr>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/11/30 15:42:18 by salee2            #+#    #+#              #
#    Updated: 2022/11/30 15:42:21 by salee2           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= philo
BONUS		= philo_bonus

CC			= cc
CFLAGS		= -Wall -Wextra -Werror
RM			= rm -f

MANDA_SRCS = \
     arg \
     common \
     ft_atoll \
     main \
     philo \
     philo_thread \
     print \
     thread \
     time \
     watcher \

BONUS_SRCS = \
     arg \
     common \
     exit \
     ft_atoll \
     main \
     philo \
     print \
     thread \
     time \
     watcher \

MANDA_FILE = $(addsuffix .c, $(addprefix mandatory/, $(MANDA_SRCS:.c=.o)))
BONUS_FILE = $(addsuffix _bonus.c, $(addprefix bonus/, $(BONUS_SRCS:.c=.o)))

MANDA_OBJS = $(MANDA_FILE:c=o)
BONUS_OBJS = $(BONUS_FILE:c=o)

all: $(NAME)
bonus : $(BONUS)

$(NAME): $(MANDA_OBJS)
	$(CC) $(CFLAGS) -o $@ $^

$(BONUS) : $(BONUS_OBJS)
	$(CC) $(CFLAGS) -o $@ $^

%o: %c
	$(CC) $(CFLAGS) -c -o $@ $<

clean:
	$(RM) $(MANDA_OBJS) $(BONUS_OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean
	make all

.PHONY: all bonus clean fclean re
