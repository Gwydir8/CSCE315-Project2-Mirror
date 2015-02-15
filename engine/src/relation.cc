#include "relation.h"

std::vector<std::string> Relation::get_row(int i) {
  std::vector<std::string> row;

  // Create row from each column
  for (const Column<std::string>& column : columns_) {
    row.push_back(column[i]);
  }
  return row;
}

void Relation::print_row(int i) { print_row(i, '\t'); }

void Relation::print_row(int i, char delimiter) {
  for (const std::string& entry : get_row(i)) {
    std::cout << entry << delimiter;
  }
}

std::vector<Column<std::string> >::iterator Relation::find_column(
    std::string column_name) {
  return std::find_if(std::begin(columns_), std::end(columns_),
                      [&column_name](Column<std::string> column)
                          -> bool { return column.title() == column_name; });
}

std::ostream& operator<<(std::ostream& os, const Relation& relation) {
  os << relation.title() << std::endl;

  for (const Column<std::string>& column : relation.columns()) {
    os << "hello" << std::endl;
  }

  return os;
}
