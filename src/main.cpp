#include <iostream>
#include <string>

#include <object_pool.hpp>  // singleton+object_pool
#include <observer.hpp>     // observer
#include <iterator.hpp>     // iterator
#include <composite.hpp>    // iterator+composite

struct folder : public composite
{
  std::string m_name;

  folder (const std::string& name) 
    : m_name(name) {}

  void evaluate(unsigned int depth=0) override {
    for (unsigned int i = 0; i < depth; i++)
      std::cout << "-";
    std::cout << m_name << std::endl;
    composite::evaluate(depth);
  }
};

struct file : public component
{
  std::string m_name;
  std::string m_content;

  file (const std::string& name, const std::string& content) 
    : m_name(name), m_content(content) {}

  void evaluate(unsigned int depth=0) override {
    for (unsigned int i = 0; i < depth; i++)
      std::cout << "-";
    std::cout << m_name << std::endl;
  }
};

int main()
{
  // Folders
  folder my_computer{"My Computer"};
  folder c_drive{"C:"};
  folder d_drive{"D:"};
  folder program_files{"Program Files"};

  my_computer.push(&c_drive);
  my_computer.push(&d_drive);
  
  c_drive.push(&program_files);

  // Files
  file my_settings  {"my_settings.ini", ""};
  file my_keybinds  {"my_keybinds.ini", ""};
  file engine       {"engine.exe", ""};
  file pdb          {"engine.pdb", ""};

  program_files.push(&my_settings);
  program_files.push(&my_keybinds);
  program_files.push(&engine);
  program_files.push(&pdb);

  my_computer.evaluate();

  return 0;
}