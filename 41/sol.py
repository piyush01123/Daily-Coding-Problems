
def flightItineray(flights: list) -> list:
    startingPoint = flights[0][0]
    H = {}
    for flight in flights:
        start, end = flight
        if start not in H:
            H[start] = [end]
        else:
            H[start].append(end)
            H[start].sort()
    iteneray = [startingPoint]
    while H:
        start = iteneray[-1]
        possibleEnds = H[start]
        end = possibleEnds.pop(0)
        itinerary.append(chosenFlight[0])
        if not H[start]:
            del H[start]
    return iteneray

if __name__ =='__main__':
    flights] = [('SFO', 'HKO'), ('YYZ', 'SFO'), ('YUL', 'YYZ'), ('HKO', 'ORD')]
    print(flightItineray(flights))
    flights = [('A', 'B'), ('A', 'C'), ('B', 'C'), ('C', 'A')]
    print(flightItineray(flights))
