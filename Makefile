# ************************************************0**************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cmieuzet <cmieuzet@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/05/24 19:05:55 by cmieuzet          #+#    #+#              #
#    Updated: 2022/06/09 11:15:24 by cmieuzet         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= minitalk
LIBFT	= Libft/libft.a
SERVER	= server
CLIENT	= client
SERVERB	= server_bonus
CLIENTB	= client_bonus

BONUS = bo

CC = @gcc

CFLAGS	= -Wall -Wextra -Werror -I include

# ---------- ## COLORS ## ---------- #

GREEN = \e[32m
ENDCOLOR = \e[0m

# ---------- ## MANDATORY PART ## ---------- #

SRCS	= server.c
SRCC	= client.c

OBJS	= ${SRCS:.c=.o}
OBJC	= ${SRCC:.c=.o}

# ---------- ## BONUS PART ## ---------- #

SRCSB	= server_bonus.c
SRCCB	= client_bonus.c

OBJSB	= ${SRCSB:.c=.o}
OBJCB	= ${SRCCB:.c=.o}

# ---------- ## RULES ## ---------- #

all: $(NAME)

$(NAME): $(CLIENT) $(SERVER)
		@printf "Libft: Make ${GREEN}Done${ENDCOLOR} !\n"
		@printf "Minitalk: Make ${GREEN}Done${ENDCOLOR} !\n"

$(BONUS): $(CLIENTB) $(SERVERB)

$(LIBFT):
	@$(MAKE) -s -C Libft/

$(CLIENT): $(OBJC) $(LIBFT)
	$(CC) $(CFLAGS) $(OBJC) $(LIBFT) -o $(CLIENT)

$(SERVER): $(OBJS) $(LIBFT)
	$(CC) $(CFLAGS) $(OBJS) $(LIBFT) -o $(SERVER)

$(CLIENTB): $(OBJCB) $(LIBFT)
	$(CC) $(CFLAGS) $(OBJCB) $(LIBFT) -o $(CLIENTB)

$(SERVERB): $(OBJSB) $(LIBFT)
	$(CC) $(CFLAGS) $(OBJSB) $(LIBFT) -o $(SERVERB)

clean:
	@rm -rf $(OBJS) $(OBJSB)
	@rm -rf $(OBJC) $(OBJCB)
	@printf "Minitalk: Clean ${GREEN}Done${ENDCOLOR} !\n"
	@$(MAKE) -s -C Libft/ clean
	@printf "Libft: Clean ${GREEN}Done${ENDCOLOR} !\n"

fclean: clean
	@rm -rf $(CLIENT) $(CLIENTB)
	@rm -rf $(SERVER) $(SERVERB)
	@printf "Minitalk: Fclean ${GREEN}Done${ENDCOLOR} !\n"
	@$(MAKE) -s -C Libft/ fclean
	@printf "Libft: Fclean ${GREEN}Done${ENDCOLOR} !\n"

re: fclean all

bonus: $(BONUS)
	@printf "Minitalk: Bonus ${GREEN}Done${ENDCOLOR} !\n"

.PHONY: all clean fclean re bonus
