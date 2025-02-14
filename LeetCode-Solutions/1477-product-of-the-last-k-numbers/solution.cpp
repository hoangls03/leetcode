class ProductOfNumbers {
public:
    vector<int> vt;
    ProductOfNumbers() {
        
    }
    
    void add(int num) {
        vt.push_back(num);
    }
    
    int getProduct(int k) {
        int n = vt.size();
        int ans = 1;
        for ( int i = n - 1 ; i >= n - k ; --i ) {
            ans *= vt[i];
        }
        return ans;
    }
};

/**
 * Your ProductOfNumbers object will be instantiated and called as such:
 * ProductOfNumbers* obj = new ProductOfNumbers();
 * obj->add(num);
 * int param_2 = obj->getProduct(k);
 */
