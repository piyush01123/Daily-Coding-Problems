---
layout: post
title: "Flight itinerary"
categories: misc
---

This problem was asked by Facebook.

Given an unordered list of flights taken by someone, each represented as (origin, destination) pairs, and a starting airport, compute the person's itinerary. If no such itinerary exists, return `null`. If there are multiple possible itineraries, return the lexicographically smallest one. All flights must be used in the itinerary.

For example, given the list of flights `[('SFO', 'HKO'), ('YYZ', 'SFO'), ('YUL', 'YYZ'), ('HKO', 'ORD')]` and starting airport `'YUL'`, you should return the list `['YUL', 'YYZ', 'SFO', 'HKO', 'ORD']`.

Given the list of flights `[('SFO', 'COM'), ('COM', 'YYZ')]` and starting airport `'COM'`, you should return `null`.

Given the list of flights `[('A', 'B'), ('A', 'C'), ('B', 'C'), ('C', 'A')]` and starting airport `'A'`, you should return the list `['A', 'B', 'C', 'A', 'C']` even though `['A', 'C', 'A', 'B', 'C']` is also a valid itinerary. However, the first one is lexicographically smaller.


My Solution(Python):
```

def flightItinerary(flights: list, startingPoint: str) -> list:
    H = {}
    for flight in flights:
        start, end = flight
        if start not in H:
            H[start] = [end]
        else:
            H[start].append(end)
            H[start].sort()
    print('H = ', H)
    itinerary = [startingPoint]
    while H:
        start = itinerary[-1]
        possibleEnds = H[start]
        end = possibleEnds.pop(0)
        itinerary.append(end)
        if not H[start]:
            del H[start]
    return itinerary

if __name__ =='__main__':
    flights = [('SFO', 'HKO'), ('YYZ', 'SFO'), ('YUL', 'YYZ'), ('HKO', 'ORD')]
    print(flightItinerary(flights, 'YUL'))
    flights = [('A', 'B'), ('A', 'C'), ('B', 'C'), ('C', 'A')]
    print(flightItinerary(flights, 'A'))
```
