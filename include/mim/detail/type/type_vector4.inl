// Copyright (c) 2023-Present Mim contributors (see LICENSE)

#include "mim/detail/compute/compute_vector.hpp"

namespace mim {

template <typename T, qualifier Q>
constexpr T& VectorT<4, T, Q>::operator[](size_type i) {
	if (i >= this->length()) {
        throw std::out_of_range("VectorT<4, T, Q>::operator[]");
    }

	switch (i) {
	default:
	case 0: return x;
	case 1: return y;
	case 2: return z;
	case 3: return w;
	}
}

template <typename T, qualifier Q>
constexpr T const& VectorT<4, T, Q>::operator[](size_type i) const {
	if (i >= this->length()) {
		throw std::out_of_range("VectorT<4, T, Q>::operator[]");
	}

	switch (i) {
	default:
	case 0: return x;
	case 1: return y;
	case 2: return z;
	case 3: return w;
	}
}

/// Constructors

template <typename T, qualifier Q>
constexpr VectorT<4, T, Q>::VectorT() : x(0), y(0), z(0), w(0) {}

template <typename T, qualifier Q>
constexpr VectorT<4, T, Q>::VectorT(T _x, T _y, T _z, T _w) : x(_x), y(_y), z(_z), w(_w) {}

template <typename T, qualifier Q>
constexpr VectorT<4, T, Q>::VectorT(VectorT<4, T, Q> const& v) : x(v.x), y(v.y), z(v.z), w(v.w) {}

template <typename T, qualifier Q>
constexpr VectorT<4, T, Q>::VectorT(T scalar) : x(scalar), y(scalar), z(scalar), w(scalar) {}


/// Template constructors

template <typename T, qualifier Q>
template <qualifier P>
constexpr VectorT<4, T, Q>::VectorT(VectorT<4, T, P> const& v)
	: x(v.x), y(v.y), z(v.z), w(v.w) {}

template <typename T, qualifier Q>
template <typename U, qualifier P>
constexpr VectorT<4, T, Q>::VectorT(VectorT<1, U, P> const& v)
	: x(static_cast<T>(v.x)), y(static_cast<T>(v.x)), z(static_cast<T>(v.x)), w(static_cast<T>(v.x)) {}

template <typename T, qualifier Q>
template <typename X, typename Y, typename Z, typename W>
constexpr VectorT<4, T, Q>::VectorT(X _x, Y _y, Z _z, W _w)
	: x(static_cast<T>(_x)), y(static_cast<T>(_y)), z(static_cast<T>(_z)), w(static_cast<T>(_w)) {}

template <typename T, qualifier Q>
template <typename X, typename Y, typename Z, typename W>
constexpr VectorT<4, T, Q>::VectorT(VectorT<1, X, Q> const& _x, Y _y, Z _z, W _w)
	: x(static_cast<T>(_x.x)), y(static_cast<T>(_y)), z(static_cast<T>(_z)), w(static_cast<T>(_w)) {}

template <typename T, qualifier Q>
template <typename X, typename Y, typename Z, typename W>
constexpr VectorT<4, T, Q>::VectorT(X _x, VectorT<1, Y, Q> const& _y, Z _z, W _w)
	: x(static_cast<T>(_x)), y(static_cast<T>(_y.x)), z(static_cast<T>(_z)), w(static_cast<T>(_w)) {}

template <typename T, qualifier Q>
template <typename X, typename Y, typename Z, typename W>
constexpr VectorT<4, T, Q>::VectorT(VectorT<1, X, Q> const& _x, VectorT<1, Y, Q> const& _y, Z _z, W _w)
	: x(static_cast<T>(_x.x)), y(static_cast<T>(_y.x)), z(static_cast<T>(_z)), w(static_cast<T>(_w)) {}

template <typename T, qualifier Q>
template <typename X, typename Y, typename Z, typename W>
constexpr VectorT<4, T, Q>::VectorT(X _x, Y _y, VectorT<1, Z, Q> const& _z, W _w)
	: x(static_cast<T>(_x)), y(static_cast<T>(_y)), z(static_cast<T>(_z.x)), w(static_cast<T>(_w)) {}

template <typename T, qualifier Q>
template <typename X, typename Y, typename Z, typename W>
constexpr VectorT<4, T, Q>::VectorT(VectorT<1, X, Q> const& _x, Y _y, VectorT<1, Z, Q> const& _z, W _w)
	: x(static_cast<T>(_x.x)), y(static_cast<T>(_y)), z(static_cast<T>(_z.x)), w(static_cast<T>(_w)) {}

template <typename T, qualifier Q>
template <typename X, typename Y, typename Z, typename W>
constexpr VectorT<4, T, Q>::VectorT(X _x, VectorT<1, Y, Q> const& _y, VectorT<1, Z, Q> const& _z, W _w)
	: x(static_cast<T>(_x)), y(static_cast<T>(_y.x)), z(static_cast<T>(_z.x)), w(static_cast<T>(_w)) {}

template <typename T, qualifier Q>
template <typename X, typename Y, typename Z, typename W>
constexpr VectorT<4, T, Q>::VectorT(VectorT<1, X, Q> const& _x, VectorT<1, Y, Q> const& _y, VectorT<1, Z, Q> const& _z, W _w)
	: x(static_cast<T>(_x.x)), y(static_cast<T>(_y.x)), z(static_cast<T>(_z.x)), w(static_cast<T>(_w)) {}

template <typename T, qualifier Q>
template <typename X, typename Y, typename Z, typename W>
constexpr VectorT<4, T, Q>::VectorT(VectorT<1, X, Q> const& _x, Y _y, Z _z, VectorT<1, W, Q> const& _w)
	: x(static_cast<T>(_x.x)), y(static_cast<T>(_y)), z(static_cast<T>(_z)), w(static_cast<T>(_w.x)) {}

template <typename T, qualifier Q>
template <typename X, typename Y, typename Z, typename W>
constexpr VectorT<4, T, Q>::VectorT(X _x, VectorT<1, Y, Q> const& _y, Z _z, VectorT<1, W, Q> const& _w)
	: x(static_cast<T>(_x)), y(static_cast<T>(_y.x)), z(static_cast<T>(_z)), w(static_cast<T>(_w.x)) {}

template <typename T, qualifier Q>
template <typename X, typename Y, typename Z, typename W>
constexpr VectorT<4, T, Q>::VectorT(VectorT<1, X, Q> const& _x, VectorT<1, Y, Q> const& _y, Z _z, VectorT<1, W, Q> const& _w)
	: x(static_cast<T>(_x.x)), y(static_cast<T>(_y.x)), z(static_cast<T>(_z)), w(static_cast<T>(_w.x)) {}

template <typename T, qualifier Q>
template <typename X, typename Y, typename Z, typename W>
constexpr VectorT<4, T, Q>::VectorT(X _x, Y _y, VectorT<1, Z, Q> const& _z, VectorT<1, W, Q> const& _w)
	: x(static_cast<T>(_x)), y(static_cast<T>(_y)), z(static_cast<T>(_z.x)), w(static_cast<T>(_w.x)) {}

template <typename T, qualifier Q>
template <typename X, typename Y, typename Z, typename W>
constexpr VectorT<4, T, Q>::VectorT(VectorT<1, X, Q> const& _x, Y _y, VectorT<1, Z, Q> const& _z, VectorT<1, W, Q> const& _w)
	: x(static_cast<T>(_x.x)), y(static_cast<T>(_y)), z(static_cast<T>(_z.x)), w(static_cast<T>(_w.x)) {}

template <typename T, qualifier Q>
template <typename X, typename Y, typename Z, typename W>
constexpr VectorT<4, T, Q>::VectorT(X _x, VectorT<1, Y, Q> const& _y, VectorT<1, Z, Q> const& _z, VectorT<1, W, Q> const& _w)
	: x(static_cast<T>(_x)), y(static_cast<T>(_y.x)), z(static_cast<T>(_z.x)), w(static_cast<T>(_w.x)) {}

template <typename T, qualifier Q>
template <typename X, typename Y, typename Z, typename W>
constexpr VectorT<4, T, Q>::VectorT(VectorT<1, X, Q> const& _x, VectorT<1, Y, Q> const& _y, VectorT<1, Z, Q> const& _z, VectorT<1, W, Q> const& _w)
	: x(static_cast<T>(_x.x)), y(static_cast<T>(_y.x)), z(static_cast<T>(_z.x)), w(static_cast<T>(_w.x)) {}

template <typename T, qualifier Q>
template <typename A, typename B, typename C, qualifier P>
constexpr VectorT<4, T, Q>::VectorT(VectorT<2, A, P> const& _xy, B _z, C _w)
	: x(static_cast<T>(_xy.x)), y(static_cast<T>(_xy.y)), z(static_cast<T>(_z)), w(static_cast<T>(_w)) {}

template <typename T, qualifier Q>
template <typename A, typename B, typename C, qualifier P>
constexpr VectorT<4, T, Q>::VectorT(VectorT<2, A, P> const& _xy, VectorT<1, B, P> const& _z, C _w)
	: x(static_cast<T>(_xy.x)), y(static_cast<T>(_xy.y)), z(static_cast<T>(_z.x)), w(static_cast<T>(_w)) {}

template <typename T, qualifier Q>
template <typename A, typename B, typename C, qualifier P>
constexpr VectorT<4, T, Q>::VectorT(VectorT<2, A, P> const& _xy, B _z, VectorT<1, C, P> const& _w)
	: x(static_cast<T>(_xy.x)), y(static_cast<T>(_xy.y)), z(static_cast<T>(_z)), w(static_cast<T>(_w.x)) {}

template <typename T, qualifier Q>
template <typename A, typename B, typename C, qualifier P>
constexpr VectorT<4, T, Q>::VectorT(VectorT<2, A, P> const& _xy, VectorT<1, B, P> const& _z, VectorT<1, C, P> const& _w)
	: x(static_cast<T>(_xy.x)), y(static_cast<T>(_xy.y)), z(static_cast<T>(_z.x)), w(static_cast<T>(_w.x)) {}

template <typename T, qualifier Q>
template <typename A, typename B, typename C, qualifier P>
constexpr VectorT<4, T, Q>::VectorT(A _x, VectorT<2, B, P> const& _yz, C _w)
	: x(static_cast<T>(_x)), y(static_cast<T>(_yz.x)), z(static_cast<T>(_yz.y)), w(static_cast<T>(_w)) {}

template <typename T, qualifier Q>
template <typename A, typename B, typename C, qualifier P>
constexpr VectorT<4, T, Q>::VectorT(VectorT<1, A, P> const& _x, VectorT<2, B, P> const& _yz, C _w)
	: x(static_cast<T>(_x.x)), y(static_cast<T>(_yz.x)), z(static_cast<T>(_yz.y)), w(static_cast<T>(_w)) {}

template <typename T, qualifier Q>
template <typename A, typename B, typename C, qualifier P>
constexpr VectorT<4, T, Q>::VectorT(A _x, VectorT<2, B, P> const& _yz, VectorT<1, C, P> const& _w)
	: x(static_cast<T>(_x)), y(static_cast<T>(_yz.x)), z(static_cast<T>(_yz.y)), w(static_cast<T>(_w.x)) {}

template <typename T, qualifier Q>
template <typename A, typename B, typename C, qualifier P>
constexpr VectorT<4, T, Q>::VectorT(VectorT<1, A, P> const& _x, VectorT<2, B, P> const& _yz, VectorT<1, C, P> const& _w)
	: x(static_cast<T>(_x.x)), y(static_cast<T>(_yz.x)), z(static_cast<T>(_yz.y)), w(static_cast<T>(_w.x)) {}

template <typename T, qualifier Q>
template <typename A, typename B, typename C, qualifier P>
constexpr VectorT<4, T, Q>::VectorT(A _x, B _y, VectorT<2, C, P> const& _zw)
	: x(static_cast<T>(_x)), y(static_cast<T>(_y)), z(static_cast<T>(_zw.x)), w(static_cast<T>(_zw.y)) {}

template <typename T, qualifier Q>
template <typename A, typename B, typename C, qualifier P>
constexpr VectorT<4, T, Q>::VectorT(VectorT<1, A, P> const& _x, B _y, VectorT<2, C, P> const& _zw)
	: x(static_cast<T>(_x.x)), y(static_cast<T>(_y)), z(static_cast<T>(_zw.x)), w(static_cast<T>(_zw.y)) {}

template <typename T, qualifier Q>
template <typename A, typename B, typename C, qualifier P>
constexpr VectorT<4, T, Q>::VectorT(A _x, VectorT<1, B, P> const& _y, VectorT<2, C, P> const& _zw)
	: x(static_cast<T>(_x)), y(static_cast<T>(_y.x)), z(static_cast<T>(_zw.x)), w(static_cast<T>(_zw.y)) {}

template <typename T, qualifier Q>
template <typename A, typename B, typename C, qualifier P>
constexpr VectorT<4, T, Q>::VectorT(VectorT<1, A, P> const& _x, VectorT<1, B, P> const& _y, VectorT<2, C, P> const& _zw)
	: x(static_cast<T>(_x.x)), y(static_cast<T>(_y.x)), z(static_cast<T>(_zw.x)), w(static_cast<T>(_zw.y)) {}

template <typename T, qualifier Q>
template <typename A, typename B, qualifier P>
constexpr VectorT<4, T, Q>::VectorT(VectorT<3, A, P> const& _xyz, B _w)
	: x(static_cast<T>(_xyz.x)), y(static_cast<T>(_xyz.y)), z(static_cast<T>(_xyz.z)), w(static_cast<T>(_w)) {}

template <typename T, qualifier Q>
template <typename A, typename B, qualifier P>
constexpr VectorT<4, T, Q>::VectorT(VectorT<3, A, P> const& _xyz, VectorT<1, B, P> const& _w)
	: x(static_cast<T>(_xyz.x)), y(static_cast<T>(_xyz.y)), z(static_cast<T>(_xyz.z)), w(static_cast<T>(_w.x)) {}

template <typename T, qualifier Q>
template <typename A, typename B, qualifier P>
constexpr VectorT<4, T, Q>::VectorT(A _x, VectorT<3, B, P> const& _yzw)
	: x(static_cast<T>(_x)), y(static_cast<T>(_yzw.x)), z(static_cast<T>(_yzw.y)), w(static_cast<T>(_yzw.z)) {}

template <typename T, qualifier Q>
template <typename A, typename B, qualifier P>
constexpr VectorT<4, T, Q>::VectorT(VectorT<1, A, P> const& _x, VectorT<3, B, P> const& _yzw)
	: x(static_cast<T>(_x.x)), y(static_cast<T>(_yzw.x)), z(static_cast<T>(_yzw.y)), w(static_cast<T>(_yzw.z)) {}

template <typename T, qualifier Q>
template <typename A, typename B, qualifier P>
constexpr VectorT<4, T, Q>::VectorT(VectorT<2, A, P> const& _xy, VectorT<2, B, P> const& _zw)
	: x(static_cast<T>(_xy.x)), y(static_cast<T>(_xy.y)), z(static_cast<T>(_zw.x)), w(static_cast<T>(_zw.y)) {}

template <typename T, qualifier Q>
template <typename U, qualifier P>
constexpr VectorT<4, T, Q>::VectorT(VectorT<4, U, P> const& v)
	: x(static_cast<T>(v.x)), y(static_cast<T>(v.y)), z(static_cast<T>(v.z)), w(static_cast<T>(v.w)) {}


/// Assignment operators

template <typename T, qualifier Q>
constexpr VectorT<4, T, Q>& VectorT<4, T, Q>::operator=(VectorT<4, T, Q> const& v) {
	this->x = v.x;
	this->y = v.y;
	this->z = v.z;
	this->w = v.w;
	return *this;
}

template <typename T, qualifier Q>
template <typename U>
constexpr VectorT<4, T, Q>& VectorT<4, T, Q>::operator=(VectorT<4, U, Q> const& v) {
	this->x = static_cast<T>(v.x);
	this->y = static_cast<T>(v.y);
	this->z = static_cast<T>(v.z);
	this->w = static_cast<T>(v.w);
	return *this;
}

template <typename T, qualifier Q>
template <typename U>
constexpr VectorT<4, T, Q>& VectorT<4, T, Q>::operator+=(U scalar) {
	return (*this = detail::Add<T, Q, detail::IsAligned<Q>::value>::compute(*this, VectorT<4, T, Q>(scalar)));
}

/*
 * \note Vec1 is deliberately treated like a scalar to mimic shader languages.
 */
template <typename T, qualifier Q>
template <typename U>
constexpr VectorT<4, T, Q>& VectorT<4, T, Q>::operator+=(VectorT<1, U, Q> const& v) {
	return (*this = detail::Add<T, Q, detail::IsAligned<Q>::value>::compute(*this, VectorT<4, T, Q>(v.x)));
}

template <typename T, qualifier Q>
template <typename U>
constexpr VectorT<4, T, Q>& VectorT<4, T, Q>::operator+=(VectorT<4, U, Q> const& v) {
	return (*this = detail::Add<T, Q, detail::IsAligned<Q>::value>::compute(*this, VectorT<4, T, Q>(v)));
}

template <typename T, qualifier Q>
template <typename U>
constexpr VectorT<4, T, Q>& VectorT<4, T, Q>::operator-=(U scalar) {
	return (*this = detail::Sub<T, Q, detail::IsAligned<Q>::value>::compute(*this, VectorT<4, T, Q>(scalar)));
}

/*
 * \note Vec1 is deliberately treated like a scalar to mimic shader languages.
 */
template <typename T, qualifier Q>
template <typename U>
constexpr VectorT<4, T, Q>& VectorT<4, T, Q>::operator-=(VectorT<1, U, Q> const& v) {
	return (*this = detail::Sub<T, Q, detail::IsAligned<Q>::value>::compute(*this, VectorT<4, T, Q>(v.x)));
}

template <typename T, qualifier Q>
template <typename U>
constexpr VectorT<4, T, Q>& VectorT<4, T, Q>::operator-=(VectorT<4, U, Q> const& v) {
	return (*this = detail::Sub<T, Q, detail::IsAligned<Q>::value>::compute(*this, VectorT<4, T, Q>(v)));
}

template <typename T, qualifier Q>
template <typename U>
constexpr VectorT<4, T, Q>& VectorT<4, T, Q>::operator*=(U scalar) {
	return (*this = detail::Mul<T, Q, detail::IsAligned<Q>::value>::compute(*this, VectorT<4, T, Q>(scalar)));
}

/*
 * \note Vec1 is deliberately treated like a scalar to mimic shader languages.
 */
template <typename T, qualifier Q>
template <typename U>
constexpr VectorT<4, T, Q>& VectorT<4, T, Q>::operator*=(VectorT<1, U, Q> const& v) {
	return (*this = detail::Mul<T, Q, detail::IsAligned<Q>::value>::compute(*this, VectorT<4, T, Q>(v.x)));
}

template <typename T, qualifier Q>
template <typename U>
constexpr VectorT<4, T, Q>& VectorT<4, T, Q>::operator*=(VectorT<4, U, Q> const& v) {
	return (*this = detail::Mul<T, Q, detail::IsAligned<Q>::value>::compute(*this, VectorT<4, T, Q>(v)));
}

template <typename T, qualifier Q>
template <typename U>
constexpr VectorT<4, T, Q>& VectorT<4, T, Q>::operator/=(U scalar) {
	return (*this = detail::Div<T, Q, detail::IsAligned<Q>::value>::compute(*this, VectorT<4, T, Q>(scalar)));
}

/*
 * \note Vec1 is deliberately treated like a scalar to mimic shader languages.
 */
template <typename T, qualifier Q>
template <typename U>
constexpr VectorT<4, T, Q>& VectorT<4, T, Q>::operator/=(VectorT<1, U, Q> const& v) {
	return (*this = detail::Div<T, Q, detail::IsAligned<Q>::value>::compute(*this, VectorT<4, T, Q>(v.x)));
}

template <typename T, qualifier Q>
template <typename U>
constexpr VectorT<4, T, Q>& VectorT<4, T, Q>::operator/=(VectorT<4, U, Q> const& v) {
	return (*this = detail::Div<T, Q, detail::IsAligned<Q>::value>::compute(*this, VectorT<4, T, Q>(v)));
}

template <typename T, qualifier Q>
template <typename U>
constexpr VectorT<4, T, Q>& VectorT<4, T, Q>::operator%=(U scalar) {
	return (*this = detail::Mod<T, Q, detail::IsAligned<Q>::value>::compute(*this, VectorT<4, T, Q>(scalar)));
}

/*
 * \note Vec1 is deliberately treated like a scalar to mimic shader languages.
 */
template <typename T, qualifier Q>
template <typename U>
constexpr VectorT<4, T, Q>& VectorT<4, T, Q>::operator%=(VectorT<1, U, Q> const& v) {
	return (*this = detail::Mod<T, Q, detail::IsAligned<Q>::value>::compute(*this, VectorT<4, T, Q>(v)));
}

template <typename T, qualifier Q>
template <typename U>
constexpr VectorT<4, T, Q>& VectorT<4, T, Q>::operator%=(VectorT<4, U, Q> const& v) {
	return (*this = detail::Mod<T, Q, detail::IsAligned<Q>::value>::compute(*this, VectorT<4, T, Q>(v)));
}


/// Increment and Decrement Operators

template <typename T, qualifier Q>
constexpr VectorT<4, T, Q>& VectorT<4, T, Q>::operator++() {
	++this->x;
	++this->y;
	++this->z;
	++this->w;
	return *this;
}

template <typename T, qualifier Q>
constexpr VectorT<4, T, Q>& VectorT<4, T, Q>::operator--() {
	--this->x;
	--this->y;
	--this->z;
	--this->w;
	return *this;
}

template <typename T, qualifier Q>
constexpr const VectorT<4, T, Q> VectorT<4, T, Q>::operator++(int) {
	VectorT<4, T, Q> result(*this);
	++*this;
	return result;
}

template <typename T, qualifier Q>
constexpr const VectorT<4, T, Q> VectorT<4, T, Q>::operator--(int) {
	VectorT<4, T, Q> result(*this);
	--*this;
	return result;
}


/// Bitwise Assignment Operators

template <typename T, qualifier Q>
template <typename U>
constexpr VectorT<4, T, Q>& VectorT<4, T, Q>::operator&=(U scalar) {
	return (*this = detail::BitwiseAnd<T, Q, std::numeric_limits<T>::is_iec559, sizeof(T) * 8, detail::IsAligned<Q>::value>::compute(*this,
																																	 VectorT<4, T, Q>(scalar)));
}

/*
 * \note Vec1 is deliberately treated like a scalar to mimic shader languages.
 */
template <typename T, qualifier Q>
template <typename U>
constexpr VectorT<4, T, Q>& VectorT<4, T, Q>::operator&=(VectorT<1, U, Q> const& v) {
	return (*this =
				detail::BitwiseAnd<T, Q, std::numeric_limits<T>::is_iec559, sizeof(T) * 8, detail::IsAligned<Q>::value>::compute(*this, VectorT<4, T, Q>(v)));
}

template <typename T, qualifier Q>
template <typename U>
constexpr VectorT<4, T, Q>& VectorT<4, T, Q>::operator&=(VectorT<4, U, Q> const& v) {
	return (*this =
				detail::BitwiseAnd<T, Q, std::numeric_limits<T>::is_iec559, sizeof(T) * 8, detail::IsAligned<Q>::value>::compute(*this, VectorT<4, T, Q>(v)));
}

template <typename T, qualifier Q>
template <typename U>
constexpr VectorT<4, T, Q>& VectorT<4, T, Q>::operator|=(U scalar) {
	return (*this = detail::BitwiseOr<T, Q, std::numeric_limits<T>::is_iec559, sizeof(T) * 8, detail::IsAligned<Q>::value>::compute(*this,
																																	VectorT<4, T, Q>(scalar)));
}

/*
 * \note Vec1 is deliberately treated like a scalar to mimic shader languages.
 */
template <typename T, qualifier Q>
template <typename U>
constexpr VectorT<4, T, Q>& VectorT<4, T, Q>::operator|=(VectorT<1, U, Q> const& v) {
	return (*this =
				detail::BitwiseOr<T, Q, std::numeric_limits<T>::is_iec559, sizeof(T) * 8, detail::IsAligned<Q>::value>::compute(*this, VectorT<4, T, Q>(v)));
}

template <typename T, qualifier Q>
template <typename U>
constexpr VectorT<4, T, Q>& VectorT<4, T, Q>::operator|=(VectorT<4, U, Q> const& v) {
	return (*this =
				detail::BitwiseOr<T, Q, std::numeric_limits<T>::is_iec559, sizeof(T) * 8, detail::IsAligned<Q>::value>::compute(*this, VectorT<4, T, Q>(v)));
}

template <typename T, qualifier Q>
template <typename U>
constexpr VectorT<4, T, Q>& VectorT<4, T, Q>::operator^=(U scalar) {
	return (*this = detail::Xor<T, Q, std::numeric_limits<T>::is_iec559, sizeof(T) * 8, detail::IsAligned<Q>::value>::compute(*this, VectorT<4, T, Q>(scalar)));
}

/*
 * \note Vec1 is deliberately treated like a scalar to mimic shader languages.
 */
template <typename T, qualifier Q>
template <typename U>
constexpr VectorT<4, T, Q>& VectorT<4, T, Q>::operator^=(VectorT<1, U, Q> const& v) {
	return (*this = detail::Xor<T, Q, std::numeric_limits<T>::is_iec559, sizeof(T) * 8, detail::IsAligned<Q>::value>::compute(*this, VectorT<4, T, Q>(v)));
}

template <typename T, qualifier Q>
template <typename U>
constexpr VectorT<4, T, Q>& VectorT<4, T, Q>::operator^=(VectorT<4, U, Q> const& v) {
	return (*this = detail::Xor<T, Q, std::numeric_limits<T>::is_iec559, sizeof(T) * 8, detail::IsAligned<Q>::value>::compute(*this, VectorT<4, T, Q>(v)));
}

template <typename T, qualifier Q>
template <typename U>
constexpr VectorT<4, T, Q>& VectorT<4, T, Q>::operator<<=(U scalar) {
	return (*this = detail::ShiftLeft<T, Q, std::numeric_limits<T>::is_iec559, sizeof(T) * 8, detail::IsAligned<Q>::value>::compute(*this,
																																	VectorT<4, T, Q>(scalar)));
}

/*
 * \note Vec1 is deliberately treated like a scalar to mimic shader languages.
 */
template <typename T, qualifier Q>
template <typename U>
constexpr VectorT<4, T, Q>& VectorT<4, T, Q>::operator<<=(VectorT<1, U, Q> const& v) {
	return (*this =
				detail::ShiftLeft<T, Q, std::numeric_limits<T>::is_iec559, sizeof(T) * 8, detail::IsAligned<Q>::value>::compute(*this, VectorT<4, T, Q>(v)));
}

template <typename T, qualifier Q>
template <typename U>
constexpr VectorT<4, T, Q>& VectorT<4, T, Q>::operator<<=(VectorT<4, U, Q> const& v) {
	return (*this =
				detail::ShiftLeft<T, Q, std::numeric_limits<T>::is_iec559, sizeof(T) * 8, detail::IsAligned<Q>::value>::compute(*this, VectorT<4, T, Q>(v)));
}

template <typename T, qualifier Q>
template <typename U>
constexpr VectorT<4, T, Q>& VectorT<4, T, Q>::operator>>=(U scalar) {
	return (*this = detail::ShiftRight<T, Q, std::numeric_limits<T>::is_iec559, sizeof(T) * 8, detail::IsAligned<Q>::value>::compute(*this,
																																	 VectorT<4, T, Q>(scalar)));
}

/*
 * \note Vec1 is deliberately treated like a scalar to mimic shader languages.
 */
template <typename T, qualifier Q>
template <typename U>
constexpr VectorT<4, T, Q>& VectorT<4, T, Q>::operator>>=(VectorT<1, U, Q> const& v) {
	return (*this =
				detail::ShiftRight<T, Q, std::numeric_limits<T>::is_iec559, sizeof(T) * 8, detail::IsAligned<Q>::value>::compute(*this, VectorT<4, T, Q>(v)));
}

template <typename T, qualifier Q>
template <typename U>
constexpr VectorT<4, T, Q>& VectorT<4, T, Q>::operator>>=(VectorT<4, U, Q> const& v) {
	return (*this =
				detail::ShiftRight<T, Q, std::numeric_limits<T>::is_iec559, sizeof(T) * 8, detail::IsAligned<Q>::value>::compute(*this, VectorT<4, T, Q>(v)));
}


/// Unary Operators

template <typename T, qualifier Q>
constexpr VectorT<4, T, Q> operator+(VectorT<4, T, Q> const& v) {
	return v;
}

template <typename T, qualifier Q>
constexpr VectorT<4, T, Q> operator-(VectorT<4, T, Q> const& v) {
	return VectorT<4, T, Q>(0) -= v;
}


/// Binary Operators

template <typename T, qualifier Q>
constexpr VectorT<4, T, Q> operator+(VectorT<4, T, Q> const& v, T const& scalar) {
	return VectorT<4, T, Q>(v) += scalar;
}

template <typename T, qualifier Q>
constexpr VectorT<4, T, Q> operator+(T scalar, VectorT<4, T, Q> const& v) {
	return VectorT<4, T, Q>(v) += scalar;
}

/*
 * \note Vec1 is deliberately treated like a scalar to mimic shader languages.
 */
template <typename T, qualifier Q>
constexpr VectorT<4, T, Q> operator+(VectorT<4, T, Q> const& v1, VectorT<1, T, Q> const& v2) {
	return VectorT<4, T, Q>(v1) += v2;
}

/*
 * \note Vec1 is deliberately treated like a scalar to mimic shader languages.
 */
template <typename T, qualifier Q>
constexpr VectorT<4, T, Q> operator+(VectorT<1, T, Q> const& v1, VectorT<4, T, Q> const& v2) {
	return VectorT<4, T, Q>(v2) += v1;
}

template <typename T, qualifier Q>
constexpr VectorT<4, T, Q> operator+(VectorT<4, T, Q> const& v1, VectorT<4, T, Q> const& v2) {
	return VectorT<4, T, Q>(v1) += v2;
}

template <typename T, qualifier Q>
constexpr VectorT<4, T, Q> operator-(VectorT<4, T, Q> const& v, T const& scalar) {
	return VectorT<4, T, Q>(v) -= scalar;
}

template <typename T, qualifier Q>
constexpr VectorT<4, T, Q> operator-(T scalar, VectorT<4, T, Q> const& v) {
	return VectorT<4, T, Q>(scalar) -= v;
}

/*
 * \note Vec1 is deliberately treated like a scalar to mimic shader languages.
 */
template <typename T, qualifier Q>
constexpr VectorT<4, T, Q> operator-(VectorT<4, T, Q> const& v1, VectorT<1, T, Q> const& v2) {
	return VectorT<4, T, Q>(v1) -= v2;
}

/*
 * \note Vec1 is deliberately treated like a scalar to mimic shader languages.
 */
template <typename T, qualifier Q>
constexpr VectorT<4, T, Q> operator-(VectorT<1, T, Q> const& v1, VectorT<4, T, Q> const& v2) {
	return VectorT<4, T, Q>(v1.x) -= v2;
}

template <typename T, qualifier Q>
constexpr VectorT<4, T, Q> operator-(VectorT<4, T, Q> const& v1, VectorT<4, T, Q> const& v2) {
	return VectorT<4, T, Q>(v1) -= v2;
}

template <typename T, qualifier Q>
constexpr VectorT<4, T, Q> operator*(VectorT<4, T, Q> const& v, T const& scalar) {
	return VectorT<4, T, Q>(v) *= scalar;
}

template <typename T, qualifier Q>
constexpr VectorT<4, T, Q> operator*(T scalar, VectorT<4, T, Q> const& v) {
	return VectorT<4, T, Q>(v) *= scalar;
}

/*
 * \note Vec1 is deliberately treated like a scalar to mimic shader languages.
 */
template <typename T, qualifier Q>
constexpr VectorT<4, T, Q> operator*(VectorT<4, T, Q> const& v1, VectorT<1, T, Q> const& v2) {
	return VectorT<4, T, Q>(v1) *= v2;
}

/*
 * \note Vec1 is deliberately treated like a scalar to mimic shader languages.
 */
template <typename T, qualifier Q>
constexpr VectorT<4, T, Q> operator*(VectorT<1, T, Q> const& v1, VectorT<4, T, Q> const& v2) {
	return VectorT<4, T, Q>(v2) *= v1;
}

template <typename T, qualifier Q>
constexpr VectorT<4, T, Q> operator*(VectorT<4, T, Q> const& v1, VectorT<4, T, Q> const& v2) {
	return VectorT<4, T, Q>(v1) *= v2;
}

template <typename T, qualifier Q>
constexpr VectorT<4, T, Q> operator/(VectorT<4, T, Q> const& v, T const& scalar) {
	return VectorT<4, T, Q>(v) /= scalar;
}

template <typename T, qualifier Q>
constexpr VectorT<4, T, Q> operator/(T scalar, VectorT<4, T, Q> const& v) {
	return VectorT<4, T, Q>(scalar) /= v;
}

/*
 * \note Vec1 is deliberately treated like a scalar to mimic shader languages.
 */
template <typename T, qualifier Q>
constexpr VectorT<4, T, Q> operator/(VectorT<4, T, Q> const& v1, VectorT<1, T, Q> const& v2) {
	return VectorT<4, T, Q>(v1) /= v2;
}

/*
 * \note Vec1 is deliberately treated like a scalar to mimic shader languages.
 */
template <typename T, qualifier Q>
constexpr VectorT<4, T, Q> operator/(VectorT<1, T, Q> const& v1, VectorT<4, T, Q> const& v2) {
	return VectorT<4, T, Q>(v1.x) /= v2;
}

template <typename T, qualifier Q>
constexpr VectorT<4, T, Q> operator/(VectorT<4, T, Q> const& v1, VectorT<4, T, Q> const& v2) {
	return VectorT<4, T, Q>(v1) /= v2;
}

template <typename T, qualifier Q>
constexpr VectorT<4, T, Q> operator%(VectorT<4, T, Q> const& v, T scalar) {
	return VectorT<4, T, Q>(v) %= scalar;
}

template <typename T, qualifier Q>
constexpr VectorT<4, T, Q> operator%(T scalar, VectorT<4, T, Q> const& v) {
	return VectorT<4, T, Q>(scalar) %= v;
}

/*
 * \note Vec1 is deliberately treated like a scalar to mimic shader languages.
 */
template <typename T, qualifier Q>
constexpr VectorT<4, T, Q> operator%(VectorT<4, T, Q> const& v1, VectorT<1, T, Q> const& v2) {
	return VectorT<4, T, Q>(v1) %= v2.x;
}

/*
 * \note Vec1 is deliberately treated like a scalar to mimic shader languages.
 */
template <typename T, qualifier Q>
constexpr VectorT<4, T, Q> operator%(VectorT<1, T, Q> const& scalar, VectorT<4, T, Q> const& v) {
	return VectorT<4, T, Q>(scalar.x) %= v;
}

template <typename T, qualifier Q>
constexpr VectorT<4, T, Q> operator%(VectorT<4, T, Q> const& v1, VectorT<4, T, Q> const& v2) {
	return VectorT<4, T, Q>(v1) %= v2;
}


/// Bitwise Binary Operators

template <typename T, qualifier Q>
constexpr VectorT<4, T, Q> operator&(VectorT<4, T, Q> const& v, T scalar) {
	return VectorT<4, T, Q>(v) &= scalar;
}

template <typename T, qualifier Q>
constexpr VectorT<4, T, Q> operator&(T scalar, VectorT<4, T, Q> const& v) {
	return VectorT<4, T, Q>(scalar) &= v;
}

/*
 * \note Vec1 is deliberately treated like a scalar to mimic shader languages.
 */
template <typename T, qualifier Q>
constexpr VectorT<4, T, Q> operator&(VectorT<4, T, Q> const& v, VectorT<1, T, Q> const& scalar) {
	return VectorT<4, T, Q>(v) &= scalar;
}

/*
 * \note Vec1 is deliberately treated like a scalar to mimic shader languages.
 */
template <typename T, qualifier Q>
constexpr VectorT<4, T, Q> operator&(VectorT<1, T, Q> const& v1, VectorT<4, T, Q> const& v2) {
	return VectorT<4, T, Q>(v1.x) &= v2;
}

template <typename T, qualifier Q>
constexpr VectorT<4, T, Q> operator&(VectorT<4, T, Q> const& v1, VectorT<4, T, Q> const& v2) {
	return VectorT<4, T, Q>(v1) &= v2;
}

template <typename T, qualifier Q>
constexpr VectorT<4, T, Q> operator|(VectorT<4, T, Q> const& v, T scalar) {
	return VectorT<4, T, Q>(v) |= scalar;
}

template <typename T, qualifier Q>
constexpr VectorT<4, T, Q> operator|(T scalar, VectorT<4, T, Q> const& v) {
	return VectorT<4, T, Q>(scalar) |= v;
}

/*
 * \note Vec1 is deliberately treated like a scalar to mimic shader languages.
 */
template <typename T, qualifier Q>
constexpr VectorT<4, T, Q> operator|(VectorT<4, T, Q> const& v1, VectorT<1, T, Q> const& v2) {
	return VectorT<4, T, Q>(v1) |= v2.x;
}

/*
 * \note Vec1 is deliberately treated like a scalar to mimic shader languages.
 */
template <typename T, qualifier Q>
constexpr VectorT<4, T, Q> operator|(VectorT<1, T, Q> const& v1, VectorT<4, T, Q> const& v2) {
	return VectorT<4, T, Q>(v1.x) |= v2;
}

template <typename T, qualifier Q>
constexpr VectorT<4, T, Q> operator|(VectorT<4, T, Q> const& v1, VectorT<4, T, Q> const& v2) {
	return VectorT<4, T, Q>(v1) |= v2;
}

template <typename T, qualifier Q>
constexpr VectorT<4, T, Q> operator^(VectorT<4, T, Q> const& v, T scalar) {
	return VectorT<4, T, Q>(v) ^= scalar;
}

template <typename T, qualifier Q>
constexpr VectorT<4, T, Q> operator^(T scalar, VectorT<4, T, Q> const& v) {
	return VectorT<4, T, Q>(scalar) ^= v;
}

/*
 * \note Vec1 is deliberately treated like a scalar to mimic shader languages.
 */
template <typename T, qualifier Q>
constexpr VectorT<4, T, Q> operator^(VectorT<4, T, Q> const& v1, VectorT<1, T, Q> const& v2) {
	return VectorT<4, T, Q>(v1) ^= v2.x;
}

/*
 * \note Vec1 is deliberately treated like a scalar to mimic shader languages.
 */
template <typename T, qualifier Q>
constexpr VectorT<4, T, Q> operator^(VectorT<1, T, Q> const& v1, VectorT<4, T, Q> const& v2) {
	return VectorT<4, T, Q>(v1.x) ^= v2;
}

template <typename T, qualifier Q>
constexpr VectorT<4, T, Q> operator^(VectorT<4, T, Q> const& v1, VectorT<4, T, Q> const& v2) {
	return VectorT<4, T, Q>(v1) ^= v2;
}

template <typename T, qualifier Q>
constexpr VectorT<4, T, Q> operator<<(VectorT<4, T, Q> const& v, T scalar) {
	return VectorT<4, T, Q>(v) <<= scalar;
}

template <typename T, qualifier Q>
constexpr VectorT<4, T, Q> operator<<(T scalar, VectorT<4, T, Q> const& v) {
	return VectorT<4, T, Q>(scalar) <<= v;
}

/*
 * \note Vec1 is deliberately treated like a scalar to mimic shader languages.
 */
template <typename T, qualifier Q>
constexpr VectorT<4, T, Q> operator<<(VectorT<4, T, Q> const& v1, VectorT<1, T, Q> const& v2) {
	return VectorT<4, T, Q>(v1) <<= v2.x;
}

/*
 * \note Vec1 is deliberately treated like a scalar to mimic shader languages.
 */
template <typename T, qualifier Q>
constexpr VectorT<4, T, Q> operator<<(VectorT<1, T, Q> const& v1, VectorT<4, T, Q> const& v2) {
	return VectorT<4, T, Q>(v1.x) <<= v2;
}

template <typename T, qualifier Q>
constexpr VectorT<4, T, Q> operator<<(VectorT<4, T, Q> const& v1, VectorT<4, T, Q> const& v2) {
	return VectorT<4, T, Q>(v1) <<= v2;
}

template <typename T, qualifier Q>
constexpr VectorT<4, T, Q> operator>>(VectorT<4, T, Q> const& v, T scalar) {
	return VectorT<4, T, Q>(v) >>= scalar;
}

template <typename T, qualifier Q>
constexpr VectorT<4, T, Q> operator>>(T scalar, VectorT<4, T, Q> const& v) {
	return VectorT<4, T, Q>(scalar) >>= v;
}

/*
 * \note Vec1 is deliberately treated like a scalar to mimic shader languages.
 */
template <typename T, qualifier Q>
constexpr VectorT<4, T, Q> operator>>(VectorT<4, T, Q> const& v1, VectorT<1, T, Q> const& v2) {
	return VectorT<4, T, Q>(v1) >>= v2.x;
}

/*
 * \note Vec1 is deliberately treated like a scalar to mimic shader languages.
 */
template <typename T, qualifier Q>
constexpr VectorT<4, T, Q> operator>>(VectorT<1, T, Q> const& v1, VectorT<4, T, Q> const& v2) {
	return VectorT<4, T, Q>(v1.x) >>= v2;
}

template <typename T, qualifier Q>
constexpr VectorT<4, T, Q> operator>>(VectorT<4, T, Q> const& v1, VectorT<4, T, Q> const& v2) {
	return VectorT<4, T, Q>(v1) >>= v2;
}

template <typename T, qualifier Q>
constexpr VectorT<4, T, Q> operator~(VectorT<4, T, Q> const& v) {
	return detail::BitwiseNot<T, Q, std::numeric_limits<T>::is_iec559, sizeof(T) * 8, detail::IsAligned<Q>::value>::compute(v);
}


/// Conditional Operators

template <typename T, qualifier Q>
constexpr bool operator==(VectorT<4, T, Q> const& v1, VectorT<4, T, Q> const& v2) {
	return detail::Equal<T, Q, std::numeric_limits<T>::is_iec559, sizeof(T) * 8, detail::IsAligned<Q>::value>::compute(v1, v2);
}

template <typename T, qualifier Q>
constexpr bool operator!=(VectorT<4, T, Q> const& v1, VectorT<4, T, Q> const& v2) {
	return detail::NotEqual<T, Q, std::numeric_limits<T>::is_iec559, sizeof(T) * 8, detail::IsAligned<Q>::value>::compute(v1, v2);
}

template <qualifier Q>
constexpr bool operator&&(VectorT<4, bool, Q> const& v1, VectorT<4, bool, Q> const& v2) {
	return (v1.x && v2.x, v1.y && v2.y, v1.z && v2.z, v1.w && v2.w);
}

template <qualifier Q>
constexpr bool operator||(VectorT<4, bool, Q> const& v1, VectorT<4, bool, Q> const& v2) {
	return (v1.x || v2.x, v1.y || v2.y, v1.z || v2.z, v1.w || v2.w);
}

} // namespace mim

#include "mim/detail/func/func_vector4.inl"
