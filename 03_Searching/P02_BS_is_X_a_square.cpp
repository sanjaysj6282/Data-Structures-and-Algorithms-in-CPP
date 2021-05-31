
class Solution{
  public:
    long long int floorSqrt(long long int x) 
    {
        long long int left=0;
        long long int right=x;
        while(left<=right){
            long long int mid= left + (right-left)/2;
            if(mid*mid==x)
                return mid;
            else if(mid*mid>x)
                right=mid-1;
            else
                left=mid+1;
        }
        // To return the floor value 
        // i.e, next lowest integer
        return floor(sqrt(x));
    }
};
