OS = $(shell uname)

#_/=\_/=\_/=\_/=\_/=\_/=\_/=\_/=\_/=\_/=\_/=\_/=\_/=\_/=\_/=\_/=\_/=\_/=\_/=\_/=\_/=\_/=\_/=\_
#_                                                                                           _
#_                                           COLORS                                          _
#_                                                                                           _
#_/=\_/=\_/=\_/=\_/=\_/=\_/=\_/=\_/=\_/=\_/=\_/=\_/=\_/=\_/=\_/=\_/=\_/=\_/=\_/=\_/=\_/=\_/=\_

RESET	= \033[0m
BLACK 	= \033[1;30m
RED 	= \033[1;31m
GREEN 	= \033[1;32m
YELLOW 	= \033[1;33m
BLUE	= \033[1;34m
PURPLE 	= \033[1;35m
CYAN 	= \033[1;36m
WHITE 	= \033[1;37m

#_/=\_/=\_/=\_/=\_/=\_/=\_/=\_/=\_/=\_/=\_/=\_/=\_/=\_/=\_/=\_/=\_/=\_/=\_/=\_/=\_/=\_/=\_/=\_
#_                                                                                           _
#_                                          COMMANDS                                         _
#_                                                                                           _
#_/=\_/=\_/=\_/=\_/=\_/=\_/=\_/=\_/=\_/=\_/=\_/=\_/=\_/=\_/=\_/=\_/=\_/=\_/=\_/=\_/=\_/=\_/=\_

CC = cc
RM = rm -rf
AR = ar -rcs

#_/=\_/=\_/=\_/=\_/=\_/=\_/=\_/=\_/=\_/=\_/=\_/=\_/=\_/=\_/=\_/=\_/=\_/=\_/=\_/=\_/=\_/=\_/=\_
#_                                                                                           _
#_                                          FOLDERS                                          _
#_                                                                                           _
#_/=\_/=\_/=\_/=\_/=\_/=\_/=\_/=\_/=\_/=\_/=\_/=\_/=\_/=\_/=\_/=\_/=\_/=\_/=\_/=\_/=\_/=\_/=\_

INC_FOLDER	= includes
SRC_FOLDER	= sources
OBJ_FOLDER	= objects
DEP_FOLDER	= dependencies
LIB			= library
LIB_A		= library/lib.a
MLX			= mlx_macos
_SUBFOLDERS	= . renderer vector entities utils intersections parser\

#_/=\_/=\_/=\_/=\_/=\_/=\_/=\_/=\_/=\_/=\_/=\_/=\_/=\_/=\_/=\_/=\_/=\_/=\_/=\_/=\_/=\_/=\_/=\_
#_                                                                                           _
#_                                           FLAGS                                           _
#_                                                                                           _
#_/=\_/=\_/=\_/=\_/=\_/=\_/=\_/=\_/=\_/=\_/=\_/=\_/=\_/=\_/=\_/=\_/=\_/=\_/=\_/=\_/=\_/=\_/=\_

CFLAGS		= -Wall -Wextra -Werror -I./mlx_macos -g
CPPFLAGS	= -I mandatory/$(INC_FOLDER)
MAKEFLAGS	= --no-print-directory
MLXFLAGS    = -framework Appkit -framework OpenGL -L ./mlx_macos -lmlx
LIBFTFLAGS	= -L ./$(LIB)
LDFLAGS		= $(LIBFTFLAGS) $(MLXFLAGS)

#_/=\_/=\_/=\_/=\_/=\_/=\_/=\_/=\_/=\_/=\_/=\_/=\_/=\_/=\_/=\_/=\_/=\_/=\_/=\_/=\_/=\_/=\_/=\_
#_                                                                                           _
#_                                        DEPENDENCIES                                       _
#_                                                                                           _
#_/=\_/=\_/=\_/=\_/=\_/=\_/=\_/=\_/=\_/=\_/=\_/=\_/=\_/=\_/=\_/=\_/=\_/=\_/=\_/=\_/=\_/=\_/=\_

# The vpath directive tells the Makefile to look in these folders for missing
# files. Because the BONUS_FILES only contains the name of the files we use and
# not the absolute path of them, the vpath directive helps the make to find
# the file names on it.

vpath %.c $(foreach subfolder, $(_SUBFOLDERS), mandatory/$(SRC_FOLDER)/$(subfolder))

#_/=\_/=\_/=\_/=\_/=\_/=\_/=\_/=\_/=\_/=\_/=\_/=\_/=\_/=\_/=\_/=\_/=\_/=\_/=\_/=\_/=\_/=\_/=\_
#_                                                                                           _
#_                                           FILES                                           _
#_                                                                                           _
#_/=\_/=\_/=\_/=\_/=\_/=\_/=\_/=\_/=\_/=\_/=\_/=\_/=\_/=\_/=\_/=\_/=\_/=\_/=\_/=\_/=\_/=\_/=\_

MANDATORY_FILES += pixel color ray
MANDATORY_FILES += vector vector_operations
MANDATORY_FILES += scene shape lightsource sphere
MANDATORY_FILES += message quadratic_formula
MANDATORY_FILES += intersection
MANDATORY_FILES += parser parse_illumination parse_utils read_map parse_shapes
MANDATORY_FILES += main

OBJS = $(patsubst %, $(OBJ_FOLDER)/%.o, $(MANDATORY_FILES))

NAME     = miniRT

#_/=\_/=\_/=\_/=\_/=\_/=\_/=\_/=\_/=\_/=\_/=\_/=\_/=\_/=\_/=\_/=\_/=\_/=\_/=\_/=\_/=\_/=\_/=\_
#_                                                                                           _
#_                                           RULES                                           _
#_                                                                                           _
#_/=\_/=\_/=\_/=\_/=\_/=\_/=\_/=\_/=\_/=\_/=\_/=\_/=\_/=\_/=\_/=\_/=\_/=\_/=\_/=\_/=\_/=\_/=\_

all: $(MLX) $(NAME)

$(NAME): $(OBJ_FOLDER) $(OBJS) $(MLX)
	echo "[$(CYAN)Compiling$(RESET)] $(GREEN)$(LIB)$(RESET)"
	$(MAKE) -C $(LIB)

	echo "[$(CYAN)Compiling$(RESET)] $(GREEN)$(MLX)$(RESET)"
	$(MAKE) -C $(MLX)

	echo "[$(CYAN) Linking $(RESET)] $(GREEN)$(NAME)$(RESET)"
	$(CC) $(CFLAGS) $(MLXFLAGS) $(CPPFLAGS) $(OBJS) $(LIB_A) -o $(NAME) $(LDFLAGS)

	echo "$(GREEN)Done.$(RESET)"

$(OBJ_FOLDER)/%.o: %.c
	echo "[$(CYAN)Compiling$(RESET)] $(CFLAGS) $(GREEN)$<$(RESET)"
	$(CC) $(CFLAGS) $(CPPFLAGS) -c $< -o $@

re: fclean
	$(MAKE) all

clean:
	echo "[$(RED) Deleted $(RESET)] $(GREEN)$(OBJ_FOLDER)$(RESET)"
	echo "[$(RED) Deleted $(RESET)] $(GREEN)$(DEP_FOLDER)$(RESET)"
	$(RM) $(OBJ_FOLDER) $(DEP_FOLDER)

fclean: clean
	$(MAKE) fclean -C $(LIB)
	$(MAKE) clean -C $(MLX)

	echo "[$(RED) Deleted $(RESET)] $(GREEN)$(NAME)$(RESET)"
	$(RM) $(NAME)

#_/=\_/=\_/=\_/=\_/=\_/=\_/=\_/=\_/=\_/=\_/=\_/=\_/=\_/=\_/=\_/=\_/=\_/=\_/=\_/=\_/=\_/=\_/=\_
#_                                                                                           _
#_                                        CUSTOM RULES                                       _
#_                                                                                           _
#_/=\_/=\_/=\_/=\_/=\_/=\_/=\_/=\_/=\_/=\_/=\_/=\_/=\_/=\_/=\_/=\_/=\_/=\_/=\_/=\_/=\_/=\_/=\_


$(OBJ_FOLDER):
	mkdir -p $(OBJ_FOLDER)

fast:
	$(MAKE) re -j

run: fast
	clear
	./$(NAME) $(SCENE)

brun: bfast
	clear
	./$(NAME) $(SCENE)

leaks: fast
	valgrind --leak-check=full --show-leak-kinds=all --log-file=output.log ./$(NAME) $(SCENE)

norm:
	echo "\n\t$(BLUE)_/=\\_/=\\_/=\\_ *.h FILES _/=\\_/=\\_/=\\_$(RESET)\n"
	norminette -R CheckDefine $(shell find . -type f -name "*.h")
	echo "\n\t$(BLUE)_/=\\_/=\\_/=\\_ *.c FILES _/=\\_/=\\_/=\\_$(RESET)\n"
	norminette -R checkForbiddenSourceHeader $(shell find . -type f -name "*.c")

.SILENT:
