#include "application.h"

#include <string>
#include <vector>
#include <sstream>

#include "sorting_engine.h"

namespace console {

    struct Inputs {
        engine::SortingAlgorithm sortingAlgorithm;

        bool isAscending;
        std::string numberList;
    };

    bool AskInputs(Inputs& inputs) { // Console Interface
        SORT_LOG("Sorting Algorithms:\n \n");

        SORT_LOG("0. None\n");
        SORT_LOG("1. Insertion Sort\n");

        SORT_LOG("\n");
        SORT_LOG("Which Sorting Algorithm should be used? ");
		std::string sortingAlgorithmInput = "";
        std::getline(std::cin, sortingAlgorithmInput);

        SORT_LOG("\n");
        SORT_LOG("Sort into Ascending or Descending? (A/d) ");
		std::string isAscendingInput = "";
        std::getline(std::cin, isAscendingInput);

        SORT_LOG("\n");
        SORT_LOG("Input your List of Numbers: (whitespace seperated...)\n");
        std::getline(std::cin, inputs.numberList);
        
        SORT_LOG("\n");

        // Set Inputs
		if (sortingAlgorithmInput.empty()) { // Validate Sorting Algorithm Input
			return false;
		}

		switch (sortingAlgorithmInput[0]) {
		    case '0':
		    	inputs.sortingAlgorithm = engine::SortingAlgorithm::NONE;
		    	break;
		    case '1':
		    	inputs.sortingAlgorithm = engine::SortingAlgorithm::INSERTION_SORT;
		    	break;
			default:
				return false;
		}
        inputs.isAscending = (isAscendingInput != "d") && (isAscendingInput != "D"); // Defaults to Ascending
        
        return true;
    }

    bool SplitNumberList(std::vector<int32_t>& numbers, const std::string& numberList) {
        std::stringstream ss(numberList);
        std::string segment;

        while (ss >> segment) { // Handles all whitespace types to seperate it out.
            try {
                numbers.push_back(std::stoi(segment));
            }
            catch (...) {
                SORT_LOG("Error: Invalid integer");
                return false;
            }
        }

        if (numbers.empty()) {
            SORT_LOG("Error: No numbers provided");
            return false;
        }

        return true;
    }

    void NormaliseInputsForEngine(engine::SortingData& sortingData, const Inputs& inputs) {
        sortingData.sortingAlgorithm = inputs.sortingAlgorithm;
        sortingData.isAscending = inputs.isAscending;

        SplitNumberList(sortingData.numberList, inputs.numberList);
    }

	void GatherSortingData(engine::SortingData& sortingData) {
        Inputs inputs = { engine::SortingAlgorithm::NONE, false, "" };
        std::vector<int32_t> numberList = {};

        bool valid = false;
        while (!valid) {
            valid = AskInputs(inputs);

            if (!valid) {
                SORT_LOG("Error: Invalid inputs. Please enter again.\n\n");
                continue;
            }

            valid = SplitNumberList(numberList, inputs.numberList);

            if (!valid) {
                SORT_LOG("Error: Invalid list of numbers. Please enter again.\n\n");
                continue;
            }
        }

        NormaliseInputsForEngine(sortingData, inputs);
	}
    
    void Run() {
        engine::SortingData sortingData = { engine::SortingAlgorithm::NONE, true, {} };

		GatherSortingData(sortingData);
        
        engine::SortList(sortingData);

		SORT_LOG("\nInfo: List Sorted\n\n");

        engine::OutputList(sortingData);
    }

}
