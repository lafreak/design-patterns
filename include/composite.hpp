#pragma once

#include <iterator.hpp>

struct component
{
  virtual void evaluate(unsigned int depth=0) = 0;
};

struct composite : public component
{
  struct container : iterable<component> {} m_components;

  void push(component* comp) { m_components.push(comp); }

  void evaluate(unsigned int depth=0) override
  {
    for (auto it = m_components.begin(); it != m_components.end(); ++it)
      it->evaluate(depth+1);
  }

};