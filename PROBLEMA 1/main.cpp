#include <iostream>
#include <vector>

/// 1-- PCT A

int minCirc(std::vector<int>a,int st,int dr )
{
    int mij=(st+dr)/2;

    if(a[mij] < a[mij-1] && a[mij]<a[mij+1])
        return mij;
    else if(mij==dr && a[mij]<a[mij-1])
        return mij;
    else if(mij==st && a[mij]<a[dr])
        return mij;
    else if(a[mij]>a[st] && a[mij]<a[dr])
        return st;

    if(a[mij]>a[dr] )
        return minCirc(a,mij+1,dr);

    if(a[mij]<a[st])
        return minCirc(a,st,mij-1);

    return -1;
}

/// 1-- PCT B
int cautare_binara(std::vector<int> a, int st, int dr,int e);


int cautare_binara(std::vector<int> a, int st, int dr,int e){

    int mij=(st+dr)/2;

    if(a[mij]==e)
        return mij;

    if(a[mij]>e)
        return cautare_binara(a,st,mij-1,e);

    if(a[mij]<e)
        return cautare_binara(a,mij+1,dr,e);


    return -1;

}

int firstCirc(std::vector<int>&a,int e,int st,int dr,int poz){

    int mij;

    if(poz==-1)
        mij=(st+dr)/2;
    else{
        mij=poz;
        poz=-1;
    }
    //std::cout<<mij<<" ";

    if(e==a[mij]) {
        if(a[mij-1]!=e)
            return mij;

        return firstCirc(a, e, st, mij, poz);

    }
    if(e>a[mij] && e<=a[dr])
        return firstCirc(a,e,mij+1,dr,poz);
    else
        return firstCirc(a,e,st,mij-1,poz);
}



int main() {

    std::vector<int> a{11,12,13,7,8,9,10};

//    std::vector<int>b{6,7,8,0,1,2,2,2,2,3,4,5};
 //   std::vector<int>b{0,1,1,1,2,3,4,5,6,7,8,9};
    std::vector<int>b{3,4,5,6,7,8,9,0,1,1,1,1,1,1,1,1,1,2,};

    std::cout<<firstCirc(b,1,0,(int)b.size()-1,minCirc(b,0,(int)b.size()-1));

    //std::cout<<minCirc(b,0,b.size()-1);





    return 0;
}
