import math

def vecLength(a,b):
    return math.sqrt((a[0]-b[0])**2+(a[1]-b[1])**2+(a[2]-b[2])**2)

def heronTri(a,b,c):
    return math.sqrt(((a+b+c)/2.0)*(((a+b+c)/2.0)-a)*(((a+b+c)/2.0)-b)*(((a+b+c)/2.0)-c))

def isObtuse(a,b,c):
    return ((a**2+b**2-c**2)/(2.0*a*b))<=0

def main():
    with open("bridge.inp", "rb") as fin, open("bridge.out", "w") as fout:
        a,b,p = (tuple(map(int, fin.readline().split())) for i in range(3))
        pa = vecLength(p,a)
        pb = vecLength(p,b)
        ab = vecLength(a,b)
        if isObtuse(pa,ab,pb) or isObtuse(pb,ab,pa):
            result = min(pa,pb)
        else:
            result = (2.0*heronTri(ab,pa,pb))/ab
        fout.write(str(int(result)+1))
    return

if __name__ == '__main__':
    main()
