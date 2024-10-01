
physics_scores = [15, 12, 8, 8, 7, 7, 7, 6, 5, 3]
history_scores = [10, 25, 17, 11, 13, 17, 20, 13, 9, 15]


mean_physics = sum(physics_scores) / len(physics_scores)
mean_history = sum(history_scores) / len(history_scores)


numerator = sum((physics_scores[i] - mean_physics) * (history_scores[i] - mean_history) for i in range(len(physics_scores)))
denominator = sum((physics_scores[i] - mean_physics) ** 2 for i in range(len(physics_scores)))
b1 = numerator / denominator


b0 = mean_history - b1 * mean_physics


physics_score_to_predict = 10
predicted_history_score = b0 + b1 * physics_score_to_predict

print(f'{predicted_history_score:.1f}')
