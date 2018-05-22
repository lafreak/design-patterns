#include <iostream>

#include <object_pool.hpp>

struct User
{
  int* m_values;

  User() {
    m_values = new int[30000];
  }

  ~User() {
    delete[] m_values;
  }
};

typedef object_pool<User, 3> UserPool;

int main()
{
  {
    auto a1 = UserPool::instance().acquire();
    auto a2 = UserPool::instance().acquire();
    auto a3 = UserPool::instance().acquire();
    auto a4 = UserPool::instance().acquire();
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