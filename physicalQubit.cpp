#include <cmath>

#include "physicalQubit.h"


PhysicalQubit::PhysicalQubit(double coherence) : c0_(sqrt(1 - coherence)), c1_(sqrt(coherence)) {}

PhysicalQubit::PhysicalQubit(std::complex<double> c0, std::complex<double> c1, double coherence) : c0_(c0 * sqrt(1 - coherence)), c1_(c1 * sqrt(coherence)) {}

PhysicalQubit::PhysicalQubit() : PhysicalQubit(1) {}

void PhysicalQubit::X() {
  swap(c0_, c1_);
}

void PhysicalQubit::Y() {
  c0_ = -c0_;
  c1_ = -c1_;
  swap(c0_, c1_);
}

void PhysicalQubit::Z() {
  c0_ = -c0_;
}

void PhysicalQubit::H() {
	std::complex<double> temp = c0_;
  c0_ = (c0_ + c1_) / sqrt(2);
  c1_ = (temp - c1_) / sqrt(2);
}

void PhysicalQubit::R(double theta) {
  c0_ *= exp(std::complex<double>(0, theta / 2));
}

void PhysicalQubit::CNOT(PhysicalQubit& q) {
    std::complex<double> temp = c1_;
    c1_ = c1_ * q.c0_ + c0_ * q.c1_;
    c0_ = c0_ * q.c0_ + temp * q.c1_;
    q.X();
}

void PhysicalQubit::Toffoli(PhysicalQubit& q1, PhysicalQubit& q2) {
    if (measure()) {
        q1.CNOT(q2);
    }
}

std::pair<std::complex<double>, std::complex<double>> PhysicalQubit::state() const {
  return {c0_, c1_};
}

double PhysicalQubit::coherence() const {
  return norm(c1_);
}

int PhysicalQubit::measure() const {
    std::uniform_real_distribution<double> distribution(0, 1);
    return distribution(Qubit::rng_) < coherence();
}