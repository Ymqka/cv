#include "CsvTable.h"

const vector<string>& CsvTable::get_header() {
    return header;
}

const vector<vector<string>>& CsvTable::get_body() {
    return body;
}

void CsvTable::add_row(vector<string> row) {
    body.push_back(row);
    rebuild_sizes(row);
    return;
}

const vector<size_t>& CsvTable::get_sizes() {
    return column_sizes;
}

void CsvTable::rebuild_sizes(vector<string> row) {

    if (row.size() > column_sizes.size()) {
        column_sizes.resize(row.size());
    }

    for(size_t i = 0; i < row.size(); i++) {
        size_t row_size = row.at(i).size();
        if(row_size > column_sizes.at(i)) {
            column_sizes.at(i) = row_size;
        }
    }

    total_horizontal_size = 0;
    for(auto it = column_sizes.begin(); it != column_sizes.end(); it++) {
        total_horizontal_size += (*it);
    }
    
    total_horizontal_size += (column_sizes.size() * 3) + 1;

    return;
}

void CsvTable::set_header(vector<string> h) {
    has_header = true;
    header = h;

    rebuild_sizes(h);

    return;
}

string CsvTable::Print() {
    stringstream s;

    s << string(total_horizontal_size, '-') << endl;
    for(auto it = body.begin(); it != body.end(); it++) {
        s << print_row(*it);
        s << endl;
        if(it != (body.end() -1)) {
            s << print_delimiter();
            s << endl;
        }
    }

    s << string(total_horizontal_size, '-') << endl;

    cout << s.str();

    return s.str();
}




