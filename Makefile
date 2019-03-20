

NAME =	ft_gkrellm

CC = clang++

FLAGS = -Wall -Werror -Wextra -std=c++98

FRAMEWORKS = -F./frameworks \
               -rpath ./frameworks \
               -framework SDL2 -framework SDL2_ttf -framework SDL2_image \

INCLUDES =  -I./frameworks/SDL2.framework/Versions/A/Headers \
               -I./frameworks/SDL2_ttf.framework/Versions/A/Headers \
               -I./frameworks/SDL2_image.framework/Versions/A/Headers \
             

SRC = main.cpp graphic.cpp DateTime.cpp Module.cpp CPU.cpp System.cpp RAM.cpp Network.cpp \
		Ncurses.cpp Disk.cpp Memory.cpp Processes.cpp

OBJ = $(addprefix $(OBJ_DIR)/, $(SRC:.cpp=.o))
OBJ_DIR = objects

all:	 $(NAME)

$(NAME): $(OBJ_DIR) $(OBJ)
		 $(CC) $(FLAGS) $(OBJ) -o $(NAME) $(FRAMEWORKS) $(INCLUDES)  -lncurses

$(OBJ_DIR):
	mkdir -p $(OBJ_DIR)
$(OBJ_DIR)/%.o: %.cpp
		$(CC) $(FLAGS) $(INCLUDES)-c $< -o $@  

clean:
		/bin/rm -f $(OBJ)

fclean: clean
		/bin/rm -f $(NAME)

re:		fclean all

run: $(NAME)
		./$(NAME) 1

.PHONY: all clean fclean re
