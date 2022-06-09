fin = open('postfix.in')
fout = open('postfix.out', 'w')

def sum(self):
    self.append(int(self.pop()) + int(self.pop()))

def sub(self):
    self.append(int(self.pop())*(-1) + int(self.pop()))

def mul(self):
    self.append(int(self.pop()) * int(self.pop()))
steck = []
line = [s.strip() for s in fin.readline().split()]
for a in line:
    if (a != '+') and (a != '-') and (a != '*') and (a != ' '):
        steck.append(a)
    else:
        if len(steck) > 1:
            if a == '+':
                sum(steck)
            elif (a == '-'):
                sub(steck)
            else:
                mul(steck)
print(steck.pop(), file=fout)
fout.close()