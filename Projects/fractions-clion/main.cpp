#include <iostream>
#include <vector>
#include <memory>

template<typename T>
class Fraction {
 private:
  //<editor-fold desc="Fields">
  T numerator_; // NOLINT(clion-misra-cpp2008-8-0-1)
  T denominator_; // NOLINT(clion-misra-cpp2008-8-0-1)
  //</editor-fold>

  //<editor-fold desc="Helper functions">

  void Reduce() {
    T gcd_numerator_and_denominator = Gcf(this->numerator_, this->denominator_); // NOLINT(clion-misra-cpp2008-8-0-1)
    this->numerator_ /= gcd_numerator_and_denominator;
    this->denominator_ /= gcd_numerator_and_denominator;
  }

  // Uses the greatest common divisor to simplify the fraction
  static T Gcf(T u, T v) {
    if (u == 0) {
      return v;
    } else if (v == 0) {
      return u;
    } else {
      T u_abs = abs(u); // NOLINT(clion-misra-cpp2008-8-0-1)
      T v_abs = abs(v); // NOLINT(clion-misra-cpp2008-8-0-1)
      T temp; // NOLINT(clion-misra-cpp2008-8-0-1)
      while (v_abs != 0) {
        temp = u_abs % v_abs;
        u_abs = v_abs;
        v_abs = temp;
      }
      return u_abs;
    }
  }
  //</editor-fold>

 public:
  //<editor-fold desc="Constructors">
  // Default constructor, sets the fraction to 0/1
  Fraction() {
    this->numerator_ = 0;
    this->denominator_ = 1;
    this->Reduce();
  }

  // Constructor for whole numbers.
  explicit Fraction(const T integer) {
    this->numerator_ = integer;
    this->denominator_ = 1;
    this->Reduce();
  }
  // Sets the fraction to the given numerator and denominator, denominator cannot be 0.
  Fraction(const T numerator, const T denominator) {
    this->numerator_ = numerator;
    if (denominator != 0) {
      this->denominator_ = denominator;
    } else {
      this->denominator_ = 1;
      throw std::invalid_argument("Denominator cannot be zero");
    }
    this->Reduce();
  }

  //</editor-fold>

  //<editor-fold desc="Getters and setters.">
  [[nodiscard]] T GetNumerator() const {
    return numerator_;
  }

  void SetNumerator(const T numerator) {
    this->numerator_ = numerator;
    this->Reduce();
  }

  [[nodiscard]] T GetDenominator() const {
    return denominator_;
  }

  void SetDenominator(const T denominator) {
    this->denominator_ = denominator;
    this->Reduce();
  }

  //</editor-fold>

  //<editor-fold desc="Arithmetic operations">
  Fraction operator+(const Fraction &other) const {
    Fraction result; // NOLINT(clion-misra-cpp2008-8-0-1)
    result.numerator_ = this->numerator_ * other.denominator_ + other.numerator_ * this->denominator_;
    result.denominator_ = this->denominator_ * other.denominator_;
    result.Reduce();
    return result;
  }

  Fraction operator-(const Fraction &other) const {
    Fraction result; // NOLINT(clion-misra-cpp2008-8-0-1)
    result.numerator_ = this->numerator_ * other.denominator_ - other.numerator_ * this->denominator_;
    result.denominator_ = this->denominator_ * other.denominator_;
    result.Reduce();
    return result;
  }

  Fraction operator*(const Fraction &other) const {
    Fraction result; // NOLINT(clion-misra-cpp2008-8-0-1)
    result.numerator_ = this->numerator_ * other.numerator_;
    result.denominator_ = this->denominator_ * other.denominator_;
    result.Reduce();
    return result;
  }

  Fraction operator/(const Fraction &other) const {
    Fraction result; // NOLINT(clion-misra-cpp2008-8-0-1)
    result = *this * other.Reciprocal();
    result.Reduce();
    return result;
  }

  [[nodiscard]] Fraction Reciprocal() const {
    if (numerator_ != 0) {
      return Fraction(this->denominator_, this->numerator_);
    } else {
      throw std::invalid_argument("Cannot take reciprocal of zero");
    }
  }
  //</editor-fold>

  //<editor-fold desc="Stream override">
  // Stream insertion operator for Fraction
  // Prints the fraction in the format "numerator / denominator"
  friend std::ostream &operator<<(std::ostream &os, const Fraction &fraction) {
    os << fraction.numerator_ << " / " << fraction.denominator_;
    return os;
  }
  //</editor-fold>
};

int main() {
  Fraction<int> f_1(100);
  Fraction<int> f_2;
  Fraction<int> f_3(2, 4);

  f_1.SetNumerator(10);
  f_1.SetDenominator(2);
  if (f_1.GetNumerator() == 10) {
    f_2.SetDenominator(40);
  }

  std::cout << f_1 << std::endl;
  std::cout << f_2 << std::endl;
  std::cout << f_3 << std::endl;
  std::cout << f_2.GetDenominator() << std::endl;
  std::cout << f_3.Reciprocal() << std::endl;

  auto f_heap_1 = std::make_shared<Fraction<int>>(4, 5);
  std::cout << f_heap_1->GetNumerator() << std::endl;

  int numerator;
  int denominator;

  std::cout << "Enter numerator: ";
  std::cin >> numerator;
  std::cout << "Enter denominator: ";
  std::cin >> denominator;

  Fraction<int> f_4(numerator, denominator);

  std::cout << "Enter numerator: ";
  std::cin >> numerator;
  std::cout << "Enter denominator: ";
  std::cin >> denominator;

  Fraction<int> f_5(numerator, denominator);

  std::cout << "your two fractions added: " << f_4 + f_5 << std::endl;
  std::cout << "your two fractions subtracted: " << f_4 - f_5 << std::endl;
  std::cout << "your two fractions multiplied: " << f_4 * f_5 << std::endl;
  std::cout << "your two fractions divided: " << f_4 / f_5 << std::endl;

  std::vector<std::unique_ptr<Fraction<int>>> v;
  for (int i = 1; i <= 1000000; ++i) {
    (void)v.emplace_back(std::make_unique<Fraction<int>>(1, i));
  }

  for (auto &f : v) {
    std::cout << f << std::endl;
  }

  return 0;
}
