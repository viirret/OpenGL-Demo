#pragma once

#include <cmath>

template <typename T>
struct Vec2
{
	T x;
	T y;

	Vec2() : x(0), y(0) {}
	Vec2(T x, T y) : x(x), y(y) {}

	bool operator!=(const Vec2 <T>& rhs) const { return x != rhs.x || y != rhs.y; }
	bool operator==(const Vec2 <T>& rhs) const { return x == rhs.x && y == rhs.y; }

	bool operator<=(const Vec2 <T>& rhs) const { return x <= rhs.x && y <= rhs.y; }
	bool operator>=(const Vec2 <T>& rhs) const { return x >= rhs.x && y >= rhs.y; }
	bool operator<(const Vec2 <T>& rhs) const { return x < rhs.x && y < rhs.y; }
	bool operator>(const Vec2 <T>& rhs) const { return x > rhs.x && y > rhs.y; }

	template <typename V> Vec2 <T> operator/(const Vec2 <V>& rhs) const { return Vec2 <T> (x / rhs.x, y / rhs.y); }
	template <typename V> Vec2 <T> operator*(const Vec2 <V>& rhs) const { return Vec2 <T> (x * rhs.x, y * rhs.y); }
	template <typename V> Vec2 <T> operator+(const Vec2 <V>& rhs) const { return Vec2 <T> (x + rhs.x, y + rhs.y); }
	template <typename V> Vec2 <T> operator-(const Vec2 <V>& rhs) const { return Vec2 <T> (x - rhs.x, y - rhs.y); }

	Vec2 <T> operator/(const T rhs) const { return Vec2 <T> (x / rhs, y / rhs); }
	Vec2 <T> operator*(const T rhs) const { return Vec2 <T> (x * rhs, y * rhs); }

	template <typename V> Vec2 <T> operator*=(const Vec2 <V>& rhs) { x *= rhs.x; y *= rhs.y; return *this; }
	template <typename V> Vec2 <T> operator/=(const Vec2 <V>& rhs) { x /= rhs.x; y /= rhs.y; return *this; }
	template <typename V> Vec2 <T> operator+=(const Vec2 <V>& rhs) { x += rhs.x; y += rhs.y; return *this; }
	template <typename V> Vec2 <T> operator-=(const Vec2 <V>& rhs) { x -= rhs.x; y -= rhs.y; return *this; }

	template <typename N>
	Vec2 <N> as() const { return Vec2 <N> (static_cast <N> (x), static_cast <N> (y)); }
	Vec2 <T> abs() const { return Vec2 <T> (std::abs(x), std::abs(y)); }
};

typedef Vec2 <float> Vec2f;
typedef Vec2 <size_t> Vec2s;
typedef Vec2 <int> Vec2i;
