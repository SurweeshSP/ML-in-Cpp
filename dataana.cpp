#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <string>
#include <limits>
#include <armadillo>

using namespace std;
using namespace arma;

bool isNumeric(const string &s) {
    try {
        stod(s);
        return true;
    } catch (...) {
        return false;
    }
}

int main() {
    string filename = "dataset.csv";
    ifstream file(filename);
    if (!file.is_open()) {
        cerr << "Cannot open file: " << filename << endl;
        return -1;
    }

    string line;
    vector<string> column_names;

    // --- Read header ---
    if (getline(file, line)) {
        stringstream ss(line);
        string col;
        while (getline(ss, col, ',')) {
            column_names.push_back(col);
        }
    }

    vector<vector<double>> numeric_data(column_names.size());
    vector<int> null_count(column_names.size(), 0);

    while (getline(file, line)) {
        stringstream ss(line);
        string val;
        for (size_t i = 0; i < column_names.size(); i++) {
            if (!getline(ss, val, ',')) val = "";
            if (isNumeric(val))
                numeric_data[i].push_back(stod(val));
            else
                null_count[i]++;
        }
    }
    file.close();

    cout << "Column Name, Mean, Min, Max, Std, Variance, Nulls\n";
    for (size_t i = 0; i < column_names.size(); i++) {
        if (numeric_data[i].size() > 0) {
            arma::vec col(numeric_data[i]);
            cout << column_names[i] << ", "
                << arma::mean(col) << ", "
                << col.min() << ", "
                << col.max() << ", "
                << arma::stddev(col) << ", "
                << arma::var(col) << ", "
                << null_count[i]
                << endl;
        } else {
            cout << column_names[i] << ", NaN, NaN, NaN, NaN, NaN, "
                << null_count[i] << endl;
        }
    }

    return 0;
}
