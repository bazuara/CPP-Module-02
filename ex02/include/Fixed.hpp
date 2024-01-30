/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bazura <bazuara@student.42madrid.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/01 16:07:09 by bazura            #+#    #+#             */
/*   Updated: 2024/01/30 12:47:59 by bazura           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// A class thar implements in a cannonical orthodox way the Fixed point number
// representation.
// The class has a private member of type int that stores the fixed point number
// and a static constant integer to store the number of fractional bits.
// Its value will always be the integer literal 8.
// The class has the following public member functions:
//   A default constructor that initializes the fixed-point number value to 0.
//   A copy constructor.
//   A copy assignment operator overload.
//   A destructor.
//   A member function int getRawBits( void ) const;
//     that returns the raw value of the fixed-point value.
//   A member function void setRawBits( int const raw );
//     that sets the raw value of the fixed-point number.

#ifndef FIXED_HPP_
#define FIXED_HPP_

#include <iostream>
#include <cmath>

class Fixed {
 private:
  int value;
  static const int fractionalBits = 8;

 public:
  Fixed(void);
  explicit Fixed(const int var);
  explicit Fixed(const float var);
  Fixed(const Fixed& src);
  ~Fixed(void);

  Fixed& operator=(const Fixed& var);

  int getRawBits(void) const;
  void setRawBits(int const raw);
  float toFloat(void) const;
  int toInt(void) const;

  bool operator>(const Fixed& var) const;
  bool operator<(const Fixed& var) const;
  bool operator>=(const Fixed& var) const;
  bool operator<=(const Fixed& var) const;
  bool operator==(const Fixed& var) const;
  bool operator!=(const Fixed& var) const;

  Fixed operator+(const Fixed& var) const;
  Fixed operator-(const Fixed& var) const;
  Fixed operator*(const Fixed& var) const;
  Fixed operator/(const Fixed& var) const;

  Fixed& operator++(void);
  Fixed operator++(int);
  Fixed& operator--(void);
  Fixed operator--(int);

  static Fixed& min(Fixed& var1, Fixed& var2);
  static Fixed& max(Fixed& var1, Fixed& var2);
  static const Fixed& min(const Fixed& var1, const Fixed& var2);
  static const Fixed& max(const Fixed& var1, const Fixed& var2);
};

  std::ostream &operator<<(std::ostream& os, const Fixed& var);

#endif  // FIXED_HPP_
