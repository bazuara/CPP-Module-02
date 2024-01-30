/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bazura <bazuara@student.42madrid.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/01 16:07:05 by bazura            #+#    #+#             */
/*   Updated: 2024/01/30 12:47:55 by bazura           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <Fixed.hpp>

Fixed::Fixed(void) {
  std::cout << "Default constructor called" << std::endl;
  this->value = 0;
}   // default constructor

Fixed::Fixed(const int var) {
  std::cout << "Int constructor called" << std::endl;
  this->value = var << this->fractionalBits;
}   // constructor with parameter const int

Fixed::Fixed(const float var) {
  std::cout << "Float constructor called" << std::endl;
  this->value = std::roundf(var * (1 << this->fractionalBits));
}   // constructor with parameter const float

Fixed::Fixed(const Fixed& src) {
  std::cout << "Copy constructor called" << std::endl;
  *this = src;
}   // copy constructor

Fixed::~Fixed(void) {
  std::cout << "Destructor called" << std::endl;
}   // destructor

Fixed
& Fixed::operator=(const Fixed& var) {
  std::cout << "Assignation operator called" << std::endl;
  this->value = var.getRawBits();
  return *this;
}   // assignation operator overload

int Fixed::getRawBits(void) const {
  return this->value;
}   // getRawBits member function

void Fixed::setRawBits(int const raw) {
  this->value = raw;
}   // setRawBits member function

float Fixed::toFloat(void) const {
  return static_cast<float>(this->value) / (1 << this->fractionalBits);
}   // toFloat member function

int Fixed::toInt(void) const {
  return this->value >> this->fractionalBits;
}   // toInt member function

std::ostream
& operator<<(std::ostream& os, const Fixed& var) {
  os << var.toFloat();
  return os;
}   // overload of the insertion («) operator

// comparison operators overloaders

bool Fixed::operator>(const Fixed& var) const {
  return this->value > var.getRawBits();
}   // overload of the comparison operator (>)

bool Fixed::operator<(const Fixed& var) const {
  return this->value < var.getRawBits();
}   // overload of the comparison operator (<)

bool Fixed::operator>=(const Fixed& var) const {
  return this->value >= var.getRawBits();
}   // overload of the comparison operator (>=)


bool Fixed::operator<=(const Fixed& var) const {
  return this->value <= var.getRawBits();
}   // overload of the comparison operator (<=)

bool Fixed::operator==(const Fixed& var) const {
  return this->value == var.getRawBits();
}   // overload of the comparison operator (==)

bool Fixed::operator!=(const Fixed& var) const {
  return this->value != var.getRawBits();
}   // overload of the comparison operator (!=)

// operations overloaders

Fixed Fixed::operator+(const Fixed& var) const {
  return Fixed(this->toFloat() + var.toFloat());
}   // overload of the addition operator (+)

Fixed Fixed::operator-(const Fixed& var) const {
  return Fixed(this->toFloat() - var.toFloat());
}   // overload of the subtraction operator (-)

Fixed Fixed::operator*(const Fixed& var) const {
  return Fixed(this->toFloat() * var.toFloat());
}   // overload of the multiplication operator (*)

Fixed Fixed::operator/(const Fixed& var) const {
  return Fixed(this->toFloat() / var.toFloat());
}   // overload of the division operator (/)

// increment and decrement operators overloaders

Fixed& Fixed::operator++(void) {
  this->value++;
  return *this;
}   // overload of the increment operator (pre-increment)

Fixed Fixed::operator++(int) {
  Fixed tmp(*this);
  operator++();
  return tmp;
}   // overload of the increment operator (post-increment)

Fixed& Fixed::operator--(void) {
  this->value--;
  return *this;
}   // overload of the decrement operator (pre-decrement)

Fixed Fixed::operator--(int) {
  Fixed tmp(*this);
  operator--();
  return tmp;
}   // overload of the decrement operator (post-decrement)

// min and max functions

Fixed& Fixed::min(Fixed& var1, Fixed& var2) {
  return var1 < var2 ? var1 : var2;
}   // returns the min between two Fixed

Fixed& Fixed::max(Fixed& var1, Fixed& var2) {
  return var1 > var2 ? var1 : var2;
}   // returns the max between two Fixed

const Fixed& Fixed::min(const Fixed& var1, const Fixed& var2) {
  return var1 < var2 ? var1 : var2;
}   // returns the min between two Fixed

const Fixed& Fixed::max(const Fixed& var1, const Fixed& var2) {
  return var1 > var2 ? var1 : var2;
}   // returns the max between two Fixed

