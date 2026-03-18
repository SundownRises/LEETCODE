class Solution {
public:
vector<string> below20 = {
    "", "One", "Two", "Three", "Four", "Five", "Six",
    "Seven", "Eight", "Nine", "Ten", "Eleven", "Twelve",
    "Thirteen", "Fourteen", "Fifteen", "Sixteen",
    "Seventeen", "Eighteen", "Nineteen"
};
vector<string> tens = {
    "", "", "Twenty", "Thirty", "Forty",
    "Fifty", "Sixty", "Seventy", "Eighty", "Ninety"
};
string helper(int num){
    if(num == 0) return "";
    if(num < 20) return below20[num];
    if(num < 100){
        string res = tens[num/10];
        if(num % 10) res += " " + helper(num % 10);
        return res;
    }
    string res = below20[num/100] + " Hundred";
    if(num % 100) res += " " + helper(num % 100);
    return res;
}
string numberToWords(int num) {
if(num == 0) return "Zero";
string res = "";
if(num >= 1000000000){
    res += helper(num/1000000000) + " Billion";
    num %= 1000000000;
    if(num) res += " ";
}
if(num >= 1000000){
    res += helper(num/1000000) + " Million";
    num %= 1000000;
    if(num) res += " ";
}
if(num >= 1000){
    res += helper(num/1000) + " Thousand";
    num %= 1000;
    if(num) res += " ";
}
if(num) res += helper(num);
return res;                
    }
};