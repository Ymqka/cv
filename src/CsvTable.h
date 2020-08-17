#ifndef _CSVTABLE_H_
#define _CSVTABLE_H_

#include <vector>
#include <iostream>

using namespace std;

class CsvTable {
public:
    const vector<string>& get_header();
    const vector<vector<string>>& get_body();
    bool check_if_rebuild_needed(vector<string> row);
    void add_row(vector<string> row);
    void set_header(vector<string> h);
    void Print();
    void resize();
private:
    bool has_header = false;
    // bool resized  = false;

    vector<size_t> column_sizes;
    vector<string> header;
    vector<vector<string>> body;
};

#endif