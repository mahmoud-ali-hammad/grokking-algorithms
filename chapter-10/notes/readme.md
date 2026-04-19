# 📘 Grokking Algorithms — Chapter 10 Notes

## k-Nearest Neighbors (KNN)

This chapter introduces **KNN**, a simple and practical machine learning algorithm for both **classification** and **regression**.

---

## 1) What this chapter teaches

- How KNN classifies items (e.g., orange vs grapefruit)
- How KNN performs regression (predicting a number)
- What feature extraction is
- Why feature selection quality matters
- Real-world uses and limitations of KNN

---

## 2) KNN in one idea

To predict something for a new item:

1. Represent it as numeric features
2. Find the `k` closest known examples
3. Use their labels/values to infer the answer

---

## 3) Two uses of KNN

### A) Classification

Predict a category/class (e.g., `"orange"` or `"grapefruit"`).

Rule:

- Majority vote among the `k` nearest neighbors.

### B) Regression

Predict a numeric value (e.g., movie rating, bread demand).

Rule:

- Average (or weighted average) of target values of nearest neighbors.

---

## 4) Feature extraction

Feature extraction means converting an object to a numeric vector.

Examples:

- Fruit → `[size, redness]`
- User taste → `[action, comedy, romance, horror, sci-fi ratings]`
- Bakery day → `[weather_score, weekend_flag, game_flag]`

KNN depends heavily on how good these features are.

---

## 5) Distance and similarity

A common distance in KNN:

- **Euclidean distance**

\[
d(\mathbf{x},\mathbf{y}) = \sqrt{\sum_i (x_i - y_i)^2}
\]

Smaller distance = more similar.

Alternative mentioned:

- **Cosine similarity** (often better when scale differences exist in ratings behavior)

---

## 6) Choosing good features

Good features:

- Correlate with the prediction target
- Are not strongly biased or irrelevant
- Capture meaningful differences between samples

Bad features hurt KNN performance even if algorithm is correct.

---

## 7) Strengths and limitations

### Strengths

- Simple to understand and implement
- No heavy training phase (lazy learner)
- Works for both classification and regression
- Good baseline model

### Limitations

- Slow at prediction on very large datasets (must compare with many points)
- Sensitive to noisy/irrelevant features
- Sensitive to feature scaling
- Choice of `k` strongly affects performance

---

## 8) Practical notes

- Normalize/standardize features before KNN.
- Try several values of `k` and validate.
- Weighted KNN can improve results by giving closer neighbors more influence.
- For huge data, use indexing/approximate nearest-neighbor methods.

---

## 9) Key takeaways

- KNN = “look at nearby examples and infer from them.”
- Classification predicts class labels.
- Regression predicts numeric outputs.
- Feature engineering is often more important than algorithm choice.
- KNN is a great first model for many practical tasks.
