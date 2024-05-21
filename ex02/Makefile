CPPFLAGS = -Wall -Wextra -Werror
NAME = identify
SRC = Base.cpp A.cpp B.cpp C.cpp\
	main.cpp
OBJETS = $(SRC:.cpp=.o)

all : $(NAME)

$(NAME) : $(OBJETS)
	c++ $(CPPFLAGS) -o $(NAME) $(OBJETS)

%.o:%.cpp Base.hpp A.hpp B.hpp C.hpp
	c++ $(CPPFLAGS) -c -o $@ $<

clean : 
	rm -f $(OBJETS)

fclean :
	rm -f $(OBJETS)
	rm -f $(NAME)

re : fclean all

.PHONY : clean fclean all re