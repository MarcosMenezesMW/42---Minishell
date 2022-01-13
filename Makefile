NAME			=	minishell

LIBFT			=	$(LIBFT_PATH)/libft.a

LIBFT_PATH		=	./libft
SRC_PATH		=	./src
OBJ_PATH		=	./obj
INCLUDES_PATH	=	./includes

SRC_FILES		=	minishell.c

CC				=	clang
FLAGS			=	-Wall -Wextra -Werror
IFLAGS			= 	-I $(LIBFT_PATH)
LFLAGS			=	-L $(LIBFT_PATH) -lft -lreadline
RM				=	rm -rf

OBJS			=	$(addprefix $(OBJ_PATH)/, $(SRC_FILES:.c=.o))

all: $(NAME)

$(NAME): $(LIBFT) $(OBJ_PATH) $(OBJS)
	$(CC) $(OBJS) -o $(NAME) $(LFLAGS)

$(LIBFT):
	@make -C $(LIBFT_PATH) all bonus

$(OBJ_PATH):
	@mkdir -p $(OBJ_PATH)

$(OBJ_PATH)/%.o: $(SRC_PATH)/%.c $(HEADERS)
	$(CC) $(FLAGS) $(IFLAGS) -c $< -o $@

clean:
	$(RM) $(OBJ_PATH)

fclean: clean
	make -C $(LIBFT_PATH) fclean
	$(RM) $(NAME)

re: fclean all

