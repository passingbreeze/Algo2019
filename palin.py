import time

def revStr(stmt):
    return stmt[::-1]

def isPalin(stmt):
    mid = len(stmt)//2
    if len(stmt)&1 :
        diff=1
    else :
        diff=0
    return stmt[:mid] == revStr(stmt[mid+diff:])

def mkPalin(stmt):
    for i in range(len(stmt)):
        yield stmt[:i]+stmt[i+1:]

def isPseudopalin(stmt):
    if isPalin(stmt):
        return "1\n"
    else :
        for s in mkPalin(stmt):
            if isPalin(s):
                return "2\n"
        return "3\n"

def main():
    result = ""
    with open("palin.inp", "r") as inp:
        strNum = int(inp.readline())
        while strNum > 0:
            result += isPseudopalin(inp.readline().rstrip())
            strNum -= 1

    with open("palin.out", "w") as out:
        out.write(result.rstrip())
    return

if __name__ == '__main__':
    beg = time.time()
    main()
    print("--- %.3f sec(s) ---" % (time.time()-beg))