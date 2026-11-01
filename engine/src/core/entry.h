#pragma once
#include "core.h"

#include <vector>

namespace engine {

	enum SortingAlgorithm {
		NONE = 0, INSERTION_SORT
	};

	struct SortingData {
		SortingAlgorithm sortingAlgorithm;
		bool isAscending;
		std::vector<int32_t> numberList;
	};

	void SortList(SortingData& data);

	void OutputList(const SortingData& data);

}
