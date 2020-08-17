#include "CsvTable.h"

const vector<string>& CsvTable::get_header() {
    return header;
}

const vector<vector<string>>& CsvTable::get_body() {
    return body;
}

void CsvTable::add_row(vector<string> row) {
    body.push_back(row);
    return;
}

bool CsvTable::check_if_rebuild_needed(vector<string> row) {
    if (row.size() == column_sizes.size()) {
        for(size_t i = 0; i < row.size(); i++) {
            size_t row_size = row.at(i).size();
            if(row_size > column_sizes.at(i)) {
                column_sizes.at(i) = row_size;
            }
        }
    } else if (row.size() > column_sizes.size()) {

    } else if (row.size() < column_sizes.size()) {
        
    }

    return false;
}

void CsvTable::set_header(vector<string> h) {
    has_header = true;
    header = h;

    return;
}
void CsvTable::Print() {

    return;
}

void CsvTable::resize() {
    // for(auto it = body.begin(); )

    return;
}


