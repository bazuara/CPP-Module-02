/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bazura <bazuara@student.42madrid.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/01 16:07:09 by bazura            #+#    #+#             */
/*   Updated: 2024/01/28 02:19:10 by bazura           ###   ########.fr       */
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
  Fixed(const int var);
  Fixed(const float var);
  Fixed(const Fixed& src);
  ~Fixed(void);

  Fixed& operator=(const Fixed& var);

  int getRawBits(void) const;
  void setRawBits(int const raw);
  float toFloat(void) const;
  int toInt(void) const;
};

  std::ostream &operator<<(std::ostream& os, const Fixed& var);

#endif  // FIXED_HPP_
