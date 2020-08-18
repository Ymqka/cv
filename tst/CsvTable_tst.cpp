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

TEST(CsvTable, get_sizes_one_row) {
    CsvTable csv_table;

    vector<string> row = {"ya", "ti", "on"};

    csv_table.add_row(row);
    EXPECT_EQ(csv_table.get_sizes().size(),3);

    vector<size_t> expected_vector = {2,2,2};
    EXPECT_EQ(csv_table.get_sizes(), expected_vector);
}

TEST(CsvTable, get_sizes_bigger_size) {
    CsvTable csv_table;

    vector<string> row = {"ya", "ti", "on"};
    vector<string> bigger_row = {"ya", "ti", "on","oni"};

    csv_table.add_row(row);
    csv_table.add_row(bigger_row);

    EXPECT_EQ(csv_table.get_sizes().size(),4);

    vector<size_t> expected_vector = {2,2,2,3};
    EXPECT_EQ(csv_table.get_sizes(), expected_vector);
}

TEST(CsvTable, get_sizes_lesser_size) {
    CsvTable csv_table;

    vector<string> row = {"ya", "ti", "on"};
    vector<string> lesser_row = {"ya", "ti"};

    csv_table.add_row(row);
    csv_table.add_row(lesser_row);

    EXPECT_EQ(csv_table.get_sizes().size(),3);

    vector<size_t> expected_vector = {2,2,2};
    EXPECT_EQ(csv_table.get_sizes(), expected_vector);
}

TEST(CsvTable, get_sizes_bigger) {
    CsvTable csv_table;

    vector<string> row =        {"ya", "ti", "on"};
    vector<string> bigger_row = {"yay", "tit", "oni"};

    csv_table.add_row(row);
    csv_table.add_row(bigger_row);

    EXPECT_EQ(csv_table.get_sizes().size(),3);

    vector<size_t> expected_vector = {3,3,3};
    EXPECT_EQ(csv_table.get_sizes(), expected_vector);
}

TEST(CsvTable, get_sizes_lesser) {
    CsvTable csv_table;

    vector<string> row =        {"ya", "ti", "o", "onii"};
    vector<string> lesser_row = {"y", "t",};

    csv_table.add_row(row);
    csv_table.add_row(lesser_row);

    EXPECT_EQ(csv_table.get_sizes().size(),4);

    vector<size_t> expected_vector = {2,2,1,4};
    EXPECT_EQ(csv_table.get_sizes(), expected_vector);
}

TEST(CsvTable, print_1) {
    CsvTable csv_table;

    vector<string> row =        {"ya", "ti", "o", "onii"};
    vector<string> lesser_row = {"y", "t",};
    vector<string> bigger_row = {"fasyay", "fastit", "onfasi"};

    csv_table.add_row(row);
    csv_table.add_row(lesser_row);
    csv_table.add_row(bigger_row);

    csv_table.Print();
    // cout << csv_table.Print() << endl;

}



