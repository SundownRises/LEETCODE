class Solution {
public:
    int maximumPopulation(vector<vector<int>>& logs) {
    unordered_map<int, int> yearPopulationChange;

    for (const auto& log : logs) {
        int birth = log[0];
        int death = log[1];
        yearPopulationChange[birth]++;
        yearPopulationChange[death]--;
    }

    int maxPopulation = 0;
    int currentPopulation = 0;
    int earliestYear = INT_MAX;

    for (int year = 1950; year <= 2050; ++year) {
        currentPopulation += yearPopulationChange[year];
        if (currentPopulation > maxPopulation) {
            maxPopulation = currentPopulation;
            earliestYear = year;
        }
    }

    return earliestYear;
}

};