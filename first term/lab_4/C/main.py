fin = open('brackets.in')
fout = open('brackets.out', 'w')
alf = '()[]'
for line in fin:
    line = [str(x) for x in line if x in alf]
    if line[0] == ')' or line[0] == ']':
        print ('NO', file = fout)
    else:
        steck = [line[0]]
        for j in range (1, len(line)):
            if line[j] == '(' or line[j] == '[':
                steck.append(line[j])
            else:
                if len(steck) > 0:
                    if ((line[j] == ']') and (steck[len(steck) - 1] == '(')):
                        break
                    elif ((line[j] == ')') and (steck[len(steck) - 1] == '[')):
                        break
                    else:
                        steck.pop()
                else:
                    steck.append(line[j])
                    break
        if len(steck) == 0:
            print ('YES', file = fout)
        else:
            print ('NO', file = fout)
fout.close()