/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmutschl <jmutschl@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/25 09:53:48 by jmutschl          #+#    #+#             */
/*   Updated: 2025/08/26 15:25:51 by jmutschl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

const int	Fixed::_fractionalBits = 8;

Fixed::Fixed() : _fixedPointValue(0)
{
	std::cout << "Default constructor called\n";
}

Fixed::Fixed(const Fixed &src)
{
	std::cout << "Copy constructor called\n";
	*this = src;
}

Fixed	&Fixed::operator=(const Fixed &src)
{
	std::cout << "Copy assignment operator called\n";
	if (this != &src)
		this->_fixedPointValue = src.getRawBits();
	return *this;
}

Fixed::~Fixed()
{
	std::cout << "Destructor called\n";
}

Fixed::Fixed(const int value)
{
	std::cout << "Int constructor called\n";
	this->_fixedPointValue = value << _fractionalBits;
}

Fixed::Fixed(const float value)
{
	std::cout << "Float constructor called\n";
	this->_fixedPointValue = static_cast<int>(roundf(value * (1 << _fractionalBits)));
}

int	Fixed::getRawBits(void) const
{
	std::cout << "getRawBits member function called\n";
	return (this->_fixedPointValue);
}

void	Fixed::setRawBits(int const raw)
{
	this->_fixedPointValue = raw;
}

int Fixed::toInt( void ) const
{
	return (this->_fixedPointValue >> _fractionalBits);
}

float Fixed::toFloat( void ) const
{
    return (static_cast<float>(this->_fixedPointValue) / (1 << _fractionalBits));
}

std::ostream	&operator<<(std::ostream &os, const Fixed &output)
{
	os << output.toFloat();
	return (os);
}