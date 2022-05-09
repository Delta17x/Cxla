#pragma once
#include <exception>
#include <sstream>

namespace cxla {
	template<class T, int C>
	class vec {
		T data[C];
	public:
		inline vec(std::initializer_list<T> _list) {
			for (int i = 0; i < _list.size(); i++) {
				data[i] = *(_list.begin() + i);
			}
			for (int i = _list.size(); i < C; i++) {
				data[i] = 0;
			}
		}

		inline T& Data(int i) {
			return data[i];
		}

		inline T Data(int i) const {
			return data[i];
		}

		explicit operator std::string() const {
			std::ostringstream oss("");
			for (int i = 0; i < C; i++) {
				oss << data[i];
				if (i != C - 1)
					oss << ", ";
			}
			return oss.str();
		}
	};

	template<>
	class vec<float, 4> {
	public:
		float x;
		float y;
		float z;
		float w;

		inline float& Data(int i) {
			switch (i) {
			case 0:
				return x;
			case 1:
				return y;
			case 2:
				return z;
			case 3:
				return w;
			default:
				throw new std::exception("Vector access was out of range.");
			}
		}

		inline float Data(int i) const {
			switch (i) {
			case 0:
				return x;
			case 1:
				return y;
			case 2:
				return z;
			case 3:
				return w;
			default:
				throw new std::exception("Vector access was out of range.");
			}
		}

		explicit operator std::string() const {
			std::ostringstream oss("");
			oss << x << ", " << y << ", " << z << ", " << w;
			return oss.str();
		}
	};

	template<>
	class vec<float, 3> {
	public:
		float x;
		float y;
		float z;

		inline float& Data(int i) {
			switch (i) {
			case 0:
				return x;
			case 1:
				return y;
			case 2:
				return z;
			default:
				throw new std::exception("Vector access was out of range.");
			}
		}

		inline float Data(int i) const {
			switch (i) {
			case 0:
				return x;
			case 1:
				return y;
			case 2:
				return z;
			default:
				throw new std::exception("Vector access was out of range.");
			}
		}

		explicit operator std::string() const {
			std::ostringstream oss("");
			oss << x << ", " << y << ", " << z;
			return oss.str();
		}
	};

	typedef vec<float, 3> vec3;

	template<>
	class vec<float, 2> {
	public:
		float x;
		float y;

		inline float& Data(int i) {
			switch (i) {
			case 0:
				return x;
			case 1:
				return y;
			default:
				throw new std::exception("Vector access was out of range.");
			}
		}

		inline float Data(int i) const {
			switch (i) {
			case 0:
				return x;
			case 1:
				return y;
			default:
				throw new std::exception("Vector access was out of range.");
			}
		}

		explicit operator std::string() const {
			std::ostringstream oss("");
			oss << x << ", " << y;
			return oss.str();
		}
	};

	typedef vec<float, 2> vec2;

	template<class T, int C>
	vec<T, C> operator+ (vec<T, C> a, vec<T, C> b) {
		for (int i = 0; i < C; i++) {
			a.Data(i) += b.Data(i);
		}
		return a;
	}

	template<class T, int C>
	vec<T, C> operator- (vec<T, C> a, vec<T, C> b) {
		for (int i = 0; i < C; i++) {
			a.Data(i) -= b.Data(i);
		}
		return a;
	}

	template<class T, int C>
	vec<T, C> operator- (vec<T, C> a) {
		for (int i = 0; i < C; i++) {
			a.Data(i) = -a.Data(i); 
		}
		return a;
	}

	template<class T, int C>
	vec<T, C> operator* (vec<T, C> a, T b) {
		for (int i = 0; i < C; i++) {
			a.Data(i) *= b;
		}
		return a;
	}

	// Computes the dot product of vectors A and B. Equivalent to T dot(vec<T, C> a, vec<T, C> b).
	template<class T, int C>
	T operator* (vec<T, C> a, vec<T, C> b) {
		T sum = 0;
		for (int i = 0; i < C; i++) {
			sum += a.Data(i) * b.Data(i);
		}
		return sum;
	}

	template<class T>
	vec<T, 3> cross(vec<T, 3> a, vec<T, 3> b) {
		return vec<T, 3>{a.Data(1)*b.Data(2) - a.Data(2)*b.Data(1), 
						 a.Data(2)*b.Data(0) - a.Data(0)*b.Data(2), 
						 a.Data(0)*b.Data(1) - a.Data(1)*b.Data(0)};
	}
	
	// Computes the dot product of vectors A and B. Equivalent to T operator* (vec<T, C> a, vec<T, C> b);
	template<class T, int C>
	T dot(vec<T, C> a, vec<T, C> b) {
		T sum = 0;
		for (int i = 0; i < C; i++) {
			sum += a.Data(i) * b.Data(i);
		}
		return sum;
	}

}
