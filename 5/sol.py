def cons(a, b):
  def pair(f):
    return f(a, b)
  return pair

def add(a, b):
  return a+b
def sub(a, b):
  return a-b

def car(pair):
  return (pair(add) + pair(sub))//2

def cdr(pair):
  return (pair(add) - pair(sub))//2

p = cons(3, 8)
print(car(p))
print(cdr(p))
