CPP_FILES = $(wildcard *.cpp)
NAME = $(basename $(CPP_FILES))

CXXFLAGS = -MMD -std=c++11
OBJ_DIR = objs
OBJS = $(addprefix $(OBJ_DIR)/, $(SRCS:.cpp=.o))
DEF = $(addprefix $(OBJ_DIR)/, $(SRCS:.cpp=.d))

all : $(NAME)

$(NAME) : $(OBJ_DIR) $(OBJS)
	@$(CXX) $(OBJS) -o $@ 

$(OBJ_DIR) :
	@mkdir $@

$(OBJ_DIR)/%.o : %.cpp
	@$(CXX) $(DEBUG) $(CXXFLAGS) -c $< -o $@

clean :
	@rm -rf $(OBJ_DIR)

fclean : clean
	@rm -f $(NAME)

re : 
	@make fclean
	@make all

test :
	@make re
	./$(NAME)

.PHONY : all clean fclean re

-include $(DEF)