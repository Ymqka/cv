#ifndef _CSVPARSER_H_
#define _CSVPARSER_H_

class CsvParser {
public:
    CsvParser();
    vector<variant<int, string, double>> parse_row(string str);
private:
    char delimiter = ",";
};

#endif