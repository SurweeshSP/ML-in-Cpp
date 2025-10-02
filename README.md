# ML-in-Cpp

ML in C++ with mlpack

This repository is my exploration of Machine Learning in C++ using the mlpack
library.
The goal is to build an end-to-end workflow for ML tasks—covering data import, preprocessing, basic analysis, and model training—fully in C++.

🚀 Project Overview

This project demonstrates how C++ can be used for Machine Learning instead of the more common Python ecosystem.
The focus is on:

Fast matrix operations

Importing and handling CSV datasets

Extracting basic dataset information

Implementing Linear Regression with mlpack

📂 File Structure
ML-Cpp/
│
├── 1.cpp                  # Matrix Operations (basic linear algebra examples)
├── data.cpp               # CSV Import using Armadillo/mlpack utilities
├── dataana.cpp            # Basic dataset information (rows, columns, summary)
├── LinearRegression.cpp   # Linear Regression model with mlpack
│
└── README.md              # Project Documentation

⚙️ Requirements

C++17 or later

mlpack
 (>= 4.x recommended)

Armadillo
 (linear algebra backend)

CMake (for building the project)

On Ubuntu/Debian, install dependencies:

sudo apt-get update
sudo apt-get install libmlpack-dev libarmadillo-dev cmake g++ 

🛠️ Build Instructions

Clone this repository:

git clone https://github.com/<your-username>/ML-Cpp.git
cd ML-Cpp


Compile an example file (e.g., 1.cpp):

g++ 1.cpp -o matrix_ops -lmlpack -larmadillo
./matrix_ops


For LinearRegression.cpp:

g++ LinearRegression.cpp -o linear_reg -lmlpack -larmadillo
./linear_reg

📊 Features Implemented

Matrix Operations (1.cpp)

Matrix creation, multiplication, transpose, and inverses.

CSV Import (data.cpp)

Load dataset from .csv into Armadillo/MLpack matrices.

Data Analysis (dataana.cpp)

Show number of rows & columns

Compute basic stats (mean, variance, min/max).

Linear Regression (LinearRegression.cpp)

Train a Linear Regression model using mlpack

Predict target values for test data

🔮 Future Work

Add Logistic Regression

Implement Decision Trees & Random Forests

Explore Clustering (K-Means)

Benchmark C++ vs Python implementations

📚 References

mlpack Documentation

Armadillo Documentation

✍️ This repo marks the start of my ML journey in C++, experimenting with efficient computation and mlpack’s powerful API.
