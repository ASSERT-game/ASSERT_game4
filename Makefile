NAME = blaster
FLAGS = -Wall -Wextra -Werror
# FLAGS = -Wall -Wextra -Werror -fsanitize=address
INCLUDES = -I includes/ -I includes/SDLX/
SDL_LIB = -L ~/.brew/lib -l SDL2 -l sdl2_image -l SDL2_ttf

SDLX_DIR = SDLX/
SRC_DIR = src/
BIN_DIR = bin/

SDLX_NAMES = 			\
	SDLX_background		\
	SDLX_button_loop	\
	SDLX_button			\
	SDLX_collisions		\
	SDLX_init			\
	SDLX_input			\
	SDLX_ticks			\
	SDLX_render_queue	\
	SDLX_render			\
	SDLX_utils			\
	SDLX_xbox			\

SCENE_FILES = 			\
	main_menu			\
	level_select		\
	\
	death_scene			\
	loot_scene			\
	\
	first_level			\
	second_level		\
	third_level			\
	\
	scene_utils			\

ENEMY_FILES = 			\
	slime				\

WEAPON_FILES = 			\
	heal				\
	laser				\
	weapon_manager		\
	weapon_utils		\


# List of all the source files.
SRC_NAMES = \
	$(addprefix enemy/, $(ENEMY_FILES))		\
	$(addprefix scenes/, $(SCENE_FILES))	\
	$(addprefix $(SDLX_DIR), $(SDLX_NAMES))	\
	$(addprefix weapons/, $(WEAPON_FILES))	\
	button \
	input \
	level_sprite \
	player \
	main \
	ui_sprites \
	utils \

# List of all the source files, folders are to be added by
# including a $(addprefix, DIR_NAME, $(DIR_FILES))
FILE_NAMES = \
	$(SRC_NAMES) \

SRCS = $(addsuffix .c, $(addprefix $(SRC_DIR), $(FILE_NAMES)))
# Object files will be built to BIN_DIR. They will build the
# structure/ path tree that the SRC_DIR has.
OBJS = $(addprefix $(BIN_DIR), $(SRCS:.c=.o))

all: $(NAME)

$(NAME): $(BIN_DIR) $(OBJS)
	gcc $(FLAGS) $(INCLUDES) -o $(NAME) $(OBJS) $(SDL_LIB)

$(BIN_DIR):
	mkdir -p $(BIN_DIR)

# These are the target object file names given by path ($(OBJS)).
# We will create the required directories with mkdir -p.
$(BIN_DIR)%.o: %.c
	mkdir -p $(BIN_DIR)$(dir $<)
	gcc $(FLAGS) $(INCLUDES) -c $< -o $@

clean:
	rm -f $(OBJS)

fclean: clean
	rm -rf $(NAME)

# Ensure that when git add is done the repo is cleaned out.
save: fclean
	git add .
	git commit -m "$(MSG)"
	git push

re: fclean all

run:
	rm -f $(NAME)
	make all
	clear
	@echo "\033[1m\033[32m$(NAME)\033[0m"
	@./$(NAME)

