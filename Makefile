NAME = blaster
NAMEW = ../index.html
# FLAGS = -Wall -Wextra -Werror
# FLAGS = -Wall -Wextra -Werror -O2
FLAGS = -Wall -Wextra -Werror -fsanitize=address
INCLUDES = -I includes/ -I includes/SDLX/

LIBRARIES = -s USE_SDL=2 -s USE_SDL_TTF=2 -s USE_SDL_IMAGE=2 -s SDL2_IMAGE_FORMATS="['png']"
SKELE_HTML = --shell-file ../skeleton.html

SDL_LIB = -L ~/.brew/lib -l SDL2 -l sdl2_image -l SDL2_ttf

PRELOAD_FILES =	\
	assets/

PRELOAD = --preload-file $(PRELOAD_FILES)

SDLX_DIR = SDLX/
SRC_DIR = src/
BIN_DIR = bin/

SDLX_NAMES = 			\
	SDLX_background		\
	SDLX_button_loop	\
	SDLX_button			\
	SDLX_collide		\
	SDLX_collisions		\
	SDLX_init			\
	SDLX_input			\
	SDLX_ticks			\
	SDLX_math			\
	SDLX_render_queue	\
	SDLX_render			\
	SDLX_utils			\
	SDLX_utilsX			\
	SDLX_xbox			\

LEVEL_FILES = 			\
	level_01			\
	level_02			\
	level_03			\
	level_04			\
	level_05			\
	level_06			\
	level_07			\
	level_08			\
	level_09			\
	level_10			\
	level_11			\
	level_12			\
	level_13			\
	level_14			\
	level_15			\
	level_16			\
	level_17			\
	level_18			\
	level_19			\

SCENE_FILES = 			\
	main_menu			\
	level_select		\
	death_scene			\
	loot_scene			\
	level				\

SPRITE_FILES = 			\
	bunny_sprite \
	chest_sprite \
	combo_sprite \
	cooldown_sprite \
	cooldown_ghost_sprite \
	emp_sprite \
	faser_sprite \
	ghostfire_sprite \
	hp_sprite \
	level_sprite \
	loot_sprite \
	pause_sprite \
	shield_sprite \
	slime_sprite \
	ui_sprites \
	laser_red_sprite \

ENEMY_FILES = 			\
	slime				\
	slime_util			\

WEAPON_FILES = 			\
	w_emp				\
	w_faser				\
	w_ghostfire			\
	w_laser				\
	w_shield			\

# List of all the source files.
SRC_NAMES = \
	$(addprefix enemy/, $(ENEMY_FILES))		\
	$(addprefix sprite/, $(SPRITE_FILES))	\
	$(addprefix scenes/, $(SCENE_FILES))	\
	$(addprefix levels/, $(LEVEL_FILES))	\
	$(addprefix $(SDLX_DIR), $(SDLX_NAMES))	\
	$(addprefix weapons/, $(WEAPON_FILES))	\
	blaster_init \
	button \
	combo \
	entity_manager \
	level_init \
	main \
	player \
	scene_utils \
	status_effects \
	ui \
	utils \
	waves \
	weapon_utils \

# List of all the source files, folders are to be added by
# including a $(addprefix, DIR_NAME, $(DIR_FILES))
FILE_NAMES = \
	$(SRC_NAMES) \

SRCS = $(addsuffix .c, $(addprefix $(SRC_DIR), $(FILE_NAMES)))
# Object files will be built to BIN_DIR. They will build the
# structure/ path tree that the SRC_DIR has.
OBJS = $(addprefix $(BIN_DIR), $(SRCS:.c=.o))

all:
	make -j $(NAME)

allw:
	emcc -Wall -Wextra -Werror -O0 $(INCLUDES) -D EMCC $(LIBRARIES) $(PRELOAD) $(SRCS) $(SKELE_HTML) -o $(NAMEW)

$(NAME): $(BIN_DIR) $(OBJS)
	@gcc $(FLAGS) $(INCLUDES) -o $(NAME) $(OBJS) $(SDL_LIB)

$(BIN_DIR):
	mkdir -p $(BIN_DIR)

# These are the target object file names given by path ($(OBJS)).
# We will create the required directories with mkdir -p.
$(BIN_DIR)%.o: %.c
	@mkdir -p $(BIN_DIR)$(dir $<)
	@gcc $(FLAGS) $(INCLUDES) -c $< -o $@

clean:
	@rm -f $(OBJS)

fclean: clean
	rm -rf $(NAME)

# Ensure that when git add is done the repo is cleaned out.
save: fclean
	git add .
	git commit -m "$(MSG)"
	git push

re: fclean all

rew:
	rm -f ../index.data
	rm -f ../index.html
	rm -f ../index.js
	rm -f ../index.wasm
	make allw

run:
	rm -f $(NAME)
	make -j all
	clear
	@echo "\033[1m\033[32m$(NAME)\033[0m"
	@./$(NAME)

