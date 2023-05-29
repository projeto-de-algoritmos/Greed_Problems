#include <iostream>
#include <vector>
#include <set>

using namespace std;

struct Toy {
    int quantity;
    int weight;
};

int findBestPack(const vector<Toy>& items, set<int>& bestItems, int weightLimit);

int main() {
    int numCases;
    cin >> numCases;

    while (numCases--) {
        int numPacks;
        cin >> numPacks;

        vector<Toy> toys;
        toys.push_back({0, 0});

        for (int i = 0; i < numPacks; i++) {
            int quantity, weight;
            cin >> quantity >> weight;
            toys.push_back({quantity, weight});
        }

        const int maximumWeight = 50;
        set<int> selectedItems;
        int totalQuantity = findBestPack(toys, selectedItems, maximumWeight);

        cout << totalQuantity << " brinquedos" << endl;

        int totalWeight = 0;
        for (auto index : selectedItems) {
            totalWeight += toys[index].weight;
        }
        cout << "Peso: " << totalWeight << " kg" << endl;

        int remainingPacks = numPacks - selectedItems.size();
        cout << "sobra(m) " << remainingPacks << " pacote(s)" << endl << endl;
    }

    return 0;
}

int findBestPack(const vector<Toy>& items, set<int>& bestItems, int weightLimit) {
    const int n = items.size();
    int bestValues[n][weightLimit + 1];
    set<int> solutionSets[n][weightLimit + 1];
    set<int> emptySet;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j <= weightLimit; j++) {
            bestValues[i][j] = 0;
            solutionSets[i][j] = emptySet;
        }
    }

    for (int i = 1; i < n; i++) {
        for (int weight = 1; weight <= weightLimit; weight++) {
            int itemWeight = items[i].weight;

            if (weight < itemWeight) {
                bestValues[i][weight] = bestValues[i - 1][weight];
                solutionSets[i][weight] = solutionSets[i - 1][weight];
            } else {
                int remainingWeight = weight - itemWeight;
                int totalQuantity = items[i].quantity + bestValues[i - 1][remainingWeight];

                if (totalQuantity > bestValues[i - 1][weight]) {
                    bestValues[i][weight] = totalQuantity;
                    solutionSets[i][weight] = solutionSets[i - 1][remainingWeight];
                    solutionSets[i][weight].insert(i);
                } else {
                    bestValues[i][weight] = bestValues[i - 1][weight];
                    solutionSets[i][weight] = solutionSets[i - 1][weight];
                }
            }
        }
    }

    bestItems.swap(solutionSets[n - 1][weightLimit]);
    return bestValues[n - 1][weightLimit];
}
