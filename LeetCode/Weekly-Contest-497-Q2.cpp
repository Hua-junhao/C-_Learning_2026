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
        double cosA = std::clamp((b*b + c*c - a*a) / (2.0 * b * c), -1.0, 1.0);
        double cosB = std::clamp((a*a + c*c - b*b) / (2.0 * a * c), -1.0, 1.0); 
        double A = acos(cosA) * (180.0 / pi);
        double B = acos(cosB) * (180.0 / pi);
        result.push_back(A);
        result.push_back(B);
        result.push_back(180.0 - A - B);
        return result;
        
    }
};©leetcode