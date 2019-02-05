
readme=[r.strip() for r in open('README.md', 'r').readlines()[7:73]]
lines = []
for i, line in enumerate(readme):
    if i<10:
        line = line[2:]
    else:
        line = line[3:]
    pid = i+1
    parts = line.split(' - ')
    qc = parts[0]
    i1 = qc.index('(')
    i2 = qc.index(')')
    q = qc[1:i1-1]
    c=qc[i1+1:i2]
    status = parts[1]
    lang = parts[2] if status=='Solved' else ''
    print({'PID': pid, 'q': q, 'c': c, 'stat': status, 'lang': lang})
    lines.append(
    '| ' + str(pid) + ' | [' +  q + '](' + str(pid) + ')' + ' | ' + c + ' | ' + status + ' | ' + lang + ' |'
    )

to_write = """| Problem ID | Problem        | Asked by           | Solved status  | Solved in |
|:---:|:-------------:|:-------------:|-------------:|-------------:|
""" + '\n'.join(lines)
open('dummy.md', 'w').write(to_write)

# readme_one = [r.replace('(', '| ').replace(')', ' |').replace('-', '|').replace('\n', ' |\n') for r in readme]
# readme_two = readme_one[:11]
# readme_three = readme_one[11:]
# readme4 = ['|'+ str(i+1) + ' |' + r[2:] for i, r in enumerate(readme_two)]
# readme5 = ['| '+ str(i+11) + ' | ' +r[3:] for i, r in enumerate(readme_three)]
# new = """| Problem ID | Problem        | Asked by           | Solved status  | Solved in |
# |:---:|:-------------:|:-------------:|-------------:|-------------:|
# """
# new+=''.join(readme4)
# new+=''.join(readme5)
# open('dummy.md','w').write(new)
