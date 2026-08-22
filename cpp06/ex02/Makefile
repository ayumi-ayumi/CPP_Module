NAME = ex02

CXX = c++

CXXFLAGS = -Wall -Wextra -Werror -std=c++98

INC_DIR	= includes
SRC_DIR	= src
OBJ_DIR = obj

SRCS_FILES = main.cpp \
		Base.cpp \
		A.cpp \
		B.cpp \
		C.cpp \
		generate.cpp \
		identify_ptr.cpp \
		identify_ref.cpp 

SRCS	= $(addprefix $(SRC_DIR)/, $(SRCS_FILES))
OBJS	= $(addprefix $(OBJ_DIR)/, $(SRCS_FILES:.cpp=.o))

all: $(NAME)

$(NAME): $(OBJS)
	$(CXX) $(CXXFLAGS) $(OBJS) -o $(NAME)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.cpp
	mkdir -p $(dir $@)
	$(CXX) $(CXXFLAGS) -I$(INC_DIR) -c $< -o $@

clean:
	rm -rf $(OBJ_DIR)

fclean: clean
	rm -rf $(NAME)

re: fclean all

.PHONY: all clean fclean re
