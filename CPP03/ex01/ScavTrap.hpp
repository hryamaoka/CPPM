/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyamaoka <hyamaoka@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/08 16:52:22 by hyamaoka          #+#    #+#             */
/*   Updated: 2025/12/08 16:53:04 by hyamaoka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCAVTRAP_HPP
#define SCAVTRAP_HPP

#include "ClapTrap.hpp"

class ScavTrap : public ClapTrap {
 private:
  bool _guardMode;

 public:
  ScavTrap();
  ScavTrap(const std::string& name);
  ScavTrap(const ScavTrap& other);
  ScavTrap& operator=(const ScavTrap& other);
  ~ScavTrap();

  void guardGate();
  void attack(const std::string& target);
};

#endif
