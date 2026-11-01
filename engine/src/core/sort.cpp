#include "sort.h"

#include "core.h"
#include "entry.h"

#include <vector>

namespace engine {

	void SortViaInsertion(SortingData& data) {
        int8_t direction = data.isAscending ? 1 : -1;

		SORT_LOG("direction: %d\n", direction);

        for (int i = 1; i < data.numberList.size(); i++) {
            int item = data.numberList[i];

            int j = i - direction; // Previous index: Then decreases...

            // Move all items bellow current up untill item can be placed correctly.
            while (j >= 0 && j <= data.numberList.size() - 1 && item < data.numberList[j]) {
                data.numberList[j + direction] = data.numberList[j];

                j -= direction;
            }

            // Finnaly insert item
            data.numberList[j + direction] = item;
        }
	}

}
