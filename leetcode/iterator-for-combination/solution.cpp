class CombinationIterator {
private:
    int charactersLength;
    std::string characters;
    int combinationLength;
    std::vector<int> combinations;
    bool hasNextCombination;
private:
    std::string getCombination() {
        std::string value = "";
        for (auto combination: combinations) {
            value += characters[combination];
        }

        return value;
    }
public:
    CombinationIterator(std::string characters, int combinationLength) {
        this->characters = std::move(characters);
        this->combinationLength = combinationLength;
        charactersLength = this->characters.size();

        hasNextCombination = true;
        combinations.resize(combinationLength);
        for (auto i = 0; i < combinationLength; ++i) {
            combinations[i] = i;
        }
    }

    std::string next() {
        if (!hasNext()) {
            return "";
        }

        std::string value = getCombination();

        // Generate new combinations
        // Max value of index i in combinations array: n - k + i
        int i = combinationLength - 1;
        bool hasCombination = false;
        while (i >= 0) {
            if (combinations[i] == charactersLength - combinationLength + i) {
                --i;
            }
            else {
                ++combinations[i];
                for (int j = i + 1; j < combinationLength; ++j) {
                    combinations[j] = combinations[j - 1] + 1;
                }
                hasCombination = true;
                break;
            }
        }
        hasNextCombination = hasCombination;

        return value;
    }

    bool hasNext() {
        return hasNextCombination;
    }
};

/**
 * Your CombinationIterator object will be instantiated and called as such:
 * CombinationIterator* obj = new CombinationIterator(characters, combinationLength);
 * string param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */

