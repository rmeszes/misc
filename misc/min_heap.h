#pragma once

#include <queue>
#include <string>
#include <iostream>

template<typename T>
class min_heap :public std::priority_queue<T,std::vector<T>,std::greater<T>> {
	bool operator==(const min_heap& other) const;
public:
	min_heap() = default;

	void write(std::ostream& os = std::cout, const std::string& separator = " ") {
		const size_t siz = std::priority_queue < T, std::vector<T>, std::greater<T>>::size();
		if (siz != 0) {
			for (size_t i = 0; i < siz - 1; ++i) {
				os << std::priority_queue < T, std::vector<T>, std::greater<T>>::top() << separator;
				std::priority_queue < T, std::vector<T>, std::greater<T>>::pop();
			}
			os << std::priority_queue < T, std::vector<T>, std::greater<T>>::top();
			std::priority_queue < T, std::vector<T>, std::greater<T>>::pop();
		}
	}
};