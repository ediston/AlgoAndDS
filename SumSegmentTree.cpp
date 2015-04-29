long init(long i, long l, long h, long *arr){
    if(l>h) return 0;
    if(l==h){
        arr[i] = done[l];
        return arr[i];
    }
    long mid = (l+h)/2;
    arr[i] = done[mid] + init(2*i, l, mid , arr) +  init(2*i+1, mid+1, h, arr);
    return arr[i];
}

void update(long i, long ui, long l, long h, long *arr, long diff){
    if(ui<l || ui > h){
        return;
    }
    arr[i]+=diff;
    if(l==h) return;
    update(2*i,   ui, l, (l+h)/2 , arr);
    update(2*i+1, ui, (l+h)/2+1, h , arr);
}

long getB(long i, long s, long e, long l, long h, long *arr){
    if(h < s || l > e)return 0;
    if(s<=l && e>=h)
        return arr[i];
    return getB(2*i, s, e, l, (l+h)/2 , arr) + getB(2*i+1, s, e, (l+h)/2+1, h, arr);
}
