/** test.cpp
 * Copyright © 2022 Gene Harvey
 *
 * This software may be modified and distributed under the terms
 * of the MIT license. See the LICENSE file for details.
 * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */

#include "unit_test_common.hpp"

template <typename T>
struct test_diff_type_allocator
  : std::allocator<T>
{
  using difference_type = std::int8_t;
  using std::allocator<T>::allocator;
};

GCH_SMALL_VECTOR_TEST_CONSTEXPR
int
test (void)
{
  gch::small_vector_with_allocator<int, gch::test_types::sized_allocator<int, std::uint8_t>> v;
  CHECK ((std::numeric_limits<std::uint8_t>::max) () / sizeof (int) == v.max_size ());

  gch::small_vector_with_allocator<int, test_diff_type_allocator<int>> w;
  CHECK ((std::numeric_limits<std::int8_t>::max) () == w.max_size ());

  return 0;
}
