NAME            = pipex
BONUS_NAME      = pipex_bonus
CC              = cc
CFLAGS          = -Wall -Wextra -Werror
SACRIFICE       = "                                                                                                     \n                                                  &                                                  \n                                                 &&&                                                 \n                                            &&   &&&   &&                                            \n                                             &&&&&&&&&&&                                             \n                                       &      &&&&&&&&       &                                       \n                                     &&        &&&&&&&        &&                                     \n                                  &&&&         &&&&&&&         &&&&                                  \n                                 &&&&          &&&&&&&          &&&&&                                \n                              &&&&&&&          &&&&&&&          &&&&&&&                              \n                            &&&&&&&&           &&&&&&&           &&&&&&&&                            \n                          &&&&&&&&&            &&&&&&&            &&&&&&&&&                          \n                          &&&&&&&&&&           &&&&&&&           &&&&&&&&&&                          \n                            &&&&&&&&&&         &&&&&&&         &&&&&&&&&&                            \n                              &&&&&&&&&&       &&&&&&&       &&&&&&&&&&                              \n                                &&&&&&&&&&     &&&&&&&     &&&&&&&&&&                                \n                                  &&&&&&&&&&   &&&&&&&   &&&&&&&&&&                                  \n                                    &&&&&&&&&& &&&&&&& &&&&&&&&&&                                    \n                                     &&&&&&&&&&&&&&&&&&&&&&&&&&&                                     \n                                       &&&&&&&&&&&&&&&&&&&&&&&                                       \n                                         &&&&&&&&&&&&&&&&&&&                                         \n                                           &&&&&&&&&&&&&&                                            \n                                             &&&&&&&&&&&                                             \n                                           &&&&&&&&&&&&&&&                                           \n                                         &&&&&&&&&&&&&&&&&&&                                         \n                                       &&&&&&&&&&&&&&&&&&&&&&&                                       \n                                      &&&&&&&&&&&&&&&&&&&&&&&&&                                      \n                                    &&&&&&&&&& &&&&&&& &&&&&&&&&&                                    \n                                  &&&&&&&&&&   &&&&&&&   &&&&&&&&&&                                  \n                                &&&&&&&&&&     &&&&&&&     &&&&&&&&&&                                \n                              &&&&&&&&&&       &&&&&&&       &&&&&&&&&&                              \n                            &&&&&&&&&&         &&&&&&&         &&&&&&&&&&                            \n                          &&&&&&&&&&           &&&&&&&           &&&&&&&&&&                          \n                           &&&&&&&&&&          &&&&&&&          &&&&&&&&&&                           \n                            &&&&&&&&&&&        &&&&&&&        &&&&&&&&&&&                            \n                              &&&&&&&&&&&      &&&&&&&      &&&&&&&&&&&                              \n                                &&&&&&&&&&     &&&&&&&    &&&&&&&&&&&                                \n                                  &&&&&&&&&&   &&&&&&&   &&&&&&&&&&                                  \n                                    &&&&&&&&&& &&&&&&& &&&&&&&&&&                                    \n                                      &&&&&&&&&&&&&&&&&&&&&&&&&                                      \n                                        &&&&&&&&&&&&&&&&&&&&&                                        \n                                          &&&&&&&&&&&&&&&&&                                          \n                                            &&&&&&&&&&&&&                                            \n                                              &&&&&&&&&                                              \n                                                &&&&&                                                \n                                                 &&&                                                 \n\n"

SRCDIR          = ./src
OBJDIR           = ./obj

SRC             = better_syscalls.c get_next_line_utils.c pipes.c psuedo_execlp.c \
                  exec_heredoc.c init.c fd_tools.c mysplit.c struct_tools.c string_tools2.c \
                  string_tools.c get_next_line.c misc_utils.c pipex.c

BONUS_SRC       = better_syscalls.c get_next_line_utils.c pipes.c psuedo_execlp.c \
                  exec_heredoc.c init.c fd_tools.c mysplit.c struct_tools.c string_tools2.c \
                  string_tools.c get_next_line.c misc_utils.c pipex_bonus.c

OBJ             = $(addprefix $(OBJDIR)/,$(SRC:.c=.o))
BONUS_OBJ       = $(addprefix $(OBJDIR)/,$(BONUS_SRC:.c=.o))

.PHONY: all bonus clean fclean re brand_of_sacrifice

all: brand_of_sacrifice $(NAME)

$(OBJDIR)/%.o: $(SRCDIR)/%.c
	@mkdir -p $(OBJDIR)
	$(CC) $(CFLAGS) -c $< -o $@

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) $^ -o $@

bonus: brand_of_sacrifice fclean $(BONUS_NAME)

$(BONUS_NAME): $(BONUS_OBJ)
	$(CC) $(CFLAGS) $^ -o $@
	@mv $(BONUS_NAME) $(NAME)

clean:
	rm -f $(OBJ) $(BONUS_OBJ)

fclean: clean
	rm -f $(NAME) $(BONUS_NAME)

re: fclean all

brand_of_sacrifice:
	@echo $(SACRIFICE)
