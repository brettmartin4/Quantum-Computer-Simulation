#pragma once

#include <complex>
#include <utility>
#include <random>


class Qubit {
public:
	virtual ~Qubit() {}

	// Applies a Pauli X (NOT) gate to the qubit
	virtual void X() = 0;

	// Applies a Pauli Y gate to the qubit
	virtual void Y() = 0;

	// Applies a Pauli Z gate to the qubit
	virtual void Z() = 0;

	// Applies a Hadamard gate to the qubit
	virtual void H() = 0;

	// Applies a phase shift gate to the qubit
	virtual void R(double theta) = 0;

	// Returns the state of the qubit as a pair of complex numbers
	virtual std::pair<std::complex<double>, std::complex<double>> state() const = 0;

protected:
	static std::mt19937 rng_;
};