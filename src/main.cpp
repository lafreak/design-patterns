#include <iostream>

#include <object_pool.hpp>

struct User
{
};

typedef object_pool<User, 3> UserPool;

int main()
{
  {
    auto a1 = UserPool::acquire_ex();
    auto a2 = UserPool::acquire_ex();
    auto a3 = UserPool::acquire_ex();
    auto a4 = UserPool::acquire_ex();
    printf("%ld\n%ld\n%ld\n%ld\n", a1.hash(), a2.hash(), a3.hash(), a4.hash());
  }

  {
    auto a1 = UserPool::instance().acquire();
    auto a2 = UserPool::instance().acquire();
    auto a3 = UserPool::instance().acquire();
    auto a4 = UserPool::instance().acquire();
    printf("%ld\n%ld\n%ld\n%ld\n", a1.hash(), a2.hash(), a3.hash(), a4.hash());
  }

  return 0;
}