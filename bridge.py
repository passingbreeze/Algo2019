import math, time, sys

def vecLength(a,b):
    return math.sqrt((a[0]-b[0])**2+(a[1]-b[1])**2+(a[2]-b[2])**2)

def heronTri(a,b,c):
    return math.sqrt(((a+b+c)/2.0)*(((a+b+c)/2.0)-a)*(((a+b+c)/2.0)-b)*(((a+b+c)/2.0)-c))

def main():
    beg = time.time()
    with open("bridge.inp", "rb") as fin, open("bridge.out", "w") as fout:
        a,b,p = (tuple(map(int, fin.readline().split())) for i in range(3))
        # print(a,b,c)
        m = ((a[0]+b[0])/2.0, (a[1]+b[1])/2.0, (a[2]+b[2])/2.0)
        pa = vecLength(p,a)
        pb = vecLength(p,b)
        ab = vecLength(a,b)
        pm = vecLength(p,m)
        # print(pa, pm, pb, ab)
        result = (2.0*heronTri(ab,pa,pb))/ab
        fout.write(str(int(result)+1))

    sys.stdout.write("----%.3f sec(s)----"%(time.time()-beg))
    sys.stdout.flush()
    return

if __name__ == '__main__':
    main()