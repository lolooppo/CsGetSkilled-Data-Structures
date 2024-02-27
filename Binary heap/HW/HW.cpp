/**************************************************************************************/
/* KthNumberProcessor  :  this is a class which keeps returning the k smallest number */
/**************************************************************************************/

class KthNumberProcessor{
private:
    int k{0};
    priority_queue<int>pq;

public:
    KthNumberProcessor(int k):k(k){}

    int next(int new_num){
    int res{0};

        if(pq.empty() or pq.size() < k){
            pq.push(new_num);
        }else if(pq.top() > new_num){
            pq.pop();
            pq.push(new_num);
        }

        res = pq.top();
        return res;
    }
};
