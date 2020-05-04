#include<iostream> 
#include <cstring>
#include<string> 
#include<iomanip> 
#include<algorithm> 
using namespace std; 

#define MAXN 9999
#define MAXSIZE 10
#define DLEN 4

class BigNum
{ 
       
public: 
    int a[1500];    
    int len; 
    BigNum(){ len = 1;memset(a,0,sizeof(a)); }   
    BigNum(const int);       
    BigNum(const char*);     
    BigNum(const BigNum &); 
    BigNum &operator=(const BigNum &);   
    
    friend istream& operator>>(istream&,  BigNum&);   
    friend ostream& operator<<(ostream&,  BigNum&);  
    
    BigNum operator+(const BigNum &) const;  
    BigNum operator-(const BigNum &) const;    
    BigNum operator*(const BigNum &) const;   
    BigNum operator/(const int   &) const;   
    
    BigNum operator^(const int  &) const;    
    int    operator%(const int  &) const;       
    bool   operator>(const BigNum & T)const; 
    bool   operator>(const int & t)const;      
    
    void print();
    string toString();
}; 
BigNum::BigNum(const int b)    
{ 
    int c,d = b;
    len = 0;
    memset(a,0,sizeof(a));
    while(d > MAXN)
    {
        c = d - (d / (MAXN + 1)) * (MAXN + 1); 
        d = d / (MAXN + 1);
        a[len++] = c;
    }
    a[len++] = d;
}
BigNum::BigNum(const char*s) 
{
    int t,k,index,l,i;
    memset(a,0,sizeof(a));
    l=strlen(s);   
    len=l/DLEN;
    if(l%DLEN)
        len++;
    index=0;
    for(i=l-1;i>=0;i-=DLEN)
    {
        t=0;
        k=i-DLEN+1;
        if(k<0)
            k=0;
        for(int j=k;j<=i;j++)
            t=t*10+s[j]-'0';
        a[index++]=t;
    }
}
BigNum::BigNum(const BigNum & T) : len(T.len)
{ 
    int i; 
    memset(a,0,sizeof(a)); 
    for(i = 0 ; i < len ; i++)
        a[i] = T.a[i]; 
} 
BigNum & BigNum::operator=(const BigNum & n) 
{
    int i;
    len = n.len;
    memset(a,0,sizeof(a)); 
    for(i = 0 ; i < len ; i++) 
        a[i] = n.a[i]; 
    return *this; 
}
istream& operator>>(istream & in,  BigNum & b)  
{
    char ch[MAXSIZE*4];
    int i = -1;
    in>>ch;
    int l=strlen(ch);
    int count=0,sum=0;
    for(i=l-1;i>=0;)
    {
        sum = 0;
        int t=1;
        for(int j=0;j<4&&i>=0;j++,i--,t*=10)
        {
            sum+=(ch[i]-'0')*t;
        }
        b.a[count]=sum;
        count++;
    }
    b.len =count++;
    return in;
    
}
ostream& operator<<(ostream& out,  BigNum& b){
    int i;  
    cout << b.a[b.len - 1]; 
    for(i = b.len - 2 ; i >= 0 ; i--)
    { 
        cout.width(DLEN); 
        cout.fill('0'); 
        cout << b.a[i]; 
    } 
    return out;
}

BigNum BigNum::operator+(const BigNum & T) const
{
    BigNum t(*this);
    int i,big;      
    big = T.len > len ? T.len : len; 
    for(i = 0 ; i < big ; i++) 
    { 
        t.a[i] +=T.a[i]; 
        if(t.a[i] > MAXN) 
        { 
            t.a[i + 1]++; 
            t.a[i] -=MAXN+1; 
        } 
    } 
    if(t.a[big] != 0)
        t.len = big + 1; 
    else
        t.len = big;   
    return t;
}
BigNum BigNum::operator-(const BigNum & T) const 
{  
    int i,j,big;
    bool flag;
    BigNum t1,t2;
    if(*this>T)
    {
        t1=*this;
        t2=T;
        flag=0;
    }
    else
    {
        t1=T;
        t2=*this;
        flag=1;
    }
    big=t1.len;
    for(i = 0 ; i < big ; i++)
    {
        if(t1.a[i] < t2.a[i])
        { 
            j = i + 1; 
            while(t1.a[j] == 0)
                j++; 
            t1.a[j--]--; 
            while(j > i)
                t1.a[j--] += MAXN;
            t1.a[i] += MAXN + 1 - t2.a[i]; 
        } 
        else
            t1.a[i] -= t2.a[i];
    }
    t1.len = big;
    while(t1.a[t1.len - 1] == 0 && t1.len > 1)
    {
        t1.len--; 
        big--;
    }
    if(flag)
        t1.a[big-1]=0-t1.a[big-1];
    return t1; 
} 

BigNum BigNum::operator*(const BigNum & T) const 
{ 
    BigNum ret; 
    int i,j,up; 
    int temp,temp1;   
    for(i = 0 ; i < len ; i++)
    { 
        up = 0; 
        for(j = 0 ; j < T.len ; j++)
        { 
            temp = a[i] * T.a[j] + ret.a[i + j] + up; 
            if(temp > MAXN)
            { 
                temp1 = temp - temp / (MAXN + 1) * (MAXN + 1); 
                up = temp / (MAXN + 1); 
                ret.a[i + j] = temp1; 
            } 
            else
            { 
                up = 0; 
                ret.a[i + j] = temp; 
            } 
        } 
        if(up != 0) 
            ret.a[i + j] = up; 
    } 
    ret.len = i + j; 
    while(ret.a[ret.len - 1] == 0 && ret.len > 1)
        ret.len--; 
    return ret; 
} 
BigNum BigNum::operator/(const int & b) const
{ 
    BigNum ret; 
    int i,down = 0;   
    for(i = len - 1 ; i >= 0 ; i--)
    { 
        ret.a[i] = (a[i] + down * (MAXN + 1)) / b; 
        down = a[i] + down * (MAXN + 1) - ret.a[i] * b; 
    } 
    ret.len = len; 
    while(ret.a[ret.len - 1] == 0 && ret.len > 1)
        ret.len--; 
    return ret; 
}
int BigNum::operator %(const int & b) const     
{
    int i,d=0;
    for (i = len-1; i>=0; i--)
    {
        d = ((d * (MAXN+1))% b + a[i])% b;  
    }
    return d;
}
BigNum BigNum::operator^(const int & n) const 
{
    BigNum t,ret(1);
    int i;
    if(n<0)
        exit(-1);
    if(n==0)
        return 1;
    if(n==1)
        return *this;
    int m=n;
    while(m>1)
    {
        t=*this;
        for( i=1;i<<1<=m;i<<=1)
        {
            t=t*t;
        }
        m-=i;
        ret=ret*t;
        if(m==1)
            ret=ret*(*this);
    }
    return ret;
}
bool BigNum::operator>(const BigNum & T) const 
{ 
    int ln; 
    if(len > T.len)
        return true; 
    else if(len == T.len)
    { 
        ln = len - 1; 
        while(a[ln] == T.a[ln] && ln >= 0)
            ln--; 
        if(ln >= 0 && a[ln] > T.a[ln])
            return true; 
        else
            return false; 
    } 
    else
        return false; 
}
bool BigNum::operator >(const int & t) const 
{
    BigNum b(t);
    return *this>b;
}

void BigNum::print() 
{ 
    int i;   
    cout << a[len - 1]; 
    for(i = len - 2 ; i >= 0 ; i--)
    { 
        cout.width(DLEN); 
        cout.fill('0'); 
        cout << a[i]; 
    } 
    cout << endl;
}




string BigNum::toString() 
{
    string res = "";
    for(int i = len - 1; i >= 0; i--) {
        string tmp = to_string(a[i]);
        
        for(int j = 0; j < 4 - tmp.length(); j++) {
            res += '0';
        }
        
        res += tmp;
    }
    
    return res;
}

BigNum pow( BigNum a, int b ) {
    BigNum res( 1 );
    while( b ) {
        if( b % 2 == 1 ) res = res * a;
        a = a * a;
        b = b / 2;
    }
    return res;
}

void m() {
    string base, expo;
    
    while(cin >> base >> expo) {
        if (expo == "0") {
            cout << "1" << endl;
            continue;
        }
        
        int pt = base.find('.');
        
        // remove the zero before the decimal point
        int j = 0;
        while (j != pt) {
            if (base[j] == '0') base.erase(j, 1);
            else break;
        }
        
        // remove the zero after the decimal point
        reverse(base.begin(), base.end());
        while (j != pt) {
            if (base[j] == '0') base.erase(j, 1);
            else break;
        }
        
        int tt = base.find('.');
        
     
        
        string tmp = base.erase(tt, 1);
        
        reverse(tmp.begin(), tmp.end());
        BigNum a = tmp.c_str();
        
        
        
        BigNum b = pow(a, stoi(expo));
        
        string res = b.toString();
        
        int new_pt = tt * stoi(expo);
        
        reverse(res.begin(), res.end());
        
        if(new_pt >= res.length()) {
            int zero_needed = new_pt - res.length();
            for (int i = 0;i < zero_needed;i++) { 
                res = res + '0';
            }   
            
            res = res + '.';
        }else {
            res.insert(new_pt, 1, '.'); 
        }
        
        if(!tt) 
            res.erase(0, 1);
        
        reverse(res.begin(), res.end());
    
    
        pt = res.find('.');
        
        // remove the zero before the decimal point
        j = 0;
        while (j != pt) {
            if (res[j] == '0') res.erase(j, 1);
            else break;
        }
        
        // remove the zero after the decimal point
        reverse(res.begin(), res.end());
        while (j != pt) {
            if (res[j] == '0') res.erase(j, 1);
            else break;
        }
        
        reverse(res.begin(), res.end());
        cout << res << endl;
    }
}

int main() {
    m();
    return 0;
}s