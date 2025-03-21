template <int... P>
constexpr int left()
{
  return (... - P);
}

template <int... P>
constexpr int right()
{
  return (P - ...);
}

int main()
{
  // (3 - 2) - 1 = 0
  static_assert(left<3, 2, 1>() == 0);
  // 3 - (2 - 1) = 2
  static_assert(right<3, 2, 1>() == 2);
}
