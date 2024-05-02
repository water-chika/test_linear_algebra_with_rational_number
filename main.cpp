#include <matrix.hpp>
#include <iostream>
#include <concepts>
#include <iomanip>
#include <rational_number.hpp>





namespace water {
	namespace concept_helper {
		template<class T>
		concept number = std::integral<T> || std::floating_point<T> || water::rational_number::concept_helper::rational_number<T>;
	}
}

class linear_algebra_test {
public:
	template<water::concept_helper::number Number>
	class set_number {
	public:
		template<std::integral Integral>
		class set_index {
		public:
			static void run() {
				try {
					using namespace linear_algebra;
					std::cout << "This is chapter 2, exercise 31." << std::endl;
					auto A = matrix<Number, 3, 3>{
						{2, 1, 1},
						{1, 2, 1},
						{1, 1, 2}
					};
					std::cout << "A = " << A << std::endl;
					auto A_I = concatenate_columns(A, identity_matrix<Number, 3>());
					std::cout << "A inverse = " << select_columns<3, 4, 5>(back_substitution(eliminate(A_I))) << std::endl;
					auto B = matrix<Number, 3, 3>{
						{2, -1, -1},
						{-1, 2, -1},
						{-1, -1, 2}
					};
					std::cout << "B = " << B << std::endl;
					auto B_I = concatenate_columns(B, identity_matrix<Number, 3>());
					std::cout << "B inverse = " <<
						select_columns<3, 4, 5>(back_substitution(eliminate(B_I))) << std::endl;
				}
				catch (std::exception& e) {
					std::cout << e.what() << std::endl;
				}
			}
		};
	};
};

int main() {
	water::rational_number::rational_number<int32_t, uint32_t>{0} == int32_t(0);
	linear_algebra_test::set_number<water::rational_number::rational_number<int64_t, uint64_t>>::set_index<uint8_t>::run();
	return 0;
}