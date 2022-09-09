'''
    Author : MESRAR Hamza - @ez7m.z - 🦂
    💬 : mesrarhamza48@gmail.com
'''

from cmath import nan
import matplotlib.pyplot as pt

class Serie:
    
    #function __init__ define the class constructor
        # t : list of time
        # y : list of values
    def __init__(self, t, y):
        self.t = t
        self.y = y
        
    # Calculate the average
     
    def Ybar(self, n):
        return sum(self.y)/n
    
    def tbar(self, n):
        return sum(self.t)/n

    # calculate covariance 

    def Cov(self, n):
        term1 = 0
        for i in range(n):
            term1 = term1 + (self.y[i] * self.t[i])
        return term1 -  n * self.Ybar(n) * self.tbar(n)

    # calculate variance 

    def Var(self, n):
        term1= 0
        for i in range(n):
            term1 = term1 + (self.t[i] * self.t[i])
        return term1 - n * (self.tbar(n) * self.tbar(n))
    
    # to calculate the trend we must calculate first a and b of : y = a*t+b
    
    def a(self,n):
        return self.Cov(n) / self.Var(n)

    def b(self, n):
        return self.Ybar(n) - (self.a(n) * self.tbar(n))


    def Trend(self, n):
        T = []
        a = self.a(n)
        b = self.b(n)
        for i in range(n):
            T.append( a * self.t[i] + b )
        return T

    # Seasonal Coefficient

    def CoeS(self, n):
        CS = []
        T = self.Trend(n)
        for i in range(n):
            CS.append(self.y[i] - T[i])
        return CS

    # Corrected Seasonal Coefficient

    def CoeSAju(self, n):
        Temp = []
        l = self.CoeS(n)
        moy = sum(l)/n
        for i in range(n):
            Temp.append(l[i] - moy)
        return Temp
    
    # The CVS Series

    def CVS(self, n):
        Temp = []
        for i in range(n):
            Temp.append(self.y[i] - self.CoeSAju(n)[i])
        return Temp
    
    # The Trend with MMC

    def MMC(self,n):
        temp = []
        res = 0
        if n%2!=0:
            k = int((n-1)/2)
            for t in range(k,len(self.y)-k):
                res = 0 
                for i in range (-k,k+1):
                    res = res + self.y[t+i]
                res = res / n
                temp.append(res)
        elif n%2==0:
            k = int(n/2)
            for t in range(k,len(self.y)-k):
                res = 0
                for j in range(-k+1,k):
                    res = res + self.y[t+j]
                res = (res + (self.y[t-k]+self.y[t+k])*0.5)/n
                temp.append(res)
        for j in range(k):
            temp.insert(j,0)
            temp.append(0)
        return temp,k
    
    # Corrected Seasonal Coefficient using MMC

    def Coefs_MMC_Corr(self,n):
        temp = []
        res , _ = self.MMC(n)
        moy = sum(res)/len(res)
        for i in range(len(res)):
            temp.append(res[i]-moy)
        return temp
    
    # The CVS Series with MMC

    def CVS_MMC(self,n):
        temp = []
        res = self.Coefs_MMC_Corr(n)
        for i in range(len(res)):
            temp.append(self.y[i]-res[i])
        return temp

    # Seasonal Coefficient using MMC

    def CoefS_MMC(self,n):
        final = []
        res , _ = self.MMC(n)
        for i in range(0,int(len(self.y)/4)):
            temp = []
            for j in range(i,len(self.y),4):
                temp.append(self.y[j] - res[j])
            final.append(sum(temp)/len(temp))
        return final

    # method to see the predictions

    def Prevision(self):
        S = self.CoefS_MMC(4)
        t1 = [17,18,19,20]
        T = []
        prev = []
        a = self.a(16)
        b = self.b(16)
        for i in t1:
            T.append(a * i + b)
        for i in range(4):
            prev.append(T[i] + S[i])
        return t1,prev,T
    
    # method for plotting graphs

    def PlostSerie(self,n):
        pt.title("Additive Chronological Series")
        pt.xlabel("Temp in Trimister")
        pt.ylabel("Sales")
        X = self.t
        Y = self.y
        t = self.Trend(n)
        mmc , _ = self.MMC(4)
        mmc[:] = [x if x != 0 else nan for x in mmc]
        t2,previs,T = self.Prevision()
        X1 = X + t2
        Y2 = Y + previs
        t1 = t + T
        pt.grid()
        pt.plot(X1,Y2,"o-",color="brown",label="Prevision")
        pt.plot(X,Y,"o-",color="blue",label="Original")
        pt.plot(X1,t1,"-", color="orange",label="Predicted Trend")
        pt.plot(X,t,"-", color="red",label="Trend")
        pt.plot(X,mmc,"o-",color="green",label="MMC")
        pt.legend()
        pt.show()
        
        
        
if __name__ == 'outils':
    print("Utilities file loaded successfully ! \n")
    print("Made By :   # MESRAR Hamza\n")