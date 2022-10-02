#include <cmath>
#include <limits>
#include <ostream>
//
// Created by Randy on 2022-01-08.
//

#ifndef FRACTIONCLASSES_FRACTION_H
#define FRACTIONCLASSES_FRACTION_H

template<typename T>
class Fraction {
 private:
  // region Fields.
  T numerator_;
  T denominator_;

  // endregion

  // region Conversions.

  [[nodiscard]] inline long double ToLongDouble() const {
    return static_cast<long double>(numerator_) / static_cast<long double>(denominator_);
  }

  [[nodiscard]] inline double ToDouble() const {
    return static_cast<double>(numerator_) / static_cast<double>(denominator_);
  }

  [[nodiscard]] inline float ToFloat() const {
    return static_cast<float>(numerator_) / static_cast<float>(denominator_);
  }

  [[nodiscard]] inline unsigned long long ToIntegral() const {
    return static_cast<unsigned long long>(numerator_) / static_cast<unsigned long long>(denominator_);
  }
  // endregion

  static T Gcf(T u, T v) {
    T u_abs = abs(u);
    T v_abs = abs(v);
    T temp;
    while (v_abs != 0) {
      temp = u_abs % v_abs;
      u_abs = v_abs;
      v_abs = temp;
    }
    return u_abs;
  }

 public:
  // region Constructors.
  Fraction() {
    numerator_ = 1;
    denominator_ = 1;
  }

  explicit Fraction(const T x) {
    numerator_ = x;
    denominator_ = 1;
  }


  Fraction(T numerator, T denominator) : numerator_(numerator), denominator_(denominator) {}
  // endregion

  // region Utility fractions.
  Fraction LowestForm() const {
    T gcd = Gcf(this->numerator_, this->denominator_);
    return Fraction<T>(this->numerator_ / gcd, this->denominator_ / gcd);
  }

  void ReduceToLowestForm() {
    T gcd = Gcf(this->numerator_, this->denominator_);
    this->numerator_ /= gcd;
    this->denominator_ /= gcd;
    return *this;
  }

  Fraction Reciprocal() const {
    return Fraction(this->denominator_, this->numerator_);
  }
  // endregion

  // region Equality comparison functions.
  static bool IsStrictlyEqual(const Fraction &rhs, const Fraction &lhs) {
    if (rhs.numerator_ == lhs.numerator_ && rhs.denominator_ == lhs.denominator_) {
      return true;
    } else {
      return false;
    }
  }

  static bool IsValueEqual(const Fraction &lhs, const Fraction &rhs) {
    if (lhs.LowestForm().numerator_ == rhs.LowestForm().numerator_
        && lhs.LowestForm().denominator_ == rhs.LowestForm().denominator_) {
      return true;
    } else {
      return false;
    }
  }

  static bool IsPrettyMuchEqual(const Fraction &lhs, const Fraction &rhs) {
    if (IsValueEqual(lhs, rhs)
        || (abs((lhs.ToLongDouble() - rhs.ToLongDouble())) < std::numeric_limits<long double>::epsilon())) {
      return true;
    } else {
      return false;
    }
  }
  // endregion

  // region Arithmetic operators.
  static Fraction Add(Fraction lhs, Fraction rhs) {
    T lhs_denominator = lhs.denominator_;
    T rhs_denominator = rhs.denominator_;

    lhs.numerator_ *= rhs_denominator;
    lhs.denominator_ *= rhs_denominator;

    rhs.numerator_ *= lhs_denominator;
    rhs.denominator_ *= lhs_denominator;

    return Fraction(lhs.numerator_ + rhs.numerator_, rhs.denominator_).LowestForm();
  }

  static Fraction Subtract(Fraction lhs, Fraction rhs) {
    T lhs_denominator = lhs.denominator_;
    T rhs_denominator = rhs.denominator_;

    lhs.numerator_ * rhs_denominator;
    lhs.denominator_ * rhs_denominator;

    rhs.numerator_ * lhs_denominator;
    rhs.denominator_ * lhs_denominator;

    return Fraction(lhs.numerator_ - rhs.numerator_, rhs.denominator_).LowestForm();
  }

  static Fraction Multiply(const Fraction lhs, const Fraction rhs) {
    return Fraction(lhs.numerator_ * rhs.numerator_, lhs.denominator_ * rhs.denominator_).LowestForm();
  }

  static Fraction Divide(const Fraction lhs, const Fraction rhs) {
    return Multiply(lhs, rhs.Reciprocal()).LowestForm();
  }

  static double Pow(Fraction lhs, Fraction rhs) {
    return std::pow(lhs.ToDouble(), rhs.ToDouble());
  }

  static double Pow(Fraction lhs, T rhs) {
    auto rhs_as_fraction = Fraction(rhs);
    return std::pow(lhs.ToDouble(), rhs_as_fraction.ToDouble());
  }

  static double Pow(T lhs, Fraction rhs) {
    auto lhs_as_fraction = Fraction(lhs);
    return std::pow(lhs_as_fraction.ToDouble(), rhs.ToDouble());
  }
  // endregion

  // region Operator overloading.
  explicit operator short() const { return this->ToIntegral(); }

  explicit operator int() const { return this->ToIntegral(); }

  explicit operator long() const { return this->ToIntegral(); }

  explicit operator long long() const { return this->ToIntegral(); }

  explicit operator float() const { return this->ToFloat(); }

  explicit operator double() const { return this->ToDouble(); }

  explicit operator long double() const { return this->ToLongDouble(); }

  Fraction operator+(const Fraction &rhs) { return Add(*this, rhs); }

  friend Fraction operator+(const T lhs, const Fraction &rhs) {
    auto lhs_as_fraction = Fraction(lhs);
    return Add(lhs_as_fraction, rhs);
  }

  Fraction operator-(const Fraction &rhs) { return Subtract(*this, rhs); }

  Fraction operator*(const Fraction &rhs) { return Multiply(*this, rhs); }

  Fraction operator/(const Fraction &rhs) { return Divide(*this, rhs); }

  Fraction operator+=(const Fraction &rhs) {
    Add(*this, rhs);
    return *this;
  }

  Fraction operator-=(const Fraction &rhs) {
    Subtract(*this, rhs);
    return *this;
  }

  Fraction operator*=(const Fraction &rhs) {
    Multiply(*this, rhs);
    return *this;
  }

  Fraction operator/=(const Fraction &rhs) {
    Divide(*this, rhs);
    return *this;
  }

  bool operator==(const Fraction &rhs) const {
    return IsPrettyMuchEqual(*this, rhs);
  }

  bool operator!=(const Fraction &rhs) const { return rhs != *this; }

  friend std::ostream &operator<<(std::ostream &os, const Fraction &fraction) {
    os << fraction.numerator_ << " / " << fraction.denominator_;
    return os;
  }
  // endregion

  // region Getters and setters.
  T GetNumerator() const { return numerator_; }

  void SetNumerator(const T value) { Fraction::numerator_ = value; }

  T GetDenominator() const { return denominator_; }

  void SetDenominator(T value) { Fraction::denominator_ = value; }

  // endregion
};

#endif // FRACTIONCLASSES_FRACTION_H