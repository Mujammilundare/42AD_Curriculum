# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mundare <mundare@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/01/21 18:14:09 by mundare           #+#    #+#              #
#    Updated: 2025/01/28 19:49:35 by mundare          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME_SERVER = server
NAME_CLIENT = client

SRCS_CLIENT = client.c
SRCS_SERVER = server.c
OBJS_CLIENT = ${SRCS_CLIENT:.c=.o}
OBJS_SERVER = ${SRCS_SERVER:.c=.o}
RM = rm -f
CFLAGS = -Wall -Wextra -Werror
CC = cc  # Explicitly define the compiler (default to gcc)

# Default rule
all: ${NAME_SERVER} ${NAME_CLIENT}

# Server rule (compiling the server object files and linking them into the executable)
${NAME_SERVER}: ${OBJS_SERVER}
	${CC} ${CFLAGS} ${OBJS_SERVER} -o ${NAME_SERVER}

# Client rule (compiling the client object files and linking them into the executable)
${NAME_CLIENT}: ${OBJS_CLIENT}
	${CC} ${CFLAGS} ${OBJS_CLIENT} -o ${NAME_CLIENT}

# Object files compilation rule
${OBJS_CLIENT}: ${SRCS_CLIENT}
	${CC} ${CFLAGS} -c ${SRCS_CLIENT}

${OBJS_SERVER}: ${SRCS_SERVER}
	${CC} ${CFLAGS} -c ${SRCS_SERVER}

# Clean rule (delete object files)
clean:
	${RM} ${OBJS_CLIENT} ${OBJS_SERVER}

# Fclean rule (delete object files and executables)
fclean: clean
	${RM} ${NAME_CLIENT} ${NAME_SERVER}

# Rebuild rule (clean and then build everything again)
re: fclean all

.PHONY: all client server clean fclean re
