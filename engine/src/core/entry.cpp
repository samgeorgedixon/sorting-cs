#include "entry.h"

#include "sort.h"

namespace engine {

	void engine::SortList(SortingData& data) {
		switch (data.sortingAlgorithm) {
			case SortingAlgorithm::INSERTION_SORT:
				SortViaInsertion(data);
				return;
			default:
				return;
		}
	}

	void engine::OutputList(const SortingData& data) {
		SORT_LOG("Sorted List:\n");

		for (int i = 0; i < data.numberList.size(); ++i) {
			SORT_LOG("%d", data.numberList[i]);

			if (i < data.numberList.size() - 1) SORT_LOG(", ");
		}
		SORT_LOG("\n");
	}

}
