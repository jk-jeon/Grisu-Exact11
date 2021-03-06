// Copyright 2020 Junekey Jeon
//
// The contents of this file may be used under the terms of
// the Apache License v2.0 with LLVM Exceptions.
//
//    (See accompanying file LICENSE-Apache or copy at
//     https://llvm.org/foundation/relicensing/LICENSE.txt)
//
// Alternatively, the contents of this file may be used under the terms of
// the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE-Boost or copy at
//     https://www.boost.org/LICENSE_1_0.txt)
//
// Unless required by applicable law or agreed to in writing, this software
// is distributed on an "AS IS" BASIS, WITHOUT WARRANTIES OR CONDITIONS OF ANY
// KIND, either express or implied.

#ifndef JKJ_FP_TO_CHARS11
#define JKJ_FP_TO_CHARS11

#include "grisu_exact11.h"

namespace jkj {
	namespace fp_to_chars11_detail {
		char* float_to_chars(unsigned_fp_t<float> v, char* buffer);
		char* double_to_chars(unsigned_fp_t<double> v, char* buffer);
	}

	// Returns the next-to-end position
	template <class Float,
		class RoundingMode = grisu_exact11_rounding_modes::nearest_to_even,
		class CorrectRoundingSearch = grisu_exact11_correct_rounding::tie_to_even
	>
	char* fp_to_chars11_n(Float x, char* buffer,
		RoundingMode&& rounding_mode = {},
		CorrectRoundingSearch&& crs = {})
	{
		auto br = get_bit_representation(x);
		if (br.is_finite()) {
			if (br.is_negative()) {
				*buffer = '-';
				++buffer;
			}
			if (br.is_nonzero()) {
				if (sizeof(Float) == 4) {
					return fp_to_chars11_detail::float_to_chars(grisu_exact11<false>(float(x),
						std::forward<RoundingMode>(rounding_mode),
						std::forward<CorrectRoundingSearch>(crs)), buffer);
				}
				else {
					return fp_to_chars11_detail::double_to_chars(grisu_exact11<false>(double(x),
						std::forward<RoundingMode>(rounding_mode),
						std::forward<CorrectRoundingSearch>(crs)), buffer);
				}
			}
			else {
				std::memcpy(buffer, "0E0", 3);
				return buffer + 3;
			}
		}
		else {
			if ((br.f << (grisu_exact11_detail::common_info<Float>::exponent_bits + 1)) != 0)
			{
				std::memcpy(buffer, "NaN", 3);
				return buffer + 3;
			}
			else {
				if (br.is_negative()) {
					*buffer = '-';
					++buffer;
				}
				std::memcpy(buffer, "Infinity", 8);
				return buffer + 8;
			}
		}
	}

	// Null-terminate and bypass the return value of fp_to_chars_n
	template <class Float,
		class RoundingMode = grisu_exact11_rounding_modes::nearest_to_even,
		class CorrectRoundingSearch = grisu_exact11_correct_rounding::tie_to_even
	>
	char* fp_to_chars11(Float x, char* buffer,
		RoundingMode&& rounding_mode = {},
		CorrectRoundingSearch&& crs = {})
	{
		auto ptr = fp_to_chars11_n(x, buffer,
			std::forward<RoundingMode>(rounding_mode),
			std::forward<CorrectRoundingSearch>(crs));
		*ptr = '\0';
		return ptr;
	}
}

#endif