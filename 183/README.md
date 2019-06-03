This problem was asked by Twitch.

Describe what happens when you type a URL into your browser and press Enter.

Ans -
1. URL is typed.
2. Browser checks the cache for DNS record to find the corresponding IP address of the typed URL. Order of search:
Browser cache -> OS cache -> Router cache -> ISP cache
3. If the requested URL is not in any cache, the ISP's DNS server initiates a DNS query to find the IP. This is done using the domain architecture. For example; for the URL maps.google.com, ISP's DNS server (acting as DNS recursor here) contacts the root name server, which directs it to .com name server which directs it to google.com name server which serves the IP address for maps.google.com.
4. Browser initiates a TCP connection with the server (using SYN/ACK packets).
5. Browser sends HTTP requests (GET in this case)
6. Server sends out the response with status codes - 1xx(information msg), 2xx(success), 3xx(redirect), 4xx(error on client side), 5xx(error on server side).
7. Browser displays the HTML content and caches it.
