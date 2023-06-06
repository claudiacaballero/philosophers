# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ccaballe <ccaballe@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/06/06 16:35:08 by ccaballe          #+#    #+#              #
#    Updated: 2023/06/06 16:40:25 by ccaballe         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = philo
CFLAGS = -Wall -Wextra -Werror -MMD
SRC = main.c 

OBJ_DIR = objects/
OBJS = $(addprefix $(OBJ_DIR), $(SRC:.c=.o))
DEPS = $(addprefix $(OBJ_DIR), $(SRC:.c=.d))
RM = rm -rf

GREEN = \033[1;92m
RED = \033[1;91m
NC = \033[0m

all: $(NAME)

$(NAME):: $(OBJS)
	@$(CC) $(CFLAGS) $(OBJS) -o $@
	@echo "$(GREEN)philosophers compiled$(NC)"
$(NAME)::
	@echo -n 

clean:
	@$(RM) $(OBJ_DIR) --no-print-directory
	@echo "$(RED)\ndestruction successful\n$(NC)"

fclean: clean
	@$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re 

-include $(DEPS)