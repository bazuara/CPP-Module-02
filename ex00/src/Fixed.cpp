/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bazura <bazuara@student.42madrid.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/01 16:07:05 by bazura            #+#    #+#             */
/*   Updated: 2023/11/02 10:32:39 by bazura           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <Fixed.hpp>

Fixed::Fixed(void) {
  std::cout << "Default constructor called" << std::endl;
  this->value = 0;
}   // default constructor

Fixed::Fixed(const Fixed& src) {
  std::cout << "Copy constructor called" << std::endl;
  *this = src;
}   // copy constructor

Fixed::~Fixed(void) {
  std::cout << "Destructor called" << std::endl;
}   // destructor

Fixed& Fixed::operator=(const Fixed& var) {
  std::cout << "Assignation operator called" << std::endl;
  this->value = var.getRawBits();
  return *this;
}   // assignation operator overload

int Fixed::getRawBits(void) const {
  std::cout << "getRawBits member function called" << std::endl;
  return this->value;
}   // getRawBits member function

void Fixed::setRawBits(int const raw) {
  std::cout << "setRawBits member function called" << std::endl;
  this->value = raw;
}   // setRawBits member function
