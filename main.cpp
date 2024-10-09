#include <matrix_test.hpp>
#include <rational_number.hpp>

int main() {
	water::rational_number::rational_number<int32_t, uint32_t>{0} == int32_t(0);
	linear_algebra_test::set_number<water::rational_number::rational_number<int64_t, uint64_t>>::set_index<uint8_t>::run();
	return 0;
}
