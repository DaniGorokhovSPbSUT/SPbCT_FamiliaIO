#include "pch.h"
#include <string>
#include <random>
#include <vector>
#include <algorithm>
#include "StringsDll.h"

namespace StringsFunc
{
	std::vector<std::string> MyStringsFunc::getStrs(std::string source)
	{
		std::vector<std::string> strs;

		int length = source.length();

		std::random_device dev;
		std::mt19937 rng(dev());
		std::uniform_int_distribution<std::mt19937::result_type> dist(1, length - 1);

		std::vector<int> ixs;

		for (int i = 0; i < 8; i += 1) {
			ixs.push_back(dist(rng));
		}
		ixs.push_back(length);

		std::sort(ixs.begin(), ixs.end());

		int prevIx = 0;
		auto it = ixs.begin();
		while (it != ixs.end()) {
			strs.push_back(
				source.substr(prevIx, *it - prevIx - 1)
			);

			prevIx = *it;
			it++;
		}

		return strs;
	}
}
