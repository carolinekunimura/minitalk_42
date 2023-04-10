# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ckunimur <ckunimur@student.42sp.org.br>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/04/10 14:56:27 by ckunimur          #+#    #+#              #
#    Updated: 2023/04/10 15:02:23 by ckunimur         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CLIENT = 

SRC_CLIENT =

OBJ_CLIENTE =

SERVER =

SRC_SERVER =

OBJ_SERVER =

NAME = minitalk.a

$(NAME) = $(CLIENT) $(SERVER)

all = $(NAME) 

bonus: $(OBJBONUS)

clean:
	rm -rf $(OBJ) $(OBJBONUS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all bonus clean fclean re