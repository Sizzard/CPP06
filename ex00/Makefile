CPPFLAGS = -Wall -Wextra -Werror -std=c++98
NAME = scalar
SRC = ScalarConverter.cpp\
	main.cpp
OBJETS = $(SRC:.cpp=.o)

all : $(NAME)

$(NAME) : $(OBJETS)
	c++ $(CPPFLAGS) -o $(NAME) $(OBJETS)

%.o:%.cpp ScalarConverter.hpp
	c++ $(CPPFLAGS) -c -o $@ $<

clean :
	rm -f $(OBJETS)

fclean :
	rm -f $(OBJETS)
	rm -f $(NAME)

re : fclean all

.PHONY : clean fclean all re
