
RL - David Silver Videos - Lecture Notes
-----------------------------------------
Reward, State, Action
Reward has to be scalar. [You cant have conflicting goals. You have to weight them if you do.] You have to be able to line them up on an axis to compare.

A state is called "Markov state" if P[S(t+1) | S(t)] = P[S(t+1) | S(1), S(2), .. S(t)]
You can describe above equation as "Future is independent of past given the present."
i.e.
Once the state is known, the history can be thrown away.
H(1..t) -> S(t) -> H(t+1..infinity)
State is a sufficient statistic of the future.

Example of Markov and Non-Markov state:
If state only has position it is Non-Markov because where it will be also depends on where it was earlier to know which direction it is moving.
Whereas in contrast if it has everything that determines the position like curr. position, wind vel., heli. vel., etc. it becomes a Markov state because then we can determine future state based only on present.

Environments can be fully (Markov Decision Process; MDP) or partially observable (agent indirectly observes the environment like a robot with a camera, A trading agent that only observes current prices, a poker playing agent; POMDP).
