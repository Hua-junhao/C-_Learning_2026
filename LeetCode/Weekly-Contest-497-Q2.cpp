class Solution {
public:
    vector<double> internalAngles(vector<int>& sides) {
        sort(sides.begin(),sides.end());
        int a=sides[0],b=sides[1],c=sides[2],sum=a+b+c;
        vector<double>result;
        for(int i:sides)
        {
            if(2*i>=sum) return result;
        }
        double pi=acos(-1.0);
        double A=acos((b*b+c*c-a*a)/(2.0*c*b))*(180.0/pi),B=acos((a*a+c*c-b*b)/(2.0*a*c))*(180.0/pi),C=acos((a*a+b*b-c*c)/(2.0*a*b))*(180.0/pi);
        result.push_back(A);
        result.push_back(B);
        result.push_back(180.0-A-B);
        return result;
        
    }
};©leetcode