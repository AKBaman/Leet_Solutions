class Solution {
    public boolean checkString(String s) {
        int n = s.length(),count=0;
        for(int i=0;i<n-1;i++){
            char a = s.charAt(i);
            char b = s.charAt(i+1);
            if(a!=b) count++;
        }
        if(s.charAt(0)!='a') count++;
        return count<=1;
    }
}