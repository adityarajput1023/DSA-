class Solution {
public:
    vector<double> convertTemperature(double celsius) {
        double kelvin,F;
        kelvin=celsius +273.15;
        F=celsius*1.80 +32.00;
         
        return {kelvin,F};
    }
};