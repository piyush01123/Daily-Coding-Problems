
import pandas as pd
import collections
import os,glob
from datetime import timedelta, datetime

lines = open("README.md",'r').readlines()
fields = ["id","company","status","lang","title","url"]
df = {k:[] for k in fields}

for idx in range(9,233):
    line = lines[idx]
    # print(line)
    items = [item.strip() for item in line.split('|')[1:-1]]
    items.append(items[1][1:-6])
    items.append(items[1][-4:-1])
    items.pop(1)
    # print(idx,len(items))
    for k,v in zip(fields,items):
        df[k].append(v)


df = pd.DataFrame(df)
f = os.path.isfile
ctr = 0
date = datetime.today()

for _,row in df.iterrows():
    id,company,status,lang,title,url = row.tolist()
    title = title.replace('<','').replace('>','').replace('/','')
    prob_file = os.path.join(url,"README.md")
    prob = open(prob_file,'r').read()
    sol_cpp_file = os.path.join(url,"sol.cpp")
    sol_py_file = os.path.join(url,"sol.py")
    if not f(sol_cpp_file) and not f(sol_py_file):
        continue
    post =  "---\nlayout: post\ntitle: \"{}\"\ncategories: misc\n---\n\n".format(title)
    post = post + prob
    if f(sol_cpp_file):
        sol_cpp = open(sol_cpp_file,'r').read()
        post = post + '\n\n' + "My Solution(C++):\n```\n" + sol_cpp + "```\n"
    if f(sol_py_file):
        sol_py = open(sol_py_file,'r').read()
        post = post + '\n\n' + "My Solution(Python):\n```\n" + sol_py + "```\n"
    post = post.replace("{{","{ {").replace("}}","} }")
    date = date-timedelta(1)
    dtstr = date.strftime("%Y-%m-%d")
    # fh = open("posts/{}-{}-{}.md".format(dtstr, '%03d' %ctr, title),'w')
    fh = open("posts/{}-{}.md".format(dtstr, title),'w')
    ctr += 1
    fh.write(post)
    fh.close()
