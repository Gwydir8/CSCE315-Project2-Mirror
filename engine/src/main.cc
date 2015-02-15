// Rabia Gunonu, Sam Gwydir, Nicolas Juarez, Daniel Koon
// CSCE 315-503
// main.cc

#include <iostream>
#include "engine.h"
#include "column.h"

void draw_line() {
  // Draw 80 line characters
  for(int i = 0; i < 80; ++i) {
    std::cout << "─";
  }
  std::cout << std::endl;
}

int main(int argc, char *argv[]) {
  draw_line();
  std::cout << "Database Engine" << std::endl;
  draw_line();
  Engine db;
  // Column<std::string> column("ID");
  std::vector<Column<std::string> > columns;
  columns.push_back(Column<std::string>("ID"));
  db.createNewTable("Test", columns);
  std::cout << "Number of Open Tables: " << db.num_open_tables() << std::endl;
  std::cout << "Test Table Index: " << db.find_table_index("Test") << std::endl;
  draw_line();
  std::cout << "Unknown Table Index(Should be -1): "
            << db.find_table_index("Unknown") << std::endl;
  std::cout << "Show Table Test: " << std::endl << db.showTable("Test");
  draw_line();
  draw_line();

  return 0;
}
