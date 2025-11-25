#pragma once
#include <cstdint>
#include <vector>
#include <iostream>


template <typename T> class Matrix {
    private:
        T* contents = nullptr;
        const std::int32_t rows;
        const std::int32_t columns;

    public:
        Matrix(std::int32_t rows, std::int32_t columns): rows(rows), columns(columns){
            contents = new T[rows*columns];
            for (int i = 0; i < rows*columns; ++i) {
                contents[i] = 0;
            }
        }  

        ~Matrix(){ delete[] contents; }

        std::int32_t get_columns() const { return columns; }
        std::int32_t get_rows() const { return rows; }

        std::vector<T> get_row(std::int32_t row) const{ 
            std::vector<T> m_row;
            for (int col = 0; col < columns; ++col) {
                m_row.push_back(get_content(row,col));
            }
            return m_row; 
        }

        std::vector<T> get_column(std::int32_t column) const{
            std::vector<T> m_col;
            for (int row = 0; row < rows; ++row) {
                m_col.push_back(get_content(row, column));
            }
            return m_col; 
        }

        T get_content(std::int32_t row, std::int32_t column) const {
            if (column < 0 || column >= columns || row < 0 || row >= rows) {
                std::string message = column < columns ? "Invalid Colums Index" : "Invalid Row Index";
                throw std::invalid_argument(message);
            }
            return contents[column+row*columns];
        }

        void set_content(std::int32_t row, std::int32_t column, T value){
            contents[column+row*columns] =  value;
        }

        Matrix<T> operator+(const Matrix<T>& other) const{
            if (columns != other.get_columns() || rows != other.get_rows()) {
                throw std::invalid_argument("Dimension Mismatch");
            }
            Matrix<T> result(rows,columns);
            for (int col = 0; col < columns ; ++col){
                for (int row = 0; row < rows; row++) {
                    result.set_content(row, col, get_content(row, col) + other.get_content(row,col));
                }
            }
            return result; 
        }

        Matrix<T> operator*(const Matrix<T>& other){
            if (columns != other.get_rows()) {
                throw std::invalid_argument("Dimension Mismatch");
            }
            Matrix<T> result(rows,other.get_columns());
            for (int col = 0; col < other.get_columns(); ++col) {
                auto other_col = other.get_column(col);
                for (int row = 0; row < rows; ++row) {
                    auto this_row = get_row(row);
                    T sum = 0;
                    for (int j = 0; j < this_row.size(); ++j) {
                        sum+= this_row[j]*other_col[j];
                    }
                    result.set_content(row, col, sum);
                }
            }
            return result;
        }
        
        Matrix<T>& operator=(const Matrix<T>& other) {
            if (this == &other) return *this;
            for (int i = 0; i < rows; ++i) {
                for (int j = 0; j < columns; ++j) {
                    set_content(i,j,other.get_content(i,j));
                }
            }
            return *this;
        }

        /* Do not change the code below here */
        /* These functions are used for testing purposes. */
        T* get_content_ptr(){
            return contents;
        }
};