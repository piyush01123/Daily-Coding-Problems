
"""
Usage: python pwned.py correcthorsebatterystaple
"""

import hashlib
import requests
import sys

def hash(pw):
	return hashlib.sha1(pw.encode('utf-8')).hexdigest().upper()

def pwn(hsh):
	h1 = hsh[:5]
	h2 = hsh[5:]
	A = requests.get('https://api.pwnedpasswords.com/range/' + h1).text.split('\n')
	res = [a for a in A if h2 in a]
	if len(res)==0:
		return "Great you chose a great password"
	num = int(res[0].split(':')[1].strip())
	return "This password has been used %d times" %num


if __name__=='__main__':
	pw = sys.argv[1]
	hsh = hash(pw)
	print('Hash = %s' %hsh)
	print(pwn(hsh))
