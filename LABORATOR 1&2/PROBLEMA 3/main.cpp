#include <iostream>
#include <vector>

using std::cout;


int cautare_binara(std::vector<int>&a,int e,int st,int dr){

    int mij=(st+dr)/2;

   cout<<st<<" "<<mij<<" "<<dr<<"\n";

    if(e==a[mij])return mij;
    if(e==a[st])return st;
    if(e==a[dr])return dr;
    else
    if((dr-st)>1 && dr>1 )
    {
        if(mij%2==0){
            if(e>a[mij])return cautare_binara(a,e,mij+2,dr);
            if(e<a[mij])return cautare_binara(a,e,st,mij-2);
        }
        else if(mij%2!=0){
            if(e>a[mij])return cautare_binara(a,e,st,mij-2);
            if(e<a[mij])return cautare_binara(a,e,mij+2,dr);
        }


    }else
    return -1;
}



int existsAlternate(std::vector<int>&a,int e ,int st,int dr){

    int x;

    x= cautare_binara(a,e,st,dr);
    if(x==-1)
        x= cautare_binara(a,e,1,dr);


    return x;
}
int main() {

    std::vector<int> a={1,11,2,10,3,9,4,8,5,7}; /// 10 , 9

    std::cout<<existsAlternate(a,7,0,a.size()-1);

    //cout<<cautare_binara(a,11,0,a.size()-1);






    return 0;
}
