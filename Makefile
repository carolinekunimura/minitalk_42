# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ckunimur <ckunimur@student.42sp.org.br>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/04/10 14:56:27 by ckunimur          #+#    #+#              #
#    Updated: 2023/05/10 17:01:06 by ckunimur         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = minitalk

#client
CLIENT = client
SRC_CLIENT = client.c
OBJ_CLIENT = $(SRC_CLIENT:%.c=%.o)

#server
SERVER = server
SRC_SERVER = server.c
OBJ_SERVER = $(SRC_SERVER:%.c=%.o)

#bonus
BONUS = minitalk_bonus

BONUS_SERVER = server_bonus
SRC_BONUS_SERVER = bonus/server_bonus.c
OBJ_BONUS_SERVER = $(SRC_BONUS_SERVER:%.c=%.o)

BONUS_CLIENT = client_bonus
SRC_BONUS_CLIENT = bonus/client_bonus.c
OBJ_BONUS_CLIENT = $(SRC_BONUS_CLIENT:%.c=%.o)

LIB_PATH = ./libft_42/libft.a

FLAGS = -Wall -Wextra -Werror

%.o: %.c
	cc $(FLAGS) -c $< -o $@ -I.

all: $(NAME)

$(NAME): $(SERVER) $(CLIENT)

$(SERVER): $(OBJ_SERVER)
	make -C libft_42
	-cc -g $(SRC_SERVER) $(LIB_PATH) $(FLAGS) -o $(SERVER)

$(CLIENT):$(OBJ_CLIENT)
	make -C libft_42
	-cc -g $(SRC_CLIENT) $(LIB_PATH) $(FLAGS) -o $(CLIENT)

bonus: $(BONUS)

$(BONUS): $(BONUS_SERVER) $(BONUS_CLIENT)

$(BONUS_SERVER): $(OBJ_BONUS_SERVER)
	make -C libft_42
	-cc -g $(SRC_BONUS_SERVER) $(LIB_PATH) $(FLAGS) -o $(BONUS_SERVER) -I.
	
$(BONUS_CLIENT): $(OBJ_BONUS_CLIENT)
	make -C libft_42
	-cc -g $(SRC_BONUS_CLIENT) $(LIB_PATH) $(FLAGS) -o $(BONUS_CLIENT) -I.

clean:
	rm -rf $(OBJ_CLIENT) $(OBJ_SERVER) $(OBJ_BONUS_SERVER)  $(OBJ_BONUS_CLIENT)
	make clean -C libft_42
	
fclean: clean
	rm -f $(NAME) $(SERVER) $(CLIENT) $(LIB_PATH) $(BONUS_SERVER) $(BONUS_CLIENT)

re: fclean all

.PHONY: all bonus clean fclean re