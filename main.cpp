#if 1
    #include <bits/stdc++.h>
    #include <boost/multiprecision/integer.hpp>
    #include <boost/multiprecision/cpp_int.hpp>
    #include <boost/multiprecision/detail/integer_ops.hpp>
    #include <boost/range/irange.hpp>
    #include <boost/range/algorithm.hpp>
    #include <boost/range/numeric.hpp>
    #include <boost/integer/common_factor.hpp>

    #define for_in(x,X) for(auto& x: X)
    #define rep(i,count) for(size_t i=0; i<count; ++i)
    #define for_range(i,begin,end) for(size_t i=begin; i<end; ++i)

    using namespace std; using boost::irange; using boost::multiprecision::cpp_int; using big_int = cpp_int;
    using uint = unsigned int; using u32 = uint32_t; using u64 = uint64_t; using s32 = int32_t; using s64 = int64_t; using f32 = float; using f64 = double;
    using v_int = vector<int>; using v_uint = vector<uint>; using v_u32 = vector<u32>; using v_s32 = vector<s32>;
    using v_u64 = vector<u64>; using v_s64 = vector<s64>; using v_bool = vector<bool>; using v_string = vector<string>;
    using v_f32 = vector<f32>; using v_f64 = vector<f64>; using v_float = vector<float>; using v_double = vector<double>;
    struct MAX{template<typename T> inline constexpr operator T() const{return numeric_limits<T>::max();}};
    struct MIN{template<typename T> inline constexpr operator T() const{return numeric_limits<T>::min();}};  
   
    void Main();
    int main(){cin.tie(0);ios::sync_with_stdio(false);cout<<fixed<<setprecision(15);Main();}
    inline char ctoi(char a){return a-'0';}
    struct input{template<typename T> inline operator T() const{T t;cin>>t;return t;}};
    void print(){cout<<"\n";}
    template<class Head, class... Tail> void print(Head&& first, Tail&&... rest){cout<<first;if(sizeof...(rest)!= 0)cout<<' ';print(forward<Tail>(rest)...);}
    template<class T> string str(T x){stringstream ss;ss<<x;return ss.str();}

    template <class T> class has_iterator{
    template <class U> static constexpr bool check(typename U::iterator*){return true;}
    template <class U> static constexpr bool check(...){return false;}
    public: static constexpr bool value = check<T>(nullptr); };
    #define template_iterable(T) template<class T, typename std::enable_if<has_iterator<T>::value, std::nullptr_t>::type = nullptr>

    constexpr u32 pow_int(u32 x, u32 n){u32 res=1; while(n){if(n&1)res*=x;n>>=1;if(n)x=x*x;} return res;}
    constexpr s32 pow_int(s32 x, u32 n){s32 res=1; while(n){if(n&1)res*=x;n>>=1;if(n)x=x*x;} return res;}
    constexpr u64 pow_int(u64 x, u32 n){u64 res=1; while(n){if(n&1)res*=x;n>>=1;if(n)x=x*x;} return res;}
    constexpr s64 pow_int(s64 x, u32 n){s64 res=1; while(n){if(n&1)res*=x;n>>=1;if(n)x=x*x;} return res;}
    using boost::math::gcd; using boost::math::lcm;
    template_iterable(T) inline typename T::value_type gcd(const T &x){auto t=*x.begin();for_in(v,x)t=gcd(t,v);return t;}
    template_iterable(T) inline typename T::value_type lcm(const T &x){auto t=*x.begin();for_in(v,x)t=lcm(t,v);return t;}

    using boost::sort; using boost::search; using boost::binary_search; using boost::max_element; using boost::min_element;
    template_iterable(T) inline typename T::value_type max(const T &x){return *max_element(x);}
    template_iterable(T) inline typename T::value_type min(const T &x){return *min_element(x);}
    template_iterable(T) inline size_t argmax(const T &x){auto it=max_element(x);return distance(x.begin(),it);}
    template_iterable(T) inline size_t argmin(const T &x){auto it=min_element(x);return distance(x.begin(),it);}
    template_iterable(T) inline typename T::value_type sum(const T &x){return boost::accumulate(x,(typename T::value_type)0);}
    template_iterable(T) inline size_t get_idx(const T &x, typename T::value_type val){auto it=boost::find(x,val); return distance(x.begin(), it);}
    template_iterable(T) inline bool is_in(typename T::value_type val, const T &x){auto it=boost::find(x,val); return it!=x.end();}
    template_iterable(T) inline void rsort(T &x){sort(x.rbegin(), x.rend());}
    template_iterable(T) inline size_t len(const T &x){return x.size();}
    
    template<class T> inline T max(const set<T> &x){return *(--x.end());}
    template<class T> inline T min(const set<T> &x){return *(x.begin());}
    template<class T> inline bool is_in(T val, const set<T> &x){return x.count(val);}
    template<class T> inline bool is_in(T val, const unordered_set<T> &x){return x.count(val);}

    template<class T, class U> inline U max_value(const map<T,U> &x){U _max=(*x.begin()).second; for_in(p,x)_max=max(_max,p.second); return _max;}
    template<class T, class U> inline U min_value(const map<T,U> &x){U _min=(*x.begin()).second; for_in(p,x)_min=min(_min,p.second); return _min;}
    template<class T, class U> inline T max_key(const map<T,U> &x){return (*(--x.end())).first;}
    template<class T, class U> inline T min_key(const map<T,U> &x){return (*(x.begin())).first;}
    template<class T, class U> inline T argmax(const map<T,U> &x){T _argmax=(*x.begin()).first; U _max=(*x.begin()).second; for_in(p,x)if(_max<p.second){_argmax=p.first;_max=p.second;}return _argmax;}
    template<class T, class U> inline T argmin(const map<T,U> &x){T _argmin=(*x.begin()).first; U _min=(*x.begin()).second; for_in(p,x)if(_min>p.second){_argmin=p.first;_min=p.second;}return _argmin;}
    template<class T, class U> inline U sum_value(const map<T,U> &x){U _sum=(*x.begin()).second; for(auto it=++x.begin(); it!=x.end(); ++it) _sum+=(*it).second; return _sum;}
    template<class T, class U> inline T sum_key(const map<T,U> &x){T _sum=(*x.begin()).first; for(auto it=++x.begin(); it!=x.end(); ++it) _sum+=(*it).first; return _sum;}
    template<class T, class U> inline T get_key(const map<T,U> &x, U val){for_in(p,x)if(p.second==val)return p.first;}
    template<class T, class U> inline bool is_in_value(U val, const map<T,U> &x){for_in(p,x)if(p.second==val)return true; return false;}
    template<class T, class U> inline bool is_in_key(T key, const map<T,U> &x){try{x.at(key);}catch(out_of_range&){return false;} return true;}
    
    template<class T, class U> inline U max_value(const unordered_map<T,U> &x){U _max=(*x.begin()).second; for_in(p,x)_max=max(_max,p.second); return _max;}
    template<class T, class U> inline U min_value(const unordered_map<T,U> &x){U _min=(*x.begin()).second; for_in(p,x)_min=min(_min,p.second); return _min;}
    template<class T, class U> inline T max_key(const unordered_map<T,U> &x){T _max=(*x.begin()).first; for_in(p,x)_max=max(_max,p.first); return _max;}
    template<class T, class U> inline T min_key(const unordered_map<T,U> &x){T _min=(*x.begin()).first; for_in(p,x)_min=min(_min,p.first); return _min;}
    template<class T, class U> inline T argmax(const unordered_map<T,U> &x){T _argmax=(*x.begin()).first; U _max=(*x.begin()).second; for_in(p,x)if(_max<p.second){_argmax=p.first;_max=p.second;}return _argmax;}
    template<class T, class U> inline T argmin(const unordered_map<T,U> &x){T _argmin=(*x.begin()).first; U _min=(*x.begin()).second; for_in(p,x)if(_min>p.second){_argmin=p.first;_min=p.second;}return _argmin;}
    template<class T, class U> inline U sum_value(const unordered_map<T,U> &x){U _sum=(*x.begin()).second; for(auto it=++x.begin(); it!=x.end(); ++it) _sum+=(*it).second; return _sum;}
    template<class T, class U> inline T sum_key(const unordered_map<T,U> &x){T _sum=(*x.begin()).first; for(auto it=++x.begin(); it!=x.end(); ++it) _sum+=(*it).first; return _sum;}
    template<class T, class U> inline T get_key(const unordered_map<T,U> &x, U val){for_in(p,x)if(p.second==val)return p.first;}
    template<class T, class U> inline bool is_in_value(U val, const unordered_map<T,U> &x){for_in(p,x)if(p.second==val)return true; return false;}
    template<class T, class U> inline bool is_in_key(T key, const unordered_map<T,U> &x){try{x.at(key);}catch(out_of_range&){return false;} return true;}
    
    template<class T, class U, class S> inline S& operator<<(S& os, const pair<T,U> &x){os<<x.first<<":"<<x.second; return os;}
    template<class T, class S> inline S& operator<<(S& os, const vector<T> &x){auto last=&x.back();os<<'[';for_in(y,x){os<<y; if(&y!=last)os<<" ";}os<<']'; return os;}
    template<class T, class S> inline S& operator<<(S& os, const deque<T> &x){auto last=&x.back();os<<'[';for_in(y,x){os<<y; if(&y!=last)os<<" ";}os<<']'; return os;}
    template<class T, size_t SIZE, class S> inline S& operator<<(S& os, const array<T,SIZE> &x){auto last=&x.back();os<<'[';for_in(y,x){os<<y; if(&y!=last)os<<" ";}os<<']'; return os;}
    template<class T, class S> S& operator<<(S& os, const set<T> &x){auto s=x.size();size_t c=0;os<<'{';for_in(y,x){os<<y;c++;if(c!=s)os<<" ";}os<<'}'; return os;}
    template<class T, class S> S& operator<<(S& os, const unordered_set<T> &x){auto s=x.size();size_t c=0;os<<'{';for_in(y,x){os<<y;c++;if(c!=s)os<<" ";}os<<'}'; return os;}
    template<class T, class U, class S> inline S& operator<<(S& os, const map<T,U> &x){auto s=x.size();size_t c=0;os<<'{';for_in(y,x){os<<y;c++;if(c!=s)os<<" ";}os<<'}'; return os;}
    template<class T, class U, class S> inline S& operator<<(S& os, const unordered_map<T,U> &x){auto s=x.size();size_t c=0;os<<'{';for_in(y,x){os<<y;c++;if(c!=s)os<<" ";}os<<'}'; return os;}

    template<class T> inline istream& operator>>(istream& is, vector<T> &x){for_in(e, x)is>>e; return is;}
    template<class T> inline istream& operator>>(istream& is, deque<T> &x){for_in(e, x)is>>e; return is;}
    template<class T, size_t SIZE> inline istream& operator>>(istream& is, array<T,SIZE> &x){for_in(e, x)is>>e; return is;}
   
    template<typename T=s32, T MOD=(pow_int(10,9)+7)>
    class ModInteger : boost::operators<ModInteger<T>>
    {
        private:
            T num;
        public:
            ModInteger():num(0){}
            ModInteger(T t){num=(t%MOD+MOD)%MOD;}
            template<typename U> ModInteger(const ModInteger<U>& x){num=((T)x)%MOD;}
            bool operator<(const ModInteger<T>& x)const{return num<x.num;}
            bool operator==(const ModInteger<T>& x)const{return num==x.num;}
            ModInteger<T>& operator+=(const ModInteger<T>& x){num=(num+x.num)%MOD;return *this;}
            ModInteger<T>& operator-=(const ModInteger<T>& x){num=(MOD+num-x.num)%MOD;return *this;}
            ModInteger<T>& operator*=(const ModInteger<T>& x){num=(static_cast<s64>(num)*static_cast<s64>(x.num)%MOD+MOD)%MOD;return *this;}
            ModInteger<T>& operator/=(const ModInteger<T>& x){if(num%x.num==0){num/=x.num; return *this;}num=(static_cast<s64>(num)*static_cast<s64>(x.inverse().num))%MOD;return *this;}
            ModInteger<T>& operator^=(const ModInteger<T>& x){T num1=num;T num2=x.num; if(num2<0){num1=inverse().num;num2*=-1;} num=boost::multiprecision::powm(num1,num2,MOD);return *this;}
            ModInteger<T>& operator++(){num=(num+1)%MOD; return *this;}
            ModInteger<T>& operator--(){num=(MOD+num-1)%MOD; return *this;}
            ModInteger<T> inverse()const{return ModInteger<T>(boost::multiprecision::powm(num,MOD-2,MOD));}
            template<typename U> explicit operator U()const{return num;}
            static inline ModInteger<T> nPr(T n, T r){ModInteger<T> res(1); for(T i=n;i>n-r;--i)res*=i; return res;}
            static inline ModInteger<T> nCr(T n, T r){if(r/2>n)r=n-r; return nPr(n,r)/factorial(r);}
            static inline ModInteger<T> factorial(T n){ModInteger<T> res(1); for(T i=1;i<=n;++i)res*=i; return res;}
        template<class U, U M,class S> friend inline S& operator<<(S& os, const ModInteger<U, M> &x);
        template<class U, U M> friend inline istream& operator>>(istream& is, ModInteger<U, M> &x);
    };
    template<class T, T M, class S> inline S& operator<<(S& os, const ModInteger<T,M> &x){os<<x.num; return os;}
    template<class T, T M> inline istream& operator>>(istream& is, ModInteger<T, M> &x){is>>x.num; return is;};
    using mint = ModInteger<>; using v_mint = vector<mint>;
#endif

void Main(){
    string a = input();
    print(a);
}
