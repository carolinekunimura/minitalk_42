# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ckunimur <ckunimur@student.42sp.org.br>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/04/10 14:56:27 by ckunimur          #+#    #+#              #
#    Updated: 2023/05/08 18:02:57 by ckunimur         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = minitalk

CLIENT = client

SRC_CLIENT = client.c

OBJ_CLIENT = $(SRC_CLIENT:%.c=%.o)

SERVER = server

SRC_SERVER = server.c

OBJ_SERVER = $(SRC_SERVER:%.c=%.o)

BONUS = minitalk_bonus

BONUS_SERVER = bonus_server
BONUS_CLIENT = bonus_client

LIB_PATH = ./libft_42/libft.a

FLAGS = -Wall -Wextra -Werror

all: $(NAME)

$(NAME): $(SERVER) $(CLIENT)

$(SERVER):
	make -C libft_42
	-cc -g $(SRC_SERVER) $(LIB_PATH) $(FLAGS) -o $(SERVER)

$(CLIENT):
	make -C libft_42
	-cc -g $(SRC_CLIENT) $(LIB_PATH) $(FLAGS) -o $(CLIENT)
	


clean:
	rm -rf $(OBJ) $(OBJBONUS) 
	make clean -C libft_42
	
fclean: clean
	rm -f $(NAME) $(SERVER) $(CLIENT) $(LIB_PATH)

re: fclean all

.PHONY: all bonus clean fclean re