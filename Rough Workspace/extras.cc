
/*class HasherFunctor {*/
/*private:*/
/*  static uint64_t random_address() {*/
/*    char *p = new char;*/
/*    delete p;*/
/*    return uint64_t(p);*/
/*  }*/
/**/
/*  static uint32_t hash_32(uint32_t x) {*/
/*    x += 0x9e3779b9;*/
/*    x = (x ^ (x >> 16)) * 0x85ebca6b;*/
/*    x = (x ^ (x >> 13)) * 0xc2b2ae35;*/
/*    return x ^ (x >> 16);*/
/*  }*/
/**/
/*  static uint64_t splitmix_64(uint64_t x) {*/
/*    x += 0x9e3779b97f4a7c15;*/
/*    x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;*/
/*    x = (x ^ (x >> 27)) * 0x94d049bb133111eb;*/
/*    return x ^ (x >> 31);*/
/*  }*/
/**/
/*public:*/
/*  template <typename T> uint64_t operator()(T x) const {*/
/*    static const uint64_t FIXED_RANDOM = splitmix_64(*/
/*        std::chrono::steady_clock::now().time_since_epoch().count() **/
/*        (random_address() | 1));*/
/*    return sizeof(x) <= 4 ? hash_32(unsigned(x ^ FIXED_RANDOM))*/
/*                          : splitmix_64(x ^ FIXED_RANDOM);*/
/*  }*/
/*};*/

/*namespace cross {*/
/**/
/*template <class Fun> class y_combinator_result {*/
/*  Fun fun_;*/
/**/
/*public:*/
/*  template <class T>*/
/*  explicit y_combinator_result(T &&fun) : fun_(std::forward<T>(fun)) {}*/
/**/
/*  template <class... Args> decltype(auto) operator()(Args &&...args) {*/
/*    return fun_(std::ref(*this), std::forward<Args>(args)...);*/
/*  }*/
/*};*/
/**/
/*template <class Fun> decltype(auto) YC(Fun &&fun) {*/
/*  return y_combinator_result<std::decay_t<Fun>>(std::forward<Fun>(fun));*/
/*}*/
/**/
/*template <typename T, typename U>*/
/*constexpr auto setmin(T &a, const U &b) -> T & {*/
/*  return a = std::min(a, T{b});*/
/*}*/
/**/
/*template <typename T, typename U>*/
/*constexpr auto setmax(T &a, const U &b) -> T & {*/
/*  return a = std::max(a, T{b});*/
/*}*/
/**/
/*template <typename T> constexpr auto nextPow2(T x) -> T {*/
/*  if (x == 0) {*/
/*    return 1;*/
/*  } else if (x & (x - 1)) {*/
/*    return T{1} << (T{std::numeric_limits<T>::digits} -
 * std::countl_zero(x));*/
/*  } else {*/
/*    return x;*/
/*  }*/
/*}*/
/**/
/*} // namespace cross*/
