#pragma once
#include <cmath>
#define M_PI       3.14159265358979323846   // pi
namespace Easing {

	// Linear
	inline float Linear(float t) {
		return t;
	}

	// Quadratic
	inline float InQuad(float t) {
		return t * t;
	}

	inline float OutQuad(float t) {
		return t * (2 - t);
	}

	inline float InOutQuad(float t) {
		return (t < 0.5f) ? (2 * t * t) : (-1 + (4 - 2 * t) * t);
	}

	// Cubic
	inline float InCubic(float t) {
		return t * t * t;
	}

	inline float OutCubic(float t) {
		t -= 1;
		return t * t * t + 1;
	}

	inline float InOutCubic(float t) {
		return (t < 0.5f) ? (4 * t * t * t) :
			((t - 1) * (2 * t - 2) * (2 * t - 2) + 1);
	}

	// Quart
	inline float InQuart(float t) {
		return t * t * t * t;
	}

	inline float OutQuart(float t) {
		t -= 1;
		return 1 - t * t * t * t;
	}

	inline float InOutQuart(float t) {
		return (t < 0.5f) ? (8 * t * t * t * t) :
			(1 - 8 * (t - 1) * (t - 1) * (t - 1) * (t - 1));
	}

	// Quint
	inline float InQuint(float t) {
		return t * t * t * t * t;
	}

	inline float OutQuint(float t) {
		t -= 1;
		return t * t * t * t * t + 1;
	}

	inline float InOutQuint(float t) {
		return (t < 0.5f) ? (16 * t * t * t * t * t) :
			(1 + 16 * (t - 1) * (t - 1) * (t - 1) * (t - 1) * (t - 1));
	}

	// Sine
	inline float InSine(float t) {
		return 1 - std::cos((t * M_PI) / 2);
	}

	inline float OutSine(float t) {
		return std::sin((t * M_PI) / 2);
	}

	inline float InOutSine(float t) {
		return -(std::cos(M_PI * t) - 1) / 2;
	}

	// Expo
	inline float InExpo(float t) {
		return (t == 0.0f) ? 0.0f : std::pow(2, 10 * (t - 1));
	}

	inline float OutExpo(float t) {
		return (t == 1.0f) ? 1.0f : 1 - std::pow(2, -10 * t);
	}

	inline float InOutExpo(float t) {
		if (t == 0.0f) return 0.0f;
		if (t == 1.0f) return 1.0f;
		if (t < 0.5f)
			return std::pow(2, 20 * t - 10) / 2;
		else
			return (2 - std::pow(2, -20 * t + 10)) / 2;
	}

	// Circular
	inline float InCirc(float t) {
		return 1 - std::sqrt(1 - t * t);
	}

	inline float OutCirc(float t) {
		t -= 1;
		return std::sqrt(1 - t * t);
	}

	inline float InOutCirc(float t) {
		if (t < 0.5f)
			return (1 - std::sqrt(1 - 4 * t * t)) / 2;
		else
			return (std::sqrt(1 - (2 * t - 2) * (2 * t - 2)) + 1) / 2;
	}

} // namespace Easing
