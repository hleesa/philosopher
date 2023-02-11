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

CC			= cc
CFLAGS		= -Wall -Wextra -Werror
RM			= rm -f

PHILO_SRCS = \
     arg \
     common \
     ft_atoll \
     life_of_philo \
     main \
     philo_thread \
     print \
     thread \
     time \
     watcher \

SRCS = $(addsuffix .c, $(PHILO_SRCS))

OBJS = $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) -o $@ $^

%o: %c
	$(CC) $(CFLAGS) -c -o $@ $<

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean
	make all

.PHONY: NAME all clean fclean re
