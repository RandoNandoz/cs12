#include <iostream>

using namespace std;

template<typename T>
class TwoByTwoMatrix {
 private:
  // The matrix is stored in a 2d 2x2 array.
  T matrix_[2][2]{};

 public:
  // default constructor, initializes to zero.
  TwoByTwoMatrix() {
    this->matrix_[0][0] = 0;
    this->matrix_[0][1] = 0;
    this->matrix_[1][0] = 0;
    this->matrix_[1][1] = 0;
  }

  // constructor, initializes an identity matrix of the given int,
  explicit TwoByTwoMatrix(T value) {
    this->matrix_[0][0] = value;
    this->matrix_[0][1] = 0;
    this->matrix_[1][0] = 0;
    this->matrix_[1][1] = value;
  }

  // constructor, initializes a matrix with the given values.
  TwoByTwoMatrix(T a_00, T a_01, T a_10, T a_11) {
    this->matrix_[0][0] = a_00;
    this->matrix_[0][1] = a_01;
    this->matrix_[1][0] = a_10;
    this->matrix_[1][1] = a_11;
  }

  ~TwoByTwoMatrix() = default;

  // gets the determinant of the matrix.
  [[nodiscard]] T Determinant() const {
    return this->matrix_[0][0] * this->matrix_[1][1] - this->matrix_[0][1] * this->matrix_[1][0];
  }

  // finds the inverse of the matrix.
  [[nodiscard]] TwoByTwoMatrix Inverse() const {
    T det = this->Determinant();
    if (det != 0) {
      return TwoByTwoMatrix(this->matrix_[1][1] / det, -this->matrix_[0][1] / det,
                            -this->matrix_[1][0] / det, this->matrix_[0][0] / det);
    } else {
      throw invalid_argument("determinant cannot be zero!");
    }
  }

  [[nodiscard]] TwoByTwoMatrix Transpose() const {
    return TwoByTwoMatrix(this->GetMatrix00(), this->GetMatrix10(), this->GetMatrix01(), this->GetMatrix11());
  }

  // adds the matrix by another matrix
  TwoByTwoMatrix operator+(const TwoByTwoMatrix &matrix) {
    TwoByTwoMatrix result;
    result.SetMatrix00(this->matrix_[0][0] + matrix.GetMatrix00());
    result.SetMatrix01(this->matrix_[0][1] + matrix.GetMatrix01());
    result.SetMatrix10(this->matrix_[1][0] + matrix.GetMatrix10());
    result.SetMatrix11(this->matrix_[1][1] + matrix.GetMatrix11());
    return result;
  }

  TwoByTwoMatrix operator-(const TwoByTwoMatrix &matrix) {
    TwoByTwoMatrix result;
    result.SetMatrix00(this->matrix_[0][0] - matrix.GetMatrix00());
    result.SetMatrix01(this->matrix_[0][1] - matrix.GetMatrix01());
    result.SetMatrix10(this->matrix_[1][0] - matrix.GetMatrix10());
    result.SetMatrix11(this->matrix_[1][1] - matrix.GetMatrix11());
    return result;
  }

  // multiplies the scalar_value by a given scalar value.
  TwoByTwoMatrix operator*(const T &scalar_value) const {
    TwoByTwoMatrix result(this->matrix_[0][0] * scalar_value, this->matrix_[0][1] * scalar_value,
                          this->matrix_[1][0] * scalar_value, this->matrix_[1][1] * scalar_value);
    return result;
  }

  TwoByTwoMatrix operator*(const TwoByTwoMatrix &matrix) {
    TwoByTwoMatrix result;
    result.SetMatrix00(this->matrix_[0][0] * matrix.GetMatrix00() + this->matrix_[0][1] * matrix.GetMatrix10());
    result.SetMatrix01(this->matrix_[0][0] * matrix.GetMatrix01() + this->matrix_[0][1] * matrix.GetMatrix11());
    result.SetMatrix10(this->matrix_[1][0] * matrix.GetMatrix00() + this->matrix_[1][1] * matrix.GetMatrix10());
    result.SetMatrix11(this->matrix_[1][0] * matrix.GetMatrix01() + this->matrix_[1][1] * matrix.GetMatrix11());
    return result;
  }

  friend TwoByTwoMatrix operator*(const int lhs, const TwoByTwoMatrix &rhs) {
    return rhs * lhs;
  }

  TwoByTwoMatrix operator/(const TwoByTwoMatrix &matrix) {
    TwoByTwoMatrix result;
    result = *this * matrix.Inverse();
    return result;
  }

  TwoByTwoMatrix &operator+=(const TwoByTwoMatrix &matrix) {
    *this = *this + matrix;
    return *this;
  }

  TwoByTwoMatrix &operator-=(const TwoByTwoMatrix &matrix) {

    *this = *this - matrix;
    return *this;
  }

  TwoByTwoMatrix &operator*=(const TwoByTwoMatrix &matrix) {
    *this = *this * matrix;
    return *this;
  }

  TwoByTwoMatrix &operator/=(const TwoByTwoMatrix &matrix) {
    *this *= matrix.Inverse();
    return *this;
  }

  // override for the output.
  friend ostream &operator<<(ostream &os, const TwoByTwoMatrix &matrix) {
    os << matrix.GetMatrix00() << ", " << matrix.GetMatrix01() << "\n"
       << matrix.GetMatrix10() << ", " << matrix.GetMatrix11();
    return os;
  }

  bool operator==(const TwoByTwoMatrix &matrix) const {
    for (int i = 0; i < 2; ++i) {
      for (int j = 0; j < 2; ++j) {
        if (this->matrix_[i][j] != matrix[i][j]) {
          return false;
        }
      }
    }
    return true;
  }

  bool operator!=(const TwoByTwoMatrix &matrix) const {
    return !(matrix == *this);
  }

  struct TwoByTwoRow {
    T array[2];
    T operator[](long long j) {
      return array[j];
    }
  };

  TwoByTwoRow operator[](const int i) const {
    TwoByTwoRow result{this->matrix_[i][0], this->matrix_[i][1]};
    return result;
  }

  //<editor-fold desc="getters and setters.">
  [[nodiscard]] T GetMatrix00() const { return this->matrix_[0][0]; }
  [[nodiscard]] T GetMatrix01() const { return this->matrix_[0][1]; }
  [[nodiscard]] T GetMatrix10() const { return this->matrix_[1][0]; }
  [[nodiscard]] T GetMatrix11() const { return this->matrix_[1][1]; }

  void SetMatrix00(const T value) { this->matrix_[0][0] = value; }
  void SetMatrix01(const T value) { this->matrix_[0][1] = value; }
  void SetMatrix10(const T value) { this->matrix_[1][0] = value; }
  void SetMatrix11(const T value) { this->matrix_[1][1] = value; }
  //</editor-fold>
};

int main() {
  TwoByTwoMatrix<double> matrix_1(1, 2, 3, 4);
  TwoByTwoMatrix<double> matrix_2(5, 6, 7, 8);
  TwoByTwoMatrix<double> matrix_3(1);
  cout << "matrix1 + matrix2: " << endl << matrix_1 + matrix_2 << endl;
  cout << "matrix1 - matrix2: " << endl << matrix_1 - matrix_2 << endl;
  cout << "matrix1 * matrix2: " << endl << matrix_1 * matrix_2 << endl;
  cout << "matrix1 / matrix2: " << endl << matrix_1 / matrix_2 << endl;

  cout << "matrix1.determinant: " << matrix_1.Determinant() << endl;
  cout << "matrix1.inverse" << endl << matrix_3.Inverse() << endl;

  cout << "matrix1.transpose" << endl << matrix_1.Transpose() << endl;

  matrix_1 *= matrix_2;

  cout << matrix_1 << endl;

  cout << endl;

  cout << matrix_3 << endl;

  TwoByTwoMatrix<double> matrix_should_be_equal_1(20);
  TwoByTwoMatrix<double> matrix_should_be_equal_2(20);

  cout << (matrix_should_be_equal_1 == matrix_should_be_equal_2) << endl;

  cout << (matrix_should_be_equal_1 != matrix_should_be_equal_2) << endl;


  auto matrix_4 = TwoByTwoMatrix<double>(1, 2, 3, 4);

  auto matrix_6 = 4 * matrix_4;

  cout << matrix_6 << endl;

  return 0;
}
