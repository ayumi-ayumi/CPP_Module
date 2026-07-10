NAME = phonebook

CXX = c++

CXXFLAGS =  -Wall -Wextra -Werror -std=c++98

OBJ_DIR = obj

SRCS = main.cpp \
		PhoneBook.cpp \
		cmd_add.cpp \
		cmd_search.cpp \
		Contact.cpp

OBJ = $(SRCS:.cpp=.o)
OBJS = $(addprefix $(OBJ_DIR)/, $(OBJ))

all: $(NAME)

$(NAME): $(OBJS)
	$(CXX) $(CXXFLAGS) $(OBJS) -o $(NAME)

$(OBJ_DIR)/%.o: %.cpp
	mkdir -p $(dir $@)
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	rm -rf $(OBJ_DIR)

fclean: clean
	rm -rf $(NAME)

re: fclean all

.PHONY: all clean fclean re
