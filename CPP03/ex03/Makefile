# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hyamaoka <hyamaoka@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/12/08 16:53:59 by hyamaoka          #+#    #+#              #
#    Updated: 2025/12/08 16:54:32 by hyamaoka         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = a.out

CXX = c++



# 1. 通常のフラグ (今は無効)
# CXXFLAGS = -Wall -Wextra -Werror -std=c++98

# 2. シャドウイング警告を出す設定 (テスト用：これを有効にするとコンパイルエラーになる)
CXXFLAGS = -Wall -Wextra -Werror -std=c++98 -Wshadow

# 3. シャドウイング警告を無視する設定 (テスト用)
# CXXFLAGS = -Wall -Wextra -Werror -std=c++98 -Wno-shadow


RM = rm -f

SRCS = main.cpp ClapTrap.cpp ScavTrap.cpp FragTrap.cpp DiamondTrap.cpp
HEADERS = ClapTrap.hpp ScavTrap.hpp FragTrap.hpp DiamondTrap.hpp
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
