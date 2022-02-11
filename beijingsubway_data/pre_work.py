d = dict()
f = open("beijing-subway.txt", "r", encoding="ANSI")
w = open("station.txt", "w", encoding="ANSI")
cnt = 0
tot = 0
for s in f:
    if s == "\n":
        continue
    if cnt == 0:
        cnt += 1
    elif cnt == 1:
        cnt += 1
    elif cnt == 2:
        cnt += 1
        tot = int(s)
        continue
    if cnt == 3 and tot > 0:
        s = s.split()
        if s[0] not in d:
            d[s[0]] = list()
        t = int(s[1])
        for i in range(t):
            if int(s[i + 2]) not in d[s[0]]:
                d[s[0]].append(int(s[i + 2]))
        tot -= 1
    if cnt == 3 and tot == 0:
        cnt = 0
num = 0
for ele in d:
    num += 1
    w.write(str(num) + " ")
    w.write(ele + " " + str(len(d[ele])))
    d[ele].sort()
    for station in d[ele]:
        w.write(" " + str(station))
    w.write("\n")
f.close()
w.close()
