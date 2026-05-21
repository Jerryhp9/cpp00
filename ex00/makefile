CXX = c++
CXXFLAGS = -g3 -Wall -Werror -Wextra -std=c++98
NAME = megaphone
RM = rm -f

SRC = megaphone.cpp

OBJ = $(SRC:.cpp=.o)

$(NAME) : $(OBJ)
		@$(CXX) $(CXXFLAGS) -I. $(OBJ) -o $@

all: $(NAME)

%.o : %.cpp
		  @$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
		@$(RM) $(OBJ)

fclean:	clean
		@$(RM) $(NAME)

re: fclean $(NAME)

.PHONY: all clean fclean re