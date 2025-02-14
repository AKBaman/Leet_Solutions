class ProductOfNumbers {
public:
    vector<int> arr;
    int n;
    ProductOfNumbers() {
        arr.clear();
        n=0;
    }
    
    void add(int num) {
        if(num==0){
            arr.clear();
            n=0;
        }
        else{
            if(n==0){
                arr.push_back(num);
            }
            else{
                arr.push_back(num*arr[n-1]);
            }
            n++;
        }
    }
    
    int getProduct(int k) {
        if(k > n) return 0;
        if(k==n) return arr[n-1];
        return arr[n-1]/arr[n-k-1];
    }
};

/**
 * Your ProductOfNumbers object will be instantiated and called as such:
 * ProductOfNumbers* obj = new ProductOfNumbers();
 * obj->add(num);
 * int param_2 = obj->getProduct(k);
 */