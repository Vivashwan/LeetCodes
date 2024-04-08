class ProductOfNumbers {
public:
    vector<int> prod;
    ProductOfNumbers() {
        
    }
    
    void add(int num) {
        if(num == 0)
            prod.clear();
        else if(prod.size() == 0)
            prod.push_back(num);
        else
            prod.push_back(num * prod.back());
    }
    
    int getProduct(int k) {
        if(prod.size() < k)
            return 0;
        else if(prod.size() == k)
            return prod.back();
        return prod.back()/prod[prod.size() - k - 1];
    }
};

/**
 * Your ProductOfNumbers object will be instantiated and called as such:
 * ProductOfNumbers* obj = new ProductOfNumbers();
 * obj->add(num);
 * int param_2 = obj->getProduct(k);
 */