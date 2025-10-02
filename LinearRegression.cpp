#include <mlpack/core.hpp>
#include <mlpack/methods/linear_regression/linear_regression.hpp>
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include <limits>
#include <armadillo>


using namespace std;
using namespace mlpack;
using namespace mlpack::regression;
using namespace arma;

// Function to check if a string is numeric
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
        cerr << "Could not open file: " << filename << endl;
        return -1;
    }

    string line;
    vector<string> headers;
    vector<vector<double>> numericData;

    // Read header line
    if (getline(file, line)) {
        stringstream ss(line);
        string col;
        while (getline(ss, col, ',')) {
            headers.push_back(col);
        }
    }

    // Read data
    while (getline(file, line)) {
        stringstream ss(line);
        string cell;
        vector<double> row;
        size_t colIndex = 0;
        while (getline(ss, cell, ',')) {
            if (isNumeric(cell)) {
                row.push_back(stod(cell));
            } else {
                // Non-numeric: fill with 0
                row.push_back(0.0);
            }
            colIndex++;
        }
        if (!row.empty()) numericData.push_back(row);
    }
    file.close();

    // Convert numericData to arma::mat
    size_t nRows = numericData.size();
    size_t nCols = numericData[0].size();
    arma::mat dataset(nCols, nRows); // columns = features, rows = samples
    for (size_t i = 0; i < nRows; i++) {
        for (size_t j = 0; j < nCols; j++) {
            dataset(j, i) = numericData[i][j];
        }
    }

    cout << "Dataset loaded successfully. Size: " 
         << dataset.n_rows << "x" << dataset.n_cols << endl;

    // Print column names and first line
    cout << "\nColumn Names: ";
    for (const auto &h : headers) cout << h << " ";
    cout << "\nFirst Row: ";
    for (size_t j = 0; j < nCols; j++) cout << dataset(j, 0) << " ";
    cout << endl;

    // Basic stats
    cout << "\nBasic Statistics (Mean, Min, Max, Std):\n";
    for (size_t j = 0; j < nCols; j++) {
        cout << headers[j] << ": "
             << "Mean=" << arma::mean(dataset.row(j))
             << ", Min=" << dataset.row(j).min()
             << ", Max=" << dataset.row(j).max()
             << ", Std=" << arma::stddev(dataset.row(j))
             << endl;
    }

    // Linear Regression
    // Assume last column is target
    arma::rowvec responses = dataset.row(nCols - 1);
    arma::mat predictors = dataset.rows(0, nCols - 2);

    // Train linear regression model
    LinearRegression lr(predictors, responses);

    // Predict on training set
    arma::rowvec predictions;
    lr.Predict(predictors, predictions);

    cout << "\nSample Predictions (first 5):\n";
    size_t n = std::min<size_t>(5, static_cast<size_t>(predictions.n_elem));
    for (size_t i = 0; i < n; i++) {
        cout << "Actual: " << responses(i) 
             << ", Predicted: " << predictions(i) << endl;
    }

    return 0;
}
