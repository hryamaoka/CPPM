# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hyamaoka <hyamaoka@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/12/07 14:58:11 by hyamaoka          #+#    #+#              #
#    Updated: 2025/12/08 16:43:54 by hyamaoka         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = a.out

CXX = c++
CXXFLAGS = -Wall -Wextra -Werror -std=c++98
RM = rm -f

SRCS = main.cpp ClapTrap.cpp ScavTrap.cpp FragTrap.cpp
HEADERS = ClapTrap.hpp ScavTrap.hpp FragTrap.hpp
OBJS = $(SRCS:.cpp=.o)

all: $(NAME)

$(NAME): $(OBJS)
	$(CXX) $(CXXFLAGS) $(OBJS) -o $@

%.o: %.cpp $(HEADERS)
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
