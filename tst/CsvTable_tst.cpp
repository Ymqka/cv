#include "gtest/gtest.h"
#include "CsvTable.h"

#include <vector>

TEST(CsvTable, set_header) {
    CsvTable csv_table;

    vector<string> header;
    csv_table.set_header(header);
    EXPECT_EQ(csv_table.get_header(), header);
}

TEST(CsvTable, add_row_1) {
    CsvTable csv_table;

    vector<string> row = {"ya","ti","on"};
    csv_table.add_row(row);
    EXPECT_EQ(csv_table.get_body(), vector<vector<string>> {row});
}

TEST(CsvTable, add_row_2) {
    CsvTable csv_table;

    vector<string> row = {"ya","ti","on"};
    vector<string> row1 = {"oni","crya","zzz"};

    csv_table.add_row(row);
    csv_table.add_row(row1);
    
    vector<vector<string>> expected = {row, row1};
    EXPECT_EQ(csv_table.get_body(), expected);
}

