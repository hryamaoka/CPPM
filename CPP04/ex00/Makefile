# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hyamaoka <hyamaoka@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/12/07 14:58:11 by hyamaoka          #+#    #+#              #
#    Updated: 2025/12/08 16:44:43 by hyamaoka         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = animals

CXX = c++
CXXFLAGS = -Wall -Wextra -Werror -std=c++98
RM = rm -f

SRCS = main.cpp \
       Animal.cpp \
       Cat.cpp \
       Dog.cpp \
       WrongAnimal.cpp \
       WrongCat.cpp

OBJS = $(SRCS:.cpp=.o)

HEADERS = Animal.hpp \
          Cat.hpp \
          Dog.hpp \
          WrongAnimal.hpp \
          WrongCat.hpp

all: $(NAME)

$(NAME): $(OBJS)
	@echo "Linking $(NAME)..."
	@$(CXX) $(CXXFLAGS) $(OBJS) -o $@
	@echo "Build complete!"

%.o: %.cpp $(HEADERS)
	@echo "Compiling $<..."
	@$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	@echo "Cleaning object files..."
	@$(RM) $(OBJS)

fclean: clean
	@echo "Removing $(NAME)..."
	@$(RM) $(NAME)

re: fclean all

test: $(NAME)
	@echo "Running tests..."
	@./$(NAME)

valgrind: $(NAME)
	@echo "Running valgrind..."
	@valgrind --leak-check=full --show-leak-kinds=all ./$(NAME)

.PHONY: all clean fclean re test valgrind
