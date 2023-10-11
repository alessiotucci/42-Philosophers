# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: atucci <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/10/05 11:09:19 by atucci            #+#    #+#              #
#    Updated: 2023/10/11 12:55:53 by atucci           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#------------------------------------------------------------------------------
# Setting the variable name to the name of the executable file
NAME = philo


#------------------------------------------------------------------------------
# Declaring all the sources file needed to build the "philo" executable
SRC = ./philosopher.c \
						./utils.c \
						./debug_print.c \
						./lay_the_table.c \
						./routine.c \
						./monitoring.c \
						./actions_of_routine.c \
#------------------------------------------------------------------------------
# Setting the variables object to a list of object neede to build from the src
OBJS = $(SRC:.c=.o)


#------------------------------------------------------------------------------
# Setting the variable header to the path of the header file 
HDRS = ./philo.h


#------------------------------------------------------------------------------
# Setting the var RM to remove them files
RM = rm -f


#------------------------------------------------------------------------------
# This set the C compiler with the specific warning flags
CC = gcc -Wall -Werror -Wextra

# Color codes for echo commands to make the output more visually informative.
GREEN := \033[1;32m
CYAN := \033[1;36m
YELLOW := \033[1;33m
RED := \033[1;31m
RESET := \033[0m

#--------------------------------------------------
# Rule for building the "fdf" executable.
$(NAME): $(OBJS)
	@echo "$(CYAN)Building $(NAME)...$(RESET)"
	${CC} -o $(NAME) $(OBJS)
	@echo "$(GREEN) $(NAME) philos created successfully! $(RESET)"

#--------------------------------------------------
# Default target: building the "philo" executable when running 'make all'.
all: $(NAME)

#--------------------------------------------------
# Rule for cleaning up generated object files.
clean:
	@echo "$(YELLOW)Cleaning up object files...$(RESET)"
	${RM} $(OBJS)

#--------------------------------------------------
# Rule for completely removing generated object files and the "philo" executable.
fclean: clean
	@echo "$(YELLOW)Cleaning up $(NAME) binary...$(RESET)"
	${RM} $(NAME)

#--------------------------------------------------
# Rule for recompiling the project from scratch.
re: fclean all

#--------------------------------------------------
# .PHONY targets to specify non-file targets.
.PHONY: all clean fclean re
