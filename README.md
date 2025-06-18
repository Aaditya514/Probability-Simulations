
# 🎲 Probability Simulations in C++

This project showcases fundamental concepts of probability theory and statistical simulation implemented in modern C++.

---

## ✨ Features

- ✅ **Coin Toss Simulation** – Calculates frequencies of heads and tails over multiple trials.
- 🎲 **Dice Roll Simulation** – Simulates dice throws and computes relative frequencies of each face.
- 🔁 **Normal Distribution Sampling** – Generates values from a normal distribution using `<random>`.
- 📊 **Naive Bayes Classifier** – Simple bag-of-words model for word classification using conditional probabilities.
- 🔄 **Markov Chain Simulation** – Models state transitions using a stochastic matrix.

---

## 🧪 Example Output

```
[Coin Toss Simulation]
Heads: 503 (50.3%)
Tails: 497 (49.7%)

[Dice Roll Simulation]
Face 1: 168 times (16.8%)
Face 2: 160 times (16.0%)
...

[Normal Distribution Sample]
Sample 1: -0.84
Sample 2: 0.42
...

[Naive Bayes Prediction]
Word 'buy' → Class: spam
Word 'hello' → Class: ham

[Markov Chain Simulation]
Step 0: Sunny
Step 1: Rainy
Step 2: Sunny
...
```

---

## 🛠 Build & Run

### Requirements
- C++11 or higher
- g++

### Compile & Run
```bash
g++ -std=c++11 src/probability_simulations.cpp -o probsim
./probsim
```

---

## 📂 Folder Structure

```
probability-simulations-cpp/
├── src/
│   └── probability_simulations.cpp
├── README.md
└── Makefile
```

---

## 📚 Key Concepts

### 📊 Naive Bayes (Laplace Smoothing)

P(C | x) ∝ P(C) × (count(x, C) + 1) / (count(C) + V)

Where:
- P(C): Prior probability of class C
- count(x, C): Frequency of feature x in class C
- V: Number of unique features (vocabulary size)


### 🔄 Markov Chain

P(Xₜ₊₁ = sⱼ | Xₜ = sᵢ) = Tᵢⱼ

Where:
- Xₜ: the state at time t
- Tᵢⱼ: the probability of transitioning from state sᵢ to sⱼ

---

Made with ❤️ in C++ for probability enthusiasts!
