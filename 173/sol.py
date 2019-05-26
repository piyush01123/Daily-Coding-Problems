
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
