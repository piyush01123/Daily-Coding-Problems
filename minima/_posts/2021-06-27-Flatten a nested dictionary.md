---
layout: post
title: "Flatten a nested dictionary"
categories: misc
---


This problem was asked by Stripe.

Write a function to flatten a nested dictionary. Namespace the keys with a period.

For example, given the following dictionary:
```
{
    "key": 3,
    "foo": {
        "a": 5,
        "bar": {
            "baz": 8
        }
    }
}
```
it should become:
```
{
    "key": 3,
    "foo.a": 5,
    "foo.bar.baz": 8
}
```
You can assume keys do not contain dots in them, i.e. no clobbering will occur.


My Solution(C++):
```

#include <string>

struct nested_dict{
  std::string key;
  nested_dict next; //could be int
};
```


My Solution(Python):
```

def unnest(dic):
    final = dict()
    def unnestutil(dic):
        for key, val in dic.items():
            if isinstance(val, int):
                final[key] = val
            else:
                dic2 = dict()
                for k, v in val.items():
                    dic2[key+'.'+k] = v
                unnestutil(dic2)
    unnestutil(dic)
    return final

dic = {
    "key": 3,
    "foo": {
        "a": 5,
        "bar": {
            "baz": 8
        }
    }
}

print(unnest(dic))
```
