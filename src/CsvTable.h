#ifndef _CSVTABLE_H_
#define _CSVTABLE_H_

#include <vector>
#include <iostream>
#include <sstream>
#include <iomanip>

using namespace std;

class CsvTable {
public:
    const vector<string>& get_header();
    const vector<vector<string>>& get_body();
    const vector<size_t>& get_sizes();
    void rebuild_sizes(vector<string> row);
    void add_row(vector<string> row);
    void set_header(vector<string> h);
    string Print();
private:
    bool has_header = false;
    // bool resized  = false;

    string print_delimiter() {
        stringstream ss;

        for(auto it = column_sizes.begin(); it != column_sizes.end(); it++) {
            if(it == column_sizes.begin()) {
                ss << "|";
            }
            ss << string((*it) + 2, '-');

            ss << "|";
        }

        return ss.str();
    }

    string print_row(vector<string> row) {
        stringstream ss;

        row.resize(column_sizes.size());
        for(size_t i = 0; i < row.size(); i++){
            if( i == 0 ){
                ss << "| ";
            }

            ss << center_indent(row.at(i), column_sizes.at(i));

            ss << " | ";

        }

        return ss.str();
    }

    string center_indent(const string& s, int width) {
        int len = s.length();
        if(width < len) {
            return s;
        }

        int diff = width - len;
        int pad1 = diff/2;
        int pad2 = diff - pad1;
        return string(pad1, ' ') + s + string(pad2, ' ');
    }

    vector<size_t> column_sizes;
    size_t total_horizontal_size = 0;
    vector<string> header;
    vector<vector<string>> body;
};

#endif