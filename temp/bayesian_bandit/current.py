from scipy.stats import beta
import numpy as np

#real probs used to simulate reality
real_probs = {'A': 0.3, 'B': 0.2, 'C': 0.25}

outcomes = {machine: {"success": 1e-5, "failure": 1e-5} for machine in ["A", "B", "C"]}

num_trials = 10

for trial in range(num_trials):
    prob_a = beta.rvs(outcomes["A"]["success"], outcomes["A"]["failure"], size=1)[0]
    prob_b = beta.rvs(outcomes["B"]["success"], outcomes["B"]["failure"], size=1)[0]
    prob_c = beta.rvs(outcomes["C"]["success"], outcomes["C"]["failure"], size=1)[0]
    print(outcomes, prob_a, prob_b, prob_c)
    selection = np.argmax([prob_a, prob_b, prob_c])
    prob_max = np.max([prob_a, prob_b, prob_c])
    if prob_max > (1-real_probs[["A", "B", "C"][selection]]):
        outcomes[["A", "B", "C"][selection]]["success"] += 1
    else:
        outcomes[["A", "B", "C"][selection]]["failure"] += 1
    

