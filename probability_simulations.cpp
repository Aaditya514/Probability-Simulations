#include <iostream>
#include <random>
#include <map>
#include <vector>
#include <string>
#include <cmath>
#include <ctime>

using namespace std;

// Coin Toss Simulation
void coinToss(int trials) {
    mt19937 gen(random_device{}());
    uniform_int_distribution<> dist(0, 1);

    int heads = 0;
    for (int i = 0; i < trials; ++i)
        heads += dist(gen);

    cout << "\n[Coin Toss Simulation]\n";
    cout << "Heads: " << heads << " (" << (double)heads / trials * 100 << "%)\n";
    cout << "Tails: " << trials - heads << " (" << (double)(trials - heads) / trials * 100 << "%)\n";
}

// Dice Roll Simulation
void diceRoll(int trials) {
    mt19937 gen(random_device{}());
    uniform_int_distribution<> dist(1, 6);
    map<int, int> freq;

    for (int i = 0; i < trials; ++i)
        freq[dist(gen)]++;

    cout << "\n[Dice Roll Simulation]\n";
    for (int i = 1; i <= 6; ++i)
        cout << "Face " << i << ": " << freq[i] << " times (" << (double)freq[i] / trials * 100 << "%)\n";
}

// Normal Distribution Sampling
void sampleNormalDistribution(int n, double mean = 0.0, double stddev = 1.0) {
    mt19937 gen(random_device{}());
    normal_distribution<> dist(mean, stddev);

    cout << "\n[Normal Distribution Sample] (first 10 values)\n";
    for (int i = 0; i < min(n, 10); ++i)
        cout << "Sample " << i + 1 << ": " << dist(gen) << endl;
}

// Naive Bayes Text Classifier (Bag-of-Words)
class NaiveBayes {
    map<string, int> classCount;
    map<string, map<string, int>> wordCount;
    int totalDocs = 0;

public:
    void train(const vector<pair<string, string>>& dataset) {
        for (auto it = dataset.begin(); it != dataset.end(); ++it) {
            const string& cls = it->first;
            const string& word = it->second;
            classCount[cls]++;
            wordCount[cls][word]++;
            totalDocs++;
        }
    }

    string predict(const string& word) {
        double maxProb = -1.0;
        string result = "Unknown";

        for (auto it = classCount.begin(); it != classCount.end(); ++it) {
            const string& cls = it->first;
            double prior = (double)classCount[cls] / totalDocs;
            double likelihood = (double)(wordCount[cls][word] + 1) / (classCount[cls] + 1); // Laplace smoothing
            double posterior = prior * likelihood;

            if (posterior > maxProb) {
                maxProb = posterior;
                result = cls;
            }
        }
        return result;
    }
};

// Markov Chain Simulator
void simulateMarkovChain(const map<string, map<string, double>>& transitionMatrix, string startState, int steps) {
    mt19937 gen(random_device{}());
    string currentState = startState;

    cout << "\n[Markov Chain Simulation]\n";
    for (int i = 0; i < steps; ++i) {
        cout << "Step " << i << ": " << currentState << endl;
        double r = uniform_real_distribution<>(0, 1)(gen);
        double cumulative = 0.0;

        for (auto& entry : transitionMatrix.at(currentState)) {
            cumulative += entry.second;
            if (r <= cumulative) {
                currentState = entry.first;
                break;
            }
        }
    }
}

int main() {
    // Run Simulations
    coinToss(1000);
    diceRoll(1000);
    sampleNormalDistribution(1000, 0, 1);

    // Naive Bayes Demo
    NaiveBayes nb;
    nb.train({
        {"spam", "buy"}, {"spam", "cheap"}, {"ham", "hello"}, {"ham", "friend"}, {"spam", "offer"}
    });
    cout << "\n[Naive Bayes Prediction]\n";
    cout << "Word 'buy' → Class: " << nb.predict("buy") << endl;
    cout << "Word 'hello' → Class: " << nb.predict("hello") << endl;

    // Markov Chain Example
    map<string, map<string, double>> transitionMatrix = {
        {"Sunny", {{"Sunny", 0.8}, {"Rainy", 0.2}}},
        {"Rainy", {{"Sunny", 0.4}, {"Rainy", 0.6}}}
    };
    simulateMarkovChain(transitionMatrix, "Sunny", 10);

    return 0;
}
