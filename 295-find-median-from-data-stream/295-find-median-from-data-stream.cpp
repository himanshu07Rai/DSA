class MedianFinder {
    private: 
     priority_queue<int> maxheap; 
     priority_queue<int,vector<int>,greater<int>> minheap;
public:
   
    /** initialize your data structure here. */
    MedianFinder() {
         
    }
    
    void addNum(int num) {
        int lsize = maxheap.size();
        int rsize = minheap.size();
        if(lsize==0)    
            maxheap.push(num);
        else if(lsize==rsize)   
        {
            if(num<minheap.top())  
                maxheap.push(num);
            else    
            {
                int temp = minheap.top();   //Save root of minheap
                minheap.pop();  //Pop the root from minheap
                minheap.push(num);  //Push num in minheap
                maxheap.push(temp); //Push the previous saved root of minheap in the maxheap
            }
        }
        else    
        {
            if(minheap.size()==0)
            {
                if(num>maxheap.top()) 
                    minheap.push(num);
                else 
                {
                    int temp = maxheap.top();
                    maxheap.pop();
                    maxheap.push(num);
                    minheap.push(temp);
                }
            }
            else if(num>=minheap.top()) 
                minheap.push(num);
            else    
            {
                if(num<maxheap.top())   
                {
                    int temp = maxheap.top();   //Save root of maxheap
                    maxheap.pop();  //Pop root of maxheap
                    maxheap.push(num);  //Push num to maxheap
                    minheap.push(temp); //Push previous saved root of maxheap to minheap
                }
                else    
                    minheap.push(num);
            }
        }
    }
    
    double findMedian() {
        int lsize = maxheap.size();
        int rsize = minheap.size();
        if(lsize > rsize)  
            return double(maxheap.top());
        else    
            return (double(maxheap.top())+double(minheap.top()))/2;
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */