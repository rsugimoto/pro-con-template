import math

def getRate(P):
    N = len(P)
    numerator = 0
    denominator = 0
    for i, p in enumerate(reversed(P), 1):
        numerator += 2**(p/800) * 0.9**i
        denominator += 0.9**i
    adjust = 1200*((1-.81**N)**.5/(1-.9**N)-1)/(19**.5-1)
    rate = 800*math.log2(numerator/denominator) - adjust
    if rate <= 400:
        rate = 400/(math.e**(1-rate/400))
    rate = math.floor(rate+.5)
    return rate

def rate2text(rate):
    texts=("灰色 Eランク (-399)", "茶色 Dランク (400-799)", "緑色 Cランク (800-1199)",
        "水色 Bランク (1200-1599)", "青色 Aランク (1600-1999)", "黄色 Sランク (2000-2399)",
        "橙色 SSランク (2400-2799)", "赤色 SSSランク (2800-)")
    if rate >= 3200: rate = 3199
    return texts[rate//400]

P = [int(p) for p in input("今までのパフォーマンスを、新しい順に空白区切りで入力してください。\n").split()]
est = sum(P)/len(P)
print("平均："+str(int(est)), "現在のレート:"+str(getRate(P)))
est = int(input("今後のパフォーマンス推定値を入力してください。\n"))
print("今後 n 回、パフォーマンス",int(est),"であった場合のレートは")
for n in range(1, 21):
    P.append(est)
    rate = getRate(P)
    print("n = %2d : %4d  "%(n, rate), rate2text(rate))
