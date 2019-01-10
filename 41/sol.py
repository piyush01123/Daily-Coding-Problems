
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
