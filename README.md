# Grisu-Exact11
This is a C++11-compatible implementation of Grisu-Exact (https://github.com/jk-jeon/Grisu-Exact).

To avoid possible name clash, I renamed namespaces and header files by adding `11` at the end. Also, various tests are removed.

The usage of this library is same as that of the original one, except for the above mentioned renamings.

# License
This library is licensed under the same terms as the original one (https://github.com/jk-jeon/Grisu-Exact).

More specifically, all code, except for those belong to third-party libraries (code in [`benchmark/ryu`](benchmark/ryu) and [`benchmark_results/shaded_plots`](benchmark_results/shaded_plots)), is licensed under either of

 * Apache License Version 2.0 with LLVM Exceptions ([LICENSE-Apache2-LLVM](LICENSE-Apache2-LLVM) or https://llvm.org/foundation/relicensing/LICENSE.txt) or
 * Boost Software License Version 1.0 ([LICENSE-Boost](LICENSE-Boost) or https://www.boost.org/LICENSE_1_0.txt).

except for the file [`fp_to_chars11.cpp`](fp_to_chars/fp_to_chars.cpp), which is licensed under either of

 * Apache License Version 2.0 ([LICENSE-Apache2](fp_to_chars/LICENSE-Apache2) or http://www.apache.org/licenses/LICENSE-2.0) or
 * Boost Software License Version 1.0 ([LICENSE-Boost](fp_to_chars/LICENSE-Boost) or https://www.boost.org/LICENSE_1_0.txt).
 
