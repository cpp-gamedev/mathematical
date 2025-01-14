// Copyright (c) 2023-Present Mim contributors (see LICENSE)

#pragma once

#include <array>
#include "mim/detail/qualifier.hpp"

namespace mim {
template <typename T, qualifier Q>
struct MatrixT<4, 3, T, Q> {
	using type = MatrixT<4, 3, T, Q>;
	using row_type = VectorT<4, T, Q>;
	using column_type = VectorT<3, T, Q>;
	using transpose_type = MatrixT<4, 3, T, Q>;
	using value_type = T;
	using size_type = std::size_t;
	static constexpr std::size_t column_size_v = 4;
	static constexpr std::size_t row_size_v = 3;
	static constexpr T size_v = VectorT<2, std::size_t, Q>(column_size_v, row_size_v);

  private:
	using data = std::array<column_type, column_size_v>;

  public:
	static constexpr size_type size() { return size_v; }
	static constexpr size_type row_size() { return row_size_v; }
	static constexpr size_type column_size() { return column_size_v; }

	constexpr column_type & operator [] (size_type i) noexcept;
	constexpr column_type const & operator [] (size_type i) const noexcept;

	constexpr row_type row(size_type i) const noexcept;
	constexpr column_type column(size_type i) const noexcept;
	//constexpr column_type at(size_type i, size_type j) const noexcept;
};
} // namespace mim
